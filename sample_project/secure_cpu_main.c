/*******************************************************************************
* File Name   : secure_cpu_main.c
* Device(s)   : R-Car U5L4 RSIP-M30A Secure CPU (Cortex-M33)
* Description : HSM side of the Host <-> RSIP mailbox protocol v2.
*               - code   : User Area0 0x00010000-0x0001FFFF (RSIPRACS0/RSIPRACE0)
*               - RAM    : S-TCM 0x3FE00000- (host cannot access)
*               - dflash : Data Area 2 0x400C0000-0x400CFFFF (RSIPRAD, RSIP only)
*               RX mode  : RSIP_CFG_SECURE_RX_MODE = IRQ  -> RSIP_INTH2S0_Handler (IRQ34)
*                                                  = POLL -> main loop polling
* History     : 13.11.2026 2.00  command dispatcher, CRC, abort, events, stats
*******************************************************************************/
#include <stdint.h>
#include "rsip_hsm_cmd.h"

#define RSIP_SECURE_CMDREG       ((rsip_cmdreg_t *)RSIP_CMDREG_SECURE_BASE)
#define RSIP_SECURE_IRQ_INTH2S0  (34u)
#define RSIP_SECURE_NVIC_ISER    ((volatile uint32_t *)0xE000E100u)
#define RSIP_SECURE_NVIC_ICER    ((volatile uint32_t *)0xE000E180u)
#define RSIP_SECURE_NVIC_ICPR    ((volatile uint32_t *)0xE000E280u)
#define RSIP_SECURE_NVIC_REG_INDEX(irq) ((irq) >> 5)
#define RSIP_SECURE_NVIC_BIT(irq)       (1u << ((irq) & 31u))

#define RSIP_DSB()  __asm(" dsb")
#define RSIP_ISB()  __asm(" isb")

/* statistics live in S-TCM (host can read them only with CMD_GET_STATS) */
static rsip_secure_stats_t s_stats;

/* ---------------------------------------------------------------------------
 * Locate the shared memory.
 *   TOKEN   : fixed address, token in MSGH2S0 must match req_hdr (seq/cmd)
 *   POINTER : host pointer -> must be inside host CPU RAM window
 * ------------------------------------------------------------------------- */
static volatile rsip_hsm_shm_t *secure_get_shm(uint32_t msg)
{
#if (RSIP_CFG_MSG_MODE == RSIP_MSG_TOKEN)
    volatile rsip_hsm_shm_t *shm = (volatile rsip_hsm_shm_t *)RSIP_SHM_SECURE_ADDR;
    if (((msg & 0xFFu) != 0xA5u) ||
        (RSIP_TOKEN_SEQ(msg) != (shm->req_hdr.seq & 0xFFFFu)) ||
        (((msg >> 8) & 0xFFu) != (shm->req_hdr.cmd & 0xFFu)))
    {
        return 0;
    }
    return shm;
#else
    /* never trust a host pointer blindly : range + alignment check */
    if ((msg < RSIP_SHM_HOST_RAM_START) ||
        ((msg + sizeof(rsip_hsm_shm_t)) > RSIP_SHM_HOST_RAM_END) ||
        ((msg & 0x3u) != 0u))
    {
        return 0;
    }
    return (volatile rsip_hsm_shm_t *)msg;
#endif
}

/* ---------------------------------------------------------------------------
 * Secure -> Host asynchronous event (one slot, flow controlled by EVT_ACK)
 * ------------------------------------------------------------------------- */
static rsip_hsm_status_t secure_send_event(volatile rsip_hsm_shm_t *shm, uint32_t evt_id, uint32_t value)
{
    rsip_cmdreg_t * const cmdreg = RSIP_SECURE_CMDREG;
    uint32_t guard = RSIP_CFG_EVT_ACK_TIMEOUT_LOOPS;

    shm->evt_hdr.magic   = RSIP_HSM_MAGIC;
    shm->evt_hdr.version = RSIP_HSM_PROTO_VERSION;
    shm->evt_hdr.cmd     = evt_id;
    shm->evt_hdr.seq++;
    shm->evt_hdr.status  = RSIP_HSM_STS_OK;
    shm->evt_hdr.len     = 4u;
    shm->evt_data[0]     = value;
    RSIP_DSB();
    cmdreg->ints2hfs0 = RSIP_S2H_EVT;                 /* -> Host INTS2H0 (IRQ95) */

    while ((cmdreg->inth2sf0 & RSIP_H2S_EVT_ACK) == 0u)
    {
        if (guard == 0u)
        {
            s_stats.evt_ack_timeout++;
            return RSIP_HSM_STS_TIMEOUT;
        }
        guard--;
    }
    cmdreg->inth2sfc0 = RSIP_H2S_EVT_ACK;
    s_stats.evt_sent++;
    return RSIP_HSM_STS_OK;
}

