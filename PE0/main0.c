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
/*******************************************************************************
* File Name     : main0.c
* Version       : 0.01
* Device(s)     : R-Car U5Lx
* Description   : This is the main_pe0 tutorial code.
********************************************************************************
* History : DD.MM.YYYY Version Description
*         : 30.11.2024 0.01    First Release
*******************************************************************************/
/*******************************************************************************
header include
*******************************************************************************/
//#include "iodef.h"

/*******************************************************************************
Macro definitions
*******************************************************************************/

/*******************************************************************************
Imported global variables and functions (from other files)
*******************************************************************************/

/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/

/*******************************************************************************
* Outline      : PE0 Main processing
* Header       : none
* Function name: void main_pe0 (void)
* Description  : Main function sample
* Arguments    : none
* Return Value : none
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <RCar_U5L_UM_rev0.40_noRSIP_ver1.0.h>
void main(void){

    uint32_t* result = 0;
    //result = (uint32_t*) malloc(4);
    *result = 0xABABABAB;
    //printf("Test\n");
    while(1)
        __asm("nop");
    
}

void unreachable_code() {
    abort();
}

void main_pe0(void)
{
    extern void application_main(void);

    application_main();

    while(1)
        __asm("nop");
}



	
