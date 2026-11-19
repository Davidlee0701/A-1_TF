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
#include <rsip_hsm_cmd.h>
#include <Debug_UART.h>

void application_main(void);
void led_port_toggle(void);

#define TOGGLE_WAIT 2450000

static volatile rsip_hsm_status_t g_rsip_hsm_last_status;

static void led_dimming_port_init(void)
{
    PORT_Enable(AP_0, BIT_0, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL);
}

static void led_dimming_write(uint32_t on)
{
    PORT_WriteBit(AP_0, BIT_0, on ? 1u : 0u);
}

static void led_dimming_wait(uint32_t count)
{
    volatile uint32_t i;

    for (i = 0u; i < count; i++)
    {
        __asm("nop");
    }
}

static void led_dimming_run(uint32_t min_duty,
                            uint32_t max_duty,
                            uint32_t step,
                            uint32_t frame_delay)
{
    uint32_t duty = min_duty;
    uint32_t up = 1u;

    for (;;)
    {
        led_dimming_write(1u);
        led_dimming_wait(duty * frame_delay);
        led_dimming_write(0u);
        led_dimming_wait((max_duty - duty + 1u) * frame_delay);

        if (up != 0u)
        {
            if ((duty + step) >= max_duty)
            {
                duty = max_duty;
                up = 0u;
            }
            else
            {
                duty += step;
            }
        }
        else
        {
            if (duty <= (min_duty + step))
            {
                duty = min_duty;
                up = 1u;
            }
            else
            {
                duty -= step;
            }
        }
    }
}

void led_port_toggle(void){

    volatile int i;

    PORT_Enable( AP_0, BIT_0, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( AP_0, BIT_1, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( AP_0, BIT_2, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( AP_0, BIT_3, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( AP_0, BIT_4, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( AP_0, BIT_5, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( AP_0, BIT_6, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );
    PORT_Enable( AP_0, BIT_7, PORT_DIR_OUTPUT, PORT_MODE_IO, PORT_FUNCTION_NORMAL );


    while(1){
        PORT_WriteBit(AP_0, BIT_0, 1);
        PORT_WriteBit(AP_0, BIT_1, 0);
        PORT_WriteBit(AP_0, BIT_2, 1);
        PORT_WriteBit(AP_0, BIT_3, 0);
        PORT_WriteBit(AP_0, BIT_4, 1);
        PORT_WriteBit(AP_0, BIT_5, 0);
        PORT_WriteBit(AP_0, BIT_6, 1);
        PORT_WriteBit(AP_0, BIT_7, 0);
        for (i = 0; i<TOGGLE_WAIT; i++)
            __asm("nop");

        PORT_WriteBit(AP_0, BIT_0, 0);
        PORT_WriteBit(AP_0, BIT_1, 1);
        PORT_WriteBit(AP_0, BIT_2, 0);
        PORT_WriteBit(AP_0, BIT_3, 1);
        PORT_WriteBit(AP_0, BIT_4, 0);
        PORT_WriteBit(AP_0, BIT_5, 1);
        PORT_WriteBit(AP_0, BIT_6, 0);
        PORT_WriteBit(AP_0, BIT_7, 1);
        for (i = 0; i<TOGGLE_WAIT; i++)
            __asm("nop");
    }
}

//#pragma ghs interrupt
//void ISR_INTOSTM0TINT(void){

  //  while(1)
  //      __asm("nop");
  //  return;
//}

/* ---------------------------------------------------------------------------
 * Result indication on AP0_0 (no UART needed)
 *   all PASS : slow blink 3 times   /   any FAIL : fast blink 10 times
 * ------------------------------------------------------------------------- */
static void rsip_result_led(uint32_t fail)
{
    uint32_t n;
    const uint32_t cnt  = (fail == 0u) ? 3u : 10u;
    const uint32_t wait = (fail == 0u) ? 1500000u : 200000u;

    for (n = 0u; n < cnt; n++)
    {
        led_dimming_write(1u);
        led_dimming_wait(wait);
        led_dimming_write(0u);
        led_dimming_wait(wait);
    }
}

volatile uint32_t g_rsip_fail_count;

void application_main(void){

    //clk_gear_up();
#if 1
    volatile u32_T* MSRKCPROT = (u32_T*) (0x5C081710);
    volatile u32_T* MSR_OSTM = (u32_T*) (0x5C081180);
    volatile u8_T* OSTM0CTL = (u8_T*) (0x5C3A0020);
    volatile u32_T* OSTM0CMP = (u32_T*) (0x5C3A0000);
    volatile u8_T* OSTM0TS = (u8_T*) (0x5C3A0014);

    *MSRKCPROT = UNLOCK_KCPROT;
    *MSR_OSTM = 0;
    *MSRKCPROT = LOCK_KCPROT;

    *OSTM0CTL = 0x81;
    *OSTM0CMP            = 0x00000080;
    *OSTM0TS = 1;
#endif
#if 1
    CFG_EXTCLK1O_PORT();
    Init_EXTCLK1O(SOURCE_CLOCK_PLL0); //--> 7.5 MHz on P10_3
#endif

    led_dimming_port_init();

#if (RSIP_CFG_LOG_UART != 0u)
    /* PB: RLIN3_1  TX=P0_5 / RX=P0_4, 115200 bps */
    UART_init_debug(PORT_0,BIT_5,PORT_FUNCTION_ALTERN1,PORT_0,BIT_4,PORT_FUNCTION_ALTERN1,RLIN3_1);
    //SK: UART_init_debug(PORT_9,BIT_2,PORT_FUNCTION_ALTERN8,PORT_9,BIT_2,PORT_FUNCTION_ALTERN3,RLIN3_6);
#endif

    /* ---------------------------------------------------------------
     * 1) Host <-> RSIP(HSM) communication test : T0..T10
     *    options : PE0/rsip_hsm/rsip_hsm_cfg.h
     *    results : g_rsip_test_report[] (MULTI watch) / UART log
     * --------------------------------------------------------------- */
    g_rsip_fail_count = rsip_test_run_all();
    rsip_result_led(g_rsip_fail_count);

#if (RSIP_CFG_RUN_LED_DIMMING_DEMO != 0u)
    /* ---------------------------------------------------------------
     * 2) Application use case : HSM approves LED dimming parameters
     * --------------------------------------------------------------- */
    {
        uint32_t ap[4];

        g_rsip_hsm_last_status = rsip_host_request_led_dimming(1u, 64u, 1u, 550u, ap);
        if (g_rsip_hsm_last_status == RSIP_HSM_STS_OK)
        {
            led_dimming_run(ap[0], ap[1], ap[2], ap[3]);   /* never returns */
        }
    }
#endif

    /* denied / error / demo disabled : keep servicing RSIP events */
    for (;;)
    {
#if (RSIP_CFG_HOST_NOTIFY_MODE == RSIP_MODE_POLL)
        rsip_host_service();
#endif
        __asm("nop");
    }
}







#pragma ghs interrupt
void ISR_INTOSTM0TINT(void){

    while(1)
        __asm("nop");
    return;
}



//void application_main(void){

//}