/* ---------------------------------------------------------------------------
 * Command handlers
 * ------------------------------------------------------------------------- */
static rsip_hsm_status_t cmd_led_policy(volatile rsip_hsm_shm_t *shm)
{
    const uint32_t min_duty    = shm->req_hdr.param[0];
    const uint32_t max_duty    = shm->req_hdr.param[1];
    const uint32_t step        = shm->req_hdr.param[2];
    const uint32_t frame_delay = shm->req_hdr.param[3];

    /* HSM policy decision point (replace with authentication / freshness /
       diagnostic-state checks in a real product) */
    if ((min_duty < 1u) || (max_duty > 128u) || (min_duty >= max_duty) ||
        (step == 0u) || (step > 16u) || (frame_delay < 100u) || (frame_delay > 2000u))
    {
        return RSIP_HSM_STS_DENIED;
    }
    shm->rsp_hdr.param[0] = min_duty;
    shm->rsp_hdr.param[1] = max_duty;
    shm->rsp_hdr.param[2] = step;
    shm->rsp_hdr.param[3] = frame_delay;
    return RSIP_HSM_STS_OK;
}

static rsip_hsm_status_t secure_dispatch(volatile rsip_hsm_shm_t *shm)
{
    rsip_cmdreg_t * const cmdreg = RSIP_SECURE_CMDREG;
    const uint32_t cmd = shm->req_hdr.cmd;
    const uint32_t len = shm->req_hdr.len;
    volatile const uint8_t *in  = (volatile const uint8_t *)shm->req_data;
    volatile uint8_t       *out = (volatile uint8_t *)shm->rsp_data;
    uint32_t i;

    /* ---- common header check ---- */
    if ((shm->req_hdr.magic != RSIP_HSM_MAGIC) || (shm->req_hdr.version != RSIP_HSM_PROTO_VERSION))
    {
        return RSIP_HSM_STS_PROTO_ERROR;
    }
    if (len > RSIP_SHM_DATA_BYTES)
    {
        return RSIP_HSM_STS_BAD_PARAM;
    }
    if (((shm->req_hdr.flags & RSIP_FLAG_CRC_VALID) != 0u) &&
        (rsip_crc32(shm->req_data, len) != shm->req_hdr.crc))
    {
        s_stats.crc_err_count++;
        return RSIP_HSM_STS_CRC_ERROR;
    }

    switch (cmd)
    {
    case RSIP_HSM_CMD_PING:
        shm->rsp_hdr.param[0] = RSIP_SECURE_FW_VERSION;
        shm->rsp_hdr.param[1] = s_stats.req_count;
        shm->rsp_hdr.param[2] = ~shm->req_hdr.param[0];
        return RSIP_HSM_STS_OK;

    case RSIP_HSM_CMD_ECHO:
        for (i = 0u; i < len; i++)
        {
            out[i] = in[i];
        }
        shm->rsp_hdr.len = len;
        return RSIP_HSM_STS_OK;

    case RSIP_HSM_CMD_CRC32:
        shm->rsp_hdr.param[0] = rsip_crc32(shm->req_data, len);
        return RSIP_HSM_STS_OK;

    case RSIP_HSM_CMD_TRANSFORM:
        for (i = 0u; i < len; i++)
        {
            out[i] = (uint8_t)~in[len - 1u - i];
        }
        shm->rsp_hdr.len = len;
        return RSIP_HSM_STS_OK;

    case RSIP_HSM_CMD_DELAY:
        for (i = 0u; i < shm->req_hdr.param[0]; i++)
        {
            if ((cmdreg->inth2sf0 & RSIP_H2S_ABORT) != 0u)
            {
                cmdreg->inth2sfc0 = RSIP_H2S_ABORT;
                s_stats.abort_count++;
                shm->rsp_hdr.param[0] = i;           /* loops done before abort */
                return RSIP_HSM_STS_ABORTED;
            }
        }
        shm->rsp_hdr.param[0] = i;
        return RSIP_HSM_STS_OK;

    case RSIP_HSM_CMD_EVENT_REQ:
    {
        const uint32_t n = shm->req_hdr.param[0];
        if ((n == 0u) || (n > 16u))
        {
            return RSIP_HSM_STS_BAD_PARAM;
        }
        for (i = 0u; i < n; i++)
        {
            if (secure_send_event(shm, RSIP_HSM_EVT_USER, shm->req_hdr.param[1] + i) != RSIP_HSM_STS_OK)
            {
                shm->rsp_hdr.param[0] = i;
                return RSIP_HSM_STS_TIMEOUT;
            }
        }
        shm->rsp_hdr.param[0] = n;
        return RSIP_HSM_STS_OK;
    }

    case RSIP_HSM_CMD_GET_STATS:
    {
        volatile uint32_t *o = shm->rsp_data;
        const uint32_t *s = (const uint32_t *)&s_stats;
        for (i = 0u; i < (sizeof(s_stats) / 4u); i++)
        {
            o[i] = s[i];
        }
        shm->rsp_hdr.len = sizeof(s_stats);
        return RSIP_HSM_STS_OK;
    }

    case RSIP_HSM_CMD_LED_DIMMING_APPROVE:
        return cmd_led_policy(shm);

    case RSIP_HSM_CMD_DFLASH2_READ:
#if (RSIP_CFG_SECURE_ENABLE_DFLASH2_READ != 0u)
    {
        const uint32_t off = shm->req_hdr.param[0];
        const uint32_t rl  = shm->req_hdr.param[1];
        volatile const uint8_t *df = (volatile const uint8_t *)(RSIP_DFLASH2_BASE + off);
        if ((rl == 0u) || (rl > RSIP_SHM_DATA_BYTES) || ((off + rl) > RSIP_DFLASH2_SIZE))
        {
            return RSIP_HSM_STS_BAD_PARAM;
        }
        for (i = 0u; i < rl; i++)
        {
            out[i] = df[i];          /* Data Area 2 : readable only by RSIP (RSIPRAD) */
        }
        shm->rsp_hdr.len = rl;
        return RSIP_HSM_STS_OK;
    }
#else
        return RSIP_HSM_STS_NOT_SUPPORTED;
#endif

    default:
        return RSIP_HSM_STS_BAD_CMD;
    }
}

