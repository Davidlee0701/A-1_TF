/******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.
******************************************************************************/

/*
**  UART.c
**
**  Routines for operating a UART
**  (C) Copyright by Renesas Electronics Europe GmbH
**
**  Notes:
**  - The implementation is UART type specific
**
**  Revisions:
**  2011/05/24  ME  Initial (UARTE on Dx4)
**  2016/02/16  ME  RLIN3 on P1x
**
**  See UART.h for more information
**
****************************************************************************/

#include "UART.h"

#include "U5L.h"
#include <Interrupts.h>
#if ( UART_TX_ENABLED && !UART_TX_SAFE ) || UART_RX_ENABLED
//  #include "Interrupts.h"
#endif




#if UART_MAX_CHANNELS < 1
  #error UART_MAX_CHANNELS must be at least 1.
#endif

#if !UART_TX_ENABLED && !UART_RX_ENABLED
  #error UART_TX_ENABLED and UART_RX_ENABLED are both disabled.
#endif

#if UART_TX_SAFE && UART_TX_BUFFERED
  #error UART_TX_SAFE and UART_TX_BUFFERED are mutually exclusive.
#endif

#if UART_TX_BUFFERED && UART_TX_BUFFER_SIZE < 1
  #error UART_TX_BUFFER_SIZE must be at least 1.
#endif

#if UART_RX_BUFFERED && UART_RX_BUFFER_SIZE < 1
  #error UART_RX_BUFFER_SIZE must be at least 1.
#endif

#if   UART_BAUD_TOLERANCE < 1
  #warning UART_BAUD_TOLERANCE is set too hard. Baud rates will not be able to be achieved.
#elif UART_BAUD_TOLERANCE > 5
  #warning UART_BAUD_TOLERANCE should be below 5%. Values above 3% may cause tramsmission problems.
#endif




#define SFR08(addr)	(*((volatile uint8_t  *)(uintptr_t)(addr)))
#define SFR16(addr)	(*((volatile uint16_t *)(uintptr_t)(addr)))

#define	RLN3nLWBR	SFR08( SFRBASEADDR[channel] + 0x00000001 )	// RW	Baud Rate selector register
#define	RLN3nLBRP01	SFR16( SFRBASEADDR[channel] + 0x00000002 )	// RW	Baud rate Prescaler register
#define	RLN3nLMD	SFR08( SFRBASEADDR[channel] + 0x00000008 )	// RW	Mode register
#define	RLN3nLBFC	SFR08( SFRBASEADDR[channel] + 0x00000009 )	// RW	Configuration Register 1
#define	RLN3nLSC	SFR08( SFRBASEADDR[channel] + 0x0000000A )	// RW	Space Configuration register
#define	RLN3nLEDE	SFR08( SFRBASEADDR[channel] + 0x0000000D )	// RW	Error Detection Enable register
#define	RLN3nLCUC	SFR08( SFRBASEADDR[channel] + 0x0000000E )	// RW	Control Register
#define	RLN3nLMST	SFR08( SFRBASEADDR[channel] + 0x00000011 )	// RW	Mode Status register
#define	RLN3nLST	SFR08( SFRBASEADDR[channel] + 0x00000012 )	// RW	Status register
#define	RLN3nLEST	SFR08( SFRBASEADDR[channel] + 0x00000013 )	// RW	Error Status register
#define	RLN3nLUOER	SFR08( SFRBASEADDR[channel] + 0x00000020 )	// RW	Operation Enable Register
#define	RLN3nLUOR1	SFR08( SFRBASEADDR[channel] + 0x00000021 )	// RW	Option Register 1
#define	RLN3nLUTDR	SFR08( SFRBASEADDR[channel] + 0x00000024 )	// RW	Transmit Data Register
#define	RLN3nLURDR	SFR08( SFRBASEADDR[channel] + 0x00000026 )	// RW	Receive Data Register




static uintptr_t			SFRBASEADDR	[UART_MAX_CHANNELS];	// remember: static variables are automatically initialized to 0
#if UART_TX_ENABLED && !UART_TX_SAFE
  static          uint_fast16_t		intnum_tx	[UART_MAX_CHANNELS];
