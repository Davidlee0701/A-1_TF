/*
 * cpu_ss_workaround_helper.c
 *
 *  Created on: 28.10.2024
 *      Author: a5105882
 */

#include <cpu_ss_workaround.h>

void set_bit_u8(volatile u8_T* address, u16_T bit_pos){
	u8_T temporary = WA(*address);
	temporary |=  ( 1 << bit_pos);
	*address = temporary;
	return;
}

void clear_bit_u8(volatile u8_T* address, u16_T bit_pos){
	u8_T temporary = WA(*address);
	u8_T bitmask =  ~( ((u16_T)1) << bit_pos);
	temporary &= bitmask;
	*address = temporary;
	return;
}

void set_bit_u16(volatile u16_T* address, u16_T bit_pos){
	u16_T temporary = WA(*address);
	temporary |=  ( 1 << bit_pos);
	*address = temporary;
	return;
}

void clear_bit_u16(volatile u16_T* address, u16_T bit_pos){
	u16_T temporary = WA(*address);
	u16_T bitmask =  ~( ((u16_T)1) << bit_pos);
	temporary &= bitmask;
	*address = temporary;
	return;
}

void set_bit_u32(volatile u32_T* address, u32_T bit_pos){
	volatile u16_T temporary = WA(*address);
	temporary |= ( 1 << bit_pos);
	*address = temporary;
	return;
}

void clear_bit_u32(volatile u32_T* address, u32_T bit_pos){
	u16_T temporary = WA(*address);
	temporary &= (u32_T)( ~( 1 << bit_pos) );
	*address = temporary;
	return;
}
