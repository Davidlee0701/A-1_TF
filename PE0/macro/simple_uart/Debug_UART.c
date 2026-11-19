/*
 * Debug_UART.c
 *
 *  Created on: 26.03.2025
 *      Author: a5105882
 */

#include <standardports.h>
#include <stdint.h>
#include "UART.h"
#include "Debug_UART.h"
uint_fast8_t UARTDebugChannel;

#ifdef CUSTOM_PRINTF
#include <stdarg.h>
void printf(const char *format, ...){
    va_list args;
    va_start(args, format);
    UARTIO_vprintf(UARTDebugChannel, format, args);
    va_end(args);
}
#endif

void UART_init_debug(PORT_NUMBER_E TX_PORT, BIT_NUMBER_E TX_PIN, PORT_ALTERNATE_FUNCTION_E ALT_FUNC_TX, PORT_NUMBER_E RX_PORT, BIT_NUMBER_E RX_PIN, PORT_ALTERNATE_FUNCTION_E ALT_FUNC_RX, RLIN_CHANNEL_E RLIN_CHANNEL){

    #define     UART_INIT_macro(x)     UARTInit( &UARTDebugChannel, (u32_T*) RLIN36_inst_0_BASE, 64, 65, 80000000uL/*Hz*/, 115200 /*bd*/, 8/*bits*/, UART_PARITY_NONE, UART_STOPBITS_1 )  // RLIN31 (MicroUSB, CN6, channel A)
    #include <UART.h>
    //PORT_Enable (PORT_9,BIT_3,PORT_DIR_INPUT,PORT_MODE_IO ,PORT_FUNCTION_ALTERN3); //RX
    //PORT_Enable (PORT_9,BIT_2,PORT_DIR_OUTPUT,PORT_MODE_IO ,PORT_FUNCTION_ALTERN8);//TX

    PORT_Enable (RX_PORT,RX_PIN,PORT_DIR_INPUT,PORT_MODE_IO ,ALT_FUNC_RX); //RX
    PORT_Enable (TX_PORT,TX_PIN,PORT_DIR_OUTPUT,PORT_MODE_IO ,ALT_FUNC_TX);//TX



    UARTInit( &UARTDebugChannel, (u32_T*) RLIN_CHANNEL, 64, 65, 80000000uL/*Hz*/, 115200 /*bd*/, 8/*bits*/, UART_PARITY_NONE, UART_STOPBITS_1 );  // RLIN31 (MicroUSB, CN6, channel A)
    //extern int UARTIO_printf ( unsigned int channel, const char *format, ... );
    //UARTIO_printf(UARTDebugChannel, "%d\n", 3);
    //#define printf(format, ...) UARTIO_printf(UARTDebugChannel, format, ##__VA_ARGS__)
    //#define printf(x, ...)    UARTIO_printf( UARTChannel, x, ... );
    //rintf("%d", 4);
}


