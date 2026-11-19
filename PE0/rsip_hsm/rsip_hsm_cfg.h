#ifndef RSIP_HSM_CFG_H
#define RSIP_HSM_CFG_H
/*******************************************************************************
* File Name   : rsip_hsm_cfg.h
* Device(s)   : R-Car U5L4 (Host Cortex-M33 + RSIP-M30A Secure CPU)
* Description : Build options for the Host <-> RSIP (HSM) communication sample.
*               This header is shared by the Host project (PE0) and the
*               Secure CPU project (sample_project/secure_cpu.gpj).
*               Every option can be overridden with -D<option>=<value> in gpj.
********************************************************************************
* History : 13.11.2026 1.00  Host/RSIP mailbox protocol v2, IRQ/POLL options,
*                            test scenarios T0-T10
*******************************************************************************/

/* ---------------------------------------------------------------------------
 * [1] Notification mode
 *   RSIP_MODE_IRQ  : interrupt driven (Host INTS2H0 = NVIC IRQ95,
 *                                      Secure INTH2S0 = Secure NVIC IRQ34)
 *   RSIP_MODE_POLL : flag polling (INTS2HF0 / INTH2SF0)
 * ------------------------------------------------------------------------- */
#define RSIP_MODE_IRQ                   (0u)
#define RSIP_MODE_POLL                  (1u)

#ifndef RSIP_CFG_HOST_NOTIFY_MODE
#define RSIP_CFG_HOST_NOTIFY_MODE       RSIP_MODE_IRQ    /* Host: wait response by ISR_INTS2H0 */
#endif

#ifndef RSIP_CFG_SECURE_RX_MODE
#define RSIP_CFG_SECURE_RX_MODE         RSIP_MODE_IRQ    /* Secure: receive request by RSIP_INTH2S0_Handler */
#endif

/* ---------------------------------------------------------------------------
 * [2] How the shared-memory location is told to the Secure CPU
 *   RSIP_MSG_TOKEN   : shared memory is at a FIXED address (RSIP_SHM_ADDR,
 *                      linker region RSIP_SHARED_RAM). MSGH2S0 carries a
 *                      token (seq | cmd). Secure CPU never trusts a pointer.
 *   RSIP_MSG_POINTER : MSGH2S0 carries the shared-memory pointer (legacy).
 *                      Secure CPU range-checks the pointer before use.
 * ------------------------------------------------------------------------- */
#define RSIP_MSG_TOKEN                  (0u)
#define RSIP_MSG_POINTER                (1u)

#ifndef RSIP_CFG_MSG_MODE
#define RSIP_CFG_MSG_MODE               RSIP_MSG_TOKEN
#endif

/* Shared memory (CPU RAM CPU0 last 4KB, see section.ld RSIP_SHARED_RAM) */
#ifndef RSIP_SHM_ADDR
#define RSIP_SHM_ADDR                   (0x204FF000u)    /* Host view                         */
#endif
#ifndef RSIP_SHM_SECURE_ADDR
#define RSIP_SHM_SECURE_ADDR            RSIP_SHM_ADDR    /* Secure CPU view (check Security UM bus map) */
#endif
#define RSIP_SHM_SIZE                   (0x00001000u)
#define RSIP_SHM_HOST_RAM_START         (0x204E0000u)    /* allowed window for POINTER mode */
#define RSIP_SHM_HOST_RAM_END           (0x20500000u)

/* ---------------------------------------------------------------------------
 * [3] Data integrity / robustness
 * ------------------------------------------------------------------------- */
#ifndef RSIP_CFG_USE_CRC
#define RSIP_CFG_USE_CRC                (1u)     /* CRC32 on request & response payload */
#endif
#ifndef RSIP_CFG_TIMEOUT_LOOPS
#define RSIP_CFG_TIMEOUT_LOOPS          (2000000u) /* host wait loop count per transaction */
#endif
#ifndef RSIP_CFG_RETRY_COUNT
#define RSIP_CFG_RETRY_COUNT            (1u)     /* re-send on TIMEOUT / CRC error        */
#endif
#ifndef RSIP_CFG_READY_TIMEOUT_LOOPS
#define RSIP_CFG_READY_TIMEOUT_LOOPS    (5000000u) /* wait for Secure CPU READY token     */
#endif
#ifndef RSIP_CFG_EVT_ACK_TIMEOUT_LOOPS
#define RSIP_CFG_EVT_ACK_TIMEOUT_LOOPS  (2000000u) /* Secure waits Host EVT_ACK            */
#endif

