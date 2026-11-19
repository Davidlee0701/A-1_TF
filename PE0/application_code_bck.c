/*
 * application_code.c
 *
 *  Created on: 06.11.2024
 *      Author: a5105882
 */


#include <standardports.h>

#include <R7F711001.h>
#include <iodef.h>
#include <U5L_common_types.h>
#include <cpu_ss_workaround.h>
#include <stdlib.h>
#include <extclk.h>
#include <stdarg.h>
#include <stdio.h>

void application_main(void);
void led_port_toggle(void);

#define TOGGLE_WAIT 2450000

void led_port_toggle(void){

    volatile int i;

    PORT_Enable( PORT_18, BIT_0, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( PORT_18, BIT_1, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( PORT_18, BIT_2, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( PORT_18, BIT_3, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( PORT_18, BIT_4, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( PORT_18, BIT_5, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( PORT_18, BIT_6, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( PORT_18, BIT_7, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );


    while(1){
        PORT_WriteBit(PORT_18, BIT_0, 1);
        PORT_WriteBit(PORT_18, BIT_1, 0);
        PORT_WriteBit(PORT_18, BIT_2, 1);
        PORT_WriteBit(PORT_18, BIT_3, 0);
        PORT_WriteBit(PORT_18, BIT_4, 1);
        PORT_WriteBit(PORT_18, BIT_5, 0);
        PORT_WriteBit(PORT_18, BIT_6, 1);
        PORT_WriteBit(PORT_18, BIT_7, 0);
        for (i = 0; i<TOGGLE_WAIT; i++)
            __asm("nop");

        PORT_WriteBit(PORT_18, BIT_0, 0);
        PORT_WriteBit(PORT_18, BIT_1, 1);
        PORT_WriteBit(PORT_18, BIT_2, 0);
        PORT_WriteBit(PORT_18, BIT_3, 1);
        PORT_WriteBit(PORT_18, BIT_4, 0);
        PORT_WriteBit(PORT_18, BIT_5, 1);
        PORT_WriteBit(PORT_18, BIT_6, 0);
        PORT_WriteBit(PORT_18, BIT_7, 1);
        for (i = 0; i<TOGGLE_WAIT; i++)
            __asm("nop");
    }
}

#pragma ghs interrupt
void ISR_INTOSTM0TINT(void){

    while(1)
        __asm("nop");
    return;
}

void application_main(void){

    //clk_gear_up();
#if 1
    volatile u32_T* MSRKCPROT = (u32_T*) (0x5C081710);
    volatile u32_T* MSR_OSTM = (u32_T*) (0x5C081180);
    volatile u8_T* OSTM0CTL = (u8_T*) (0x5C3A0020);
    volatile u8_T* OSTM0TOE = (u8_T*) (0x5C3A000C);
    volatile u32_T* OSTM0CMP = (u32_T*) (0x5C3A0000);
    volatile u8_T* OSTM0TS = (u8_T*) (0x5C3A0014);
    
    *MSRKCPROT = UNLOCK_KCPROT;
    *MSR_OSTM = 0;
    *MSRKCPROT = LOCK_KCPROT;
    
    *OSTM0CTL = 0x81;
    //*OSTM0TOE = 1;
    *OSTM0CMP            = 0x00000080;
    *OSTM0TS = 1;

    UNMASK_ISR_INTOSTM0TINT();
#endif     
#if 1
    CFG_EXTCLK1O_PORT();
    Init_EXTCLK1O(SOURCE_CLOCK_PLL0); //--> 7.5 MHz on P10_3

#elif 1
    CFG_EXTCLK1O_PORT();
    Init_EXTCLK1O(SOURCE_CLOCK_PLL1); //--> 20 MHz on P10_3
#endif

    //toggle_p13_2();
    //toggle_device_connector_J37();	//PASS
    //toggle_device_connector_J27();	//PASS
    //toggle_device_connector_J25(); 	//PASS
    //toggle_device_connector_J26(); 	//PASS
    //toggle_error_out();
    led_port_toggle();

    #include <Debug_UART.h>
    //SK:
    //UART_init_debug(PORT_9,BIT_2,PORT_FUNCTION_ALTERN8,PORT_9,BIT_2,PORT_FUNCTION_ALTERN3,RLIN3_6);
    //PB:
    UART_init_debug(PORT_0,BIT_5,PORT_FUNCTION_ALTERN1,PORT_0,BIT_4,PORT_FUNCTION_ALTERN1,RLIN3_1);
    printf("%d", 4);
    PORT_Enable( PORT_18, BIT_0, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_inst_0->P18_b.P18_0 = 1;
    PORT_inst_0->P01 = 1;
}