#endif
#if UART_RX_ENABLED
  static          uint_fast16_t		intnum_rx	[UART_MAX_CHANNELS];
  static volatile uint_least8_t		UART_STATUS_RX	[UART_MAX_CHANNELS];
#endif
#if UART_TX_ENABLED && UART_TX_BUFFERED
  static volatile uint_fast8_t		TX_BUSY		[UART_MAX_CHANNELS];
  static          uint_least16_t	BUFFER_TX_inptr	[UART_MAX_CHANNELS];
  static volatile uint_least16_t	BUFFER_TX_outptr[UART_MAX_CHANNELS];
  static          unsigned char		BUFFER_TX	[UART_MAX_CHANNELS][UART_TX_BUFFER_SIZE];
  static          void			UARTSendInt	(void);
#endif
#if UART_RX_ENABLED && UART_RX_BUFFERED
  static volatile uint_least16_t	BUFFER_RX_inptr	[UART_MAX_CHANNELS];
  static          uint_least16_t	BUFFER_RX_outptr[UART_MAX_CHANNELS];
  static volatile unsigned char		BUFFER_RX	[UART_MAX_CHANNELS][UART_RX_BUFFER_SIZE];
  static          void			UARTReceiveInt	(void);
#endif




uint_fast8_t UARTInit (
	uint_fast8_t	*channelp	,// will be returned: logical number of channel
	volatile void	*SFRBASEADDRp	,// SFR base address of macro
	uint_fast16_t	intno_tx	,// UART TX interrupt number (may be 0 when not needed)
	uint_fast16_t	intno_rx	,// UART RX interrupt number (may be 0 when not needed)
	uint_fast32_t	basefreq	,// frequency that is used to generate the baud rate
	uint_fast32_t	baud		,// baud rate
	uint_fast8_t	bits		,// number of message bits in a frame
	uint_fast8_t	parity		,// type   of parity   in a frame (use enums to stay compatible)
	uint_fast8_t	stopbits	)// number of stopbits in a frame (use enums to stay compatible)
 {
  uint_fast8_t	channel;
  uint_fast32_t	prs, brs;


  // check parameters
  *channelp = UART_MAX_CHANNELS;
  for ( channel = 0;  channel < UART_MAX_CHANNELS;  channel++ )
    if ( SFRBASEADDR[channel] == (uintptr_t)SFRBASEADDRp )
      return( UART_STATUS_BADCHANNEL );

  if (	((uintptr_t)SFRBASEADDRp & 0x0000003F)
	#if UART_TX_ENABLED && !UART_TX_SAFE
	||	intno_tx >= NUM_IRQS
	#endif
	#if UART_RX_ENABLED
//	||	intno_rx >= NUM_IRQS
	#endif
	||	baud		== 0
	|| (	bits		!= 7
	&&	bits		!= 8			)
	|| (	parity		!= UART_PARITY_NONE
	&&	parity		!= UART_PARITY_SPACE
	&&	parity		!= UART_PARITY_ODD
	&&	parity		!= UART_PARITY_EVEN	)
	|| (	stopbits	!= UART_STOPBITS_1
	&&	stopbits	!= UART_STOPBITS_2	) )
    return( UART_STATUS_BADPARAMETER );


  // calculate baud rate
  prs = 0;
  brs = ( basefreq + (baud << 3) ) / (baud << 4);
  while ( brs > 0x00010000 )
   {
    brs >>= 1;
    prs++;
   }
  if ( prs > 7
    || ( (int32_t)( (basefreq >> (prs+4) ) / brs ) - (int32_t)baud ) * 100 >  1 * UART_BAUD_TOLERANCE * (int32_t)baud
    || ( (int32_t)( (basefreq >> (prs+4) ) / brs ) - (int32_t)baud ) * 100 < -1 * UART_BAUD_TOLERANCE * (int32_t)baud )
    return( UART_STATUS_BADBAUDRATE );
  brs--;


  // allocate logic channel
  for ( channel = 0;  channel < UART_MAX_CHANNELS;  channel++ )
    if ( SFRBASEADDR[channel] == 0 )
      break;
  if ( channel == UART_MAX_CHANNELS )
    return( UART_STATUS_BADCHANNEL );
  *channelp = channel;
  SFRBASEADDR	[channel] = (uintptr_t)SFRBASEADDRp;
  #if UART_TX_ENABLED && !UART_TX_SAFE
    intnum_tx	[channel] = intno_tx;
  #endif
  #if UART_RX_ENABLED
    intnum_rx	[channel] = intno_rx;
    UART_STATUS_RX[channel] = 0x00;
  #endif


  // clear buffer(s)
  #if UART_TX_ENABLED && UART_TX_BUFFERED
    BUFFER_TX_inptr [channel] = 0;
    BUFFER_TX_outptr[channel] = 0;
    TX_BUSY[channel] = 0;
  #endif
  #if UART_RX_ENABLED && UART_RX_BUFFERED
    BUFFER_RX_inptr [channel] = 0;
    BUFFER_RX_outptr[channel] = 0;
  #endif


  // register interrupt handler(s)
  #if UART_TX_ENABLED && UART_TX_BUFFERED
    if ( IRQHandlerInstall( intno_tx, UARTSendInt, INTC_ENABLED, INTC_SELF, INTC_PRIORITY_MAX, INTC_EDGE, INTC_GROUP_VECTOR ) != INTC_OK )
     {
      SFRBASEADDR[channel] = 0;
      return( UART_STATUS_BADCHANNEL );
     }
  #endif
  #if UART_RX_ENABLED && UART_RX_BUFFERED
    if ( IRQHandlerInstall( intno_rx, UARTReceiveInt, INTC_ENABLED, INTC_SELF, INTC_PRIORITY_MAX, INTC_EDGE, INTC_GROUP_VECTOR ) != INTC_OK )
     {
      SFRBASEADDR[channel] = 0;
      #if UART_TX_ENABLED && UART_TX_BUFFERED
        IRQHandlerUninstall( intno_tx, UARTSendInt );
      #endif
      return( UART_STATUS_BADCHANNEL );
     }
  #endif


  // set up UART

  // disable clock selector protection
  u32_T* CLKKCPROT1 = (u32_T*)(0x5C080700);
  u32_T* CKS_RLINC = (u32_T*)(0x5C080140);
  u32_T* CKS_RLINS = (u32_T*)(0x5C080148);
  
  //SYS0_CLOCK_inst_0->CLKKCPROT1 = UNLOCK_KCPROT;
  *CLKKCPROT1 = UNLOCK_KCPROT;
  // set RLIN31 clock source
  //SYS0_CLOCK_inst_0->CKS_RLINC_b.RLINSCSID = 0x01; // CLK_P080
  *CKS_RLINC = 0x01; // CLK_P080
  //while (WA( SYS0_CLOCK_inst_0->CKS_RLINS_b.RLINSACT) != 0x01);
  while (WA( *CKS_RLINS ) != 0x01);
  
  //SYS0_CLOCK_inst_0->CLKKCPROT1 = LOCK_KCPROT;
  *CLKKCPROT1 = LOCK_KCPROT;


  u32_T* MSRKCPROT = (u32_T*)(0x5C081710);
  u32_T* MSR_RLIN3 = (u32_T*)(0x5C081060);
  
  // disable register protection
  //SYS0_STBC_inst_0->MSRKCPROT = UNLOCK_KCPROT;
  *MSRKCPROT = UNLOCK_KCPROT;
  // Enable RLIN31 clock supply
  //SYS0_STBC_inst_0->MSR_RLIN3_b.MS_RLIN3 = 0;
  *MSR_RLIN3 = 0;
  //SYS0_STBC_inst_0->MSRKCPROT = LOCK_KCPROT;
  *MSRKCPROT = LOCK_KCPROT;


/*
  SYSCTRLMSRKCPROT	 =  0xA5A5A501;	// disable write protection
  SYSCTRLMSR_RLIN3	&= ~0x00FFFFFF;	// start all RLIN3 clocks
  PBGERRSLV50PBGKCPROT	 =  0xA5A5A501;	// unlock write protect
  PBG51PBGPROT0_0	&= ~0x1FF8;	// allow access to RLIN3xx register (even channels)
  PBGERRSLV11H0PBGKCPROT =  0xA5A5A501;	// unlock write protect
  PBG11H0PBGPROT0_0	&= ~0xFF80;	// allow access to RLIN3xx registers (odd channels, 1..17)
  PBGERRSLV8L0PBGKCPROT	 =  0xA5A5A501;	// unlock write protect
  PBG8L0PBGPROT0_0	&= ~0x0010;	// allow access to RLIN323 registers (odd channel 23)
*/
  RLN3nLWBR	= prs << 1;		// set baud rate prescaler
  RLN3nLBRP01	= brs;			// set baud rate counter
  RLN3nLEDE	= 0x0C;			// enable error detections for: framing, overrun
  RLN3nLBFC	=			// regular polarity for TX and RX
		  ( parity   << 3 )
		| ( stopbits << 2 )
					// LSB first
		| ( ( bits == 8 ) ? 0x00 : 0x01 );
  RLN3nLSC	= 0x00;			// 0 bit inter byte space
  #if !UART_TX_SAFE
  RLN3nLUOR1	= 0x00;			// interrupt at start of transmission; no expansion bit operations
  #else
  RLN3nLUOR1	= 0x08;			// interrupt at end of transmission; no expansion bit operations
  #endif
  RLN3nLMD	= 0x21;			// switch to UART mode; disable noise filter
  RLN3nLCUC	= 0x01;			// request to exit reset mode
  while ( !(RLN3nLMST & 0x01) )  {}	// wait to exit reset mode
  RLN3nLUOER	= ( UART_TX_ENABLED ? 0x01 : 0x00 ) | ( UART_RX_ENABLED ? 0x02 : 0x00 );

  #if UART_TX_ENABLED && !UART_TX_BUFFERED && !UART_TX_SAFE
    INTC_IntDisable	( intno_tx );
    INTC_IntPendingSet	( intno_tx );
  #endif
  #if UART_TX_ENABLED &&  UART_TX_BUFFERED
    INTC_IntPendingClear( intno_tx );
    INTC_IntEnable	( intno_tx );
  #endif
  #if UART_RX_ENABLED && !UART_RX_BUFFERED
    INTC_IntDisable	( intno_rx );
    INTC_IntPendingClear( intno_rx );
  #endif
  #if UART_RX_ENABLED &&  UART_RX_BUFFERED
    INTC_IntPendingClear( intno_rx );
    INTC_IntEnable	( intno_rx );
  #endif

  #if ( UART_TX_ENABLED && UART_TX_BUFFERED ) || ( UART_RX_ENABLED && UART_RX_BUFFERED )
    CPU_InterruptEnable();
  #endif

  return( UART_STATUS_OK );
 }




