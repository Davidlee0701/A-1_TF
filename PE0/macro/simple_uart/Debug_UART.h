/*
 * Debug_UART.h
 *
 *  Created on: 26.03.2025
 *      Author: a5105882
 */

#ifndef MACRO_SIMPLE_UART_DEBUG_UART_H_
#define MACRO_SIMPLE_UART_DEBUG_UART_H_

#include <UART.h>
#include <U5L.h>
#include <standardports.h>

#define CUSTOM_PRINTF

#define RLIN31_inst_0_BASE          0x5D19B100UL
#define RLIN33_inst_0_BASE          0x5D19B300UL
#define RLIN35_inst_0_BASE          0x5D19B500UL
#define RLIN37_inst_0_BASE          0x5D19B700UL
#define RLIN39_inst_0_BASE          0x5D19B900UL
#define RLIN311_inst_0_BASE         0x5D19BB00UL
#define RLIN313_inst_0_BASE         0x5D19BD00UL
#define RLIN315_inst_0_BASE         0x5D19BF00UL
#define RLIN317_inst_0_BASE         0x5D19C100UL

#define RLIN30_inst_0_BASE          0x5C3B4000UL
#define RLIN32_inst_0_BASE          0x5C3B4200UL
#define RLIN34_inst_0_BASE          0x5C3B4400UL
#define RLIN36_inst_0_BASE          0x5C3B4600UL
#define RLIN38_inst_0_BASE          0x5C3B4800UL
#define RLIN310_inst_0_BASE         0x5C3B4A00UL
#define RLIN312_inst_0_BASE         0x5C3B4C00UL
#define RLIN314_inst_0_BASE         0x5C3B4E00UL
#define RLIN316_inst_0_BASE         0x5C3B5000UL

#define DEBUG_printf(format, ...) UARTIO_printf(UARTChannel, format, ##__VA_ARGS__)

#ifndef CUSTOM_PRINTF
 #define printf(format, ...) UARTIO_printf(UARTDebugChannel, format, ##__VA_ARGS__)
#endif 

extern uint_fast8_t UARTDebugChannel;

typedef enum {
    RLIN3_0  = RLIN30_inst_0_BASE,
    RLIN3_1  = RLIN31_inst_0_BASE,
    RLIN3_2  = RLIN32_inst_0_BASE,
    RLIN3_3  = RLIN33_inst_0_BASE,
    RLIN3_4  = RLIN34_inst_0_BASE,
    RLIN3_5  = RLIN35_inst_0_BASE,
    RLIN3_6  = RLIN36_inst_0_BASE,
    RLIN3_7  = RLIN37_inst_0_BASE,
    RLIN3_8  = RLIN38_inst_0_BASE,
    RLIN3_9  = RLIN39_inst_0_BASE,
    RLIN3_10 = RLIN310_inst_0_BASE,
    RLIN3_11 = RLIN311_inst_0_BASE,
    RLIN3_12 = RLIN312_inst_0_BASE,
    RLIN3_13 = RLIN313_inst_0_BASE,
    RLIN3_14 = RLIN314_inst_0_BASE,
    RLIN3_15 = RLIN315_inst_0_BASE,
    RLIN3_16 = RLIN316_inst_0_BASE,
    RLIN3_17 = RLIN317_inst_0_BASE,
}RLIN_CHANNEL_E;

extern void UART_init_debug(PORT_NUMBER_E TX_PORT, BIT_NUMBER_E TX_PIN, PORT_ALTERNATE_FUNCTION_E ALT_FUNC_TX, PORT_NUMBER_E RX_PORT, BIT_NUMBER_E RX_PIN, PORT_ALTERNATE_FUNCTION_E ALT_FUNC_RX, RLIN_CHANNEL_E RLIN_CHANNEL);
extern int UARTIO_printf ( unsigned int channel, const char *format, ... );
#endif /* MACRO_SIMPLE_UART_DEBUG_UART_H_ */
