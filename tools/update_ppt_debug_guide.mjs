import fs from "node:fs/promises";
import path from "node:path";
import { FileBlob, PresentationFile } from "@oai/artifact-tool";

const [inputPptx, outputPptx, previewDir] = process.argv.slice(2);
if (!inputPptx || !outputPptx || !previewDir) {
  console.error("Usage: node update_ppt_debug_guide.mjs <input.pptx> <output.pptx> <preview-dir>");
  process.exit(2);
}

await fs.mkdir(previewDir, { recursive: true });

const deck = await PresentationFile.importPptx(await FileBlob.load(inputPptx));

const C = {
  bg: "#F7F8FA",
  ink: "#15171A",
  muted: "#59616D",
  red: "#D74324",
  blue: "#1769AA",
  green: "#16805A",
  line: "#D6DAE1",
  amber: "#B7791F",
  white: "#FFFFFF",
  dark: "#253041",
};
const page = { left: 54, top: 42, width: 1172, height: 618 };

function addText(slide, text, x, y, w, h, opts = {}) {
  const sh = slide.shapes.add({
    geometry: "textbox",
    position: { left: x, top: y, width: w, height: h },
    fill: "none",
    line: { style: "solid", fill: "none", width: 0 },
  });
  sh.text = text;
  sh.text.style = {
    fontSize: opts.size ?? 20,
    bold: opts.bold ?? false,
    color: opts.color ?? C.ink,
    fontFace: opts.font ?? "Malgun Gothic",
    alignment: opts.align ?? "left",
  };
  return sh;
}

function addTitle(slide, section, title, subtitle, slideNo) {
  slide.background.fill = C.bg;
  addText(slide, section, page.left, 28, 360, 28, { size: 16, bold: true, color: C.red });
  addText(slide, title, page.left, 64, 980, 58, { size: 35, bold: true });
  if (subtitle) addText(slide, subtitle, page.left, 118, 1100, 42, { size: 19, color: C.muted });
  slide.shapes.add({
    geometry: "rect",
    position: { left: page.left, top: 158, width: page.width, height: 1 },
    fill: C.line,
    line: { style: "solid", fill: C.line, width: 0 },
  });
  addText(slide, `R-Car U5L RSIP HSM debug guide | ${slideNo}`, page.left, 672, 560, 24, {
    size: 12,
    color: C.muted,
  });
}

function bullet(lines) {
  return lines.map((line) => `• ${line}`).join("\n");
}

function box(slide, x, y, w, h, title, body, color = C.blue) {
  slide.shapes.add({
    geometry: "roundRect",
    position: { left: x, top: y, width: w, height: h },
    fill: C.white,
    line: { style: "solid", fill: C.line, width: 1 },
    borderRadius: "rounded-lg",
  });
  slide.shapes.add({
    geometry: "rect",
    position: { left: x, top: y, width: 7, height: h },
    fill: color,
    line: { style: "solid", fill: color, width: 0 },
  });
  addText(slide, title, x + 22, y + 18, w - 40, 30, { size: 20, bold: true });
  addText(slide, body, x + 22, y + 56, w - 42, h - 66, { size: 16, color: C.muted });
}

function arrow(slide, x1, y1, x2, y2, color = C.dark) {
  slide.shapes.add({
    geometry: "line",
    position: { left: x1, top: y1, width: x2 - x1, height: y2 - y1 },
    line: { style: "solid", fill: color, width: 2, beginArrowType: "none", endArrowType: "triangle" },
    fill: "none",
  });
}

function codeBox(slide, x, y, w, h, text) {
  slide.shapes.add({
    geometry: "roundRect",
    position: { left: x, top: y, width: w, height: h },
    fill: "#111827",
    line: { style: "solid", fill: "#111827", width: 0 },
    borderRadius: "rounded-lg",
  });
  addText(slide, text, x + 22, y + 18, w - 44, h - 30, {
    size: 15,
    color: "#E5E7EB",
    font: "Consolas",
  });
}

let slideNo = deck.slides.items.length + 1;

let slide = deck.slides.add();
addTitle(
  slide,
  "GHS MULTI Debug",
  "Core별 ELF 로드와 디버깅 시작점",
  "두 Cortex-M33 target이 보이면 Host ELF와 RSIP/Secure ELF를 각각의 core에 연결해 심볼을 분리해서 봅니다.",
  slideNo++,
);
box(
  slide,
  80,
  205,
  500,
  260,
  "Host core",
  bullet([
    "Core 0 또는 Host쪽 Cortex-M33 선택",
    "u5l4_startup.out 로드",
    "application_main(), rsip_host_request_led_dimming_irq()에 BP",
    "요청 flag inth2sfs0[4] set 지점까지 진행",
  ]),
  C.blue,
);
box(
  slide,
  700,
  205,
  430,
  260,
  "RSIP / Secure core",
  bullet([
    "Core 1 또는 RSIP쪽 Cortex-M33 선택",
    "secure_cpu.out 로드",
    "secure_cpu_main(), RSIP_INTH2S0_Handler()에 BP",
    "wfi 대기 후 IRQ34 진입 확인",
  ]),
  C.green,
);
codeBox(
  slide,
  105,
  515,
  1010,
  74,
  "Host ELF   : output\\objs\\u5l4_startup.out\nRSIP ELF   : output\\objs\\secure_cpu.out\nConnection : E2_U5L4_RSIP_20M 또는 E2_U5L4_RSIP_20M_SWBP_FLASH",
);

