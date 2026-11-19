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
**  UARTIO.h
**
**  Routines for communicating on high-level using a UART
**  (C) Copyright by Renesas Electronics Europe GmbH
**
**  Prerequisits:
**  - the UART needs to be setup using the according UART.c module
**
**  Revisions:
**  2011/05/24  ME  Initial
**
****************************************************************************/

#ifndef UARTIO_H
#define UARTIO_H




// **************************************************************************
// ************************************************** user configuration ****
// **************************************************************************

// these settings may be modified to match the requirements

#define	UARTIO_EOL			"\n"	// character(s) to send at the end of a line

// configuration for UARTIO_putc (default: all off)
#define	UARTIO_CONVERTOUT_SWALLOW_CR	1	// 1: filter outgoing CRs (0x0D 13 \r)	0: transmit outgoing CRs
#define	UARTIO_CONVERTOUT_SWALLOW_LF	0	// 1: filter outgoing LFs (0x0A 10 \n)	0: transmit outgoing LFs
#define	UARTIO_CONVERTOUT_CR2CRLF	0	// 1: convert an outgoing CR to CR+LF	0: do not convert outgoing CRs
#define	UARTIO_CONVERTOUT_LF2CRLF	0	// 1: convert an outgoing LF to CR+LF	0: do not convert outgoing LFs
#define	UARTIO_CONVERTOUT_CR2LF		0	// 1: convert an outgoing CR to LF	0: do not convert outgoing CRs
#define	UARTIO_CONVERTOUT_LF2CR		0	// 1: convert an outgoing LF to CR	0: do not convert outgoing LFs

// configuration for UARTIO_getc
#define	UARTIO_REMOTEECHO		1	// 1: characters received will     be echoed back to host
						// 0: characters received will not be echoed back to host (default)

#define	UARTIO_CONVERTIN_SMART_CRLF2CR	0	// 1: convert single or consequative alternating CR/LFs to one CR
#define	UARTIO_CONVERTIN_SMART_CRLF2LF	1	// 1: convert single or consequative alternating CR/LFs to one LF
#define	UARTIO_CONVERTIN_SWALLOW_CR	0	// 1: ignore incoming CRs (0x0D 13 \r)	0: handle incoming CRs
#define	UARTIO_CONVERTIN_SWALLOW_LF	0	// 1: ignore incoming LFs (0x0A 10 \n)	0: handle incoming LFs
#define	UARTIO_CONVERTIN_CR2CRLF	0	// 1: convert an incoming CR to CR+LF	0: do not convert incoming CRs
#define	UARTIO_CONVERTIN_LF2CRLF	0	// 1: convert an incoming LF to CR+LF	0: do not convert incoming LFs
#define	UARTIO_CONVERTIN_CR2LF		0	// 1: convert an incoming CR to LF	0: do not convert incoming CRs
#define	UARTIO_CONVERTIN_LF2CR		0	// 1: convert an incoming LF to CR	0: do not convert incoming LFs
#define	UARTIO_CONVERTIN_TAB2SPC	1	// 1: convert an incoming TAB to SPACE	0: do not convert incoming TABs

// configuration for UARTIO_gets
#define	UARTIO_LINEENDCHR		'\n'	// character that will be considered as line end (usually '\n')

#define	UARTIO_CONSUMELINEENDCHR	1	// 1: remove line end character from string
						// 0: keep line end character at end of string (default)

#define	UARTIO_RAWBACKSPACE		0	// 1: a backspace will be inserted into the reception buffer
						// 0: receiving a backspace will back up in reception buffer (default)

#define	UARTIO_BACKSLASH_NEWLINE	1	// 1: a backslash at the line end will cause the next line to be concatinated (default)
						// 0: a backslash at the line end will not be handled specially

#define	UARTIO_LINESTARTOVER		1	// 1: allow keys like ESC or CTRL-C to clear the current entry and to start over
						// 0: special keys will not be processed, but added to input string (raw)

// configuration for UARTIO_(v)printf/(v)scanf
#define	UARTIO_BUFFERLENGTH		256	// length of buffer for composing strings




// **************************************************************************
// ********************************************************** prototypes ****
// **************************************************************************

#include "UART.h"
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

#if	UART_TX_ENABLED
int	UARTIO_putc	( int ch				, unsigned int channel );	// returns ch on success, else EOF
int	UARTIO_puts	( const char *s				, unsigned int channel );	// returns the last character on success, else EOF
size_t	UARTIO_write	( const void *ptr, size_t size, size_t n, unsigned int channel );	// returns the number of elements written (not bytes!)
int	UARTIO_vprintf	( unsigned int channel, const char *format, va_list arglist );		// returns the number of written characters, EOF in case of error
int	UARTIO_printf	( unsigned int channel, const char *format, ... );			// returns the number of written characters, EOF in case of error
#endif

