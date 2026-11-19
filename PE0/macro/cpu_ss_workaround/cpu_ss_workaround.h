/*
 * cpu_ss_workaround.h
 *
 *  Created on: 14.10.2024
 *      Author: a5105882
 */

#ifndef SRC_DEVICE_SVD_CPU_SS_WORKAROUND_H_
#define SRC_DEVICE_SVD_CPU_SS_WORKAROUND_H_

#include <U5L_common_types.h>

//
// needs "-gcc" option, if GHS
//

#if defined(__GNUC__) || defined(__ghs__)
    #define WAITING() __asm volatile("dsb")
#else
    #error "Unsupported compiler"
#endif

#define WA(var) ({ \
    unsigned int tmp = (unsigned int)(var); \
    WAITING(); \
    tmp; \
})

extern void set_bit_u8(volatile u8_T* address, u16_T bit_pos);
extern void clear_bit_u8(volatile u8_T* address, u16_T bit_pos);

extern void clear_bit_u16(volatile u16_T* address, u16_T bit_pos);
extern void set_bit_u16(volatile u16_T* address, u16_T bit_pos);

extern void clear_bit_u32(volatile u32_T* address, u32_T bit_pos);
extern void set_bit_u32(volatile u32_T* address, u32_T bit_pos);


#endif /* SRC_DEVICE_SVD_CPU_SS_WORKAROUND_H_ */
