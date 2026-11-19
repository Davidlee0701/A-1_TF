/*
 * UART.h
 *
 *  Created on: 20.11.2024
 *      Author: a5147739
 */

#ifndef UART_H_
#define UART_H_

//#include <stdio.h>
//#include <stdlib.h>
//#include <standardports.h>
//
//#include <RCar_U5L_UM_rev0.40_noRSIP_ver1.0.h>
//#include <U5L_common_types.h>
//#include <cpu_ss_workaround.h>
//
//#include <extclk.h>


void uart_TXport_initialize(void);
void uart_RXport_initialize(void);
void uart_RegInitialize(void);
void uartTransmitChar(char send_char);
void uartReceiveChar(void);
void uart_main(void);


#endif /* UART_H_ */
