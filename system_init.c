/*******************************************************************************
* Warranty Disclaimer :
*
* Because the Product(s) is licensed free of charge, there is no warranty of
* any kind whatsoever and expressly disclaimed and excluded by Renesas, either
* expressed or implied, including but not limited to those for non-infringement
* of intellectual property, merchantability and/or fitness for the particular
* purpose. Renesas shall not have any obligation to maintain, service or provide
* bug fixes for the supplied Product(s) and/or the Application.
*
* Each User is solely responsible for determining the appropriateness of using
* the Product(s) and assumes all risks associated with its exercise of rights
* under this Agreement, including, but not limited to the risks and costs of
* program errors, compliance with applicable laws, damage to or loss of data,
* programs or equipment, and unavailability or interruption of operations.
*
* Limitation of Liability :
*
* In no event shall Renesas be liable to the User for any incidental,
* consequential, indirect, or punitive damage (including but not limited to
* lost profits) regardless of whether such liability is based on breach of
* contract, tort, strict liability, breach of warranties, failure of essential
* purpose or otherwise and even if advised of the possibility of such damages.
* Renesas shall not be liable for any services or products provided by third
* party vendors, developers or consultants identified or referred to the User
* by Renesas in connection with the Product(s) and/or the Application.
*
* Copyright (C) 2024 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/******************************************************************************
* File Name   : system_init.c
* Version     : 0.01
* Device(s)   : R-Car U5Lx
* Description : This is the system initialization code.
*******************************************************************************
* History     : DD.MM.YYYY Version Description
*             : 30.11.2024 0.01    First Relase
******************************************************************************/

/******************************************************************************
Includes <System Includes> , "Project Includes"ù
******************************************************************************/

#if __GHS__
#include "arm_ghs.h"
#include "iodef.h"
#endif

/******************************************************************************
Macro definitions
******************************************************************************/

#define CLOCK_GEARUP_ERROR 0
#define CLOCK_GEARUP_OK    1

/******************************************************************************
Pragma order
******************************************************************************/

/******************************************************************************
Exported global functions (to be accessed by other files)
******************************************************************************/
int clkGearUp(void);   // Clock gearup

/******************************************************************************
Private global variables and functions
******************************************************************************/


static void wait_us(unsigned long time_us);


/******************************************************************************
* Function Name: wait_us
* Description  : This function waits of us unit by loop.
* Arguments    : unsigned long time_us: wait time [us]
* Return Value : none
******************************************************************************/
static void wait_us(unsigned long time_us)
{
    unsigned long i = 0;
    
    for(i = 0; i < (time_us * 240); i++)
    {
      __asm("NOP");
    }
    
}   // End of function wait_1us

