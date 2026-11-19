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
**  UARTIO.c
**
**  Routines for communicating on high-level using a UART
**  (C) Copyright by Renesas Electronics Europe GmbH
**
**  See UARTIO.h for more information
**
****************************************************************************/

#include "UARTIO.h"




#if UART_TX_ENABLED


int UARTIO_putc ( int ch, unsigned int channel )
 {
  #if UARTIO_CONVERTOUT_SWALLOW_CR
    if ( ch == '\r' )  return( '\r' );
  #endif

  #if UARTIO_CONVERTOUT_SWALLOW_LF
    if ( ch == '\n' )  return( '\n' );
  #endif

  #if UARTIO_CONVERTOUT_LF2CRLF
    if ( ch == '\n' )
      if ( UARTSend( channel, '\r' ) != UART_STATUS_OK )
        return( EOF );
  #endif

  #if UARTIO_CONVERTOUT_CR2LF
    if ( ch == '\r' )  ch = '\n';
  #endif

  #if UARTIO_CONVERTOUT_LF2CR
    if ( ch == '\n' )  ch = '\r';
  #endif


  if ( UARTSend( channel, ch ) != UART_STATUS_OK )
    return( EOF );


  #if UARTIO_CONVERTOUT_CR2CRLF
    if ( ch == '\r' )
      if ( UARTSend( channel, '\n' ) != UART_STATUS_OK )
        return( EOF );
  #endif


  return( ch );
 }




int UARTIO_puts ( const char *s, unsigned int channel )
 {
  for (;  *s;  s++ )
    if ( UARTIO_putc( *s, channel ) == EOF )
      return( EOF );
  return( 1 );
 }




size_t UARTIO_write ( const void *ptr, size_t size, size_t n, unsigned int channel )
 {
  size_t cnt, byte;
  unsigned char *s;

  s = (unsigned char *)ptr;
  for (   cnt  = 0;  cnt  < n;     cnt++  )
    for ( byte = 0;  byte < size;  byte++ )
      if ( UARTIO_putc( *s++, channel ) == EOF )
        return( cnt );

  return( cnt );
 }




int UARTIO_vprintf ( unsigned int channel, const char *format, va_list arglist )
 {
  int length;
  char str[UARTIO_BUFFERLENGTH];

  length = vsnprintf( str, UARTIO_BUFFERLENGTH, format, arglist );
  if ( length == EOF )
    return( EOF );
  if ( UARTIO_puts( str, channel ) == EOF )
    return( EOF );
  return( length );
 }




int UARTIO_printf ( unsigned int channel, const char *format, ... )
 {
  int length;
  va_list argsptr;

  va_start( argsptr, format );
  length = UARTIO_vprintf( channel, format, argsptr );
  va_end( argsptr );
  return( length );
 }


#endif  // UART_TX_ENABLED


#if UART_RX_ENABLED


#if UART_TX_ENABLED

static char ECHO = UARTIO_ECHO_DEFAULT;

char UARTIO_setecho ( char echo )
 {
  char previous;
  previous = ECHO;
  ECHO = echo;
  return( previous );
 }

char UARTIO_getecho (void)
 {
  return( ECHO );
 }

#endif




int UARTIO_getc ( unsigned int channel )
 {
  int ch;
  #if UARTIO_CONVERTIN_SMART_CRLF2CR || UARTIO_CONVERTIN_SMART_CRLF2LF
  static int ch_last = 0;
  #endif

  #if UARTIO_CONVERTIN_CR2CRLF || UARTIO_CONVERTIN_LF2CRLF
  static int pending_LF = 0;

  if ( pending_LF )
   {
    pending_LF = 0;
    return( '\n' );
   }
  #endif

  while (1)
   {
    ch = UARTReceive( channel );
    if ( ch < 0 || ch > 255 )
      return( EOF );

    #if UARTIO_CONVERTIN_TAB2SPC
      if ( ch == '\t' )
        ch = ' ';
    #endif

    #if UART_TX_ENABLED
      if ( ECHO == UARTIO_ECHO_ON || ( ECHO == UARTIO_ECHO_DEFAULT && UARTIO_REMOTEECHO ) )
      //UARTIO_putc( ch, channel );	// this is bad when e.g. terminal sends CR, but we use LF as line end. decided to switch to UARTSend
        UARTSend( channel, ch );
    #endif

    #if UARTIO_CONVERTIN_SMART_CRLF2CR
      if ( ch == '\r' && ch_last == '\n' )  { ch_last = 0;   continue; }
      if ( ch == '\n' && ch_last == '\r' )  { ch_last = 0;   continue; }
      ch_last = ch;
      if ( ch == '\r' )  return( '\r' );
      if ( ch == '\n' )  return( '\r' );
    #endif

    #if UARTIO_CONVERTIN_SMART_CRLF2LF
      if ( ch == '\r' && ch_last == '\n' )  { ch_last = 0;   continue; }
      if ( ch == '\n' && ch_last == '\r' )  { ch_last = 0;   continue; }
      ch_last = ch;
      if ( ch == '\r' )  return( '\n' );
      if ( ch == '\n' )  return( '\n' );
    #endif

    #if UARTIO_CONVERTIN_SWALLOW_CR
      if ( ch == '\r' )  continue;
    #endif

    #if UARTIO_CONVERTIN_SWALLOW_LF
      if ( ch == '\n' )  continue;
    #endif

    #if UARTIO_CONVERTIN_CR2CRLF
      if ( ch == '\r' )
       {
        pending_LF = 1;
        return( '\r' );
       }
    #endif

    #if UARTIO_CONVERTIN_LF2CRLF
      if ( ch == '\n' )
       {
        pending_LF = 1;
        return( '\r' );
       }
    #endif

    #if UARTIO_CONVERTIN_CR2LF
      if ( ch == '\r' )
        return(  '\n' );
    #endif

    #if UARTIO_CONVERTIN_LF2CR
      if ( ch == '\n' )
        return(  '\r' );
    #endif

    break;
   }

  return( ch );
 }