slide = deck.slides.add();
addTitle(
  slide,
  "Breakpoint Flow",
  "BP를 사이에 둔 Host↔RSIP 왕복 관찰 순서",
  "아래 네 지점이 순서대로 걸리면 interrupt 기반 handoff가 정상 동작하는 것입니다.",
  slideNo++,
);
box(slide, 58, 214, 255, 180, "1. Host request", "rsip_host_request_led_dimming_irq()\n\n공유 블록 작성 후\ninth2sfs0[4] set", C.blue);
box(slide, 363, 214, 255, 180, "2. RSIP IRQ", "RSIP_INTH2S0_Handler()\n\nIRQ34로 진입,\n요청 flag 확인", C.green);
box(slide, 668, 214, 255, 180, "3. RSIP approve", "secure_approve_led_dimming()\n\nmagic/version/command,\n파라미터 range 검증", C.green);
box(slide, 973, 214, 235, 180, "4. Host complete", "ISR_INTS2H0()\n\nstatus OK 수신 후\napproved event", C.red);
arrow(slide, 318, 304, 358, 304);
arrow(slide, 623, 304, 663, 304);
arrow(slide, 928, 304, 968, 304);
codeBox(
  slide,
  92,
  470,
  1040,
  88,
  "Debug order: Host run → request BP hit → RSIP core로 전환 → IRQ34 BP hit → Host core로 복귀 → INTS2H0 BP hit → led_dimming_run() 확인\nRecommended extra BP: led_dimming_run(), secure_process_host_request()",
);

slide = deck.slides.add();
addTitle(
  slide,
  "Core Switching",
  "MULTI에서 core를 왔다갔다 보며 확인하는 방법",
  "Target tree에서 Core 0/Core 1을 클릭해 active target을 바꾸면 소스, register, call stack view가 해당 core 기준으로 전환됩니다.",
  slideNo++,
);
box(
  slide,
  80,
  190,
  330,
  300,
  "Run/Halt 운용",
  bullet([
    "처음에는 두 core 모두 halt/reset 상태로 시작",
    "RSIP는 secure_cpu_main() → wfi까지 진행",
    "Host를 run해서 요청 BP까지 진행",
    "필요 시 한 core만 step, 상대 core는 run 가능 상태 유지",
  ]),
  C.amber,
);
box(
  slide,
  475,
  190,
  330,
  300,
  "Watch 항목",
  bullet([
    "Host: g_rsip_shared, g_rsip_hsm_event",
    "Host: inth2sfs0, ints2hfc0",
    "RSIP: shared->status, param0~3",
    "RSIP: inth2sf0, inth2sfc0, ints2hfs0",
  ]),
  C.blue,
);
box(
  slide,
  870,
  190,
  330,
  300,
  "정상 판정",
  bullet([
    "Host request BP 다음 RSIP IRQ BP hit",
    "RSIP status가 RSIP_HSM_STS_OK",
    "RSIP completion 뒤 Host ISR BP hit",
    "마지막에 led_dimming_run() 진입",
  ]),
  C.green,
);
addText(
  slide,
  "주의: RSIP core가 halt 상태로 멈춰 있으면 Host가 interrupt flag를 세워도 handoff가 보이지 않을 수 있습니다.",
  95,
  548,
  1040,
  42,
  { size: 20, bold: true, color: C.red },
);

const startRender = Math.max(0, deck.slides.items.length - 3);
for (let i = startRender; i < deck.slides.items.length; i += 1) {
  const rendered = await deck.export({ slide: deck.slides.items[i], format: "png", scale: 1 });
  const stem = `slide-${String(i + 1).padStart(2, "0")}`;
  await fs.writeFile(path.join(previewDir, `${stem}.png`), new Uint8Array(await rendered.arrayBuffer()));
  const layout = await deck.slides.items[i].export({ format: "layout" });
  await fs.writeFile(path.join(previewDir, `${stem}.layout.json`), await layout.text(), "utf8");
}

const montage = await deck.export({ format: "webp", montage: true, scale: 1 });
await fs.writeFile(path.join(previewDir, "final-montage.webp"), new Uint8Array(await montage.arrayBuffer()));

const pptx = await PresentationFile.exportPptx(deck);
await pptx.save(outputPptx);
console.log(outputPptx);
