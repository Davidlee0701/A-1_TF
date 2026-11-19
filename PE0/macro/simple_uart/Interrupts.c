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
**  Interrupts.c
**
**  Interrupt handler routines
**  (C) Copyright by Renesas Electronics Europe GmbH
**
**  Revisions:
**  2014/11/18  ME  Initial
**  2016/02/16  ME  For RH850
**
****************************************************************************/


#include "Interrupts.h"
#include "U5L.h"
#include <stddef.h>	// for NULL


int_fast8_t INTC_IntDisable( uint_fast16_t intno_tx )
{
	return 0;
}

int_fast8_t INTC_IntPendingClear( uint_fast16_t intno_tx )
{
    volatile u32_T* IMFU0PC19 = (u32_T*)(0x5CE81138);
    if(intno_tx = 65U) // RLINRLIN31 receive completion interrupt
    {
	    
	//IMFU00_inst_0->IMFU0PC19 = 0x2;	// Set IMFU Pulse Clear Register -> RLIN31
	*IMFU0PC19 = 0x2;
    }
    NVIC_ClearPendingIRQ(intno_tx);
    return 0;
}


int_fast8_t	INTC_IntPendingGet		( uint_fast16_t IRQno )
{
	int_fast8_t intPending = (int_fast8_t)NVIC_GetPendingIRQ(IRQno);
	return (intPending);
}

