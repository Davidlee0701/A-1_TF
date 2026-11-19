/*******************************************************************************
* File Name   : rsip_hsm_host.c
* Device(s)   : R-Car U5L4 Host CPU (Cortex-M33, PE0)
* Description : Host side mailbox driver for RSIP-M30A (HSM) protocol v2.
*               - shared memory @ RSIP_SHM_ADDR (.rsip_shared -> RSIP_SHARED_RAM)
*               - doorbell     : RSIP_INTH2SFS0 bit0 REQ / bit1 ABORT / bit2 EVT_ACK
*               - completion   : RSIP_INTS2HF0  bit0 RSP / bit1 EVT
*                                IRQ mode : ISR_INTS2H0 (NVIC IRQ95)
*                                POLL mode: rsip_host_service() in wait loop
* History     : 13.11.2026 2.00  rewritten (seq/CRC/timeout/retry/abort/event)
*******************************************************************************/
#include "rsip_hsm_cmd.h"
#include <interrupt_functions.h>

#define RSIP_HOST_CMDREG     ((rsip_cmdreg_t *)RSIP_CMDREG_HOST_BASE)
#define RSIP_HOST_IRQ_INTS2H0 (95)

#define RSIP_DSB()           __asm(" dsb")
#define RSIP_ISB()           __asm(" isb")

/* Cortex-M33 DWT cycle counter */
#define RSIP_DEMCR           (*(volatile uint32_t *)0xE000EDFCu)
#define RSIP_DWT_CTRL        (*(volatile uint32_t *)0xE0001000u)
#define RSIP_DWT_CYCCNT      (*(volatile uint32_t *)0xE0001004u)

/* ---------------------------------------------------------------------------
 * Shared memory : placed by section.ld into RSIP_SHARED_RAM (0x204FF000)
 * ------------------------------------------------------------------------- */
#pragma ghs section bss=".rsip_shared"
static volatile rsip_hsm_shm_t g_rsip_shm;
#pragma ghs section bss=default

static volatile uint32_t   s_rsp_flag;      /* set by ISR / service when RSP bit seen */
static volatile uint32_t   s_rsp_token;     /* MSGS2H0 captured with RSP              */
static uint32_t            s_seq;
static rsip_event_cb_t     s_evt_cb;
static volatile rsip_host_stats_t s_stats;

/* ------------------------------------------------------------------------- */
uint32_t rsip_host_cycles_now(void)
{
#if (RSIP_CFG_USE_DWT_CYCCNT != 0u)
    return RSIP_DWT_CYCCNT;
#else
    return 0u;
#endif
}

volatile rsip_hsm_shm_t *rsip_host_shm(void)
{
    return &g_rsip_shm;
}

const rsip_host_stats_t *rsip_host_get_stats(void)
{
    return (const rsip_host_stats_t *)&s_stats;
}

void rsip_xfer_init(rsip_xfer_t *x, uint32_t cmd)
{
    uint32_t i;
    uint8_t *p = (uint8_t *)x;

    for (i = 0u; i < sizeof(*x); i++)
    {
        p[i] = 0u;
    }
    x->cmd = cmd;
    x->timeout_loops = RSIP_CFG_TIMEOUT_LOOPS;
    x->retry = RSIP_CFG_RETRY_COUNT;
}

/* ---------------------------------------------------------------------------
 * Flag handler : common for ISR (IRQ mode) and rsip_host_service (POLL mode)
 * ------------------------------------------------------------------------- */