uint_fast8_t UARTDisable ( uint_fast8_t channel )
 {
  #if ( UART_TX_ENABLED && UART_TX_BUFFERED ) || ( UART_RX_ENABLED && UART_RX_BUFFERED )
    __istate_t	InterruptState;
  #endif

  // check parameters
  if ( channel >= UART_MAX_CHANNELS )
    return( UART_STATUS_BADCHANNEL );
  if ( SFRBASEADDR[channel] == 0 )
    return( UART_STATUS_BADCHANNEL );

  // wait until it is idle
  while ( UARTSendPending( channel ) )  {}

  #if ( UART_TX_ENABLED && UART_TX_BUFFERED ) || ( UART_RX_ENABLED && UART_RX_BUFFERED )
    InterruptState = CPU_InterruptDisable();
  #endif

  // disable UART
  RLN3nLCUC	= 0x00;
  while ( RLN3nLMST )  {}
  RLN3nLWBR	= 0x00;
  RLN3nLBRP01	= 0x0000;
  RLN3nLEDE	= 0x00;
  RLN3nLBFC	= 0x00;
  RLN3nLSC	= 0x00;
  RLN3nLUOR1	= 0x00;
  RLN3nLMD	= 0x00;

  #if UART_TX_ENABLED && !UART_TX_BUFFERED && !UART_TX_SAFE
    INTC_IntDisable	( intnum_tx[channel] );
    INTC_IntPendingClear( intnum_tx[channel] );
  #endif
  #if UART_TX_ENABLED &&  UART_TX_BUFFERED
    IRQHandlerUninstall( intnum_tx[channel], UARTSendInt );
  #endif
  #if UART_RX_ENABLED && !UART_RX_BUFFERED
    INTC_IntDisable	( intnum_rx[channel] );
    INTC_IntPendingClear( intnum_rx[channel] );
  #endif
  #if UART_RX_ENABLED &&  UART_RX_BUFFERED
    IRQHandlerUninstall( intnum_rx[channel], UARTReceiveInt );
  #endif

  SFRBASEADDR[channel] = 0;

  #if ( UART_TX_ENABLED && UART_TX_BUFFERED ) || ( UART_RX_ENABLED && UART_RX_BUFFERED )
    CPU_InterruptRestore( InterruptState );
  #endif

  return( UART_STATUS_OK );
 }




