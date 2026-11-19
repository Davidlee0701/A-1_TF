/*******************************************************************************
* Warranty Disclaimer :
*
* Because the Product(s) is licensed free of charge, there is no warranty of
* any kind whatsoever and expressly disclaimed and excluded by Renesas, either
* expressed or implied, including but not limited to those for non-infringement
* of intellectual property, merchantability and/or fitness for the particular
* purpose. Renesas shall not have any obligation to maintain, service or provide
* bug fixes for the supplied Product(s) and/or the Application.
*
* Each User is solely responsible for determining the appropriateness of using
* the Product(s) and assumes all risks associated with its exercise of rights
* under this Agreement, including, but not limited to the risks and costs of
* program errors, compliance with applicable laws, damage to or loss of data,
* programs or equipment, and unavailability or interruption of operations.
*
* Limitation of Liability :
*
* In no event shall Renesas be liable to the User for any incidental,
* consequential, indirect, or punitive damage (including but not limited to
* lost profits) regardless of whether such liability is based on breach of
* contract, tort, strict liability, breach of warranties, failure of essential
* purpose or otherwise and even if advised of the possibility of such damages.
* Renesas shall not be liable for any services or products provided by third
* party vendors, developers or consultants identified or referred to the User
* by Renesas in connection with the Product(s) and/or the Application.
*
* Copyright (C) 2024 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/******************************************************************************
* File Name   : set_csa.c
* Version     : 0.04
* Device(s)   : R-Car U5L4
* Description : This is the CSA (Configuration Setting Area) code for U5L4
*             : Each section must be programmed to the following address.
*             :
*             : Section Name          Address     
*             : --------------------------------------------------------
*             : CSA_OFFSET_0x200      0x4012_1200 (<CSAb_base> + 0x0200)
*             : CSA_OFFSET_0x300      0x4012_1300 (<CSAb_base> + 0x0300)
*             : RSIP_OPTION_BYTES     0x4012_2700 (<SSAb_base> + 0x0700, RSIP_OPBT0 to RSIP_OPBT7)
*             :
*******************************************************************************
* History     : DD.MM.YYYY Version Description
*             : 30.11.2024 0.01    First Relase
*             : 31.12 2024 0.02    Add GNU ARM version
*             : 13.11.2026 0.03    Fix RSIP_OPTION_BYTES address: 0x4012_1700 -> 0x4012_2700
*             :                    (RSIP_OPBTn are in Security Setting Area <SSAk_base>+0x0700,
*             :                     back side <SSAb_base> = 0x4012_2000)
*             : 13.11.2026 0.04    RSIP_OPBT3 (RSIPRAD) 0x00000000 -> 0x400C0000
*             :                    (valid values: 0x400C0000 = Data Area 2 secure, 0xFFFFFFFF = none)
******************************************************************************/

#if defined(__GHS__)
#pragma ghs section rodata="CSA_OFFSET_0x200"
const unsigned long CSA_OFFSET_0x200_to_0x21F[] =
#elif defined(__GNU__ARM__)
const unsigned long CSA_OFFSET_0x200_to_0x21F[] __attribute__ ((section ("CSA_OFFSET_0x200"))) =
#endif
{
//  Setting Value,     Value at the shipping,     Address,               Name,                                       Comment
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0200,   OTP Setting of Configuration setting Area
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0204,   OTP Setting of Configuration setting Area
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0208,   OTP Setting of Configuration setting Area
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x020C,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0210,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0214,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0218,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x021C,   Reserved (need to be programmed)
};