static void rsip_host_handle_flags(void)
{
    rsip_cmdreg_t * const cmdreg = RSIP_HOST_CMDREG;
    const uint32_t flags = cmdreg->ints2hf0;

    if ((flags & RSIP_S2H_RSP) != 0u)
    {
        s_rsp_token = cmdreg->msg_s2h0;      /* (seq<<16)|status */
        cmdreg->ints2hfc0 = RSIP_S2H_RSP;    /* clear completion flag */
        (void)cmdreg->ints2hf0;              /* read-back: clear completed before re-check */
        RSIP_DSB();
        s_rsp_flag = 1u;
        s_stats.rsp_count++;
    }

    if ((flags & RSIP_S2H_EVT) != 0u)
    {
        uint32_t words;

        cmdreg->ints2hfc0 = RSIP_S2H_EVT;
        (void)cmdreg->ints2hf0;              /* read-back */
        RSIP_DSB();
        if (g_rsip_shm.evt_hdr.magic == RSIP_HSM_MAGIC)
        {
            words = g_rsip_shm.evt_hdr.len / 4u;
            if (words > RSIP_SHM_EVT_WORDS)
            {
                words = RSIP_SHM_EVT_WORDS;
            }
            s_stats.evt_count++;
            if (s_evt_cb != 0)
            {
                s_evt_cb(g_rsip_shm.evt_hdr.cmd, g_rsip_shm.evt_data, words);
            }
        }
        RSIP_DSB();
        cmdreg->inth2sfs0 = RSIP_H2S_EVT_ACK; /* slot free -> Secure may send next event */
    }
}

void rsip_host_service(void)
{
    rsip_host_handle_flags();
}

#pragma ghs interrupt
void ISR_INTS2H0(void)
{
    s_stats.irq_count++;
    rsip_host_handle_flags();
    NVIC_ClearPendingIRQ(RSIP_HOST_IRQ_INTS2H0);
}

/* ---------------------------------------------------------------------------
 * Init
 * ------------------------------------------------------------------------- */
rsip_hsm_status_t rsip_host_init(rsip_event_cb_t cb)
{
    rsip_cmdreg_t * const cmdreg = RSIP_HOST_CMDREG;
    volatile uint32_t *p = (volatile uint32_t *)&g_rsip_shm;
    uint32_t i;

    for (i = 0u; i < (sizeof(rsip_hsm_shm_t) / 4u); i++)
    {
        p[i] = 0u;
    }
    s_evt_cb = cb;
    s_rsp_flag = 0u;
    s_seq = 0u;

#if (RSIP_CFG_USE_DWT_CYCCNT != 0u)
    RSIP_DEMCR |= (1u << 24);       /* TRCENA */
    RSIP_DWT_CYCCNT = 0u;
    RSIP_DWT_CTRL |= 1u;            /* CYCCNTENA */
#endif

    cmdreg->ints2hfc0 = RSIP_S2H_ALL; /* drop stale completion flags */
    RSIP_DSB();

#if (RSIP_CFG_HOST_NOTIFY_MODE == RSIP_MODE_IRQ)
    NVIC_ClearPendingIRQ(RSIP_HOST_IRQ_INTS2H0);
    UNMASK_ISR_INTS2H0();
#endif

#if (RSIP_CFG_MSG_MODE == RSIP_MSG_TOKEN)
    /* TOKEN mode: Secure CPU uses the fixed address, so the linker must agree */
    if ((uint32_t)&g_rsip_shm != RSIP_SHM_ADDR)
    {
        return RSIP_HSM_STS_PROTO_ERROR;
    }
#endif
    return RSIP_HSM_STS_OK;
}

rsip_hsm_status_t rsip_host_wait_ready(uint32_t timeout_loops)
{
    rsip_cmdreg_t * const cmdreg = RSIP_HOST_CMDREG;
    uint32_t guard = timeout_loops;
    rsip_xfer_t x;

    while (guard > 0u)
    {
        if (cmdreg->msg_s2h0 == RSIP_SECURE_READY_TOKEN)
        {
            return RSIP_HSM_STS_OK;
        }
        guard--;
    }

    /* Secure CPU may have been running before a host-only reset:
       MSGS2H0 then holds an old response token -> confirm with PING */
    rsip_xfer_init(&x, RSIP_HSM_CMD_PING);
    x.timeout_loops = timeout_loops;
    x.retry = 0u;
    return rsip_host_xfer(&x);
}

/* ---------------------------------------------------------------------------
 * One transaction
 * ------------------------------------------------------------------------- */