// This source code was written by and may be maintained by
// 	Michael Engelbrecht
// It is part of a production test environment.
// It is not intended for release of any kind, as whole or in parts.
// No guarantees or warranties apply. Use at own risk.
// It may not be used for commercial products.




char *UARTIO_gets ( char *s, int n, unsigned int channel )
 {
  int	ch;
  int	linelen;
  char	echo;
  #if UARTIO_BACKSLASH_NEWLINE || ( UARTIO_LINESTARTOVER && UART_TX_ENABLED )// && UARTIO_REMOTEECHO )
    int	cnt;
  #endif

  if  ( n < 2 || s == NULL )
    return( NULL );

  linelen = 0;

  while ( linelen + 1 < n )
   {
    echo = UARTIO_setecho( UARTIO_ECHO_OFF );
    ch = UARTIO_getc( channel );
    UARTIO_setecho( echo );
    if ( ( ch == UARTIO_BACKSPACE || ch == UARTIO_DELETE ) && linelen == 0 )
      continue;
    #if UART_TX_ENABLED
      if ( ECHO == UARTIO_ECHO_ON || ( ECHO == UARTIO_ECHO_DEFAULT && UARTIO_REMOTEECHO ) )
      //UARTIO_putc( ch, channel );	// this is bad when e.g. terminal sends CR, but we use LF as line end. decided to switch to UARTSend
        UARTSend( channel, ch );
    #endif

    // end of stream or error
    if ( ch == EOF )
     {
      if ( linelen == 0 )	// EOF at start of line returns NULL
        return( NULL );
      else
        break;
     }

    // line end
    if ( ch == UARTIO_LINEENDCHR )
     {
      #if UARTIO_BACKSLASH_NEWLINE
        cnt = linelen;
        while ( cnt )
         {
          cnt--;
          if ( s[cnt] == ' ' || s[cnt] == '\t' )
            continue;
          if ( s[cnt] == '\\' )
            linelen = cnt;
          else
            s[linelen] = 0;
          break;
         }
        if ( s[linelen] == '\\' )
          continue;
      #endif

      #if !UARTIO_CONSUMELINEENDCHR
        s[linelen] = UARTIO_LINEENDCHR;
        linelen++;
      #endif

      break;
     }

    // start over
    #if UARTIO_LINESTARTOVER
      if (	ch == UARTIO_ESC    ||
		ch == UARTIO_CTRL_C ||
		ch == UARTIO_CTRL_Z ||	// not really used to start over, but may be handy
		ch == UARTIO_BREAK )	// UART break, not BREAK key	caveat: the UART may configured that a BREAK causes to set some status flag
       {
        #if UART_TX_ENABLED // && UARTIO_REMOTEECHO
          if ( ch == UARTIO_ESC )
            UARTIO_putc( '7', channel );	// the ESC was aready echoed, so send a dummy code (VT100 save cursor) to prevent the next character from being swallowed by the terminal
          for ( cnt = linelen;  cnt > 0;  cnt-- )  UARTIO_putc( UARTIO_BACKSPACE, channel );
          for ( cnt = linelen;  cnt > 0;  cnt-- )  UARTIO_putc( ' ',              channel );
          for ( cnt = linelen;  cnt > 0;  cnt-- )  UARTIO_putc( UARTIO_BACKSPACE, channel );
        #endif
        linelen = 0;
        continue;
       }
    #endif

    // backspace
    #if !UARTIO_RAWBACKSPACE
      if ( ch == UARTIO_BACKSPACE || ch == UARTIO_DELETE )
       {
        linelen--;
        #if UART_TX_ENABLED && UARTIO_REMOTEECHO
          UARTIO_putc( ' ', channel );
          UARTIO_putc( ch,  channel );
        #endif
        continue;
       }
    #endif

    // store character
    s[linelen] = ch;
    linelen++;
   }
  s[linelen] = '\0';

  return( s );
 }




size_t UARTIO_read ( void *ptr, size_t size, size_t n, unsigned int channel )
 {
  size_t cnt, byte;
  unsigned char *s;
  int ch;

  s = (unsigned char *)ptr;
  for (   cnt  = 0;  cnt  < n;     cnt++  )
    for ( byte = 0;  byte < size;  byte++ )
     {
      ch = UARTIO_getc( channel );
      if ( ch == EOF )
        return( cnt );
      *s++ = ch;
     }

  return( cnt );
 }




int UARTIO_vscanf ( unsigned int channel, const char *format, va_list arglist )
 {
  char buf[UARTIO_BUFFERLENGTH];

  if ( UARTIO_gets( buf, UARTIO_BUFFERLENGTH, channel ) == NULL )
    return( 0 );

  return( vsscanf( buf, format, arglist ) );
 }




int UARTIO_scanf ( unsigned int channel, const char *format, ... )
 {
  int stat;
  va_list argsptr;

  va_start( argsptr, format );
  stat = UARTIO_vscanf( channel, format, argsptr );
  va_end( argsptr );
  return( stat );
 }


#endif  // UART_RX_ENABLED


// ****************************************************************** EOF ***

/*
todo:
- currently, UARTIO_getc will echo back any character that is received.
  but if the receiving CR/LF setting differs from the transmitting CR/LF setting
  this causes strange results.
  consider converting the echo from one setting to the other.
*/
