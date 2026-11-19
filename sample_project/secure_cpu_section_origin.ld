MEMORY
{
  SECURE_CODE : ORIGIN = 0x00010000, LENGTH = 0x00010000
  SECURE_RAM  : ORIGIN = 0x200E0000, LENGTH = 0x00008000
}

DEFAULTS {
  secure_stack_reserve = 4K
}

SECTIONS
{
  .isr_vector align(512) :>SECURE_CODE
  .text       align(4)   :>.
  .rodata     align(4)   :>.
  .ROM.data   ROM(.data) align(4) :>.

  .data       align(4)   :>SECURE_RAM
  .bss        align(4)   :>.
  .stack      align(8) pad(secure_stack_reserve) :>.

  __secure_vector_base = ADDR(.isr_vector);
  __secure_stack_top = MEMENDADDR(SECURE_RAM);
  __secure_data_rom_addr = ADDR(.ROM.data);
  __secure_data_ram_addr = ADDR(.data);
  __secure_data_size = SIZEOF(.data);

  __ghs_ramstart = MEMADDR(SECURE_RAM);
  __ghs_ramend   = MEMENDADDR(SECURE_RAM);
  __ghs_romstart = MEMADDR(SECURE_CODE);
  __ghs_romend   = MEMENDADDR(SECURE_CODE);
}
