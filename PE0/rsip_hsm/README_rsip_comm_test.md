# Host ↔ RSIP(HSM) 통신 샘플 (U5L4, GHS MULTI)

## 1. 구성

| 위치 | 파일 | 역할 |
|---|---|---|
| 공통 | `PE0/rsip_hsm/rsip_hsm_cfg.h` | 빌드 옵션 (IRQ/POLL, TOKEN/POINTER, CRC, Timeout, Test mask …) |
| 공통 | `PE0/rsip_hsm/rsip_hsm_cmd.h` | 프로토콜 v2 : 명령/상태 코드, 공유메모리 구조체, CMDREG 레지스터, CRC32 |
| Host | `PE0/rsip_hsm/rsip_hsm_host.c` | 메일박스 드라이버 : `rsip_host_init / xfer / service`, `ISR_INTS2H0` |
| Host | `PE0/rsip_hsm/rsip_hsm_test.c` | 테스트 시나리오 T0–T10, 결과표 `g_rsip_test_report[]` |
| Host | `PE0/PE0/application_code.c` | `application_main()` : UART 초기화 → 테스트 → LED 결과 → HSM 승인 LED dimming |
| Secure | `sample_project/secure_cpu_main.c` | 명령 디스패처, IRQ34 핸들러, 이벤트 송신, 통계 |
| Secure | `sample_project/secure_cpu_start.arm` | SP 설정, .data 복사, .bss 클리어, VTOR 설정 |
| Secure | `sample_project/secure_cpu_section.ld` | Secure 코드 0x0001_0000 / S-TCM 0x3FE0_0000 / Data Area 2 |
| Host | `section.ld` (= `sample_project/section.ld`) | Host 코드 0x0002_0000~, 공유메모리 0x204F_F000 고정 |
| Host | `PE0/set_csa.c` v0.04 | RSIP_OPTION_BYTES 0x4012_2700, RSIPRAD = 0x400C_0000 |

## 2. 메모리 배치

| 영역 | 주소 | Host | RSIP |
|---|---|---|---|
| Host 벡터/스타트업 | 0x0000_0000–0x0000_FFFF (Block 0–3) | RX | – |
| Secure CPU 코드 | 0x0001_0000–0x0001_FFFF (Block 4–7, RSIPRACS0/RACE0) | 접근 불가 | RX |
| Host 프로그램 | 0x0002_0000–0x001F_FFFF (Block 8–37) | RX | – |
| Host data/bss/stack | 0x204E_0000–0x204F_EFFF | RW | – |
| **공유메모리** | **0x204F_F000–0x204F_FFFF** (`rsip_hsm_shm_t`, 704B 사용) | RW | RW |
| Secure RAM (S-TCM) | 0x3FE0_0000–0x3FE1_7FFF | 접근 불가 | RW |
| Data Area 2 | 0x400C_0000–0x400C_FFFF (RSIPRAD) | 접근 불가 | R (FACI2로 P/E) |
| CMDREG | Host 0x5CFF_E000 / Secure 0x5FFF_E000 (+0x200 ch0) | RW | RW |

## 3. 프로토콜

* Doorbell H→S (`INTH2SFS0`) : bit0 REQ(IRQ34), bit1 ABORT, bit2 EVT_ACK
* Doorbell S→H (`INTS2HFS0`) : bit0 RSP, bit1 EVT (둘 다 Host IRQ95 `INTS2H0`)
* `MSGH2S0` : TOKEN 모드 `(seq<<16)|(cmd<<8)|0xA5`, POINTER 모드 공유메모리 주소
* `MSGS2H0` : `(seq<<16)|status`, 초기화 직후 `0x52445921 ("RDY!")`
* 공유메모리 : req_hdr+req_data(256B) / rsp_hdr+rsp_data(256B) / evt_hdr+evt_data(32B)
* 헤더 : magic, version, cmd, seq, status, len, crc(CRC32), flags, param[4]

## 4. 옵션 (`rsip_hsm_cfg.h` 또는 gpj에 `-D`)

| 옵션 | 기본값 | 설명 |
|---|---|---|
| `RSIP_CFG_HOST_NOTIFY_MODE` | IRQ | Host 응답 수신 : IRQ95 ISR / 폴링 |
| `RSIP_CFG_SECURE_RX_MODE` | IRQ | Secure 요청 수신 : IRQ34 ISR / 메인루프 폴링 |
| `RSIP_CFG_MSG_MODE` | TOKEN | 고정주소+토큰 / 포인터 전달(범위검사) |
| `RSIP_CFG_USE_CRC` | 1 | payload CRC32 |
| `RSIP_CFG_TIMEOUT_LOOPS` | 2,000,000 | 트랜잭션 대기 루프 |
| `RSIP_CFG_RETRY_COUNT` | 1 | TIMEOUT/CRC 오류 재전송 횟수 |
| `RSIP_CFG_TEST_MASK` | T0–T9 | 실행할 시나리오 (T10은 Data Area 2 프로그램 후 활성화) |
| `RSIP_CFG_SECURE_ENABLE_DFLASH2_READ` | 0 | Secure의 Data Area 2 읽기 허용 |
| `RSIP_CFG_LOG_UART` | 1 | RLIN3_1 (P0_5/P0_4) 115200bps 로그 |
| `RSIP_CFG_RUN_LED_DIMMING_DEMO` | 1 | 테스트 후 HSM 승인 LED dimming |

Host 와 Secure 프로젝트는 같은 헤더를 쓰므로 **옵션은 두 프로젝트에 동일하게** 넣어야 합니다
(단, `HOST_NOTIFY_MODE` 는 Host 만, `SECURE_RX_MODE` 는 Secure 만 영향).

## 5. 테스트 시나리오

| ID | 내용 | PASS 조건 |
|---|---|---|
| T0 | 공유메모리 주소 / Secure READY 토큰 | `&shm == 0x204FF000`, READY 또는 PING OK |
| T1 | PING | fw ver, `~param0` 일치 |
| T2 | ECHO 1/4/16/64/256B | 데이터·길이 일치 |
| T3 | CRC32 | Secure 계산 CRC == Host 계산 CRC |
| T4 | TRANSFORM (반전+역순) | 바이트 단위 검증 |
| T5 | BURST 100회 × 64B | 100/100 성공, 평균 cycle |
| T6 | 오류 처리 | BAD_CMD / BAD_PARAM / CRC_ERROR 후 PING OK |
| T7 | Timeout → ABORT → 지연응답 회수 → PING | 늦은 응답 seq 일치 & ABORTED, 복구 |
| T8 | Secure → Host 비동기 이벤트 8개 | 이벤트 값 순서 일치, EVT_ACK 흐름제어 |
| T9 | HSM 정책(LED dimming) 승인/거부 | 64 승인, 200 거부(DENIED) |
| T10 | Data Area 2 읽기 (옵션) | 활성화 시 32B 읽기 OK, 비활성 시 NOT_SUPPORTED |

결과 : MULTI Watch `g_rsip_test_report`, `g_rsip_test_pass/fail`, UART 로그,
AP0_0 LED (전체 PASS = 느린 점멸 3회, FAIL = 빠른 점멸 10회).

## 6. 디버그 연결

`default.gpj` 를 열고 `E2_U5L_20M.con` 의 RSIP 대응 연결
(`E2_U5L4_RSIP_20M_SWBP_FLASH`)을 사용합니다. Host-only 연결은 Secure CPU 디버그 연결을 만들지 않습니다.
옵션바이트(CSA/SSA/RSIP_OPBT)는 E2로 쓰지 말고 rfp-cli 커맨드 모드로 기록합니다.
