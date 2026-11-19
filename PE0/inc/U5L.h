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
* Copyright (C) 2024 Renesas Electronics Corporation. All rights reserved.
******************************************************************************/

/*
**  U5L.h
**
**  Routines for configuring the U5L device
**  (C) Copyright by Renesas Electronics Europe GmbH
**
**  Revisions:
**  2024/11/18  TS  Initial
**
****************************************************************************/

#ifndef U5L_H
#define U5L_H

#include <stdint.h>
#include <inttypes.h>
//#include "Bit.h"

#include <U5L_common_types.h>
#include <cpu_ss_workaround.h>
//#include <RCar_U5L_UM_rev0.40_noRSIP_ver1.0.h>

#define PORT_BASE 0x5C190000

#define PORT0PMC00 		(PORT_BASE + 0x0014)
#define PORT0PMCSR00	(PORT_BASE + 0x0024)
#define	PORT0PM00       (PORT_BASE + 0x0010)
#define	PORT0PMSR00     (PORT_BASE + 0x0020)
#define	PORT0P00		(PORT_BASE)
#define	PORT0PSR00		(PORT_BASE + 0x0004)
#define	PORT0PNOT00		(PORT_BASE + 0x0008)
#define	PORT0PPR00		(PORT_BASE + 0x000C)
#define	PORT0PIBC00		(PORT_BASE + 0x4000)
#define	PORT0PBDC00		(PORT_BASE + 0x4004)
#define	PORT0PU00		(PORT_BASE + 0x400C)
#define	PORT0PD00		(PORT_BASE + 0x4010)
#define	PORT0PFC00		(PORT_BASE + 0x0018)
#define	PORT0PFCE00		(PORT_BASE + 0x001C)
#define	PORT0PFCAE00	(PORT_BASE + 0x0028)
#define	PORT0PDSC00		(PORT_BASE + 0x4018)
//#define	PORT0PUCC00		/* To be checked */

void	InitDevice	(void);

#define SFR8(addr)	(*((volatile uint8_t  *)(uintptr_t)(addr)))
#define SFR08(addr)	(*((volatile uint8_t  *)(uintptr_t)(addr)))
#define SFR16(addr)	(*((volatile uint16_t *)(uintptr_t)(addr)))
#define SFR32(addr)	(*((volatile uint32_t *)(uintptr_t)(addr)))
#define SFR64(addr)	(*((volatile uint64_t *)(uintptr_t)(addr)))

#define	SFR8R(    addr )		     SFR8 ( addr )
#define	SFR08R(   addr )		     SFR08( addr )
#define	SFR16R(   addr )		     SFR16( addr )
#define	SFR32R(   addr )		     SFR32( addr )
#define	SFR64R(   addr )		     SFR64( addr )
#define	SFR8W(    addr, data )		do { SFR8 ( addr ) = data; }  while (0)
#define	SFR08W(   addr, data )		do { SFR08( addr ) = data; }  while (0)
#define	SFR16W(   addr, data )		do { SFR16( addr ) = data; }  while (0)
#define	SFR32W(   addr, data )		do { SFR32( addr ) = data; }  while (0)
#define	SFR64W(   addr, data )		do { SFR64( addr ) = data; }  while (0)
#define	SFR8RMW(  addr, mask, data )	do { SFR8 ( addr ) = ( SFR8R ( addr ) & (~(mask)) ) | ( (data) & (mask) ); }  while (0)
#define	SFR08RMW( addr, mask, data )	do { SFR08( addr ) = ( SFR08R( addr ) & (~(mask)) ) | ( (data) & (mask) ); }  while (0)
#define	SFR16RMW( addr, mask, data )	do { SFR16( addr ) = ( SFR16R( addr ) & (~(mask)) ) | ( (data) & (mask) ); }  while (0)
#define	SFR32RMW( addr, mask, data )	do { SFR32( addr ) = ( SFR32R( addr ) & (~(mask)) ) | ( (data) & (mask) ); }  while (0)
#define	SFR64RMW( addr, mask, data )	do { SFR64( addr ) = ( SFR64R( addr ) & (~(mask)) ) | ( (data) & (mask) ); }  while (0)


#endif

// ****************************************************************** EOF ***