/* ---------------------------------------------------------------------------
 * One request : REQ flag -> dispatch -> response slot -> RSP doorbell
 * ------------------------------------------------------------------------- */
static void secure_process_host_request(void)
{
    rsip_cmdreg_t * const cmdreg = RSIP_SECURE_CMDREG;
    volatile rsip_hsm_shm_t *shm;
    rsip_hsm_status_t sts;
    uint32_t msg;
    uint32_t seq = 0u;
    uint32_t cmd = 0u;

    if ((cmdreg->inth2sf0 & RSIP_H2S_REQ) == 0u)
    {
        return;
    }
    msg = cmdreg->msg_h2s0;
    cmdreg->inth2sfc0 = RSIP_H2S_REQ | RSIP_H2S_ABORT;   /* ack REQ, drop stale ABORT */
    (void)cmdreg->inth2sf0;                              /* read-back: clear completed */
    RSIP_DSB();
    s_stats.req_count++;

    shm = secure_get_shm(msg);
    if (shm == 0)
    {
        /* cannot locate a trusted buffer -> answer with status only */
        s_stats.err_count++;
        cmdreg->msg_s2h0 = RSIP_TOKEN_S2H(RSIP_TOKEN_SEQ(msg), RSIP_HSM_STS_PROTO_ERROR);
        RSIP_DSB();
        cmdreg->ints2hfs0 = RSIP_S2H_RSP;
        return;
    }
    seq = shm->req_hdr.seq;
    cmd = shm->req_hdr.cmd;
    s_stats.last_cmd = cmd;
    shm->secure_heartbeat++;

    /* prepare response header (status filled after dispatch) */
    shm->rsp_hdr.len      = 0u;
    shm->rsp_hdr.flags    = 0u;
    shm->rsp_hdr.param[0] = 0u;
    shm->rsp_hdr.param[1] = 0u;
    shm->rsp_hdr.param[2] = 0u;
    shm->rsp_hdr.param[3] = 0u;

    sts = secure_dispatch(shm);

    if (sts == RSIP_HSM_STS_OK) { s_stats.ok_count++; } else { s_stats.err_count++; }

#if (RSIP_CFG_USE_CRC != 0u)
    shm->rsp_hdr.crc   = rsip_crc32(shm->rsp_data, shm->rsp_hdr.len);
    shm->rsp_hdr.flags = RSIP_FLAG_CRC_VALID;
#endif
    shm->rsp_hdr.cmd     = cmd;
    shm->rsp_hdr.seq     = seq;
    shm->rsp_hdr.status  = (uint32_t)sts;
    shm->rsp_hdr.version = RSIP_HSM_PROTO_VERSION;
    shm->rsp_hdr.magic   = RSIP_HSM_MAGIC;            /* written last = slot valid */

    cmdreg->msg_s2h0 = RSIP_TOKEN_S2H(seq, sts);
    RSIP_DSB();                                       /* shm visible before doorbell */
    cmdreg->ints2hfs0 = RSIP_S2H_RSP;                 /* -> Host INTS2H0 (IRQ95) */
}

