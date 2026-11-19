/*
 * UART.c
 *
 *  Created on: 20.11.2024
 *      Author: a5147739
 */

//#include <UART.h>

#include <stdio.h>
#include <stdlib.h>
#include <standardports.h>

#include <RCar_U5L_UM_rev0.40_noRSIP_ver1.0.h>
#include <U5L_common_types.h>
#include <cpu_ss_workaround.h>

#include <extclk.h>

void uart_TXport_initialize(void)
{

PORT_Enable( PORT_0, BIT_2, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_ALTERN2 );
return;
}

void uart_RXport_initialize(void)
{

PORT_Enable( PORT_0, BIT_3, PORT_DIR_INPUT, PORT_MODE_IO, PORT_FUNCTION_ALTERN2 );
return;
}

void uart_RegInitialize(void){

    RLIN30_inst_0->RLN3nLWBR_b.LPRS = 0x00; //
    RLIN30_inst_0->RLN3nLWBR_b.NSPB = 0x05; // 0x00 = 0 0 0 0: 16 samplings , 0x05 = 0 1 0 1: 6 samplings
    RLIN30_inst_0->RLN3nLBRP01_b.BRP = 0x056B;  // setting the baud rate precaler =>80 000000/8332 = 9600 baud (0x0280)

    RLIN30_inst_0->RLN3nLMD_b.LMD = 0x01;   // LIN/UART Mode Select 1: UART mode
    RLIN30_inst_0->RLN3nLMD_b.LRDNFS = 1;   // UART Reception Data Noise Filter Disable
    RLIN30_inst_0->RLN3nLEDE_b.BERE = 0;    // Disable Bit Error Detection Enable
    RLIN30_inst_0->RLN3nLEDE_b.OERE = 0;    // Disable Overrun Error Detection Enable
    RLIN30_inst_0->RLN3nLEDE_b.FERE = 0;    // Disable Framing Error Detection Enable
    RLIN30_inst_0->RLN3nLBFC_b.UBLS = 0;    // UART Character Length Select 0 : UART 8 bits communication;
    RLIN30_inst_0->RLN3nLBFC_b.UBOS = 0;    // UART Transfer Format Order Select 0: LSB First 1: MSB First
    RLIN30_inst_0->RLN3nLBFC_b.USBLS = 0;   // UART Stop Bit length Select 0: Stop bit: 1 bit 1: Stop bit: 2 bits
    RLIN30_inst_0->RLN3nLBFC_b.UPS = 0;     // UART Parity Select 00: Parity disabled, 01: Even parity, 10: 0 Parity, 11: Odd parity
    RLIN30_inst_0->RLN3nLBFC_b.URPS = 0;    // UART Input Polarity Switch 0: Reception data normal input, 1: Reception data inverted input
    RLIN30_inst_0->RLN3nLBFC_b.UTPS = 0;    // UART Output Polarity Switch 0: Transmit data normal output 1: Transmit data with inverted output
    RLIN30_inst_0->RLN3nLCUC_b.OM0  = 1;    //LIN Reset 0: LIN reset mode. 1: LIN reset mode is canceled.
    RLIN30_inst_0->RLN3nLUOER_b.UTOE = 1;   // 0: Disables transmission 1: Enables transmission
    RLIN30_inst_0->RLN3nLUOER_b.UROE = 1;   // 0: Disables reception 1: Enables reception
    return;
}

void uartTransmitChar(char send_char)
{
    //RLIN39.LUOER |= 0x01; //The RLN3nLUOER register 0th bit settin 1 UTOE : Transmission Enable is automatically cleared to 00H upon transition to LIN reset mod,

    /* Wait until UART transmission is finished */
    while((WA(RLIN30_inst_0->RLN3nLST_b.URS) & 1));

    RLIN30_inst_0->RLN3nLUTDR_b.UTD = send_char;    // Sets the data to be transmitted. Setting range: 000H to 1FFH
    return;
}

void uartReceiveChar (void)
{
    int dataReceived = 0;
    while((WA(RLIN30_inst_0->RLN3nLST_b.URS) & 1)); // receive the data and return the value
    dataReceived = (WA(RLIN30_inst_0->RLN3nLUTDR_b.UTD) & 0xFF);
    //printf("Value Rx %c \n", dataReceived);
    return;
}

void uart_main(void)
{
     char send_char= 'A';
     uart_TXport_initialize();
     uart_RXport_initialize();
     uart_RegInitialize();
     int count=0;


     while(count <100)
  {
    uartTransmitChar(send_char);

    printf("Character %c \n", send_char);
    for (int i = 0; i<1000000; i++)
        __asm("nop");

    uartReceiveChar ();

    for (int i = 0; i<1000000; i++)
        __asm("nop");
    send_char++;
    count++;

  }
     return;

}


