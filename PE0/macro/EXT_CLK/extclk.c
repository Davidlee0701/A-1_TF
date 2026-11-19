/*
 * extclk.c
 *
 *  Created on: 29.10.2024
 *      Author: a5105882
 */

#include <standardports.h>
#include <extclk.h>
#include <cpu_ss_workaround.h>


void CFG_EXTCLK0O_PORT(void){
	PORT_Enable( PORT_0, BIT_0, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_ALTERN6 );
	PORT_SetDriveStrength( PORT_0, BIT_0, PORT_DRIVE_STRENGTH_HIGH);
	return;
}

void CFG_EXTCLK1O_PORT(void){
	PORT_Enable( PORT_10, BIT_3, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_ALTERN5 );
	PORT_SetDriveStrength( PORT_10, BIT_3, PORT_DRIVE_STRENGTH_HIGH);
	return;
}


void Init_EXTCLK0O(void){
	//TODO if required
	return;
}


void Init_EXTCLK1O(SOURCE_CLOCK_E SrcClk){

	volatile u32_T* CKS_EXTCLK1C = (u32_T*) (0x5C080600);
	volatile u32_T* CKS_EXTCLK1S = (u32_T*) (0x5C080608);

	volatile u32_T* CKD_EXTCLK1C = (u32_T*) (0x5C080610);
	volatile u32_T* CKD_EXTCLK1S = (u32_T*) (0x5C080618);

	volatile u32_T* CLKKCPROT1   = (u32_T*) (0x5C080700);

	*CLKKCPROT1 = UNLOCK_KCPROT;
	*CKS_EXTCLK1C = (u32_T) SrcClk;

	while( (u32_T)WA( *CKS_EXTCLK1S ) !=  (u32_T)SrcClk);

	*CKD_EXTCLK1C = 4;

	while( (u32_T)WA( *CKD_EXTCLK1S ) != (u32_T) 0x03 );

	*CLKKCPROT1 = LOCK_KCPROT;

	return;
}