#if defined(__GHS__)
#pragma ghs section rodata="CSA_OFFSET_0x300"
const unsigned long CSA_OFFSET_0x300_to_0x47F[] =
#elif defined(__GNU__ARM__)
const unsigned long CSA_OFFSET_0x300_to_0x47F[] __attribute__ ((section ("CSA_OFFSET_0x300"))) =
#endif
{
//  Setting Value,     Value at the shipping,     Address,               Name,                                       Comment
    0x00000000,      //0x00000000,                <CSAb_base> +0x0300,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0304,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0308,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x030C,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0310,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0314,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0318,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x031C,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0320,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0324,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0328,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x032C,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0330,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0334,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0338,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x033C,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0340,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0344,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0348,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x034C,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0350,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0354,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0358,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x035C,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0360,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0364,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0368,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x036C,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0370,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0374,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x0378,   Software Configuration Option Byte
    0x00000000,      //0x00000000,                <CSAb_base> +0x037C,   Software Configuration Option Byte
    
    0x00000000,      //0x00000000,                <CSAb_base> +0x0380,   Vector Table Base Address(CPU0)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0384,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0388,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x038C,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0390,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0394,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0398,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x039C,   Reserved (need to be programmed)
    
    0x3FE30010,      //0x3FE30010,                <CSAb_base> +0x03A0,   Option byte 0 (OPBT0)
    0xFE7B0000,      //0xFE7B0000,                <CSAb_base> +0x03A4,   Option byte 1 (OPBT1)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03A8,   Reserved (need to be programmed)
    0xFFFFFFFD,      //0xFFFFFFFF,                <CSAb_base> +0x03AC,   Option byte 3 (OPBT3)               [Modified] (STMSEL=0)
    0xFCFFFFFF,      //0xFCFFFFFF,                <CSAb_base> +0x03B0,   Option byte 4 (OPBT4)
    0xFFFFE7FF,      //0xFFFFE7FF,                <CSAb_base> +0x03B4,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03B8,   Option byte 6 (OPBT6)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03BC,   Reserved (need to be programmed)
    0xF9FFFFFF,      //0xF9FFFFFF,                <CSAb_base> +0x03C0,   Option byte 8 (OPBT8)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03C4,   Reserved (need to be programmed)
    0xFAFFFCCA,      //0xFAFFFCCA,                <CSAb_base> +0x03C8,   Option byte 10 (OPBT10)
    0xEFFFFFFF,      //0xEFFFFFFF,                <CSAb_base> +0x03CC,   Option byte 11 (OPBT11)
    0xFFFFFFFD,      //0xFFFFFFFD,                <CSAb_base> +0x03D0,   Option byte 12 (OPBT12)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03D4,   Option byte 13 (OPBT13)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03D8,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03DC,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03E0,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03E4,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03E8,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03EC,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03F0,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03F4,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03F8,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x03FC,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0400,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0404,   Reserved (need to be programmed)
    0xFFFF0010,      //0xFFFF0010,                <CSAb_base> +0x0408,   Option byte 26 (OPBT26)
    0xFFFF0000,      //0xFFFF0000,                <CSAb_base> +0x040C,   Option byte 27 (OPBT27)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0410,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0414,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0418,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x041C,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0420,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0424,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0428,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x042C,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0430,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0434,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0438,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x043C,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0440,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0444,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0448,   Option byte 42 (OPBT42)
    0x2B01B824,      //0x2B01B824,                <CSAb_base> +0x044C,   Option byte 43 (OPBT43)
    0x2C000000,      //0x2C000000,                <CSAb_base> +0x0450,   Option byte 44 (OPBT44)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0454,   Option byte 45 (OPBT45)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0458,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x045C,   Option byte 47 (OPBT47)
    
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0460,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0464,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0468,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x046C,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0470,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0474,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x0478,   Reserved (need to be programmed)
    0xFFFFFFFF,      //0xFFFFFFFF,                <CSAb_base> +0x047C,   Reserved (need to be programmed)
};

#if defined(__GHS__)
#pragma ghs section rodata="RSIP_OPTION_BYTES"
const unsigned long RSIP_OPBT0_to_RSIP_OPBT7[] =
#elif defined(__GNU__ARM__)
const unsigned long RSIP_OPBT0_to_RSIP_OPBT7[] __attribute__ ((section ("RSIP_OPTION_BYTES"))) =
#endif
{
//  Setting Value,     Value at the shipping,     Address,               Name,                                       Comment
    0x0FFFFFFF,      //0xFFFFFFFF,                <SSAk_base> +0x0700,   RSIP_OPBT0                                  RSIPON=0: RSIP-M30A On
    0x00010000,      //0xFFFFFFFF,                <SSAk_base> +0x0704,   RSIP_OPBT1                                  RSIPRESV Secure CPU firmware vector table base
    0x00010000,      //0xFFFFFFFF,                <SSAk_base> +0x0708,   RSIP_OPBT2                                  RSIPRACS0 secure code flash start
    0x400C0000,      //0xFFFFFFFF,                <SSAk_base> +0x070C,   RSIP_OPBT3                                  RSIPRAD = Data Area 2 start: 0x400C_0000-0x400C_FFFF RSIP only
    0xFFFFBFDF,      //0xFFFFBFEF,                <SSAk_base> +0x0710,   RSIP_OPBT4                                  C&R skipped, SM3/SM4 enabled, WDTA software trigger
    0x00020000,      //0xFFFFFFFF,                <SSAk_base> +0x0714,   RSIP_OPBT5                                  RSIPRACE0 secure code flash end boundary
    0xFFFFFFFF,      //0xFFFFFFFF,                <SSAk_base> +0x0718,   RSIP_OPBT6                                  Region 1 disabled
    0xFFFFFFFF,      //0xFFFFFFFF,                <SSAk_base> +0x071C,   RSIP_OPBT7                                  Region 1 disabled
};

#if __GHS__
#pragma ghs section rodata=default
#else
#pragma section default
#endif

