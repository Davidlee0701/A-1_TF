/*===========================================================================*/
/* Warranty Disclaimer                                                       */
/*                                                                           */
/* Because the Product(s) is licensed free of charge, there is no warranty   */
/* of any kind whatsoever and expressly disclaimed and excluded by Renesas,  */
/* either expressed or implied, including but not limited to those for       */
/* non-infringement of intellectual property, merchantability and/or         */
/* fitness for the particular purpose. Renesas shall not have any obligation */
/* to maintain, service or provide bug fixes for the supplied Product(s)     */
/* and/or the Application.                                                   */
/*                                                                           */
/* Each User is solely responsible for determining the appropriateness of    */
/* using the Product(s) and assumes all risks associated with its exercise   */
/* of rights under this Agreement, including, but not limited to the risks   */
/* and costs of program errors, compliance with applicable laws, damage to   */
/* or loss of data, programs or equipment, and unavailability or             */
/* interruption of operations.                                               */
/*                                                                           */
/* Limitation of Liability                                                   */
/*                                                                           */
/* In no event shall Renesas be liable to the User for any incidental,       */
/* consequential, indirect, or punitive damage (including but not limited    */
/* to lost profits) regardless of whether such liability is based on breach  */
/* of contract, tort, strict liability, breach of warranties, failure of     */
/* essential purpose or otherwise and even if advised of the possibility of  */
/* such damages. Renesas shall not be liable for any services or products    */
/* provided by third party vendors, developers or consultants identified or  */
/* referred to the User by Renesas in connection with the Product(s) and/or  */
/* the Application.                                                          */
/*                                                                           */
/*===========================================================================*/

CONSTANTS
{

}

MEMORY
{
  CFLASH_USER_AREA0             : ORIGIN = 0x00000000,                  LENGTH = 0x00010000   /* Block 0-3 : host vector table / startup */
  CFLASH_SECURE_CODE_RSVD       : ORIGIN = 0x00010000,                  LENGTH = 0x00010000   /* Block 4-7 : RSIP-M Secure CPU code (secure_cpu_section.ld SECURE_CODE, RSIP_OPBT2/5) - host must not use */
  CFLASH_USER_AREA0_MAIN        : ORIGIN = 0x00020000,                  LENGTH = 0x001E0000   /* Block 8-37 : host program */
  CFLASH_USER_AREA0_END         : ORIGIN = .         ,                  LENGTH = 0

  CFLASH_USER_AREA1             : ORIGIN = 0x00400000,                  LENGTH = 0x00200000   /* U5L4 User Area 1 = 2MB */
  CFLASH_USER_AREA1_END         : ORIGIN = .         ,                  LENGTH = 0

  CFLASH_USER_BOOT_AREA0        : ORIGIN = 0x08000000,                  LENGTH = 0x00010000
  CFLASH_USER_BOOT_AREA0_END    : ORIGIN = .         ,                  LENGTH = 0
 
  CFLASH_USER_BOOT_AREA1        : ORIGIN = 0x08400000,                  LENGTH = 0x00010000
  CFLASH_USER_BOOT_AREA1_END    : ORIGIN = .         ,                  LENGTH = 0

  CPU_RAM_SELF                  : ORIGIN = 0x200E0000,                  LENGTH = 0x00020000
  CPU_RAM_SELF_END              : ORIGIN = .         ,                  LENGTH = 0

  CPU_RAM_CPU0                  : ORIGIN = 0x204E0000,                  LENGTH = 0x0001F000   /* 0x204E0000-0x204FEFFF host data/bss/stack */
  CPU_RAM_CPU0_END              : ORIGIN = .         ,                  LENGTH = 0
  RSIP_SHARED_RAM               : ORIGIN = 0x204FF000,                  LENGTH = 0x00001000   /* Host<->RSIP shared memory (rsip_hsm_shm_t) = RSIP_SHM_ADDR */

  GRAM                          : ORIGIN = 0x28000000,                  LENGTH = 0x000B0000
  GRAM_END                      : ORIGIN = .         ,                  LENGTH = 0

  RETENTION_RAM                 : ORIGIN = 0x2C000000,                  LENGTH = 0x00008000
  RETENTION_RAM_END             : ORIGIN = .         ,                  LENGTH = 0

  CSA1                          : ORIGIN = 0x40121200,                  LENGTH = 0x00000020	/* OTP and Reserved (need to be programmed) */
  CSA2                          : ORIGIN = 0x40121300,                  LENGTH = 0x00000180	/* Vector Table Base Address, OPBT, and Reserved (need to be programmed) */
  RSIP_OPTION_BYTES              : ORIGIN = 0x40122700,                  LENGTH = 0x00000020  /* RSIP_OPBT0-7 : <SSAb_base>(0x40122000) + 0x700 */

  /* Data Area 2 (0x400C0000-0x400CFFFF) : RSIP-M only (RSIP_OPBT3 RSIPRAD = 0x400C0000) - host must not place data here */

}

