/*******************************************************************************
* File Name   : rsip_hsm_test.c
* Device(s)   : R-Car U5L4 Host CPU (PE0)
* Description : Host <-> RSIP (HSM) communication test scenarios T0..T10.
*               Result table g_rsip_test_report[] can be watched in MULTI,
*               and is printed on UART when RSIP_CFG_LOG_UART = 1.
* History     : 13.11.2026 1.00  first release
*******************************************************************************/
#include "rsip_hsm_cmd.h"

#if (RSIP_CFG_LOG_UART != 0u)
extern void printf(const char *format, ...);   /* simple_uart/Debug_UART.c */
#define RSIP_LOG(...)   printf(__VA_ARGS__)
#else
#define RSIP_LOG(...)
#endif

#define RSIP_TEST_NUM   (11u)

typedef enum { RSIP_TR_NOT_RUN = 0u, RSIP_TR_PASS = 1u, RSIP_TR_FAIL = 2u } rsip_test_result_t;

typedef struct
{
    const char        *name;
    rsip_test_result_t result;
    uint32_t           status;     /* last rsip_hsm_status_t */
    uint32_t           detail;     /* test specific value (cycles, count ...) */
} rsip_test_report_t;

/* watch this in debugger */
volatile rsip_test_report_t g_rsip_test_report[RSIP_TEST_NUM] =
{
    { "T0 CONFIG/READY", RSIP_TR_NOT_RUN, 0u, 0u },
    { "T1 PING",         RSIP_TR_NOT_RUN, 0u, 0u },
    { "T2 ECHO",         RSIP_TR_NOT_RUN, 0u, 0u },
    { "T3 CRC32",        RSIP_TR_NOT_RUN, 0u, 0u },
    { "T4 TRANSFORM",    RSIP_TR_NOT_RUN, 0u, 0u },
    { "T5 BURST",        RSIP_TR_NOT_RUN, 0u, 0u },
    { "T6 ERROR",        RSIP_TR_NOT_RUN, 0u, 0u },
    { "T7 TIMEOUT",      RSIP_TR_NOT_RUN, 0u, 0u },
    { "T8 EVENT",        RSIP_TR_NOT_RUN, 0u, 0u },
    { "T9 POLICY",       RSIP_TR_NOT_RUN, 0u, 0u },
    { "T10 DFLASH2",     RSIP_TR_NOT_RUN, 0u, 0u }
};

volatile uint32_t g_rsip_test_pass;
volatile uint32_t g_rsip_test_fail;

static uint8_t  s_tx[RSIP_SHM_DATA_BYTES];
static uint8_t  s_rx[RSIP_SHM_DATA_BYTES];

/* event log filled by callback (ISR context in IRQ mode) */
static volatile uint32_t s_evt_values[16];
static volatile uint32_t s_evt_num;

static void rsip_test_event_cb(uint32_t evt_id, const volatile uint32_t *data, uint32_t words)
{
    if ((evt_id == RSIP_HSM_EVT_USER) && (words >= 1u) && (s_evt_num < 16u))
    {
        s_evt_values[s_evt_num] = data[0];
        s_evt_num++;
    }
}

static void fill_pattern(uint8_t *p, uint32_t len, uint32_t seed)
{
    uint32_t i;
    for (i = 0u; i < len; i++)
    {
        p[i] = (uint8_t)((i * 7u) + seed);
    }
}

static uint32_t mem_equal(const uint8_t *a, const uint8_t *b, uint32_t len)
{
    uint32_t i;
    for (i = 0u; i < len; i++)
    {
        if (a[i] != b[i])
        {
            return 0u;
        }
    }
    return 1u;
}

static void report(uint32_t idx, uint32_t pass, uint32_t status, uint32_t detail)
{
    g_rsip_test_report[idx].result = (pass != 0u) ? RSIP_TR_PASS : RSIP_TR_FAIL;
    g_rsip_test_report[idx].status = status;
    g_rsip_test_report[idx].detail = detail;
    if (pass != 0u) { g_rsip_test_pass++; } else { g_rsip_test_fail++; }
    RSIP_LOG("[%s] %s  sts=0x%x detail=%u\r\n", (pass != 0u) ? "PASS" : "FAIL",
             g_rsip_test_report[idx].name, status, detail);
}

/* ------------------------------------------------------------------ T0 --- */
static void test_t0_config(void)
{
    rsip_hsm_status_t sts = rsip_host_wait_ready(RSIP_CFG_READY_TIMEOUT_LOOPS);
    uint32_t addr_ok = 1u;
#if (RSIP_CFG_MSG_MODE == RSIP_MSG_TOKEN)
    addr_ok = ((uint32_t)rsip_host_shm() == RSIP_SHM_ADDR) ? 1u : 0u;
#endif
    report(0u, (sts == RSIP_HSM_STS_OK) && (addr_ok != 0u), sts, (uint32_t)rsip_host_shm());
}