static rsip_hsm_status_t rsip_host_xfer_once(rsip_xfer_t *x)
{
    rsip_cmdreg_t * const cmdreg = RSIP_HOST_CMDREG;
    const uint8_t *src = (const uint8_t *)x->tx;
    volatile uint8_t *dst = (volatile uint8_t *)g_rsip_shm.req_data;
    uint32_t guard;
    uint32_t seq;
    uint32_t i;
    uint32_t t0;
    uint32_t len;
    uint32_t tok;
    rsip_hsm_status_t sts;

    if ((x->tx_len > RSIP_SHM_DATA_BYTES) || ((x->tx_len != 0u) && (src == 0)))
    {
        return RSIP_HSM_STS_BAD_PARAM;
    }

    s_seq = (s_seq + 1u) & 0xFFFFu;
    if (s_seq == 0u)
    {
        s_seq = 1u;
    }
    seq = s_seq;
    x->seq = seq;

    /* ---- 1. invalidate response slot ---- */
    g_rsip_shm.rsp_hdr.magic  = 0u;
    g_rsip_shm.rsp_hdr.seq    = 0u;
    g_rsip_shm.rsp_hdr.status = RSIP_HSM_STS_PENDING;

    /* ---- 2. request header + payload ---- */
    for (i = 0u; i < x->tx_len; i++)
    {
        dst[i] = src[i];
    }
    g_rsip_shm.req_hdr.magic    = RSIP_HSM_MAGIC;
    g_rsip_shm.req_hdr.version  = RSIP_HSM_PROTO_VERSION;
    g_rsip_shm.req_hdr.cmd      = x->cmd;
    g_rsip_shm.req_hdr.seq      = seq;
    g_rsip_shm.req_hdr.status   = RSIP_HSM_STS_PENDING;
    g_rsip_shm.req_hdr.len      = ((x->raw_flags & RSIP_RAW_BAD_LEN) != 0u) ? 0x400u : x->tx_len;
    g_rsip_shm.req_hdr.flags    = 0u;
    g_rsip_shm.req_hdr.crc      = 0u;
#if (RSIP_CFG_USE_CRC != 0u)
    g_rsip_shm.req_hdr.crc      = rsip_crc32(g_rsip_shm.req_data, x->tx_len);
    g_rsip_shm.req_hdr.flags    = RSIP_FLAG_CRC_VALID;
#endif
    if ((x->raw_flags & RSIP_RAW_BREAK_CRC) != 0u)
    {
        g_rsip_shm.req_hdr.crc  ^= 0xDEADBEEFu;
        g_rsip_shm.req_hdr.flags = RSIP_FLAG_CRC_VALID;
    }
    for (i = 0u; i < 4u; i++)
    {
        g_rsip_shm.req_hdr.param[i] = x->param[i];
    }

    /* ---- 3. message register + doorbell ---- */
    s_rsp_flag = 0u;
    RSIP_DSB();                                   /* shm writes visible before doorbell */
#if (RSIP_CFG_MSG_MODE == RSIP_MSG_TOKEN)
    cmdreg->msg_h2s0 = RSIP_TOKEN_H2S(seq, x->cmd);
#else
    cmdreg->msg_h2s0 = (uint32_t)&g_rsip_shm;
#endif
    RSIP_DSB();
    t0 = rsip_host_cycles_now();
    cmdreg->inth2sfs0 = RSIP_H2S_REQ;             /* -> Secure INTH2S0 (IRQ34) */
    s_stats.tx_count++;

    /* ---- 4. wait for completion (IRQ: ISR sets s_rsp_flag / POLL: service) ---- */
    guard = (x->timeout_loops != 0u) ? x->timeout_loops : RSIP_CFG_TIMEOUT_LOOPS;
    for (;;)
    {
#if (RSIP_CFG_HOST_NOTIFY_MODE == RSIP_MODE_POLL)
        rsip_host_handle_flags();
#endif
        if (s_rsp_flag != 0u)
        {
            s_rsp_flag = 0u;
            tok = s_rsp_token;
            if (RSIP_TOKEN_SEQ(tok) == seq)
            {
                break;                            /* our response */
            }
            s_stats.stale_rsp_count++;            /* late response of an aborted request */
        }
        if (guard == 0u)
        {
            s_stats.timeout_count++;
            if ((x->raw_flags & RSIP_RAW_NO_ABORT) == 0u)
            {
                cmdreg->inth2sfs0 = RSIP_H2S_ABORT;
            }
            return RSIP_HSM_STS_TIMEOUT;
        }
        guard--;
    }
    x->cycles = rsip_host_cycles_now() - t0;
    RSIP_DSB();
    RSIP_ISB();

    /* ---- 5. validate response ---- */
    if ((g_rsip_shm.rsp_hdr.magic   != RSIP_HSM_MAGIC) ||
        (g_rsip_shm.rsp_hdr.version != RSIP_HSM_PROTO_VERSION) ||
        (g_rsip_shm.rsp_hdr.seq     != seq) ||
        (g_rsip_shm.rsp_hdr.cmd     != x->cmd))
    {
        return RSIP_HSM_STS_PROTO_ERROR;
    }
    sts = (rsip_hsm_status_t)g_rsip_shm.rsp_hdr.status;
    len = g_rsip_shm.rsp_hdr.len;
    if (len > RSIP_SHM_DATA_BYTES)
    {
        return RSIP_HSM_STS_PROTO_ERROR;
    }
#if (RSIP_CFG_USE_CRC != 0u)
    if (((g_rsip_shm.rsp_hdr.flags & RSIP_FLAG_CRC_VALID) != 0u) &&
        (rsip_crc32(g_rsip_shm.rsp_data, len) != g_rsip_shm.rsp_hdr.crc))
    {
        s_stats.crc_err_count++;
        return RSIP_HSM_STS_CRC_ERROR;
    }
#endif
    for (i = 0u; i < 4u; i++)
    {
        x->rsp_param[i] = g_rsip_shm.rsp_hdr.param[i];
    }
    x->rx_len = len;
    if (x->rx != 0)
    {
        uint8_t *rd = (uint8_t *)x->rx;
        const volatile uint8_t *rs = (const volatile uint8_t *)g_rsip_shm.rsp_data;
        const uint32_t n = (len < x->rx_cap) ? len : x->rx_cap;
        for (i = 0u; i < n; i++)
        {
            rd[i] = rs[i];
        }
    }
    return sts;
}