// This source code was written by and may be maintained by
// 	Michael Engelbrecht
// It is part of a production test environment.
// It is not intended for release of any kind, as whole or in parts.
// No guarantees or warranties apply. Use at own risk.
// It may not be used for commercial products.




#if UART_TX_ENABLED


uint_fast8_t UARTSend ( uint_fast8_t channel, unsigned char ch )
 {
  #if UART_TX_BUFFERED
    __istate_t	InterruptState;
  #endif

  // check parameters
  if ( channel >= UART_MAX_CHANNELS )
    return( UART_STATUS_BADCHANNEL );
  if ( SFRBASEADDR[channel] == 0 )
    return( UART_STATUS_BADCHANNEL );


  #if UART_TX_SAFE	// ************************************ safe mode ***
    while ( WA(RLN3nLST) & 0x10 )  {}	// wait until character has been sent
    RLN3nLUTDR = ch;			// write character to the UART macro's register
    while ( WA(RLN3nLST) & 0x10 )  {}	// wait until character has been sent


  #elif !UART_TX_BUFFERED	// ********************** unbuffered mode ***
    // wait until character can be written to the UART macro
    while ( !INTC_IntPendingGet( intnum_tx[channel] ) )  {}	// wait for last character to cause a pending interrupt
    INTC_IntPendingClear( intnum_tx[channel] );
    RLN3nLUTDR = ch;		// write character to the UART macro's register


  #else	// ************************************************ buffered mode ***
    // wait until character can be written to the buffer
    InterruptState = CPU_InterruptDisable();
    while ( ( ( BUFFER_TX_inptr[channel] + 1 ) % UART_TX_BUFFER_SIZE ) == BUFFER_TX_outptr[channel] )
     {
      CPU_InterruptRestore( InterruptState );
      InterruptState = CPU_InterruptDisable();
     }
    // write character to the buffer
    BUFFER_TX[channel][ BUFFER_TX_inptr[channel] ] = ch;
    BUFFER_TX_inptr[channel] = ( BUFFER_TX_inptr[channel] + 1 ) % UART_TX_BUFFER_SIZE;
    if ( !TX_BUSY[channel] )
     {
      INTC_IntPendingSet( intnum_tx[channel] );	// set pending flag character can be sent
      TX_BUSY[channel] = 1;
     }
    CPU_InterruptRestore( InterruptState );

  #endif

  return( UART_STATUS_OK );
 }