/* ------------------------------------------------------------------ T1 --- */
static void test_t1_ping(void)
{
    rsip_xfer_t x;
    rsip_hsm_status_t sts;

    rsip_xfer_init(&x, RSIP_HSM_CMD_PING);
    x.param[0] = 0x13572468u;
    sts = rsip_host_xfer(&x);
    report(1u, (sts == RSIP_HSM_STS_OK) &&
               (x.rsp_param[0] == RSIP_SECURE_FW_VERSION) &&
               (x.rsp_param[2] == ~0x13572468u), sts, x.cycles);
}

/* ------------------------------------------------------------------ T2 --- */
static void test_t2_echo(void)
{
    static const uint32_t lens[5] = { 1u, 4u, 16u, 64u, 256u };
    rsip_xfer_t x;
    rsip_hsm_status_t sts = RSIP_HSM_STS_OK;
    uint32_t i;
    uint32_t ok = 1u;

    for (i = 0u; i < 5u; i++)
    {
        fill_pattern(s_tx, lens[i], 0x30u + i);
        rsip_xfer_init(&x, RSIP_HSM_CMD_ECHO);
        x.tx = s_tx;  x.tx_len = lens[i];
        x.rx = s_rx;  x.rx_cap = sizeof(s_rx);
        sts = rsip_host_xfer(&x);
        if ((sts != RSIP_HSM_STS_OK) || (x.rx_len != lens[i]) || (mem_equal(s_tx, s_rx, lens[i]) == 0u))
        {
            ok = 0u;
            break;
        }
    }
    report(2u, ok, sts, (ok != 0u) ? x.cycles : lens[i]);
}

/* ------------------------------------------------------------------ T3 --- */
static void test_t3_crc(void)
{
    rsip_xfer_t x;
    rsip_hsm_status_t sts;
    uint32_t host_crc;

    fill_pattern(s_tx, 200u, 0x5Au);
    host_crc = rsip_crc32(s_tx, 200u);
    rsip_xfer_init(&x, RSIP_HSM_CMD_CRC32);
    x.tx = s_tx;  x.tx_len = 200u;
    sts = rsip_host_xfer(&x);
    report(3u, (sts == RSIP_HSM_STS_OK) && (x.rsp_param[0] == host_crc), sts, x.rsp_param[0]);
}

/* ------------------------------------------------------------------ T4 --- */
static void test_t4_transform(void)
{
    rsip_xfer_t x;
    rsip_hsm_status_t sts;
    uint32_t i;
    uint32_t ok;
    const uint32_t len = 37u;

    fill_pattern(s_tx, len, 0x11u);
    rsip_xfer_init(&x, RSIP_HSM_CMD_TRANSFORM);
    x.tx = s_tx;  x.tx_len = len;
    x.rx = s_rx;  x.rx_cap = sizeof(s_rx);
    sts = rsip_host_xfer(&x);
    ok = ((sts == RSIP_HSM_STS_OK) && (x.rx_len == len)) ? 1u : 0u;
    for (i = 0u; (ok != 0u) && (i < len); i++)
    {
        if (s_rx[i] != (uint8_t)~s_tx[len - 1u - i])
        {
            ok = 0u;
        }
    }
    report(4u, ok, sts, x.cycles);
}

/* ------------------------------------------------------------------ T5 --- */
static void test_t5_burst(void)
{
    rsip_xfer_t x;
    rsip_hsm_status_t sts = RSIP_HSM_STS_OK;
    uint32_t n;
    uint32_t pass = 0u;
    uint32_t t0 = rsip_host_cycles_now();

    for (n = 0u; n < RSIP_CFG_BURST_COUNT; n++)
    {
        fill_pattern(s_tx, 64u, n);
        rsip_xfer_init(&x, RSIP_HSM_CMD_ECHO);
        x.tx = s_tx;  x.tx_len = 64u;
        x.rx = s_rx;  x.rx_cap = 64u;
        sts = rsip_host_xfer(&x);
        if ((sts == RSIP_HSM_STS_OK) && (mem_equal(s_tx, s_rx, 64u) != 0u))
        {
            pass++;
        }
    }
    /* detail = average cycles per 64-byte transaction */
    report(5u, pass == RSIP_CFG_BURST_COUNT, sts,
           (rsip_host_cycles_now() - t0) / RSIP_CFG_BURST_COUNT);
}