#if (RSIP_CFG_SECURE_RX_MODE == RSIP_MODE_IRQ)
static void secure_enable_inth2s0_irq(void)
{
    const uint32_t irq   = RSIP_SECURE_IRQ_INTH2S0;
    const uint32_t index = RSIP_SECURE_NVIC_REG_INDEX(irq);
    const uint32_t bit   = RSIP_SECURE_NVIC_BIT(irq);

    RSIP_SECURE_NVIC_ICER[index] = bit;
    RSIP_SECURE_NVIC_ICPR[index] = bit;
    RSIP_SECURE_NVIC_ISER[index] = bit;
    __asm(" cpsie i");
    RSIP_DSB();
    RSIP_ISB();
}
#endif

/* IRQ34 INTH2S0 (secure_cpu_vectors.arm). Always linked; in POLL mode the
   IRQ is never enabled, so this handler is not entered.                  */
#pragma ghs interrupt
void RSIP_INTH2S0_Handler(void)
{
    const uint32_t irq   = RSIP_SECURE_IRQ_INTH2S0;
    const uint32_t index = RSIP_SECURE_NVIC_REG_INDEX(irq);
    const uint32_t bit   = RSIP_SECURE_NVIC_BIT(irq);

    secure_process_host_request();
    RSIP_SECURE_NVIC_ICPR[index] = bit;
    RSIP_DSB();
    RSIP_ISB();
}

void secure_cpu_main(void)
{
    rsip_cmdreg_t * const cmdreg = RSIP_SECURE_CMDREG;

    /* REQ raises IRQ34 ; ABORT / EVT_ACK are polled inside long commands */
#if (RSIP_CFG_SECURE_RX_MODE == RSIP_MODE_IRQ)
    cmdreg->inth2sie0 = RSIP_H2S_REQ;
#else
    cmdreg->inth2sie0 = 0u;
#endif
    cmdreg->ints2hie0 = RSIP_S2H_ALL;                 /* RSP + EVT -> Host IRQ95 */
    cmdreg->inth2sfc0 = RSIP_H2S_ALL;
    cmdreg->ints2hfc0 = RSIP_S2H_ALL;
    RSIP_DSB();

    cmdreg->msg_s2h0 = RSIP_SECURE_READY_TOKEN;       /* Host waits for this (T0) */
    RSIP_DSB();

#if (RSIP_CFG_SECURE_RX_MODE == RSIP_MODE_IRQ)
    secure_enable_inth2s0_irq();
    for (;;)
    {
        __asm(" wfi");
    }
#else
    for (;;)
    {
        secure_process_host_request();
    }
#endif
}
