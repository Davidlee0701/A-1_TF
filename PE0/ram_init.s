//
// File: ram_init.s
// GCC for ARM Embedded Processors
// Created date: 2023/11/13 
//

.syntax unified
.cpu cortex-m33
.thumb

/*******************************************************************************
* section
*******************************************************************************/
	.section .text
	.align	2

	.globl	ram_init
ram_init:

/*******************************************************************************
* Init the CPU ram via 4 byte write accesses to avoid ECC RAM errors
*******************************************************************************/
	ldr	r1, = 0x204E0000		
	ldr	r2, = 0x204FFFFF
    movs r3, #0
	
    b LoopFillZero

FillZero:
	str  r3, [r1]
	adds r1, r1, #4

LoopFillZero:
	cmp r1, r2
	bcc FillZero

	bx lr	// Return to caller

/* EOF */