uint_fast16_t UARTSendSpace ( uint_fast8_t channel )
 {
  #if UART_TX_BUFFERED
    __istate_t		InterruptState;
    uint_fast16_t	space;
  #endif

  // check parameters
  if ( channel >= UART_MAX_CHANNELS )
    return( 0 );
  if ( SFRBASEADDR[channel] == 0 )
    return( 0 );


  #if UART_TX_SAFE	// ************************************ safe mode ***
    return( 1 );

  #elif !UART_TX_BUFFERED	// ********************** unbuffered mode ***
    if ( INTC_IntPendingGet( intnum_tx[channel] ) )
      return( 2 );
    return( 1 );

  #else	// ************************************************ buffered mode ***
    InterruptState = CPU_InterruptDisable();
    space = BUFFER_TX_outptr[channel];
    if ( space <= BUFFER_TX_inptr[channel] )
      space += UART_TX_BUFFER_SIZE;
    space -= BUFFER_TX_inptr[channel] + 1;
    CPU_InterruptRestore( InterruptState );
    return( space );

  #endif
 }




uint_fast16_t UARTSendPending ( uint_fast8_t channel )
 {
  #if UART_TX_BUFFERED
    __istate_t		InterruptState;
    uint_fast16_t	pending;
  #endif

  // check parameters
  if ( channel >= UART_MAX_CHANNELS )
    return( 0 );
  if ( SFRBASEADDR[channel] == 0 )
    return( 0 );


  #if UART_TX_SAFE	// ************************************ safe mode ***
    return( 0 );

  #elif !UART_TX_BUFFERED	// ********************** unbuffered mode ***
    if ( INTC_IntPendingGet( intnum_tx[channel] ) )
      return( 0 );
    return( 1 );

  #else	// ************************************************ buffered mode ***
    InterruptState = CPU_InterruptDisable();
    pending = BUFFER_TX_inptr[channel];
    if ( pending < BUFFER_TX_outptr[channel] )
      pending += UART_TX_BUFFER_SIZE;
    pending -= BUFFER_TX_outptr[channel];
    CPU_InterruptRestore( InterruptState );
    return( pending );

  #endif
 }