/* ------------------------------------------------------------------ T6 --- */
static void test_t6_error(void)
{
    rsip_xfer_t x;
    rsip_hsm_status_t s1;
    rsip_hsm_status_t s2;
    rsip_hsm_status_t s3;
    rsip_hsm_status_t s4;

    rsip_xfer_init(&x, 0x55u);                       /* unknown command */
    x.retry = 0u;
    s1 = rsip_host_xfer(&x);

    rsip_xfer_init(&x, RSIP_HSM_CMD_ECHO);           /* declared len 1024 > 256 */
    fill_pattern(s_tx, 16u, 1u);
    x.tx = s_tx;  x.tx_len = 16u;  x.retry = 0u;
    x.raw_flags = RSIP_RAW_BAD_LEN;
    s2 = rsip_host_xfer(&x);

    rsip_xfer_init(&x, RSIP_HSM_CMD_ECHO);           /* corrupted CRC */
    x.tx = s_tx;  x.tx_len = 16u;  x.retry = 0u;
    x.raw_flags = RSIP_RAW_BREAK_CRC;
    s3 = rsip_host_xfer(&x);

    rsip_xfer_init(&x, RSIP_HSM_CMD_PING);           /* link still alive ? */
    s4 = rsip_host_xfer(&x);

    report(6u, (s1 == RSIP_HSM_STS_BAD_CMD) &&
               (s2 == RSIP_HSM_STS_BAD_PARAM) &&
#if (RSIP_CFG_USE_CRC != 0u)
               (s3 == RSIP_HSM_STS_CRC_ERROR) &&
#endif
               (s4 == RSIP_HSM_STS_OK),
           ((uint32_t)s1 << 24) | ((uint32_t)s2 << 16) | ((uint32_t)s3 << 8) | (uint32_t)s4, 0u);
}

/* ------------------------------------------------------------------ T7 --- */
static void test_t7_timeout(void)
{
    rsip_xfer_t x;
    rsip_hsm_status_t s1;
    rsip_hsm_status_t s3;
    rsip_hsm_status_t sd;
    uint32_t late_seq = 0u;
    uint32_t late_sts = 0u;
    uint32_t req_seq;

    /* Secure busy for a long time, host gives up early -> ABORT */
    rsip_xfer_init(&x, RSIP_HSM_CMD_DELAY);
    x.param[0] = 0x7FFFFFFFu;                 /* very long */
    x.timeout_loops = 20000u;                 /* short host timeout */
    x.retry = 0u;
    s1 = rsip_host_xfer(&x);
    req_seq = x.seq;

    /* Secure sees ABORT bit and answers the old seq with ABORTED */
    sd = rsip_host_drain_late_response(RSIP_CFG_TIMEOUT_LOOPS, &late_seq, &late_sts);

    /* link recovered ? */
    rsip_xfer_init(&x, RSIP_HSM_CMD_PING);
    s3 = rsip_host_xfer(&x);

    report(7u, (s1 == RSIP_HSM_STS_TIMEOUT) &&
               (sd == RSIP_HSM_STS_OK) && (late_seq == req_seq) &&
               (late_sts == RSIP_HSM_STS_ABORTED) &&
               (s3 == RSIP_HSM_STS_OK), late_sts, late_seq);
}

/* ------------------------------------------------------------------ T8 --- */
static void test_t8_event(void)
{
    rsip_xfer_t x;
    rsip_hsm_status_t sts;
    uint32_t i;
    uint32_t ok;

    s_evt_num = 0u;
    rsip_xfer_init(&x, RSIP_HSM_CMD_EVENT_REQ);
    x.param[0] = RSIP_CFG_EVENT_COUNT;
    x.param[1] = 0x1000u;
    sts = rsip_host_xfer(&x);         /* events arrive (ISR / service) before RSP */

    ok = ((sts == RSIP_HSM_STS_OK) && (x.rsp_param[0] == RSIP_CFG_EVENT_COUNT) &&
          (s_evt_num == RSIP_CFG_EVENT_COUNT)) ? 1u : 0u;
    for (i = 0u; (ok != 0u) && (i < RSIP_CFG_EVENT_COUNT); i++)
    {
        if (s_evt_values[i] != (0x1000u + i))
        {
            ok = 0u;
        }
    }
    report(8u, ok, sts, s_evt_num);
}

/* ------------------------------------------------------------------ T9 --- */
rsip_hsm_status_t rsip_host_request_led_dimming(uint32_t min_duty, uint32_t max_duty,
                                                uint32_t step, uint32_t frame_delay,
                                                uint32_t approved[4])
{
    rsip_xfer_t x;
    rsip_hsm_status_t sts;
    uint32_t i;

    rsip_xfer_init(&x, RSIP_HSM_CMD_LED_DIMMING_APPROVE);
    x.param[0] = min_duty;  x.param[1] = max_duty;
    x.param[2] = step;      x.param[3] = frame_delay;
    sts = rsip_host_xfer(&x);
    if (approved != 0)
    {
        for (i = 0u; i < 4u; i++)
        {
            approved[i] = x.rsp_param[i];
        }
    }
    return sts;
}