/******************************************************************************
* Function Name: clkGearUp
* Description  : This function executes the sequence to shift the Clock Gear Up.
* Arguments    : none
* Return Value : 0 : Clock gear up is error.
*              : 1 : Clock gear up is OK.
******************************************************************************/
int clkGearUp(void){

    //Verify that PLL0/1 are stable.
	while(SYS0_CLOCK.PLLS != 0x3);


    //Release the write protection of Clock controller register.
    SYS0_CLOCK.CLKKCPROT1 = 0xA5A5A501;

	//[Step1] Division ratio of clock source PLL0/1 are changed from 1/1 to 2/16.
    // (1-1) Write 0010B to Clock Divider Control Register
	//       - CKD_PLL0C.PLLCLKDCSID[3:0]
    //       - CKD_PLL1C.PLLCLKDCSID[3:0]
    // (1-2) Read Divider Status Register CKD_PLL0S/CKD_PLL1S
	//       and verify that the value of PLLCLKDSYNC is 1B.
    SYS0_CLOCK.CKD_PLL0C = 2;
    SYS0_CLOCK.CKD_PLL1C = 2;

    while(SYS0_CLOCK.CKD_PLL0S != 2);
    while(SYS0_CLOCK.CKD_PLL1S != 2);

    //[Step2] The clock source for the System clock is changed from CLK_IOSC1 to CLK_PLL0O/CLK_PLL1O.
    // (2-1) Write 0B to Clock Source Selector Control Register CKS_SYS0C and CKS_SYS1C
    // (2-2) Read Clock Source Selector Status Register CKS_SYS0S/CKS_SYS1S
	//       and verify that the value of SYSCLKSACT is 0B
    //
	// (2-3) Wait 100 us after verifying
    SYS0_CLOCK.CKS_SYS0C = 0;
    SYS0_CLOCK.CKS_SYS1C = 0;

    while(SYS0_CLOCK.CKS_SYS0S != 0);
    while(SYS0_CLOCK.CKS_SYS1S != 0);

    wait_us(100u);
 

	//Start of repetitions 7 repetitions
	//[Step3] Division ratio of clock source PLL0/1 are changed
	//        4/16 (1st) -> 6/16 -> 8/16 -> 10/16 -> 12/16 -> 14/16 -> 16/16.
    // (3-1)  Write Clock Divider Control Register
	//        - CKD_PLL0C.PLLCLKDCSID[3:0]
	//        - CKD_PLL1C.PLLCLKDCSID[3:0].
    //        1st: 0100B (=4)
    //        2nd: 0110B (=6)
    //        3rd: 1000B (=8)
    //        4th: 1010B (=10)
    //        5th: 1100B (=12)
    //        6th: 1110B (=14)
    //        7th: 0000B (=0)
	// (3-2)  Read Divider Status Register CKD_PLL0S/CKD_PLL1S
	//        and verify that the value of PLLCLKDSYNC is 1B
	// (3-3)  Wait 100 us after verifying
    // End of repetitions
 
    SYS0_CLOCK.CKD_PLL0C = 4;
    SYS0_CLOCK.CKD_PLL1C = 4;
    while(SYS0_CLOCK.CKD_PLL0S != 2);
    while(SYS0_CLOCK.CKD_PLL1S != 2);
    wait_us(100);

    SYS0_CLOCK.CKD_PLL0C = 6;
    SYS0_CLOCK.CKD_PLL1C = 6;
    while(SYS0_CLOCK.CKD_PLL0S != 2);
    while(SYS0_CLOCK.CKD_PLL1S != 2);
    wait_us(100);

    SYS0_CLOCK.CKD_PLL0C = 8;
    SYS0_CLOCK.CKD_PLL1C = 8;
    while(SYS0_CLOCK.CKD_PLL0S != 2);
    while(SYS0_CLOCK.CKD_PLL1S != 2);
    wait_us(100);
    	
    SYS0_CLOCK.CKD_PLL0C = 10;
    SYS0_CLOCK.CKD_PLL1C = 10;
    while(SYS0_CLOCK.CKD_PLL0S != 2);
    while(SYS0_CLOCK.CKD_PLL1S != 2);
    wait_us(100);
    
    SYS0_CLOCK.CKD_PLL0C = 12;
    SYS0_CLOCK.CKD_PLL1C = 12;
    while(SYS0_CLOCK.CKD_PLL0S != 2);
    while(SYS0_CLOCK.CKD_PLL1S != 2);
    wait_us(100);

    SYS0_CLOCK.CKD_PLL0C = 14;
    SYS0_CLOCK.CKD_PLL1C = 14;
    while(SYS0_CLOCK.CKD_PLL0S != 2);
    while(SYS0_CLOCK.CKD_PLL1S != 2);
    wait_us(100);
    
    SYS0_CLOCK.CKD_PLL0C = 0;
    SYS0_CLOCK.CKD_PLL1C = 0;
    while(SYS0_CLOCK.CKD_PLL0S != 2);
    while(SYS0_CLOCK.CKD_PLL1S != 2);
    wait_us(100);
    

	//Set the write protection of Clock controller registers.
    SYS0_CLOCK.CLKKCPROT1 = 0xA5A5A500;


    
    return CLOCK_GEARUP_OK;
} // End of function clkGearUp()