#if UART_TX_BUFFERED

static void UARTSendInt (void)
 {
  uint_fast8_t	channel;

  for ( channel = 0;  channel < UART_MAX_CHANNELS;  channel++ )
    if ( SFRBASEADDR[channel] != 0 && INTC_GetRunningIRQNo() == intnum_tx[channel] )
     {
      if ( BUFFER_TX_inptr[channel] == BUFFER_TX_outptr[channel] )
        TX_BUSY[channel] = 0;
      else
       {
        RLN3nLUTDR = BUFFER_TX[channel][ BUFFER_TX_outptr[channel] ];
        BUFFER_TX_outptr[channel] = ( BUFFER_TX_outptr[channel] + 1 ) % UART_TX_BUFFER_SIZE;
       }
      break;
     }
  if ( channel == UART_MAX_CHANNELS )
   while (1)  {}  // if you hit this loop, an unexpected interrupt has occurred! check your software and/or hardware!
 }

#endif	// UART_TX_BUFFERED

#endif	// UART_TX_ENABLED




#if UART_RX_ENABLED

uint_fast16_t UARTReceive ( uint_fast8_t channel )
 {
  #if !UART_RX_BUFFERED
    uint_fast8_t	error;
  #else
    unsigned char	ch;
    __istate_t		InterruptState;
  #endif


  // check parameters
  if ( channel >= UART_MAX_CHANNELS )
    return( 0x8000 | UART_RX_ERROR_CHR );
  if ( SFRBASEADDR[channel] == 0 )
    return( 0x8000 | UART_RX_ERROR_CHR );


  #if !UART_RX_BUFFERED	// ****************************** unbuffered mode ***
    // wait for a character (or error)
    while ( !INTC_IntPendingGet( intnum_rx[channel] ) && !RLN3nLEST )  {}
    if ( RLN3nLEST )
     {
      error = RLN3nLEST;
      UART_STATUS_RX[channel] |= error;
      RLN3nLEST = 0x00;
      if ( error & 0x04 )
        return( ( (uint_fast16_t)error << 8 ) | UART_RX_OVERFLOW_CHR );
      return(   ( (uint_fast16_t)error << 8 ) | UART_RX_ERROR_CHR    );
     }
    INTC_IntPendingClear( intnum_rx[channel] );
    return(RLN3nLURDR);


  #else	// ************************************************ buffered mode ***
    InterruptState = CPU_InterruptDisable();
    while ( BUFFER_RX_inptr[channel] == BUFFER_RX_outptr[channel] )
     {
      CPU_InterruptRestore( InterruptState );
      InterruptState = CPU_InterruptDisable();
     }
    ch = BUFFER_RX[channel][ BUFFER_RX_outptr[channel] ];
    BUFFER_RX_outptr[channel] = ( BUFFER_RX_outptr[channel] + 1 ) % UART_RX_BUFFER_SIZE;
    CPU_InterruptRestore( InterruptState );
    return( ch );

  #endif
 }




