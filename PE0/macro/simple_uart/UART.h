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
**  UART.h
**
**  Routines for operating a UART
**  (C) Copyright by Renesas Electronics Europe GmbH
**
**  Notes:
**  - the function interfaces are generic.
**    The implementation is UART type specific
**  - interrupts are only required used when a software buffer is enabled
**  - the specific UART macro may have more features than are available by
**    this interface (e.g. LSB/MSB first, inversion, stop bits, break, LIN).
**    However this interface is intended to be generic and for communication
**    with a PC, so only common parameters/functions may be used
**
**  Prerequisits:
**  - the GPIO ports and clock must be configured outside of this library.
**  - interrupts (if needed) must be adapted to the targeted device
**
**  Revisions:
**  2011/05/24  ME  Initial
**  2016/02/16  ME  Port for V1R-M
**
****************************************************************************/

#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <inttypes.h>
#include <stdarg.h>




// **************************************************************************
// *************************************************** user configuration ***
// **************************************************************************

// these settings may be modified to match the requirements

#define	UART_MAX_CHANNELS	2	// maximum number of (simultaneously open) logical channels
					// this number should not be greater than the number of physical UART instances


#define	UART_TX_ENABLED		1	// 1: UART can transmit
					// 0: UART will be able to not transmit

#define	UART_TX_SAFE		1	// 1: UARTSend will return only, when the character has safely been sent
					//    when set to 1, UART_TX_BUFFERED must be set to 0
					// 0: UARTSend may return before the character has left the device

#define	UART_TX_BUFFERED	0	// 1: a software ringbuffer is used. interrupts are required!
					// 0: no software buffer is used. no interrupts are used

#define	UART_TX_BUFFER_SIZE	64	// size of software buffer (if enabled), per channel


#define	UART_RX_ENABLED		1	// 1: UART can receive
					// 0: UART will not be able to receive

#define	UART_RX_BUFFERED	0	// 1: a software ringbuffer is used. interrupts are required!
					// 0: no software buffer is used. no interrupts are used.
					//    poll often or use handshaking to ensure no characters are lost

#define	UART_RX_BUFFER_SIZE	64	// size of software buffer (if enabled), per channel

#define	UART_RX_OVERFLOW_CHR	'#'	// character that will be returned if an overflow has occurred
#define	UART_RX_ERROR_CHR	'#'	// character that will be returned if an error has occurred

#define	UART_BAUD_TOLERANCE	2	// maximum systematic baud rate error in percent (1% is safe, more may cause problems)




// **************************************************************************
// *********************************************************** prototypes ***
// **************************************************************************

/* Overview. For details, see farther below

uint_fast8_t	UARTInit		(	uint_fast8_t		*channelp	,
						volatile void		*SFRBASEADDRp	,
						uint_fast16_t		intno_tx	,
						uint_fast16_t		intno_rx	,
						volatile uint16_t	*SFRPICTXp	,
						volatile uint16_t	*SFRPICRXp	,
						uint_fast32_t		basefreq	,
						uint_fast32_t		baud		,
						uint_fast8_t		bits		,
						uint_fast8_t		parity		,
						uint_fast8_t		stopbits	);

uint_fast8_t	UARTDisable		(	uint_fast8_t	channel		);

uint_fast8_t	UARTSend		(	uint_fast8_t	channel		,
						unsigned char	ch		);
uint_fast16_t	UARTSendSpace		(	uint_fast8_t	channel		);
uint_fast16_t	UARTSendPending		(	uint_fast8_t	channel		);

uint_fast16_t	UARTReceive		(	uint_fast8_t	channel		);
uint_fast16_t	UARTReceiveStatus	(	uint_fast8_t	channel		,
						uint_fast8_t	consume		);
uint_fast16_t	UARTReceiveSpace	(	uint_fast8_t	channel		);
uint_fast16_t	UARTReceivePending	(	uint_fast8_t	channel		);

*/




// ==========================================================================
// === UARTInit ================================================ UARTInit ===
// ==========================================================================

uint_fast8_t	UARTInit	(
// function:	configures the UART macro
// parameters:
	uint_fast8_t		*channelp	,	// will be returned: logical number of channel
	volatile void		*SFRBASEADDRp	,	// SFR base address of macro
	uint_fast16_t		intno_tx	,	// UART TX interrupt number (may be 0 when not needed)
	uint_fast16_t		intno_rx	,	// UART RX interrupt number (may be 0 when not needed)
	uint_fast32_t		basefreq	,	// frequency that is used to generate the baud rate
	uint_fast32_t		baud		,	// baud rate
	uint_fast8_t		bits		,	// number of message bits in a frame
	uint_fast8_t		parity		,	// type   of parity   in a frame (use enums to stay compatible)
	uint_fast8_t		stopbits	);	// number of stopbits in a frame (use enums to stay compatible)
// return values:
//	UART_STATUS_OK			ok, UART initialized successfully
//	UART_STATUS_BADCHANNEL		UART instance already in use or no free channels available
//	UART_STATUS_BADPARAMETER	at least one parameter is invalid
//	UART_STATUS_BADBAUDRATE		the baud rate cannot be achieved
//	the value in *channelp is the channel handler for future calls