static void test_t9_policy(void)
{
    uint32_t ap[4];
    rsip_hsm_status_t s_ok   = rsip_host_request_led_dimming(1u, 64u, 1u, 550u, ap);
    rsip_hsm_status_t s_deny = rsip_host_request_led_dimming(1u, 200u, 1u, 550u, 0);  /* max>128 */

    report(9u, (s_ok == RSIP_HSM_STS_OK) && (ap[1] == 64u) && (s_deny == RSIP_HSM_STS_DENIED),
           ((uint32_t)s_ok << 8) | (uint32_t)s_deny, 0u);
}

/* ----------------------------------------------------------------- T10 --- */
static void test_t10_dflash2(void)
{
    rsip_xfer_t x;
    rsip_hsm_status_t sts;

    /* Host never touches 0x400C0000 itself (RSIPRAD: RSIP only).
       It asks the Secure CPU to read and return the first 32 bytes.     */
    rsip_xfer_init(&x, RSIP_HSM_CMD_DFLASH2_READ);
    x.param[0] = 0u;        /* offset */
    x.param[1] = 32u;       /* length */
    x.rx = s_rx;  x.rx_cap = sizeof(s_rx);
    sts = rsip_host_xfer(&x);
#if (RSIP_CFG_SECURE_ENABLE_DFLASH2_READ != 0u)
    report(10u, (sts == RSIP_HSM_STS_OK) && (x.rx_len == 32u), sts, (uint32_t)s_rx[0]);
#else
    report(10u, (sts == RSIP_HSM_STS_NOT_SUPPORTED), sts, 0u);
#endif
}

/* ------------------------------------------------------------------------- */
uint32_t rsip_test_run_all(void)
{
    const rsip_host_stats_t *hs;
    rsip_hsm_status_t sts;

    g_rsip_test_pass = 0u;
    g_rsip_test_fail = 0u;

    RSIP_LOG("\r\n==== RSIP HSM comm test : host=%s secure=%s msg=%s crc=%u ====\r\n",
             (RSIP_CFG_HOST_NOTIFY_MODE == RSIP_MODE_IRQ) ? "IRQ" : "POLL",
             (RSIP_CFG_SECURE_RX_MODE == RSIP_MODE_IRQ) ? "IRQ" : "POLL",
             (RSIP_CFG_MSG_MODE == RSIP_MSG_TOKEN) ? "TOKEN" : "POINTER",
             RSIP_CFG_USE_CRC);

    sts = rsip_host_init(rsip_test_event_cb);
    if (sts != RSIP_HSM_STS_OK)
    {
        report(0u, 0u, sts, (uint32_t)rsip_host_shm());
        return g_rsip_test_fail;
    }

    if ((RSIP_CFG_TEST_MASK & RSIP_T0_CONFIG) != 0u)    { test_t0_config(); }
    if ((RSIP_CFG_TEST_MASK & RSIP_T1_PING) != 0u)      { test_t1_ping(); }
    if ((RSIP_CFG_TEST_MASK & RSIP_T2_ECHO) != 0u)      { test_t2_echo(); }
    if ((RSIP_CFG_TEST_MASK & RSIP_T3_CRC) != 0u)       { test_t3_crc(); }
    if ((RSIP_CFG_TEST_MASK & RSIP_T4_TRANSFORM) != 0u) { test_t4_transform(); }
    if ((RSIP_CFG_TEST_MASK & RSIP_T5_BURST) != 0u)     { test_t5_burst(); }
    if ((RSIP_CFG_TEST_MASK & RSIP_T6_ERROR) != 0u)     { test_t6_error(); }
    if ((RSIP_CFG_TEST_MASK & RSIP_T7_TIMEOUT) != 0u)   { test_t7_timeout(); }
    if ((RSIP_CFG_TEST_MASK & RSIP_T8_EVENT) != 0u)     { test_t8_event(); }
    if ((RSIP_CFG_TEST_MASK & RSIP_T9_POLICY) != 0u)    { test_t9_policy(); }
    if ((RSIP_CFG_TEST_MASK & RSIP_T10_DFLASH2) != 0u)  { test_t10_dflash2(); }

    hs = rsip_host_get_stats();
    RSIP_LOG("---- PASS %u / FAIL %u | tx=%u rsp=%u irq=%u evt=%u timeout=%u retry=%u stale=%u crcerr=%u\r\n",
             g_rsip_test_pass, g_rsip_test_fail, hs->tx_count, hs->rsp_count, hs->irq_count,
             hs->evt_count, hs->timeout_count, hs->retry_count, hs->stale_rsp_count, hs->crc_err_count);
    return g_rsip_test_fail;
}
