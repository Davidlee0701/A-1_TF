/*
 * interrupt_functions.h
 *
 *  Created on: 06.02.2025
 *      Author: a5105882
 */

#ifndef MACRO_INTERRUPTS_INTERRUPT_FUNCTIONS_H_
#define MACRO_INTERRUPTS_INTERRUPT_FUNCTIONS_H_

#include <interrupt_data.h>
#include <stdint.h>
#include <U5L_common_types.h>
//#include <ree_types.h>
#include <stddef.h>

#define IMFU0_BASE 0x5CE80000

//extern vector_func my_vector_table[198];

extern void NVIC_ENABLE_IRQ(int32_t channel_nr);
extern void NVIC_DISABLE_IRQ(int32_t channel_nr);
extern void NVIC_SETPENDING(int32_t channel_nr);
extern void CONFIG_MASK_IMFU(IMFU_TYPE_E type, IMFU_GROUP_E group, IMFU_BIT_ASSIGNMENT_E bit, IMFU_MASK_STATUS_E status);
extern void CLEAR_IMFU_PULSE(IMFU_GROUP_E group, IMFU_BIT_ASSIGNMENT_E bit);
extern u32_T GET_IMFU_STATUS(IMFU_TYPE_E type, IMFU_GROUP_E group);
extern u32_T GET_IMFU_STATUS_UNMASKED(IMFU_TYPE_E type, IMFU_GROUP_E group);

extern void NVIC_ClearPendingIRQ(int32_t IRQn);
extern uint32_t NVIC_GetPendingIRQ(int32_t IRQn);

#endif /* MACRO_INTERRUPTS_INTERRUPT_FUNCTIONS_H_ */
