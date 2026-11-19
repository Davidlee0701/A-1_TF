/*
 * interrupt_functions.c
 *
 *  Created on: 06.02.2025
 *      Author: a5105882
 */
//#include <RCar_U5L_UM_rev0.40_noRSIP_ver1.0.h>
#include <U5L_common_types.h>
#include <cpu_ss_workaround.h>
#include <interrupt_functions.h>

#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */
#define SCS_BASE            (0xE000E000UL)                             /*!< System Control Space Base Address */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                     /*!< NVIC Base Address */
#define NVIC                ((NVIC_Type      *)     NVIC_BASE        ) /*!< NVIC configuration struct */
 
typedef struct
{
  __IOM uint32_t ISER[16U];              /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[16U];
  __IOM uint32_t ICER[16U];              /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RSERVED1[16U];
  __IOM uint32_t ISPR[16U];              /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[16U];
  __IOM uint32_t ICPR[16U];              /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[16U];
  __IOM uint32_t IABR[16U];              /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32_t RESERVED4[16U];
  __IOM uint32_t ITNS[16U];              /*!< Offset: 0x280 (R/W)  Interrupt Non-Secure State Register */
        uint32_t RESERVED5[16U];
  __IOM uint8_t  IPR[496U];              /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
        uint32_t RESERVED6[580U];
  __OM  uint32_t STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_Type;


void NVIC_ENABLE_IRQ(int32_t channel_nr){
    if ( channel_nr < 0 )
        return;

    NVIC->ISER[(((uint32_t)channel_nr) >> 5UL)] |= (uint32_t)(1UL << (((uint32_t)channel_nr) & 0x1FUL));
}

void NVIC_DISABLE_IRQ(int32_t channel_nr){
    if ( channel_nr < 0 )
        return;

    NVIC->ISER[(((uint32_t)channel_nr) >> 5UL)] &= ~(uint32_t)(1UL << (((uint32_t)channel_nr) & 0x1FUL));
}

void CONFIG_MASK_IMFU(IMFU_TYPE_E type, IMFU_GROUP_E group, IMFU_BIT_ASSIGNMENT_E bit, IMFU_MASK_STATUS_E status){
    volatile u32_T* msk;
    switch(type){
        case IMFU_PULSE:
            msk = (u32_T*) ((u32_T)IMFU0_BASE + 0x1004 + ((u32_T)0x10 * (u32_T)group));
            break;
        case IMFU_LEVEL:
            msk = (u32_T*) ((u32_T)IMFU0_BASE + 0x0004 + ((u32_T)0x10 * (u32_T)group));
            break;
        default:
            return;
    }

    switch (status){
        case IMFU_MASKED:
            set_bit_u32(msk, (u32_T)bit);
            break;
        case IMFU_UNMASKED:
            clear_bit_u32(msk, (u32_T)bit);
            break;
        default:
            return;
    }
    return;
}

void CLEAR_IMFU_PULSE(IMFU_GROUP_E group, IMFU_BIT_ASSIGNMENT_E bit){

    volatile u32_T* pcr = (u32_T*) ((u32_T)IMFU0_BASE + 0x1008 + ((u32_T)0x10 * (u32_T)group));
    set_bit_u32(pcr, (u32_T)bit);
    WA( *pcr );
    return;
}

u32_T GET_IMFU_STATUS(IMFU_TYPE_E type, IMFU_GROUP_E group){
    volatile u32_T* f;
    switch(type){
        case IMFU_PULSE:
            f = (u32_T*) ((u32_T)IMFU0_BASE + 0x1000 + ((u32_T)0x10 * (u32_T)group));
            break;
        case IMFU_LEVEL:
            f = (u32_T*) ((u32_T)IMFU0_BASE + 0x0000 + ((u32_T)0x10 * (u32_T)group));
            break;
        default:
            return 0;
    }
    return ( WA(*f) & 0xFF );
}

u32_T GET_IMFU_STATUS_UNMASKED(IMFU_TYPE_E type, IMFU_GROUP_E group){

    volatile u32_T* msk;
    switch(type){
        case IMFU_PULSE:
            msk = (u32_T*) ((u32_T)IMFU0_BASE + 0x1004 + ((u32_T)0x10 * (u32_T)group));
            break;
        case IMFU_LEVEL:
            msk = (u32_T*) ((u32_T)IMFU0_BASE + 0x0004 + ((u32_T)0x10 * (u32_T)group));
            break;
        default:
            return 0;
    }

    u32_T imfu_status = GET_IMFU_STATUS(type, group);
    return ( imfu_status & ~( WA(*msk) & 0xFF ) );

}

void NVIC_SETPENDING(int32_t channel_nr){
    if ((int32_t)(channel_nr) >= 0)
      {
        NVIC->ISPR[(((uint32_t)channel_nr) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)channel_nr) & 0x1FUL));
      }
}

void NVIC_ClearPendingIRQ(int32_t IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC->ICPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}

uint32_t NVIC_GetPendingIRQ(int32_t IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((NVIC->ISPR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