uint_fast16_t UARTReceiveStatus ( uint_fast8_t channel, uint_fast8_t consume )
 {
  uint_fast8_t	error;


  // check parameters
  if ( channel >= UART_MAX_CHANNELS )
    return( UART_STATUS_BADCHANNEL );
  if ( SFRBASEADDR[channel] == 0 )
    return( UART_STATUS_BADCHANNEL );


  // determine error state
  error = UART_STATUS_RX[channel];
  if ( error )
   {
    if ( consume )
      UART_STATUS_RX[channel] = 0x00;
    if ( error & 0x01 )	// overflow
      return( ( (uint_fast16_t)error << 8 ) | UART_RX_OVERFLOW_CHR );
    return(   ( (uint_fast16_t)error << 8 ) | UART_RX_ERROR_CHR    );
   }

  return( UART_STATUS_OK );
 }




uint_fast16_t UARTReceiveSpace ( uint_fast8_t channel )
 {
  #if UART_RX_BUFFERED
    __istate_t		InterruptState;
    uint_fast16_t	space;
  #endif

  // check parameters
  if ( channel >= UART_MAX_CHANNELS )
    return( 0 );
  if ( SFRBASEADDR[channel] == 0 )
    return( 0 );


  #if !UART_RX_BUFFERED	// ****************************** unbuffered mode ***
    if ( INTC_IntPendingGet( intnum_rx[channel] ) )
      return( 0 );
    return( 1 );

  #else	// ************************************************ buffered mode ***
    InterruptState = CPU_InterruptDisable();
    space = BUFFER_RX_outptr[channel];
    if ( space <= BUFFER_RX_inptr[channel] )
      space += UART_RX_BUFFER_SIZE;
    space -= BUFFER_RX_inptr[channel] + 1;
    CPU_InterruptRestore( InterruptState );
    return( space );

  #endif
 }




uint_fast16_t UARTReceivePending ( uint_fast8_t channel )
 {
  #if UART_RX_BUFFERED
    __istate_t		InterruptState;
    uint_fast16_t	pending;
  #endif

  // check parameters
  if ( channel >= UART_MAX_CHANNELS )
    return( 0 );
  if ( SFRBASEADDR[channel] == 0 )
    return( 0 );


  #if !UART_RX_BUFFERED	// ****************************** unbuffered mode ***
    if ( INTC_IntPendingGet( intnum_rx[channel] ) )
      return( 1 );
    return( 0 );

  #else	// ************************************************ buffered mode ***
    InterruptState = CPU_InterruptDisable();
    pending = BUFFER_RX_inptr[channel];
    if ( pending < BUFFER_RX_outptr[channel] )
      pending += UART_RX_BUFFER_SIZE;
    pending -= BUFFER_RX_outptr[channel];
    CPU_InterruptRestore( InterruptState );
    return( pending );

  #endif
 }




#if UART_RX_BUFFERED

static void UARTReceiveInt (void)
 {
  uint_fast8_t	channel;

  for ( channel = 0;  channel < UART_MAX_CHANNELS;  channel++ )
    if ( SFRBASEADDR[channel] != 0 && INTC_GetRunningIRQNo() == intnum_rx[channel] )
     {
      UART_STATUS_RX[channel] |= RLN3nLEST;
      RLN3nLEST = 0x00;
      if ( ( ( BUFFER_RX_inptr[channel] + 1 ) % UART_RX_BUFFER_SIZE ) == BUFFER_RX_outptr[channel] )
       {
        // overflow
        BUFFER_RX[channel][ ( BUFFER_RX_inptr[channel] - 1 + UART_RX_BUFFER_SIZE ) % UART_RX_BUFFER_SIZE ] = UART_RX_OVERFLOW_CHR;
        UART_STATUS_RX[channel] |= 0x04;
       }
      else
       {
        // write character to the buffer
        BUFFER_RX[channel][ BUFFER_RX_inptr[channel] ] = RLN3nLURDR;
        BUFFER_RX_inptr[channel] = ( BUFFER_RX_inptr[channel] + 1 ) % UART_RX_BUFFER_SIZE;
       }
      break;
     }
  if ( channel == UART_MAX_CHANNELS )
   while (1)  {}  // if you hit this loop, an unexpected interrupt has occurred! check your software and/or hardware!
 }

#endif	// UART_RX_BUFFERED

#endif	// UART_RX_ENABLED




// ****************************************************************** EOF ***