// ==========================================================================
// === UARTDisable ========================================== UARTDisable ===
// ==========================================================================

uint_fast8_t	UARTDisable	(
// function:	turns off and releases the UART macro (waits for it to be idle first)
// parameters:
	uint_fast8_t	channel		);	// logical number of channel
// return values:
//	UART_STATUS_OK			ok, UART released successfully
//	UART_STATUS_BADCHANNEL		channel is not available (not in use, or above max. index)




// ==========================================================================
// === UARTSend ================================================ UARTSend ===
// ==========================================================================
#if UART_TX_ENABLED

uint_fast8_t	UARTSend	(
// function:	writes data into the send buffer of the UART. If no space is available, it will wait.
// parameters:
	uint_fast8_t	channel		,	// logical number of channel
	unsigned char	ch		);	// data to be sent
// return values:
//	UART_STATUS_OK			ok, data sent successfully
//	UART_STATUS_BADCHANNEL		channel is not available (not in use, or above max. index)
// caution:
//	do not modify the interrupt pending bit outside of this library!

#endif




// ==========================================================================
// === UARTSendSpace ====================================== UARTSendSpace ===
// ==========================================================================
#if UART_TX_ENABLED

uint_fast16_t	UARTSendSpace	(
// function:	returns the number of bytes that can be written without blocking
// parameters:
	uint_fast8_t	channel		);	// logical number of channel
// return values:
//	0:				no bytes can be written, or channel is not available (not in use, or above max. index)
//	>0:				the number of bytes that can be written without blocking

#endif




// ==========================================================================
// === UARTSendPending ================================== UARTSendPending ===
// ==========================================================================
#if UART_TX_ENABLED

uint_fast16_t	UARTSendPending	(
// function:	returns the number of bytes that still need to be sent
// parameters:
	uint_fast8_t	channel		);	// logical number of channel
// return values:
//	0:				no bytes need to be send, or channel is not available (not in use, or above max. index)
//	>0:				the number of bytes that still need to be sent

#endif




// ==========================================================================
// === UARTReceive ========================================== UARTReceive ===
// ==========================================================================
#if UART_RX_ENABLED

uint_fast16_t	UARTReceive	(
// function:	returns the next received character. if no character is available, it will wait for one.
// parameters:
	uint_fast8_t	channel		);	// logical number of channel
// return values:
//	0..255				ok, received character
//	0x8000 | UART_RX_ERROR_CHR	channel is not available (not in use, or above max. index)
//	0xXX00 | UART_RX_xxxxx_CHR	reception error; upper byte represents error flag register

#endif




// ==========================================================================
// === UARTReceiveStatus ============================== UARTReceiveStatus ===
// ==========================================================================
#if UART_RX_ENABLED

uint_fast16_t	UARTReceiveStatus	(
// function:	returns the accumulated error status. if consume is set, the status gets cleared.
// parameters:
	uint_fast8_t	channel		,	// logical number of channel
	uint_fast8_t	consume		);	// if 0, the status will remain unchanged, else it will be reset
// return values:
//	UART_STATUS_OK			ok, UART released successfully
//	UART_STATUS_BADCHANNEL		channel is not available (not in use, or above max. index)
//	0xXX00 | UART_RX_xxxxx_CHR	accumulated status; upper byte represents error flag register

#endif




// ==========================================================================
// === UARTReceiveSpace ================================ UARTReceiveSpace ===
// ==========================================================================
#if UART_RX_ENABLED

uint_fast16_t	UARTReceiveSpace	(
// function:	returns the number of bytes that can be received without overflow
// parameters:
	uint_fast8_t	channel		);	// logical number of channel
// return values:
//	0:				no bytes can be received, or channel is not available (not in use, or above max. index)
//	>0:				the number of bytes that can be received without overflow

#endif




// ==========================================================================
// === UARTReceivePending ============================ UARTReceivePending ===
// ==========================================================================
#if UART_RX_ENABLED

uint_fast16_t	UARTReceivePending	(
// function:	returns the number of bytes that have been received and still need to be consumed
// parameters:
	uint_fast8_t	channel		);	// logical number of channel
// return values:
//	0:				no bytes have been received, or channel is not available (not in use, or above max. index)
//	>0:				the number of bytes that have been received and still need to be consumed

#endif




// **************************************************************************
// ************************************************* symbolic parameters ****
// **************************************************************************

enum	UART_PARITY
 {
	UART_PARITY_NONE	= 0,
	UART_PARITY_EVEN	= 1,
	UART_PARITY_SPACE	= 2,	// logic 0
	UART_PARITY_ODD		= 3,
//	UART_PARITY_MARK	= 4	// logic 1, not supported
 };


enum	UART_STOPBITS
 {
	UART_STOPBITS_1		= 0,
	UART_STOPBITS_2		= 1
 };


enum	UART_STATUS
 {
	UART_STATUS_OK			= 0,
	UART_STATUS_BADCHANNEL		= 1,
	UART_STATUS_BADBAUDRATE		= 2,
	UART_STATUS_BADPARAMETER	= 3
 };


extern int UARTIO_vprintf ( unsigned int channel, const char *format, va_list arglist );

#endif




// ****************************************************************** EOF ***