DEFAULTS {
  stack_reserve = 8K
}

SECTIONS
{

  /* -----------------------------------------------------------------------------------------*/
  /* Start of internal ROM area (CFLASH0)                                                     */
  /* -----------------------------------------------------------------------------------------*/
  .start.CFLASH_USER_AREA0                              :>CFLASH_USER_AREA0
  .isr_vector /*align(1024)*/                               :>.            /* vector table  */
  .application_vectors					:>.
  .text       align(1024)                               :>CFLASH_USER_AREA0_MAIN /* program code area (0x00020000~, skips Secure CPU code 0x00010000-0x0001FFFF) */
  
  .fixaddr    align(4)                                  :>.            /* ghs internal (compiler) */
  .fixtype    align(4)                                  :>.            /* ghs internal (compiler) */
  .secinfo    align(4)                                  :>.            /* ghs internal (runtime library) */
  .syscall    align(4)					:>.
  
  .rodata     align(4)                                  :>.            /* constant datas in normal area */
  .ROM.data   ROM(.data)  align(4)                      :>.            /* constant data to initialize variables (copied to RAM at startup)*/
  .ROM.sdata  ROM(.sdata) align(4)                      :>.            /* constant data to initialize variables (copied to RAM at startup)*/
  
  .end.CFLASH_USER_AREA0                                :>CFLASH_USER_AREA0_END


  /* -----------------------------------------------------------------------------------------*/
  /* Start of internal RAM area (CPU RAM self)                                                */
  /* -----------------------------------------------------------------------------------------*/

  /* -----------------------------------------------------------------------------------------*/
  /* Start of internal RAM area (CPU RAM CPU0)                                                       */
  /* -----------------------------------------------------------------------------------------*/
  .start.CPU_RAM_CPU0                                   :>CPU_RAM_CPU0
  .data        align(4)                                 :>.            /* initialized data */
  .bss         align(4)                                 :>.            /* zero initialized data */
  .sda_start   align(4)                                 :>.            /* initialize globalpointer GP for SDA addressing */
  .sda_base    align(4)                                 :>.            
  .sdata       align(4)                                 :>.            /* initialized data in SDA area*/
  .sbss        align(4)                                 :>.            /* zero initialized data in SDA area*/
  .sda_end     align(4)                                 :>.            /* end of SDA addressing */

  .stack       align(4) pad(stack_reserve)              :>.            /* stack area (for PE0)*/

//  .heap        align(4) /*pad(USR_HEAP_RESERVED)*/ 	:
//  {
//    _heap_start = .;
//    . += 2k;
//    _heap_end  = .;    
//  } >.
  
  .end.CPU_RAM_CPU0                                     :>CPU_RAM_CPU0_END

  /* Host <-> RSIP shared memory : fixed address 0x204FF000 (TOKEN mode) */
  .rsip_shared align(32)                                :>RSIP_SHARED_RAM

  /* -----------------------------------------------------------------------------------------*/
  /*  Global RAM                                                                              */
  /* -----------------------------------------------------------------------------------------*/
  .heap        align(4) /*pad(USR_HEAP_RESERVED)*/ 	:
  {
    _heap_start = .;
    . += 2k;
    _heap_end = .;
  } >GRAM
  
  /* -----------------------------------------------------------------------------------------*/
  /*  Retention RAM                                                                           */
  /* -----------------------------------------------------------------------------------------*/

  /* -----------------------------------------------------------------------------------------*/
  /* Start of internal ROM area (DFLASH)                                                      */
  /* -----------------------------------------------------------------------------------------*/
  CSA_OFFSET_0x200 align(4)                             :>CSA1         	/* OTP and Reserved (need to be programmed) */
  CSA_OFFSET_0x300 align(4)                             :>CSA2          /* Vector Table Base Address, OPBT, and Reserved (need to be programmed) */
  RSIP_OPTION_BYTES align(4)                            :>RSIP_OPTION_BYTES


  /* -----------------------------------------------------------------------------------------*/
  /*  Symbols for compiler references                                                         */
  /* -----------------------------------------------------------------------------------------*/

  __DATA_ROM_ADDR    =  ADDR(.ROM.data);
  __DATA_RAM_ADDR    =  ADDR(.data);
  __DATA_RAM_SIZE    =  SIZEOF(.data);

  __SDATA_ROM_ADDR   =  ADDR(.ROM.sdata);
  __SDATA_RAM_ADDR   =  ADDR(.sdata);
  __SDATA_RAM_SIZE   =  SIZEOF(.sdata);


  __ghs_ramstart  = MEMADDR(CPU_RAM_SELF);
  __ghs_ramend    = MEMENDADDR(RETENTION_RAM_END);
  __ghs_romstart  = MEMADDR(CFLASH_USER_AREA0);
  __ghs_romend    = MEMENDADDR(CFLASH_USER_BOOT_AREA1_END);  
}

/*===========================================================================*/
/*      End of File                                                          */
/*===========================================================================*/