#if	UART_RX_ENABLED
int	UARTIO_getc	(					  unsigned int channel );	// returns character on success, else EOF
char *	UARTIO_gets	(       char *s, int n			, unsigned int channel );	// returns *s on success, else NULL
size_t	UARTIO_read	(       void *ptr, size_t size, size_t n, unsigned int channel );	// returns the number of elements read    (not bytes!)
int	UARTIO_vscanf	( unsigned int channel, const char *format, va_list arglist );		// returns the number of converted elements
int	UARTIO_scanf	( unsigned int channel, const char *format, ... );			// returns the number of converted elements
char	UARTIO_setecho	( char echo );								// sets the (global) echo;  returns previous setting
char	UARTIO_getecho	( void );								// returns the (global) echo setting
#endif




enum	UARTIO_ECHO
 {
	UARTIO_ECHO_OFF		= 0,	// forced off
	UARTIO_ECHO_DEFAULT	,	// default from #define
	UARTIO_ECHO_ON			// forced on
 };


#define	UARTIO_LF		0x0A	// \n
#define	UARTIO_CR		0x0D	// \r
#define	UARTIO_BACKSPACE	0x08	// \b
#define	UARTIO_DELETE		0x7F
#define	UARTIO_TAB		0x09	// \t
#define	UARTIO_ESC		0x1B
#define	UARTIO_BREAK		0x00	// UART break, not BREAK key	caveat: the UART may configured that a BREAK causes to set some status flag
#define	UARTIO_CTRL_C		0x03
#define	UARTIO_CTRL_Z		0x1A
#define	UARTIO_BELL		0x07	// \a

#define	UARTIO_LFs		"\n"
#define	UARTIO_CRs		"\r"
#define	UARTIO_BACKSPACEs	"\b"
#define	UARTIO_DELETEs		"\x7F"
#define	UARTIO_TABs		"\t"
#define	UARTIO_ESCs		"\x1B"
#define	UARTIO_BREAKs		"\x00"	// UART break, not BREAK key	caveat: the UART may configured that a BREAK causes to set some status flag
#define	UARTIO_CTRL_Cs		"\x03"
#define	UARTIO_CTRL_Zs		"\x1A"
#define	UARTIO_BELLs		"\a"


#endif


// ****************************************************************** EOF ***



/* NOTES


If you use the UARTIO_REMOTEECHO feature:
The terminal should only send one character (either CR or LF) as end-of-line indicator.
If it sends two (usually CR+LF, but also LF+CR), then the second character will be echoed when it is read, not when it is sent.
Usually, it is read when receiving the following command, after already printing the result of the issed commend.
This will result in strange line breaks.

------------------------

I use TeraTerm a lot.
TeraTerm is special in the respect that it can handle CR or CR+LF, but not LF.
To have a uniform output, the shell's outputs need to match the terminal's (TeraTerm's) inputs.
As TeraTerm can only send CR, the shell must use CR too.
This may be a bad choice for other terminals!

This setting works nicely:

in TeraTerm:
============
Receive:  CR+LF
Transmit: CR

in UARTIO.h:
============
// configuration for UARTIO_putc (default: all off)
#define	UARTIO_CONVERTOUT_SWALLOW_CR	0	// 1: filter outgoing CRs (0x0D 13 \r)	0: transmit outgoing CRs
#define	UARTIO_CONVERTOUT_SWALLOW_LF	1	// 1: filter outgoing LFs (0x0A 10 \n)	0: transmit outgoing LFs
#define	UARTIO_CONVERTOUT_CR2CRLF	0	// 1: convert an outgoing CR to CR+LF	0: do not convert outgoing CRs
#define	UARTIO_CONVERTOUT_LF2CRLF	0	// 1: convert an outgoing LF to CR+LF	0: do not convert outgoing LFs
#define	UARTIO_CONVERTOUT_CR2LF		0	// 1: convert an outgoing CR to LF	0: do not convert outgoing CRs
#define	UARTIO_CONVERTOUT_LF2CR		0	// 1: convert an outgoing LF to CR	0: do not convert outgoing LFs

// configuration for UARTIO_getc
#define	UARTIO_REMOTEECHO		1	// 1: characters received will     be echoed back to host
						// 0: characters received will not be echoed back to host (default)

#define	UARTIO_CONVERTIN_SMART_CRLF2CR	0	// 1: convert single or consequative alternating CR/LFs to one CR
#define	UARTIO_CONVERTIN_SMART_CRLF2LF	1	// 1: convert single or consequative alternating CR/LFs to one LF
#define	UARTIO_CONVERTIN_SWALLOW_CR	0	// 1: ignore incoming CRs (0x0D 13 \r)	0: handle incoming CRs
#define	UARTIO_CONVERTIN_SWALLOW_LF	0	// 1: ignore incoming LFs (0x0A 10 \n)	0: handle incoming LFs
#define	UARTIO_CONVERTIN_CR2CRLF	0	// 1: convert an incoming CR to CR+LF	0: do not convert incoming CRs
#define	UARTIO_CONVERTIN_LF2CRLF	0	// 1: convert an incoming LF to CR+LF	0: do not convert incoming LFs
#define	UARTIO_CONVERTIN_CR2LF		0	// 1: convert an incoming CR to LF	0: do not convert incoming CRs
#define	UARTIO_CONVERTIN_LF2CR		0	// 1: convert an incoming LF to CR	0: do not convert incoming LFs

// configuration for UARTIO_gets
#define	UARTIO_LINEENDCHR		'\n'	// character that will be considered as line end (usually '\n')
*/