rsip_hsm_status_t rsip_host_xfer(rsip_xfer_t *x)
{
    rsip_hsm_status_t sts;
    uint32_t attempt = 0u;

    if (x == 0)
    {
        return RSIP_HSM_STS_BAD_PARAM;
    }
    for (;;)
    {
        sts = rsip_host_xfer_once(x);
        if (((sts == RSIP_HSM_STS_TIMEOUT) || (sts == RSIP_HSM_STS_CRC_ERROR)) &&
            (attempt < x->retry) &&
            ((x->raw_flags & RSIP_RAW_BREAK_CRC) == 0u))
        {
            attempt++;
            s_stats.retry_count++;
            continue;
        }
        return sts;
    }
}

/* After a TIMEOUT(+ABORT) the Secure CPU still answers the old seq.
   Wait for it so the next transaction starts clean.                   */
rsip_hsm_status_t rsip_host_drain_late_response(uint32_t timeout_loops, uint32_t *seq, uint32_t *status)
{
    uint32_t guard = timeout_loops;

    while (guard > 0u)
    {
#if (RSIP_CFG_HOST_NOTIFY_MODE == RSIP_MODE_POLL)
        rsip_host_handle_flags();
#endif
        if (s_rsp_flag != 0u)
        {
            s_rsp_flag = 0u;
            RSIP_DSB();
            if (seq != 0)
            {
                *seq = RSIP_TOKEN_SEQ(s_rsp_token);
            }
            if (status != 0)
            {
                *status = g_rsip_shm.rsp_hdr.status;
            }
            return RSIP_HSM_STS_OK;
        }
        guard--;
    }
    return RSIP_HSM_STS_TIMEOUT;
}
