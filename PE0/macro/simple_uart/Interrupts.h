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
**  Interrupts.h
**
**  Interrupt handler routines
**  (C) Copyright by Renesas Electronics Europe GmbH
**
**  Revisions:
**  2014/11/18  ME  Initial
**  2016/02/16  ME  For RH850
**
****************************************************************************/

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <interrupt_functions.h>

#include <stdint.h>
#include <inttypes.h>

int_fast8_t	INTC_PrioritySet		( uint_fast16_t IRQno, uint_fast8_t priority );		// 0 (highest priority) .. 7 (lowest priority)
int_fast16_t INTC_PriorityGet		( uint_fast16_t IRQno );
int_fast8_t	INTC_SensitivitySet		( uint_fast16_t IRQno, uint_fast8_t sensitivity );	// 0 = edge, 1 = level
int_fast8_t	INTC_SensitivityGet		( uint_fast16_t IRQno );
int_fast8_t	INTC_VectorTypeSet		( uint_fast16_t IRQno, uint_fast8_t vector_type );	// 0 = group, 1 = own
int_fast8_t	INTC_VectorTypeGet		( uint_fast16_t IRQno );
int_fast8_t	INTC_IntEnable			( uint_fast16_t IRQno );
int_fast8_t	INTC_IntDisable			( uint_fast16_t IRQno );
int_fast8_t	INTC_IntEnableGet		( uint_fast16_t IRQno );
int_fast8_t	INTC_IntPendingSet		( uint_fast16_t IRQno );
int_fast8_t	INTC_IntPendingClear		( uint_fast16_t IRQno );
int_fast8_t	INTC_IntPendingGet		( uint_fast16_t IRQno );

enum INTC_ERROR_CODES
 {
  INTC_OK		=  0	,// operation completed successfully
  INTC_ERROR_BADNO	= -1	,// invalid IRQ number
  INTC_ERROR_BADARG	= -2	,// invalid argument given
  INTC_ERROR_OTHER	= -3	 // other error
 };


#define	INTC_PRIORITY(p)	(p)	// 0..15
enum INTC_PRIORITY
 {
  INTC_PRIORITY_MAX	= 0,
  INTC_PRIORITY_MIN	= 15
 };


enum INTC_TARGET
 {
  INTC_SELF		= 0,
  INTC_PE1		,
  INTC_PE2
 };


enum INTC_SENSITIVITY
 {
  INTC_EDGE		= 0,
  INTC_LEVEL
 };


enum INTC_STATUS
 {
  INTC_DISABLED		= 0,
  INTC_ENABLED		,

  INTC_IDLE		= 0,
  INTC_PENDING
 };


enum INTC_VECTOR_TYPE
 {
  INTC_GROUP_VECTOR	= 0,
  INTC_OWN_VECTOR
 };




#define	NUM_IRQS	768


int_fast8_t INTC_IntDisable( uint_fast16_t intno_tx );
int_fast8_t INTC_IntPendingGet      ( uint_fast16_t IRQno );
int_fast8_t INTC_IntPendingClear( uint_fast16_t intno_tx );

#endif

// ****************************************************************** EOF ***