/* ---------------------------------------------------------------------------
 * [4] Host test scenario selection (bit mask, see rsip_hsm_test.c)
 * ------------------------------------------------------------------------- */
#define RSIP_T0_CONFIG      (1u << 0)   /* shared memory address / secure READY       */
#define RSIP_T1_PING        (1u << 1)   /* basic round trip                           */
#define RSIP_T2_ECHO        (1u << 2)   /* variable length 4..256B echo + CRC         */
#define RSIP_T3_CRC         (1u << 3)   /* Secure computes CRC32, Host compares       */
#define RSIP_T4_TRANSFORM   (1u << 4)   /* Secure processing (invert + reverse)       */
#define RSIP_T5_BURST       (1u << 5)   /* N consecutive transactions, cycle count    */
#define RSIP_T6_ERROR       (1u << 6)   /* bad cmd / bad length / broken CRC          */
#define RSIP_T7_TIMEOUT     (1u << 7)   /* timeout -> ABORT -> late response -> PING  */
#define RSIP_T8_EVENT       (1u << 8)   /* Secure -> Host asynchronous events         */
#define RSIP_T9_POLICY      (1u << 9)   /* HSM policy decision (LED dimming approve)  */
#define RSIP_T10_DFLASH2    (1u << 10)  /* Secure reads Data Area 2 (0x400C0000)      */

#ifndef RSIP_CFG_TEST_MASK
#define RSIP_CFG_TEST_MASK  (RSIP_T0_CONFIG | RSIP_T1_PING | RSIP_T2_ECHO | RSIP_T3_CRC | \
                             RSIP_T4_TRANSFORM | RSIP_T5_BURST | RSIP_T6_ERROR |           \
                             RSIP_T7_TIMEOUT | RSIP_T8_EVENT | RSIP_T9_POLICY)
#endif

#ifndef RSIP_CFG_BURST_COUNT
#define RSIP_CFG_BURST_COUNT            (100u)
#endif
#ifndef RSIP_CFG_EVENT_COUNT
#define RSIP_CFG_EVENT_COUNT            (8u)     /* max 16 */
#endif

/* ---------------------------------------------------------------------------
 * [5] Secure CPU side features
 * ------------------------------------------------------------------------- */
#ifndef RSIP_CFG_SECURE_ENABLE_DFLASH2_READ
#define RSIP_CFG_SECURE_ENABLE_DFLASH2_READ (0u) /* 1: CMD_DFLASH2_READ reads 0x400C0000.
                                                    Program Data Area 2 first (blank read
                                                    may raise ECC error notification)   */
#endif
#define RSIP_DFLASH2_BASE               (0x400C0000u)    /* = RSIP_OPBT3 RSIPRAD */
#define RSIP_DFLASH2_SIZE               (0x00010000u)

/* ---------------------------------------------------------------------------
 * [6] Host application options
 * ------------------------------------------------------------------------- */
#ifndef RSIP_CFG_LOG_UART
#define RSIP_CFG_LOG_UART               (1u)     /* printf result via RLIN3_1 (P0_5 TX / P0_4 RX) */
#endif
#ifndef RSIP_CFG_USE_DWT_CYCCNT
#define RSIP_CFG_USE_DWT_CYCCNT         (1u)     /* measure transaction cycles */
#endif
#ifndef RSIP_CFG_RUN_LED_DIMMING_DEMO
#define RSIP_CFG_RUN_LED_DIMMING_DEMO   (1u)     /* after tests: HSM approved LED dimming on AP0_0 */
#endif

#endif /* RSIP_HSM_CFG_H */
