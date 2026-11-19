//#include <RCar_U5L_UM_rev0.40_noRSIP_ver1.0.h>
#include <U5L_common_types.h>
#include <cpu_ss_workaround.h>
#include <interrupt_data.h>
#include <interrupt_functions.h>

void UNUSED_ISR(void){
	while(1)
		__asm("nop");
}
#ifdef IMFUL_0_ENABLED
void ISR_IMFUL_0(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_0);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRCAN0ERR_ENABLED
		ISR_INTRCAN0ERR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRCAN2ERR_ENABLED
		ISR_INTRCAN2ERR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRCAN4ERR_ENABLED
		ISR_INTRCAN4ERR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_1_ENABLED
void ISR_IMFUL_1(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_1);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRCAN1ERR_ENABLED
		ISR_INTRCAN1ERR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRCAN3ERR_ENABLED
		ISR_INTRCAN3ERR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRCAN5ERR_ENABLED
		ISR_INTRCAN5ERR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_2_ENABLED
void ISR_IMFUL_2(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_2);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRCAN0REC_ENABLED
		ISR_INTRCAN0REC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRCAN2REC_ENABLED
		ISR_INTRCAN2REC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRCAN4REC_ENABLED
		ISR_INTRCAN4REC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_3_ENABLED
void ISR_IMFUL_3(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_3);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRCAN1REC_ENABLED
		ISR_INTRCAN1REC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRCAN3REC_ENABLED
		ISR_INTRCAN3REC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRCAN5REC_ENABLED
		ISR_INTRCAN5REC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_4_ENABLED
void ISR_IMFUL_4(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_4);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRCAN0TRX_ENABLED
		ISR_INTRCAN0TRX();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRCAN2TRX_ENABLED
		ISR_INTRCAN2TRX();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRCAN4TRX_ENABLED
		ISR_INTRCAN4TRX();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_5_ENABLED
void ISR_IMFUL_5(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_5);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRCAN1TRX_ENABLED
		ISR_INTRCAN1TRX();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRCAN3TRX_ENABLED
		ISR_INTRCAN3TRX();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRCAN5TRX_ENABLED
		ISR_INTRCAN5TRX();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_6_ENABLED
void ISR_IMFUL_6(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_6);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRSENT0SI_ENABLED
		ISR_INTRSENT0SI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRSENT2SI_ENABLED
		ISR_INTRSENT2SI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRSENT4SI_ENABLED
		ISR_INTRSENT4SI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTRSENT6SI_ENABLED
		ISR_INTRSENT6SI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_7_ENABLED
void ISR_IMFUL_7(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_7);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRSENT1SI_ENABLED
		ISR_INTRSENT1SI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRSENT3SI_ENABLED
		ISR_INTRSENT3SI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRSENT5SI_ENABLED
		ISR_INTRSENT5SI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTRSENT7SI_ENABLED
		ISR_INTRSENT7SI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_8_ENABLED
void ISR_IMFUL_8(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_8);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCXP10TI_ENABLED
		ISR_INTCXP10TI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCXP12TI_ENABLED
		ISR_INTCXP12TI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_9_ENABLED
void ISR_IMFUL_9(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_9);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCXP10RI_ENABLED
		ISR_INTCXP10RI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCXP12RI_ENABLED
		ISR_INTCXP12RI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_10_ENABLED
void ISR_IMFUL_10(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_10);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCXP10SI_ENABLED
		ISR_INTCXP10SI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCXP12SI_ENABLED
		ISR_INTCXP12SI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_11_ENABLED
void ISR_IMFUL_11(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_11);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCXP11TI_ENABLED
		ISR_INTCXP11TI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCXP13TI_ENABLED
		ISR_INTCXP13TI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_12_ENABLED
void ISR_IMFUL_12(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_12);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCXP11RI_ENABLED
		ISR_INTCXP11RI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCXP13RI_ENABLED
		ISR_INTCXP13RI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUL_13_ENABLED
void ISR_IMFUL_13(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_LEVEL, IMFU_13);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCXP11SI_ENABLED
		ISR_INTCXP11SI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCXP13SI_ENABLED
		ISR_INTCXP13SI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_0_ENABLED
void ISR_IMFUP_0(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_0);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTPDMAC0CH0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_0, IMFU_BIT_0);
		ISR_INTPDMAC0CH0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTPDMAC0CH2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_0, IMFU_BIT_1);
		ISR_INTPDMAC0CH2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTPDMAC0CH4_ENABLED
		CLEAR_IMFU_PULSE(IMFU_0, IMFU_BIT_2);
		ISR_INTPDMAC0CH4();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTPDMAC0CH6_ENABLED
		CLEAR_IMFU_PULSE(IMFU_0, IMFU_BIT_3);
		ISR_INTPDMAC0CH6();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_1_ENABLED
void ISR_IMFUP_1(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_1);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTPDMAC0CH1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_1, IMFU_BIT_0);
		ISR_INTPDMAC0CH1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTPDMAC0CH3_ENABLED
		CLEAR_IMFU_PULSE(IMFU_1, IMFU_BIT_1);
		ISR_INTPDMAC0CH3();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTPDMAC0CH5_ENABLED
		CLEAR_IMFU_PULSE(IMFU_1, IMFU_BIT_2);
		ISR_INTPDMAC0CH5();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTPDMAC0CH7_ENABLED
		CLEAR_IMFU_PULSE(IMFU_1, IMFU_BIT_3);
		ISR_INTPDMAC0CH7();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_2_ENABLED
void ISR_IMFUP_2(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_2);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCSIH0IC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_2, IMFU_BIT_0);
		ISR_INTCSIH0IC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCSIH2IC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_2, IMFU_BIT_1);
		ISR_INTCSIH2IC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTCSIH4IC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_2, IMFU_BIT_2);
		ISR_INTCSIH4IC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTCSIH6IC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_2, IMFU_BIT_3);
		ISR_INTCSIH6IC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_3_ENABLED
void ISR_IMFUP_3(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_3);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCSIH1IC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_3, IMFU_BIT_0);
		ISR_INTCSIH1IC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCSIH3IC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_3, IMFU_BIT_1);
		ISR_INTCSIH3IC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTCSIH5IC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_3, IMFU_BIT_2);
		ISR_INTCSIH5IC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTCSIH7IC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_3, IMFU_BIT_3);
		ISR_INTCSIH7IC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_4_ENABLED
void ISR_IMFUP_4(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_4);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCSIH0IR_ENABLED
		CLEAR_IMFU_PULSE(IMFU_4, IMFU_BIT_0);
		ISR_INTCSIH0IR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCSIH2IR_ENABLED
		CLEAR_IMFU_PULSE(IMFU_4, IMFU_BIT_1);
		ISR_INTCSIH2IR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTCSIH4IR_ENABLED
		CLEAR_IMFU_PULSE(IMFU_4, IMFU_BIT_2);
		ISR_INTCSIH4IR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTCSIH6IR_ENABLED
		CLEAR_IMFU_PULSE(IMFU_4, IMFU_BIT_3);
		ISR_INTCSIH6IR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_5_ENABLED
void ISR_IMFUP_5(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_5);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCSIH1IR_ENABLED
		CLEAR_IMFU_PULSE(IMFU_5, IMFU_BIT_0);
		ISR_INTCSIH1IR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCSIH3IR_ENABLED
		CLEAR_IMFU_PULSE(IMFU_5, IMFU_BIT_1);
		ISR_INTCSIH3IR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTCSIH5IR_ENABLED
		CLEAR_IMFU_PULSE(IMFU_5, IMFU_BIT_2);
		ISR_INTCSIH5IR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTCSIH7IR_ENABLED
		CLEAR_IMFU_PULSE(IMFU_5, IMFU_BIT_3);
		ISR_INTCSIH7IR();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_6_ENABLED
void ISR_IMFUP_6(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_6);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCSIH0IRE_ENABLED
		CLEAR_IMFU_PULSE(IMFU_6, IMFU_BIT_0);
		ISR_INTCSIH0IRE();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCSIH2IRE_ENABLED
		CLEAR_IMFU_PULSE(IMFU_6, IMFU_BIT_1);
		ISR_INTCSIH2IRE();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTCSIH4IRE_ENABLED
		CLEAR_IMFU_PULSE(IMFU_6, IMFU_BIT_2);
		ISR_INTCSIH4IRE();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTCSIH6IRE_ENABLED
		CLEAR_IMFU_PULSE(IMFU_6, IMFU_BIT_3);
		ISR_INTCSIH6IRE();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_7_ENABLED
void ISR_IMFUP_7(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_7);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCSIH1IRE_ENABLED
		CLEAR_IMFU_PULSE(IMFU_7, IMFU_BIT_0);
		ISR_INTCSIH1IRE();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCSIH3IRE_ENABLED
		CLEAR_IMFU_PULSE(IMFU_7, IMFU_BIT_1);
		ISR_INTCSIH3IRE();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTCSIH5IRE_ENABLED
		CLEAR_IMFU_PULSE(IMFU_7, IMFU_BIT_2);
		ISR_INTCSIH5IRE();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTCSIH7IRE_ENABLED
		CLEAR_IMFU_PULSE(IMFU_7, IMFU_BIT_3);
		ISR_INTCSIH7IRE();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_8_ENABLED
void ISR_IMFUP_8(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_8);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCSIH0IJC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_8, IMFU_BIT_0);
		ISR_INTCSIH0IJC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCSIH2IJC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_8, IMFU_BIT_1);
		ISR_INTCSIH2IJC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTCSIH4IJC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_8, IMFU_BIT_2);
		ISR_INTCSIH4IJC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTCSIH6IJC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_8, IMFU_BIT_3);
		ISR_INTCSIH6IJC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_9_ENABLED
void ISR_IMFUP_9(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_9);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTCSIH1IJC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_9, IMFU_BIT_0);
		ISR_INTCSIH1IJC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTCSIH3IJC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_9, IMFU_BIT_1);
		ISR_INTCSIH3IJC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTCSIH5IJC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_9, IMFU_BIT_2);
		ISR_INTCSIH5IJC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTCSIH7IJC_ENABLED
		CLEAR_IMFU_PULSE(IMFU_9, IMFU_BIT_3);
		ISR_INTCSIH7IJC();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_10_ENABLED
void ISR_IMFUP_10(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_10);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTTAUJ0I0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_10, IMFU_BIT_0);
		ISR_INTTAUJ0I0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTTAUJ0I1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_10, IMFU_BIT_1);
		ISR_INTTAUJ0I1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTTAUJ0I2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_10, IMFU_BIT_2);
		ISR_INTTAUJ0I2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTTAUJ0I3_ENABLED
		CLEAR_IMFU_PULSE(IMFU_10, IMFU_BIT_3);
		ISR_INTTAUJ0I3();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_11_ENABLED
void ISR_IMFUP_11(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_11);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTTAUJ1I0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_11, IMFU_BIT_0);
		ISR_INTTAUJ1I0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTTAUJ1I1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_11, IMFU_BIT_1);
		ISR_INTTAUJ1I1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTTAUJ1I2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_11, IMFU_BIT_2);
		ISR_INTTAUJ1I2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTTAUJ1I3_ENABLED
		CLEAR_IMFU_PULSE(IMFU_11, IMFU_BIT_3);
		ISR_INTTAUJ1I3();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_12_ENABLED
void ISR_IMFUP_12(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_12);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTTAUJ2I0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_12, IMFU_BIT_0);
		ISR_INTTAUJ2I0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTTAUJ2I1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_12, IMFU_BIT_1);
		ISR_INTTAUJ2I1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTTAUJ2I2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_12, IMFU_BIT_2);
		ISR_INTTAUJ2I2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTTAUJ2I3_ENABLED
		CLEAR_IMFU_PULSE(IMFU_12, IMFU_BIT_3);
		ISR_INTTAUJ2I3();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_13_ENABLED
void ISR_IMFUP_13(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_13);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTTAUJ3I0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_13, IMFU_BIT_0);
		ISR_INTTAUJ3I0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTTAUJ3I1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_13, IMFU_BIT_1);
		ISR_INTTAUJ3I1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTTAUJ3I2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_13, IMFU_BIT_2);
		ISR_INTTAUJ3I2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTTAUJ3I3_ENABLED
		CLEAR_IMFU_PULSE(IMFU_13, IMFU_BIT_3);
		ISR_INTTAUJ3I3();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_14_ENABLED
void ISR_IMFUP_14(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_14);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTTAUD0I1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_14, IMFU_BIT_0);
		ISR_INTTAUD0I1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTTAUD0I3_ENABLED
		CLEAR_IMFU_PULSE(IMFU_14, IMFU_BIT_1);
		ISR_INTTAUD0I3();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTTAUD0I5_ENABLED
		CLEAR_IMFU_PULSE(IMFU_14, IMFU_BIT_2);
		ISR_INTTAUD0I5();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTTAUD0I7_ENABLED
		CLEAR_IMFU_PULSE(IMFU_14, IMFU_BIT_3);
		ISR_INTTAUD0I7();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTTAUD0I9_ENABLED
		CLEAR_IMFU_PULSE(IMFU_14, IMFU_BIT_4);
		ISR_INTTAUD0I9();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTTAUD0I11_ENABLED
		CLEAR_IMFU_PULSE(IMFU_14, IMFU_BIT_5);
		ISR_INTTAUD0I11();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTTAUD0I13_ENABLED
		CLEAR_IMFU_PULSE(IMFU_14, IMFU_BIT_6);
		ISR_INTTAUD0I13();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTTAUD0I15_ENABLED
		CLEAR_IMFU_PULSE(IMFU_14, IMFU_BIT_7);
		ISR_INTTAUD0I15();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_15_ENABLED
void ISR_IMFUP_15(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_15);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTTAUD1I0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_15, IMFU_BIT_0);
		ISR_INTTAUD1I0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTTAUD1I2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_15, IMFU_BIT_1);
		ISR_INTTAUD1I2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTTAUD1I4_ENABLED
		CLEAR_IMFU_PULSE(IMFU_15, IMFU_BIT_2);
		ISR_INTTAUD1I4();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTTAUD1I6_ENABLED
		CLEAR_IMFU_PULSE(IMFU_15, IMFU_BIT_3);
		ISR_INTTAUD1I6();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTTAUD1I8_ENABLED
		CLEAR_IMFU_PULSE(IMFU_15, IMFU_BIT_4);
		ISR_INTTAUD1I8();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTTAUD1I10_ENABLED
		CLEAR_IMFU_PULSE(IMFU_15, IMFU_BIT_5);
		ISR_INTTAUD1I10();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTTAUD1I12_ENABLED
		CLEAR_IMFU_PULSE(IMFU_15, IMFU_BIT_6);
		ISR_INTTAUD1I12();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTTAUD1I14_ENABLED
		CLEAR_IMFU_PULSE(IMFU_15, IMFU_BIT_7);
		ISR_INTTAUD1I14();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_16_ENABLED
void ISR_IMFUP_16(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_16);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTTAUD1I1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_16, IMFU_BIT_0);
		ISR_INTTAUD1I1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTTAUD1I3_ENABLED
		CLEAR_IMFU_PULSE(IMFU_16, IMFU_BIT_1);
		ISR_INTTAUD1I3();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTTAUD1I5_ENABLED
		CLEAR_IMFU_PULSE(IMFU_16, IMFU_BIT_2);
		ISR_INTTAUD1I5();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTTAUD1I7_ENABLED
		CLEAR_IMFU_PULSE(IMFU_16, IMFU_BIT_3);
		ISR_INTTAUD1I7();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTTAUD1I9_ENABLED
		CLEAR_IMFU_PULSE(IMFU_16, IMFU_BIT_4);
		ISR_INTTAUD1I9();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTTAUD1I11_ENABLED
		CLEAR_IMFU_PULSE(IMFU_16, IMFU_BIT_5);
		ISR_INTTAUD1I11();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTTAUD1I13_ENABLED
		CLEAR_IMFU_PULSE(IMFU_16, IMFU_BIT_6);
		ISR_INTTAUD1I13();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTTAUD1I15_ENABLED
		CLEAR_IMFU_PULSE(IMFU_16, IMFU_BIT_7);
		ISR_INTTAUD1I15();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_17_ENABLED
void ISR_IMFUP_17(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_17);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRLIN30_ENABLED
		CLEAR_IMFU_PULSE(IMFU_17, IMFU_BIT_0);
		ISR_INTRLIN30();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRLIN31_ENABLED
		CLEAR_IMFU_PULSE(IMFU_17, IMFU_BIT_1);
		ISR_INTRLIN31();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRLIN32_ENABLED
		CLEAR_IMFU_PULSE(IMFU_17, IMFU_BIT_2);
		ISR_INTRLIN32();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTRLIN33_ENABLED
		CLEAR_IMFU_PULSE(IMFU_17, IMFU_BIT_3);
		ISR_INTRLIN33();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTRLIN34_ENABLED
		CLEAR_IMFU_PULSE(IMFU_17, IMFU_BIT_4);
		ISR_INTRLIN34();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTRLIN35_ENABLED
		CLEAR_IMFU_PULSE(IMFU_17, IMFU_BIT_5);
		ISR_INTRLIN35();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTRLIN36_ENABLED
		CLEAR_IMFU_PULSE(IMFU_17, IMFU_BIT_6);
		ISR_INTRLIN36();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTRLIN37_ENABLED
		CLEAR_IMFU_PULSE(IMFU_17, IMFU_BIT_7);
		ISR_INTRLIN37();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_18_ENABLED
void ISR_IMFUP_18(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_18);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRLIN30UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_18, IMFU_BIT_0);
		ISR_INTRLIN30UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRLIN31UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_18, IMFU_BIT_1);
		ISR_INTRLIN31UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRLIN32UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_18, IMFU_BIT_2);
		ISR_INTRLIN32UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTRLIN33UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_18, IMFU_BIT_3);
		ISR_INTRLIN33UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTRLIN34UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_18, IMFU_BIT_4);
		ISR_INTRLIN34UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTRLIN35UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_18, IMFU_BIT_5);
		ISR_INTRLIN35UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTRLIN36UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_18, IMFU_BIT_6);
		ISR_INTRLIN36UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTRLIN37UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_18, IMFU_BIT_7);
		ISR_INTRLIN37UR0();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_19_ENABLED
void ISR_IMFUP_19(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_19);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRLIN30UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_19, IMFU_BIT_0);
		ISR_INTRLIN30UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRLIN31UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_19, IMFU_BIT_1);
		ISR_INTRLIN31UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRLIN32UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_19, IMFU_BIT_2);
		ISR_INTRLIN32UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTRLIN33UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_19, IMFU_BIT_3);
		ISR_INTRLIN33UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTRLIN34UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_19, IMFU_BIT_4);
		ISR_INTRLIN34UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTRLIN35UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_19, IMFU_BIT_5);
		ISR_INTRLIN35UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTRLIN36UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_19, IMFU_BIT_6);
		ISR_INTRLIN36UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTRLIN37UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_19, IMFU_BIT_7);
		ISR_INTRLIN37UR1();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_20_ENABLED
void ISR_IMFUP_20(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_20);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRLIN30UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_20, IMFU_BIT_0);
		ISR_INTRLIN30UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRLIN31UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_20, IMFU_BIT_1);
		ISR_INTRLIN31UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRLIN32UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_20, IMFU_BIT_2);
		ISR_INTRLIN32UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTRLIN33UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_20, IMFU_BIT_3);
		ISR_INTRLIN33UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTRLIN34UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_20, IMFU_BIT_4);
		ISR_INTRLIN34UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTRLIN35UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_20, IMFU_BIT_5);
		ISR_INTRLIN35UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTRLIN36UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_20, IMFU_BIT_6);
		ISR_INTRLIN36UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTRLIN37UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_20, IMFU_BIT_7);
		ISR_INTRLIN37UR2();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_21_ENABLED
void ISR_IMFUP_21(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_21);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRSENT0RI_ENABLED
		CLEAR_IMFU_PULSE(IMFU_21, IMFU_BIT_0);
		ISR_INTRSENT0RI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRSENT2RI_ENABLED
		CLEAR_IMFU_PULSE(IMFU_21, IMFU_BIT_1);
		ISR_INTRSENT2RI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRSENT4RI_ENABLED
		CLEAR_IMFU_PULSE(IMFU_21, IMFU_BIT_2);
		ISR_INTRSENT4RI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTRSENT6RI_ENABLED
		CLEAR_IMFU_PULSE(IMFU_21, IMFU_BIT_3);
		ISR_INTRSENT6RI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_22_ENABLED
void ISR_IMFUP_22(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_22);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRSENT1RI_ENABLED
		CLEAR_IMFU_PULSE(IMFU_22, IMFU_BIT_0);
		ISR_INTRSENT1RI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRSENT3RI_ENABLED
		CLEAR_IMFU_PULSE(IMFU_22, IMFU_BIT_1);
		ISR_INTRSENT3RI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRSENT5RI_ENABLED
		CLEAR_IMFU_PULSE(IMFU_22, IMFU_BIT_2);
		ISR_INTRSENT5RI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTRSENT7RI_ENABLED
		CLEAR_IMFU_PULSE(IMFU_22, IMFU_BIT_3);
		ISR_INTRSENT7RI();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_23_ENABLED
void ISR_IMFUP_23(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_23);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTLPSTM0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_23, IMFU_BIT_0);
		ISR_INTLPSTM0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTLPSTM2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_23, IMFU_BIT_1);
		ISR_INTLPSTM2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTLPSTM4_ENABLED
		CLEAR_IMFU_PULSE(IMFU_23, IMFU_BIT_2);
		ISR_INTLPSTM4();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_24_ENABLED
void ISR_IMFUP_24(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_24);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTLPSTM1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_24, IMFU_BIT_0);
		ISR_INTLPSTM1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTLPSTM3_ENABLED
		CLEAR_IMFU_PULSE(IMFU_24, IMFU_BIT_1);
		ISR_INTLPSTM3();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_25_ENABLED
void ISR_IMFUP_25(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_25);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTPDMAC1CH0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_25, IMFU_BIT_0);
		ISR_INTPDMAC1CH0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTPDMAC1CH2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_25, IMFU_BIT_1);
		ISR_INTPDMAC1CH2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTPDMAC1CH4_ENABLED
		CLEAR_IMFU_PULSE(IMFU_25, IMFU_BIT_2);
		ISR_INTPDMAC1CH4();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTPDMAC1CH6_ENABLED
		CLEAR_IMFU_PULSE(IMFU_25, IMFU_BIT_3);
		ISR_INTPDMAC1CH6();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_26_ENABLED
void ISR_IMFUP_26(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_26);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTPDMAC1CH1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_26, IMFU_BIT_0);
		ISR_INTPDMAC1CH1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTPDMAC1CH3_ENABLED
		CLEAR_IMFU_PULSE(IMFU_26, IMFU_BIT_1);
		ISR_INTPDMAC1CH3();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTPDMAC1CH5_ENABLED
		CLEAR_IMFU_PULSE(IMFU_26, IMFU_BIT_2);
		ISR_INTPDMAC1CH5();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTPDMAC1CH7_ENABLED
		CLEAR_IMFU_PULSE(IMFU_26, IMFU_BIT_3);
		ISR_INTPDMAC1CH7();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_27_ENABLED
void ISR_IMFUP_27(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_27);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTTAUD2I0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_27, IMFU_BIT_0);
		ISR_INTTAUD2I0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTTAUD2I2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_27, IMFU_BIT_1);
		ISR_INTTAUD2I2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTTAUD2I4_ENABLED
		CLEAR_IMFU_PULSE(IMFU_27, IMFU_BIT_2);
		ISR_INTTAUD2I4();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTTAUD2I6_ENABLED
		CLEAR_IMFU_PULSE(IMFU_27, IMFU_BIT_3);
		ISR_INTTAUD2I6();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTTAUD2I8_ENABLED
		CLEAR_IMFU_PULSE(IMFU_27, IMFU_BIT_4);
		ISR_INTTAUD2I8();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTTAUD2I10_ENABLED
		CLEAR_IMFU_PULSE(IMFU_27, IMFU_BIT_5);
		ISR_INTTAUD2I10();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTTAUD2I12_ENABLED
		CLEAR_IMFU_PULSE(IMFU_27, IMFU_BIT_6);
		ISR_INTTAUD2I12();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTTAUD2I14_ENABLED
		CLEAR_IMFU_PULSE(IMFU_27, IMFU_BIT_7);
		ISR_INTTAUD2I14();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_28_ENABLED
void ISR_IMFUP_28(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_28);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTTAUD2I1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_28, IMFU_BIT_0);
		ISR_INTTAUD2I1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTTAUD2I3_ENABLED
		CLEAR_IMFU_PULSE(IMFU_28, IMFU_BIT_1);
		ISR_INTTAUD2I3();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTTAUD2I5_ENABLED
		CLEAR_IMFU_PULSE(IMFU_28, IMFU_BIT_2);
		ISR_INTTAUD2I5();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTTAUD2I7_ENABLED
		CLEAR_IMFU_PULSE(IMFU_28, IMFU_BIT_3);
		ISR_INTTAUD2I7();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTTAUD2I9_ENABLED
		CLEAR_IMFU_PULSE(IMFU_28, IMFU_BIT_4);
		ISR_INTTAUD2I9();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTTAUD2I11_ENABLED
		CLEAR_IMFU_PULSE(IMFU_28, IMFU_BIT_5);
		ISR_INTTAUD2I11();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTTAUD2I13_ENABLED
		CLEAR_IMFU_PULSE(IMFU_28, IMFU_BIT_6);
		ISR_INTTAUD2I13();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTTAUD2I15_ENABLED
		CLEAR_IMFU_PULSE(IMFU_28, IMFU_BIT_7);
		ISR_INTTAUD2I15();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_29_ENABLED
void ISR_IMFUP_29(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_29);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRLIN38_ENABLED
		CLEAR_IMFU_PULSE(IMFU_29, IMFU_BIT_0);
		ISR_INTRLIN38();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRLIN39_ENABLED
		CLEAR_IMFU_PULSE(IMFU_29, IMFU_BIT_1);
		ISR_INTRLIN39();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRLIN310_ENABLED
		CLEAR_IMFU_PULSE(IMFU_29, IMFU_BIT_2);
		ISR_INTRLIN310();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTRLIN311_ENABLED
		CLEAR_IMFU_PULSE(IMFU_29, IMFU_BIT_3);
		ISR_INTRLIN311();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTRLIN312_ENABLED
		CLEAR_IMFU_PULSE(IMFU_29, IMFU_BIT_4);
		ISR_INTRLIN312();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTRLIN313_ENABLED
		CLEAR_IMFU_PULSE(IMFU_29, IMFU_BIT_5);
		ISR_INTRLIN313();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTRLIN314_ENABLED
		CLEAR_IMFU_PULSE(IMFU_29, IMFU_BIT_6);
		ISR_INTRLIN314();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTRLIN315_ENABLED
		CLEAR_IMFU_PULSE(IMFU_29, IMFU_BIT_7);
		ISR_INTRLIN315();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_30_ENABLED
void ISR_IMFUP_30(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_30);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRLIN38UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_30, IMFU_BIT_0);
		ISR_INTRLIN38UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRLIN39UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_30, IMFU_BIT_1);
		ISR_INTRLIN39UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRLIN310UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_30, IMFU_BIT_2);
		ISR_INTRLIN310UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTRLIN311UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_30, IMFU_BIT_3);
		ISR_INTRLIN311UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTRLIN312UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_30, IMFU_BIT_4);
		ISR_INTRLIN312UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTRLIN313UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_30, IMFU_BIT_5);
		ISR_INTRLIN313UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTRLIN314UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_30, IMFU_BIT_6);
		ISR_INTRLIN314UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTRLIN315UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_30, IMFU_BIT_7);
		ISR_INTRLIN315UR0();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_31_ENABLED
void ISR_IMFUP_31(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_31);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRLIN38UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_31, IMFU_BIT_0);
		ISR_INTRLIN38UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRLIN39UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_31, IMFU_BIT_1);
		ISR_INTRLIN39UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRLIN310UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_31, IMFU_BIT_2);
		ISR_INTRLIN310UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTRLIN311UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_31, IMFU_BIT_3);
		ISR_INTRLIN311UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTRLIN312UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_31, IMFU_BIT_4);
		ISR_INTRLIN312UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTRLIN313UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_31, IMFU_BIT_5);
		ISR_INTRLIN313UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTRLIN314UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_31, IMFU_BIT_6);
		ISR_INTRLIN314UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTRLIN315UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_31, IMFU_BIT_7);
		ISR_INTRLIN315UR1();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_32_ENABLED
void ISR_IMFUP_32(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_32);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRLIN38UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_32, IMFU_BIT_0);
		ISR_INTRLIN38UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRLIN39UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_32, IMFU_BIT_1);
		ISR_INTRLIN39UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		#ifdef ISR_INTRLIN310UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_32, IMFU_BIT_2);
		ISR_INTRLIN310UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		#ifdef ISR_INTRLIN311UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_32, IMFU_BIT_3);
		ISR_INTRLIN311UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		#ifdef ISR_INTRLIN312UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_32, IMFU_BIT_4);
		ISR_INTRLIN312UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		#ifdef ISR_INTRLIN313UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_32, IMFU_BIT_5);
		ISR_INTRLIN313UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		#ifdef ISR_INTRLIN314UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_32, IMFU_BIT_6);
		ISR_INTRLIN314UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		#ifdef ISR_INTRLIN315UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_32, IMFU_BIT_7);
		ISR_INTRLIN315UR2();
		#else
		UNUSED_ISR();
		#endif
	}
}
#endif
#ifdef IMFUP_33_ENABLED
void ISR_IMFUP_33(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_33);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRLIN316_ENABLED
		CLEAR_IMFU_PULSE(IMFU_33, IMFU_BIT_0);
		ISR_INTRLIN316();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		#ifdef ISR_INTRLIN317_ENABLED
		CLEAR_IMFU_PULSE(IMFU_33, IMFU_BIT_1);
		ISR_INTRLIN317();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_34_ENABLED
void ISR_IMFUP_34(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_34);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRLIN316UR0_ENABLED
		CLEAR_IMFU_PULSE(IMFU_34, IMFU_BIT_0);
		ISR_INTRLIN316UR0();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_35_ENABLED
void ISR_IMFUP_35(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_35);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRLIN316UR1_ENABLED
		CLEAR_IMFU_PULSE(IMFU_35, IMFU_BIT_0);
		ISR_INTRLIN316UR1();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef IMFUP_36_ENABLED
void ISR_IMFUP_36(void){
	u32_T imfu_status = GET_IMFU_STATUS_UNMASKED(IMFU_PULSE, IMFU_36);
	if (imfu_status & (1 << IMFU_BIT_0)){
		#ifdef ISR_INTRLIN316UR2_ENABLED
		CLEAR_IMFU_PULSE(IMFU_36, IMFU_BIT_0);
		ISR_INTRLIN316UR2();
		#else
		UNUSED_ISR();
		#endif
	}
	if (imfu_status & (1 << IMFU_BIT_1)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_2)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_3)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_4)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_5)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_6)){
		UNUSED_ISR();
	}
	if (imfu_status & (1 << IMFU_BIT_7)){
		UNUSED_ISR();
	}
}
#endif
#ifdef NVIC_0_ENABLED
void NVIC_ISR_0(void){
	ISR_INTECMNMI();
}
#endif
#ifdef NVIC_1_ENABLED
void NVIC_ISR_1(void){
	ISR_INTECMMI();
}
#endif
#ifdef NVIC_2_ENABLED
void NVIC_ISR_2(void){
	ISR_INTFPUEXCIRQ();
}
#endif
#ifdef NVIC_3_ENABLED
void NVIC_ISR_3(void){
	ISR_INTTAUD0I0();
}
#endif
#ifdef NVIC_4_ENABLED
void NVIC_ISR_4(void){
	ISR_INTTAUD0I2();
}
#endif
#ifdef NVIC_5_ENABLED
void NVIC_ISR_5(void){
	ISR_INTTAUD0I4();
}
#endif
#ifdef NVIC_6_ENABLED
void NVIC_ISR_6(void){
	ISR_INTTAUD0I6();
}
#endif
#ifdef NVIC_7_ENABLED
void NVIC_ISR_7(void){
	ISR_INTEINTSW0();
}
#endif
#ifdef NVIC_8_ENABLED
void NVIC_ISR_8(void){
	ISR_INTEINTSW1();
}
#endif
#ifdef NVIC_9_ENABLED
void NVIC_ISR_9(void){
	ISR_INTEINTSW2();
}
#endif
#ifdef NVIC_10_ENABLED
void NVIC_ISR_10(void){
	ISR_INTEINTSW3();
}
#endif
#ifdef NVIC_11_ENABLED
void NVIC_ISR_11(void){
	ISR_INTS2HS0();
}
#endif
#ifdef NVIC_12_ENABLED
void NVIC_ISR_12(void){
	ISR_INTWDTB0TIT();
}
#endif
#ifdef NVIC_13_ENABLED
void NVIC_ISR_13(void){
	ISR_INTTAUD0I8();
}
#endif
#ifdef NVIC_14_ENABLED
void NVIC_ISR_14(void){
	ISR_INTTAUD0I10();
}
#endif
#ifdef NVIC_15_ENABLED
void NVIC_ISR_15(void){
	ISR_INTTAUD0I12();
}
#endif
#ifdef NVIC_16_ENABLED
void NVIC_ISR_16(void){
	ISR_INTTAUD0I14();
}
#endif
#ifdef NVIC_17_ENABLED
void NVIC_ISR_17(void){
	ISR_INTTAPA0IPEK0();
}
#endif
#ifdef NVIC_18_ENABLED
void NVIC_ISR_18(void){
	ISR_INTTAPA0IVLY0();
}
#endif
#ifdef NVIC_19_ENABLED
void NVIC_ISR_19(void){
	ISR_INTPDMACERR();
}
#endif
#ifdef NVIC_20_ENABLED
void NVIC_ISR_20(void){
	ISR_INTDTSERR();
}
#endif
#ifdef NVIC_21_ENABLED
void NVIC_ISR_21(void){
	ISR_INTDCUDEGRADPE();
}
#endif
#ifdef NVIC_22_ENABLED
void NVIC_ISR_22(void){
	ISR_INTFL0ENDNM();
}
#endif
#ifdef NVIC_23_ENABLED
void NVIC_ISR_23(void){
	ISR_INTFL2ENDNM();
}
#endif
#ifdef NVIC_24_ENABLED
void NVIC_ISR_24(void){
	ISR_INTDTS7TO0();
}
#endif
#ifdef NVIC_25_ENABLED
void NVIC_ISR_25(void){
	ISR_INTDTSCT7TO0();
}
#endif
#ifdef NVIC_26_ENABLED
void NVIC_ISR_26(void){
	ISR_IMFUP_0();
}
#endif
#ifdef NVIC_27_ENABLED
void NVIC_ISR_27(void){
	ISR_IMFUP_1();
}
#endif
#ifdef NVIC_28_ENABLED
void NVIC_ISR_28(void){
	ISR_INTOSTM0TINT();
}
#endif
#ifdef NVIC_29_ENABLED
void NVIC_ISR_29(void){
	ISR_INTADCK0ERR();
}
#endif
#ifdef NVIC_30_ENABLED
void NVIC_ISR_30(void){
	ISR_INTADCK0I0();
}
#endif
#ifdef NVIC_31_ENABLED
void NVIC_ISR_31(void){
	ISR_INTADCK0I1();
}
#endif
#ifdef NVIC_32_ENABLED
void NVIC_ISR_32(void){
	ISR_INTADCK0I2();
}
#endif
#ifdef NVIC_33_ENABLED
void NVIC_ISR_33(void){
	ISR_INTADCK0I3();
}
#endif
#ifdef NVIC_34_ENABLED
void NVIC_ISR_34(void){
	ISR_INTADCK0I4();
}
#endif
#ifdef NVIC_35_ENABLED
void NVIC_ISR_35(void){
	ISR_INTADCK0MPX();
}
#endif
#ifdef NVIC_36_ENABLED
void NVIC_ISR_36(void){
	ISR_INTADCK0SD();
}
#endif
#ifdef NVIC_37_ENABLED
void NVIC_ISR_37(void){
	ISR_IMFUP_2();
}
#endif
#ifdef NVIC_38_ENABLED
void NVIC_ISR_38(void){
	ISR_IMFUP_3();
}
#endif
#ifdef NVIC_39_ENABLED
void NVIC_ISR_39(void){
	ISR_IMFUP_4();
}
#endif
#ifdef NVIC_40_ENABLED
void NVIC_ISR_40(void){
	ISR_IMFUP_5();
}
#endif
#ifdef NVIC_41_ENABLED
void NVIC_ISR_41(void){
	ISR_IMFUP_6();
}
#endif
#ifdef NVIC_42_ENABLED
void NVIC_ISR_42(void){
	ISR_IMFUP_7();
}
#endif
#ifdef NVIC_43_ENABLED
void NVIC_ISR_43(void){
	ISR_IMFUP_8();
}
#endif
#ifdef NVIC_44_ENABLED
void NVIC_ISR_44(void){
	ISR_IMFUP_9();
}
#endif
#ifdef NVIC_45_ENABLED
void NVIC_ISR_45(void){
	ISR_INTRCANGERR0();
}
#endif
#ifdef NVIC_46_ENABLED
void NVIC_ISR_46(void){
	ISR_INTRCANGRECC0();
}
#endif
#ifdef NVIC_47_ENABLED
void NVIC_ISR_47(void){
	ISR_IMFUL_0();
}
#endif
#ifdef NVIC_48_ENABLED
void NVIC_ISR_48(void){
	ISR_IMFUL_1();
}
#endif
#ifdef NVIC_49_ENABLED
void NVIC_ISR_49(void){
	ISR_IMFUL_2();
}
#endif
#ifdef NVIC_50_ENABLED
void NVIC_ISR_50(void){
	ISR_IMFUL_3();
}
#endif
#ifdef NVIC_51_ENABLED
void NVIC_ISR_51(void){
	ISR_IMFUL_4();
}
#endif
#ifdef NVIC_52_ENABLED
void NVIC_ISR_52(void){
	ISR_IMFUL_5();
}
#endif
#ifdef NVIC_53_ENABLED
void NVIC_ISR_53(void){
	ISR_INTXCAN0FUNC();
}
#endif
#ifdef NVIC_54_ENABLED
void NVIC_ISR_54(void){
	ISR_INTXCAN0ERR();
}
#endif
#ifdef NVIC_55_ENABLED
void NVIC_ISR_55(void){
	ISR_INTXCAN0SAFETY();
}
#endif
#ifdef NVIC_56_ENABLED
void NVIC_ISR_56(void){
	ISR_IMFUP_10();
}
#endif
#ifdef NVIC_57_ENABLED
void NVIC_ISR_57(void){
	ISR_IMFUP_11();
}
#endif
#ifdef NVIC_58_ENABLED
void NVIC_ISR_58(void){
	ISR_IMFUP_12();
}
#endif
#ifdef NVIC_59_ENABLED
void NVIC_ISR_59(void){
	ISR_IMFUP_13();
}
#endif
#ifdef NVIC_60_ENABLED
void NVIC_ISR_60(void){
	ISR_IMFUP_14();
}
#endif
#ifdef NVIC_61_ENABLED
void NVIC_ISR_61(void){
	ISR_IMFUP_15();
}
#endif
#ifdef NVIC_62_ENABLED
void NVIC_ISR_62(void){
	ISR_IMFUP_16();
}
#endif
#ifdef NVIC_63_ENABLED
void NVIC_ISR_63(void){
	ISR_IMFUP_17();
}
#endif
#ifdef NVIC_64_ENABLED
void NVIC_ISR_64(void){
	ISR_IMFUP_18();
}
#endif
#ifdef NVIC_65_ENABLED
void NVIC_ISR_65(void){
	ISR_IMFUP_19();
}
#endif
#ifdef NVIC_66_ENABLED
void NVIC_ISR_66(void){
	ISR_IMFUP_20();
}
#endif
#ifdef NVIC_67_ENABLED
void NVIC_ISR_67(void){
	ISR_IMFUP_21();
}
#endif
#ifdef NVIC_68_ENABLED
void NVIC_ISR_68(void){
	ISR_IMFUP_22();
}
#endif
#ifdef NVIC_69_ENABLED
void NVIC_ISR_69(void){
	ISR_IMFUL_6();
}
#endif
#ifdef NVIC_70_ENABLED
void NVIC_ISR_70(void){
	ISR_IMFUL_7();
}
#endif
#ifdef NVIC_71_ENABLED
void NVIC_ISR_71(void){
	ISR_INTENCA0IOV();
}
#endif
#ifdef NVIC_72_ENABLED
void NVIC_ISR_72(void){
	ISR_INTENCA0I0();
}
#endif
#ifdef NVIC_73_ENABLED
void NVIC_ISR_73(void){
	ISR_INTENCA0I1();
}
#endif
#ifdef NVIC_74_ENABLED
void NVIC_ISR_74(void){
	ISR_INTENCA0IUD();
}
#endif
#ifdef NVIC_75_ENABLED
void NVIC_ISR_75(void){
	ISR_INTENCA0IEC();
}
#endif
#ifdef NVIC_77_ENABLED
void NVIC_ISR_77(void){
	ISR_IRQ0();
}
#endif
#ifdef NVIC_78_ENABLED
void NVIC_ISR_78(void){
	ISR_IRQ1();
}
#endif
#ifdef NVIC_79_ENABLED
void NVIC_ISR_79(void){
	ISR_IRQ2();
}
#endif
#ifdef NVIC_80_ENABLED
void NVIC_ISR_80(void){
	ISR_IRQ3();
}
#endif
#ifdef NVIC_81_ENABLED
void NVIC_ISR_81(void){
	ISR_IRQ4();
}
#endif
#ifdef NVIC_82_ENABLED
void NVIC_ISR_82(void){
	ISR_IRQ5();
}
#endif
#ifdef NVIC_83_ENABLED
void NVIC_ISR_83(void){
	ISR_IRQ6();
}
#endif
#ifdef NVIC_84_ENABLED
void NVIC_ISR_84(void){
	ISR_IRQ16();
}
#endif
#ifdef NVIC_85_ENABLED
void NVIC_ISR_85(void){
	ISR_IRQ18();
}
#endif
#ifdef NVIC_86_ENABLED
void NVIC_ISR_86(void){
	ISR_IRQ19();
}
#endif
#ifdef NVIC_87_ENABLED
void NVIC_ISR_87(void){
	ISR_IRQ20();
}
#endif
#ifdef NVIC_88_ENABLED
void NVIC_ISR_88(void){
	ISR_IRQ21();
}
#endif
#ifdef NVIC_89_ENABLED
void NVIC_ISR_89(void){
	ISR_IRQ22();
}
#endif
#ifdef NVIC_90_ENABLED
void NVIC_ISR_90(void){
	ISR_IRQ23();
}
#endif
#ifdef NVIC_91_ENABLED
void NVIC_ISR_91(void){
	ISR_IRQ24();
}
#endif
#ifdef NVIC_92_ENABLED
void NVIC_ISR_92(void){
	ISR_INTRTCA01S();
}
#endif
#ifdef NVIC_93_ENABLED
void NVIC_ISR_93(void){
	ISR_INTRTCA0AL();
}
#endif
#ifdef NVIC_94_ENABLED
void NVIC_ISR_94(void){
	ISR_INTRTCA0R();
}
#endif
#ifdef NVIC_95_ENABLED
void NVIC_ISR_95(void){
	ISR_INTS2H0();
}
#endif
#ifdef NVIC_96_ENABLED
void NVIC_ISR_96(void){
	ISR_INTPWGCG00();
}
#endif
#ifdef NVIC_97_ENABLED
void NVIC_ISR_97(void){
	ISR_INTPWGCG01();
}
#endif
#ifdef NVIC_98_ENABLED
void NVIC_ISR_98(void){
	ISR_INTPWGCG02();
}
#endif
#ifdef NVIC_99_ENABLED
void NVIC_ISR_99(void){
	ISR_INTPWSDQFULL();
}
#endif
#ifdef NVIC_100_ENABLED
void NVIC_ISR_100(void){
	ISR_IMFUL_8();
}
#endif
#ifdef NVIC_101_ENABLED
void NVIC_ISR_101(void){
	ISR_IMFUL_9();
}
#endif
#ifdef NVIC_102_ENABLED
void NVIC_ISR_102(void){
	ISR_IMFUL_10();
}
#endif
#ifdef NVIC_103_ENABLED
void NVIC_ISR_103(void){
	ISR_IMFUL_11();
}
#endif
#ifdef NVIC_104_ENABLED
void NVIC_ISR_104(void){
	ISR_IMFUL_12();
}
#endif
#ifdef NVIC_105_ENABLED
void NVIC_ISR_105(void){
	ISR_IMFUL_13();
}
#endif
#ifdef NVIC_106_ENABLED
void NVIC_ISR_106(void){
	ISR_INTRI3C0RESP();
}
#endif
#ifdef NVIC_107_ENABLED
void NVIC_ISR_107(void){
	ISR_INTRI3C0CMD();
}
#endif
#ifdef NVIC_108_ENABLED
void NVIC_ISR_108(void){
	ISR_INTRI3C0IBI();
}
#endif
#ifdef NVIC_109_ENABLED
void NVIC_ISR_109(void){
	ISR_INTRI3C0RX0();
}
#endif
#ifdef NVIC_110_ENABLED
void NVIC_ISR_110(void){
	ISR_INTRI3C0TX0();
}
#endif
#ifdef NVIC_111_ENABLED
void NVIC_ISR_111(void){
	ISR_INTRI3C0RCV();
}
#endif
#ifdef NVIC_112_ENABLED
void NVIC_ISR_112(void){
	ISR_INTRI3C0HRESP();
}
#endif
#ifdef NVIC_113_ENABLED
void NVIC_ISR_113(void){
	ISR_INTRI3C0HCMD();
}
#endif
#ifdef NVIC_114_ENABLED
void NVIC_ISR_114(void){
	ISR_INTRI3C0HRX();
}
#endif
#ifdef NVIC_115_ENABLED
void NVIC_ISR_115(void){
	ISR_INTRI3C0HTX();
}
#endif
#ifdef NVIC_116_ENABLED
void NVIC_ISR_116(void){
	ISR_INTRI3C0TEND();
}
#endif
#ifdef NVIC_117_ENABLED
void NVIC_ISR_117(void){
	ISR_INTRI3C0EEI();
}
#endif
#ifdef NVIC_118_ENABLED
void NVIC_ISR_118(void){
	ISR_INTRIIC0EE();
}
#endif
#ifdef NVIC_119_ENABLED
void NVIC_ISR_119(void){
	ISR_INTRIIC0RI();
}
#endif
#ifdef NVIC_120_ENABLED
void NVIC_ISR_120(void){
	ISR_INTRIIC0TI();
}
#endif
#ifdef NVIC_121_ENABLED
void NVIC_ISR_121(void){
	ISR_INTRIIC0TEI();
}
#endif
#ifdef NVIC_122_ENABLED
void NVIC_ISR_122(void){
	ISR_INTRIIC1EE();
}
#endif
#ifdef NVIC_123_ENABLED
void NVIC_ISR_123(void){
	ISR_INTRIIC1RI();
}
#endif
#ifdef NVIC_124_ENABLED
void NVIC_ISR_124(void){
	ISR_INTRIIC1TI();
}
#endif
#ifdef NVIC_125_ENABLED
void NVIC_ISR_125(void){
	ISR_INTRIIC1TEI();
}
#endif
#ifdef NVIC_126_ENABLED
void NVIC_ISR_126(void){
	ISR_INTCWEND();
}
#endif
#ifdef NVIC_127_ENABLED
void NVIC_ISR_127(void){
	ISR_INTDPE();
}
#endif
#ifdef NVIC_128_ENABLED
void NVIC_ISR_128(void){
	ISR_IMFUP_23();
}
#endif
#ifdef NVIC_129_ENABLED
void NVIC_ISR_129(void){
	ISR_IMFUP_24();
}
#endif
#ifdef NVIC_130_ENABLED
void NVIC_ISR_130(void){
	ISR_INTRSIPMFATALERR();
}
#endif
#ifdef NVIC_131_ENABLED
void NVIC_ISR_131(void){
	ISR_INTWDTBATIT();
}
#endif
#ifdef NVIC_132_ENABLED
void NVIC_ISR_132(void){
	ISR_INTDCUTDI();
}
#endif
#ifdef NVIC_133_ENABLED
void NVIC_ISR_133(void){
	ISR_INTSSIF0TX();
}
#endif
#ifdef NVIC_134_ENABLED
void NVIC_ISR_134(void){
	ISR_INTSSIF0RX();
}
#endif
#ifdef NVIC_135_ENABLED
void NVIC_ISR_135(void){
	ISR_INTSSIF0();
}
#endif
#ifdef NVIC_136_ENABLED
void NVIC_ISR_136(void){
	ISR_INTSSIF1TX();
}
#endif
#ifdef NVIC_137_ENABLED
void NVIC_ISR_137(void){
	ISR_INTSSIF1RX();
}
#endif
#ifdef NVIC_138_ENABLED
void NVIC_ISR_138(void){
	ISR_INTSSIF1();
}
#endif
#ifdef NVIC_139_ENABLED
void NVIC_ISR_139(void){
	ISR_IMFUP_25();
}
#endif
#ifdef NVIC_140_ENABLED
void NVIC_ISR_140(void){
	ISR_IMFUP_26();
}
#endif
#ifdef NVIC_141_ENABLED
void NVIC_ISR_141(void){
	ISR_IMFUP_27();
}
#endif
#ifdef NVIC_142_ENABLED
void NVIC_ISR_142(void){
	ISR_IMFUP_28();
}
#endif
#ifdef NVIC_143_ENABLED
void NVIC_ISR_143(void){
	ISR_IRQ7();
}
#endif
#ifdef NVIC_144_ENABLED
void NVIC_ISR_144(void){
	ISR_IRQ9();
}
#endif
#ifdef NVIC_145_ENABLED
void NVIC_ISR_145(void){
	ISR_IRQ10();
}
#endif
#ifdef NVIC_146_ENABLED
void NVIC_ISR_146(void){
	ISR_IRQ11();
}
#endif
#ifdef NVIC_147_ENABLED
void NVIC_ISR_147(void){
	ISR_IRQ12();
}
#endif
#ifdef NVIC_148_ENABLED
void NVIC_ISR_148(void){
	ISR_IRQ13();
}
#endif
#ifdef NVIC_149_ENABLED
void NVIC_ISR_149(void){
	ISR_IRQ14();
}
#endif
#ifdef NVIC_150_ENABLED
void NVIC_ISR_150(void){
	ISR_IRQ15();
}
#endif
#ifdef NVIC_151_ENABLED
void NVIC_ISR_151(void){
	ISR_IRQ17();
}
#endif
#ifdef NVIC_152_ENABLED
void NVIC_ISR_152(void){
	ISR_INTADCK1ERR();
}
#endif
#ifdef NVIC_153_ENABLED
void NVIC_ISR_153(void){
	ISR_INTADCK1I0();
}
#endif
#ifdef NVIC_154_ENABLED
void NVIC_ISR_154(void){
	ISR_INTADCK1I1();
}
#endif
#ifdef NVIC_155_ENABLED
void NVIC_ISR_155(void){
	ISR_INTADCK1I2();
}
#endif
#ifdef NVIC_156_ENABLED
void NVIC_ISR_156(void){
	ISR_INTADCK1I3();
}
#endif
#ifdef NVIC_157_ENABLED
void NVIC_ISR_157(void){
	ISR_INTADCK1I4();
}
#endif
#ifdef NVIC_158_ENABLED
void NVIC_ISR_158(void){
	ISR_INTADCK1MPX();
}
#endif
#ifdef NVIC_159_ENABLED
void NVIC_ISR_159(void){
	ISR_INTADCK1SD();
}
#endif
#ifdef NVIC_160_ENABLED
void NVIC_ISR_160(void){
	ISR_IMFUP_29();
}
#endif
#ifdef NVIC_161_ENABLED
void NVIC_ISR_161(void){
	ISR_IMFUP_30();
}
#endif
#ifdef NVIC_162_ENABLED
void NVIC_ISR_162(void){
	ISR_IMFUP_31();
}
#endif
#ifdef NVIC_163_ENABLED
void NVIC_ISR_163(void){
	ISR_IMFUP_32();
}
#endif
#ifdef NVIC_164_ENABLED
void NVIC_ISR_164(void){
	ISR_INTOSTM1TINT();
}
#endif
#ifdef NVIC_165_ENABLED
void NVIC_ISR_165(void){
	ISR_INTOSTM2TINT();
}
#endif
#ifdef NVIC_166_ENABLED
void NVIC_ISR_166(void){
	ISR_INTETNF0DATA();
}
#endif
#ifdef NVIC_167_ENABLED
void NVIC_ISR_167(void){
	ISR_INTETNF0ERR();
}
#endif
#ifdef NVIC_168_ENABLED
void NVIC_ISR_168(void){
	ISR_INTETNF0MNG();
}
#endif
#ifdef NVIC_169_ENABLED
void NVIC_ISR_169(void){
	ISR_INTETNF0MAC();
}
#endif
#ifdef NVIC_170_ENABLED
void NVIC_ISR_170(void){
	ISR_IRQ8();
}
#endif
#ifdef NVIC_171_ENABLED
void NVIC_ISR_171(void){
	ISR_INTPSI50SI();
}
#endif
#ifdef NVIC_172_ENABLED
void NVIC_ISR_172(void){
	ISR_INTPSI50RI();
}
#endif
#ifdef NVIC_173_ENABLED
void NVIC_ISR_173(void){
	ISR_INTPSI50TI();
}
#endif
#ifdef NVIC_174_ENABLED
void NVIC_ISR_174(void){
	ISR_INTPSI51SI();
}
#endif
#ifdef NVIC_175_ENABLED
void NVIC_ISR_175(void){
	ISR_INTPSI51RI();
}
#endif
#ifdef NVIC_176_ENABLED
void NVIC_ISR_176(void){
	ISR_INTPSI51TI();
}
#endif
#ifdef NVIC_177_ENABLED
void NVIC_ISR_177(void){
	ISR_INTPSI5W();
}
#endif
#ifdef NVIC_178_ENABLED
void NVIC_ISR_178(void){
	ISR_INTMMCA0();
}
#endif
#ifdef NVIC_179_ENABLED
void NVIC_ISR_179(void){
	ISR_INTOSTM3TINT();
}
#endif
#ifdef NVIC_180_ENABLED
void NVIC_ISR_180(void){
	ISR_INTOSTM4TINT();
}
#endif
#ifdef NVIC_181_ENABLED
void NVIC_ISR_181(void){
	ISR_INTXCAN1FUNC();
}
#endif
#ifdef NVIC_182_ENABLED
void NVIC_ISR_182(void){
	ISR_INTXCAN1ERR();
}
#endif
#ifdef NVIC_183_ENABLED
void NVIC_ISR_183(void){
	ISR_INTXCAN1SAFETY();
}
#endif
#ifdef NVIC_184_ENABLED
void NVIC_ISR_184(void){
	ISR_INTETND00();
}
#endif
#ifdef NVIC_185_ENABLED
void NVIC_ISR_185(void){
	ISR_INTETND01();
}
#endif
#ifdef NVIC_186_ENABLED
void NVIC_ISR_186(void){
	ISR_INTETND02();
}
#endif
#ifdef NVIC_187_ENABLED
void NVIC_ISR_187(void){
	ISR_INTETND03();
}
#endif
#ifdef NVIC_188_ENABLED
void NVIC_ISR_188(void){
	ISR_INTETND04();
}
#endif
#ifdef NVIC_189_ENABLED
void NVIC_ISR_189(void){
	ISR_INTETND05();
}
#endif
#ifdef NVIC_190_ENABLED
void NVIC_ISR_190(void){
	ISR_INTETND06();
}
#endif
#ifdef NVIC_191_ENABLED
void NVIC_ISR_191(void){
	ISR_INTGPTP();
}
#endif
#ifdef NVIC_192_ENABLED
void NVIC_ISR_192(void){
	ISR_IRQ25();
}
#endif
#ifdef NVIC_193_ENABLED
void NVIC_ISR_193(void){
	ISR_IMFUP_33();
}
#endif
#ifdef NVIC_194_ENABLED
void NVIC_ISR_194(void){
	ISR_IMFUP_34();
}
#endif
#ifdef NVIC_195_ENABLED
void NVIC_ISR_195(void){
	ISR_IMFUP_35();
}
#endif
#ifdef NVIC_196_ENABLED
void NVIC_ISR_196(void){
	ISR_IMFUP_36();
}
#endif
void UNMASK_ISR_INTECMNMI(void){
	NVIC_ENABLE_IRQ((int32_t)0);
}
void UNMASK_ISR_INTECMMI(void){
	NVIC_ENABLE_IRQ((int32_t)1);
}
void UNMASK_ISR_INTFPUEXCIRQ(void){
	NVIC_ENABLE_IRQ((int32_t)2);
}
void UNMASK_ISR_INTTAUD0I0(void){
	NVIC_ENABLE_IRQ((int32_t)3);
}
void UNMASK_ISR_INTTAUD0I2(void){
	NVIC_ENABLE_IRQ((int32_t)4);
}
void UNMASK_ISR_INTTAUD0I4(void){
	NVIC_ENABLE_IRQ((int32_t)5);
}
void UNMASK_ISR_INTTAUD0I6(void){
	NVIC_ENABLE_IRQ((int32_t)6);
}
void UNMASK_ISR_INTEINTSW0(void){
	NVIC_ENABLE_IRQ((int32_t)7);
}
void UNMASK_ISR_INTEINTSW1(void){
	NVIC_ENABLE_IRQ((int32_t)8);
}
void UNMASK_ISR_INTEINTSW2(void){
	NVIC_ENABLE_IRQ((int32_t)9);
}
void UNMASK_ISR_INTEINTSW3(void){
	NVIC_ENABLE_IRQ((int32_t)10);
}
void UNMASK_ISR_INTS2HS0(void){
	NVIC_ENABLE_IRQ((int32_t)11);
}
void UNMASK_ISR_INTWDTB0TIT(void){
	NVIC_ENABLE_IRQ((int32_t)12);
}
void UNMASK_ISR_INTTAUD0I8(void){
	NVIC_ENABLE_IRQ((int32_t)13);
}
void UNMASK_ISR_INTTAUD0I10(void){
	NVIC_ENABLE_IRQ((int32_t)14);
}
void UNMASK_ISR_INTTAUD0I12(void){
	NVIC_ENABLE_IRQ((int32_t)15);
}
void UNMASK_ISR_INTTAUD0I14(void){
	NVIC_ENABLE_IRQ((int32_t)16);
}
void UNMASK_ISR_INTTAPA0IPEK0(void){
	NVIC_ENABLE_IRQ((int32_t)17);
}
void UNMASK_ISR_INTTAPA0IVLY0(void){
	NVIC_ENABLE_IRQ((int32_t)18);
}
void UNMASK_ISR_INTPDMACERR(void){
	NVIC_ENABLE_IRQ((int32_t)19);
}
void UNMASK_ISR_INTDTSERR(void){
	NVIC_ENABLE_IRQ((int32_t)20);
}
void UNMASK_ISR_INTDCUDEGRADPE(void){
	NVIC_ENABLE_IRQ((int32_t)21);
}
void UNMASK_ISR_INTFL0ENDNM(void){
	NVIC_ENABLE_IRQ((int32_t)22);
}
void UNMASK_ISR_INTFL2ENDNM(void){
	NVIC_ENABLE_IRQ((int32_t)23);
}
void UNMASK_ISR_INTDTS7TO0(void){
	NVIC_ENABLE_IRQ((int32_t)24);
}
void UNMASK_ISR_INTDTSCT7TO0(void){
	NVIC_ENABLE_IRQ((int32_t)25);
}
void UNMASK_ISR_INTPDMAC0CH0(void){
	NVIC_ENABLE_IRQ((int32_t)26);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_0, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC0CH2(void){
	NVIC_ENABLE_IRQ((int32_t)26);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_0, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC0CH4(void){
	NVIC_ENABLE_IRQ((int32_t)26);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_0, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC0CH6(void){
	NVIC_ENABLE_IRQ((int32_t)26);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_0, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC0CH1(void){
	NVIC_ENABLE_IRQ((int32_t)27);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_1, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC0CH3(void){
	NVIC_ENABLE_IRQ((int32_t)27);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_1, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC0CH5(void){
	NVIC_ENABLE_IRQ((int32_t)27);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_1, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC0CH7(void){
	NVIC_ENABLE_IRQ((int32_t)27);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_1, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTOSTM0TINT(void){
	NVIC_ENABLE_IRQ((int32_t)28);
}
void UNMASK_ISR_INTADCK0ERR(void){
	NVIC_ENABLE_IRQ((int32_t)29);
}
void UNMASK_ISR_INTADCK0I0(void){
	NVIC_ENABLE_IRQ((int32_t)30);
}
void UNMASK_ISR_INTADCK0I1(void){
	NVIC_ENABLE_IRQ((int32_t)31);
}
void UNMASK_ISR_INTADCK0I2(void){
	NVIC_ENABLE_IRQ((int32_t)32);
}
void UNMASK_ISR_INTADCK0I3(void){
	NVIC_ENABLE_IRQ((int32_t)33);
}
void UNMASK_ISR_INTADCK0I4(void){
	NVIC_ENABLE_IRQ((int32_t)34);
}
void UNMASK_ISR_INTADCK0MPX(void){
	NVIC_ENABLE_IRQ((int32_t)35);
}
void UNMASK_ISR_INTADCK0SD(void){
	NVIC_ENABLE_IRQ((int32_t)36);
}
void UNMASK_ISR_INTCSIH0IC(void){
	NVIC_ENABLE_IRQ((int32_t)37);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_2, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH2IC(void){
	NVIC_ENABLE_IRQ((int32_t)37);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_2, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH4IC(void){
	NVIC_ENABLE_IRQ((int32_t)37);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_2, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH6IC(void){
	NVIC_ENABLE_IRQ((int32_t)37);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_2, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH1IC(void){
	NVIC_ENABLE_IRQ((int32_t)38);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_3, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH3IC(void){
	NVIC_ENABLE_IRQ((int32_t)38);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_3, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH5IC(void){
	NVIC_ENABLE_IRQ((int32_t)38);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_3, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH7IC(void){
	NVIC_ENABLE_IRQ((int32_t)38);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_3, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH0IR(void){
	NVIC_ENABLE_IRQ((int32_t)39);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_4, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH2IR(void){
	NVIC_ENABLE_IRQ((int32_t)39);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_4, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH4IR(void){
	NVIC_ENABLE_IRQ((int32_t)39);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_4, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH6IR(void){
	NVIC_ENABLE_IRQ((int32_t)39);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_4, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH1IR(void){
	NVIC_ENABLE_IRQ((int32_t)40);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_5, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH3IR(void){
	NVIC_ENABLE_IRQ((int32_t)40);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_5, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH5IR(void){
	NVIC_ENABLE_IRQ((int32_t)40);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_5, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH7IR(void){
	NVIC_ENABLE_IRQ((int32_t)40);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_5, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH0IRE(void){
	NVIC_ENABLE_IRQ((int32_t)41);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_6, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH2IRE(void){
	NVIC_ENABLE_IRQ((int32_t)41);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_6, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH4IRE(void){
	NVIC_ENABLE_IRQ((int32_t)41);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_6, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH6IRE(void){
	NVIC_ENABLE_IRQ((int32_t)41);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_6, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH1IRE(void){
	NVIC_ENABLE_IRQ((int32_t)42);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_7, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH3IRE(void){
	NVIC_ENABLE_IRQ((int32_t)42);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_7, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH5IRE(void){
	NVIC_ENABLE_IRQ((int32_t)42);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_7, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH7IRE(void){
	NVIC_ENABLE_IRQ((int32_t)42);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_7, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH0IJC(void){
	NVIC_ENABLE_IRQ((int32_t)43);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_8, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH2IJC(void){
	NVIC_ENABLE_IRQ((int32_t)43);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_8, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH4IJC(void){
	NVIC_ENABLE_IRQ((int32_t)43);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_8, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH6IJC(void){
	NVIC_ENABLE_IRQ((int32_t)43);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_8, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH1IJC(void){
	NVIC_ENABLE_IRQ((int32_t)44);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_9, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH3IJC(void){
	NVIC_ENABLE_IRQ((int32_t)44);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_9, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH5IJC(void){
	NVIC_ENABLE_IRQ((int32_t)44);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_9, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCSIH7IJC(void){
	NVIC_ENABLE_IRQ((int32_t)44);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_9, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCANGERR0(void){
	NVIC_ENABLE_IRQ((int32_t)45);
}
void UNMASK_ISR_INTRCANGRECC0(void){
	NVIC_ENABLE_IRQ((int32_t)46);
}
void UNMASK_ISR_INTRCAN0ERR(void){
	NVIC_ENABLE_IRQ((int32_t)47);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_0, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN2ERR(void){
	NVIC_ENABLE_IRQ((int32_t)47);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_0, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN4ERR(void){
	NVIC_ENABLE_IRQ((int32_t)47);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_0, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN1ERR(void){
	NVIC_ENABLE_IRQ((int32_t)48);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_1, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN3ERR(void){
	NVIC_ENABLE_IRQ((int32_t)48);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_1, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN5ERR(void){
	NVIC_ENABLE_IRQ((int32_t)48);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_1, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN0REC(void){
	NVIC_ENABLE_IRQ((int32_t)49);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_2, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN2REC(void){
	NVIC_ENABLE_IRQ((int32_t)49);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_2, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN4REC(void){
	NVIC_ENABLE_IRQ((int32_t)49);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_2, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN1REC(void){
	NVIC_ENABLE_IRQ((int32_t)50);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_3, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN3REC(void){
	NVIC_ENABLE_IRQ((int32_t)50);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_3, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN5REC(void){
	NVIC_ENABLE_IRQ((int32_t)50);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_3, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN0TRX(void){
	NVIC_ENABLE_IRQ((int32_t)51);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_4, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN2TRX(void){
	NVIC_ENABLE_IRQ((int32_t)51);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_4, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN4TRX(void){
	NVIC_ENABLE_IRQ((int32_t)51);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_4, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN1TRX(void){
	NVIC_ENABLE_IRQ((int32_t)52);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_5, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN3TRX(void){
	NVIC_ENABLE_IRQ((int32_t)52);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_5, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRCAN5TRX(void){
	NVIC_ENABLE_IRQ((int32_t)52);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_5, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTXCAN0FUNC(void){
	NVIC_ENABLE_IRQ((int32_t)53);
}
void UNMASK_ISR_INTXCAN0ERR(void){
	NVIC_ENABLE_IRQ((int32_t)54);
}
void UNMASK_ISR_INTXCAN0SAFETY(void){
	NVIC_ENABLE_IRQ((int32_t)55);
}
void UNMASK_ISR_INTTAUJ0I0(void){
	NVIC_ENABLE_IRQ((int32_t)56);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_10, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ0I1(void){
	NVIC_ENABLE_IRQ((int32_t)56);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_10, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ0I2(void){
	NVIC_ENABLE_IRQ((int32_t)56);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_10, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ0I3(void){
	NVIC_ENABLE_IRQ((int32_t)56);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_10, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ1I0(void){
	NVIC_ENABLE_IRQ((int32_t)57);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_11, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ1I1(void){
	NVIC_ENABLE_IRQ((int32_t)57);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_11, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ1I2(void){
	NVIC_ENABLE_IRQ((int32_t)57);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_11, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ1I3(void){
	NVIC_ENABLE_IRQ((int32_t)57);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_11, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ2I0(void){
	NVIC_ENABLE_IRQ((int32_t)58);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_12, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ2I1(void){
	NVIC_ENABLE_IRQ((int32_t)58);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_12, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ2I2(void){
	NVIC_ENABLE_IRQ((int32_t)58);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_12, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ2I3(void){
	NVIC_ENABLE_IRQ((int32_t)58);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_12, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ3I0(void){
	NVIC_ENABLE_IRQ((int32_t)59);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_13, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ3I1(void){
	NVIC_ENABLE_IRQ((int32_t)59);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_13, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ3I2(void){
	NVIC_ENABLE_IRQ((int32_t)59);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_13, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUJ3I3(void){
	NVIC_ENABLE_IRQ((int32_t)59);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_13, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD0I1(void){
	NVIC_ENABLE_IRQ((int32_t)60);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_14, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD0I3(void){
	NVIC_ENABLE_IRQ((int32_t)60);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_14, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD0I5(void){
	NVIC_ENABLE_IRQ((int32_t)60);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_14, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD0I7(void){
	NVIC_ENABLE_IRQ((int32_t)60);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_14, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD0I9(void){
	NVIC_ENABLE_IRQ((int32_t)60);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_14, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD0I11(void){
	NVIC_ENABLE_IRQ((int32_t)60);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_14, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD0I13(void){
	NVIC_ENABLE_IRQ((int32_t)60);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_14, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD0I15(void){
	NVIC_ENABLE_IRQ((int32_t)60);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_14, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I0(void){
	NVIC_ENABLE_IRQ((int32_t)61);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_15, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I2(void){
	NVIC_ENABLE_IRQ((int32_t)61);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_15, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I4(void){
	NVIC_ENABLE_IRQ((int32_t)61);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_15, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I6(void){
	NVIC_ENABLE_IRQ((int32_t)61);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_15, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I8(void){
	NVIC_ENABLE_IRQ((int32_t)61);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_15, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I10(void){
	NVIC_ENABLE_IRQ((int32_t)61);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_15, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I12(void){
	NVIC_ENABLE_IRQ((int32_t)61);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_15, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I14(void){
	NVIC_ENABLE_IRQ((int32_t)61);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_15, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I1(void){
	NVIC_ENABLE_IRQ((int32_t)62);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_16, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I3(void){
	NVIC_ENABLE_IRQ((int32_t)62);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_16, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I5(void){
	NVIC_ENABLE_IRQ((int32_t)62);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_16, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I7(void){
	NVIC_ENABLE_IRQ((int32_t)62);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_16, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I9(void){
	NVIC_ENABLE_IRQ((int32_t)62);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_16, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I11(void){
	NVIC_ENABLE_IRQ((int32_t)62);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_16, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I13(void){
	NVIC_ENABLE_IRQ((int32_t)62);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_16, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD1I15(void){
	NVIC_ENABLE_IRQ((int32_t)62);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_16, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN30(void){
	NVIC_ENABLE_IRQ((int32_t)63);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_17, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN31(void){
	NVIC_ENABLE_IRQ((int32_t)63);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_17, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN32(void){
	NVIC_ENABLE_IRQ((int32_t)63);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_17, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN33(void){
	NVIC_ENABLE_IRQ((int32_t)63);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_17, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN34(void){
	NVIC_ENABLE_IRQ((int32_t)63);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_17, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN35(void){
	NVIC_ENABLE_IRQ((int32_t)63);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_17, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN36(void){
	NVIC_ENABLE_IRQ((int32_t)63);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_17, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN37(void){
	NVIC_ENABLE_IRQ((int32_t)63);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_17, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN30UR0(void){
	NVIC_ENABLE_IRQ((int32_t)64);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_18, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN31UR0(void){
	NVIC_ENABLE_IRQ((int32_t)64);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_18, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN32UR0(void){
	NVIC_ENABLE_IRQ((int32_t)64);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_18, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN33UR0(void){
	NVIC_ENABLE_IRQ((int32_t)64);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_18, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN34UR0(void){
	NVIC_ENABLE_IRQ((int32_t)64);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_18, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN35UR0(void){
	NVIC_ENABLE_IRQ((int32_t)64);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_18, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN36UR0(void){
	NVIC_ENABLE_IRQ((int32_t)64);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_18, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN37UR0(void){
	NVIC_ENABLE_IRQ((int32_t)64);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_18, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN30UR1(void){
	NVIC_ENABLE_IRQ((int32_t)65);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_19, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN31UR1(void){
	NVIC_ENABLE_IRQ((int32_t)65);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_19, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN32UR1(void){
	NVIC_ENABLE_IRQ((int32_t)65);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_19, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN33UR1(void){
	NVIC_ENABLE_IRQ((int32_t)65);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_19, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN34UR1(void){
	NVIC_ENABLE_IRQ((int32_t)65);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_19, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN35UR1(void){
	NVIC_ENABLE_IRQ((int32_t)65);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_19, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN36UR1(void){
	NVIC_ENABLE_IRQ((int32_t)65);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_19, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN37UR1(void){
	NVIC_ENABLE_IRQ((int32_t)65);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_19, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN30UR2(void){
	NVIC_ENABLE_IRQ((int32_t)66);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_20, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN31UR2(void){
	NVIC_ENABLE_IRQ((int32_t)66);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_20, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN32UR2(void){
	NVIC_ENABLE_IRQ((int32_t)66);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_20, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN33UR2(void){
	NVIC_ENABLE_IRQ((int32_t)66);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_20, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN34UR2(void){
	NVIC_ENABLE_IRQ((int32_t)66);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_20, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN35UR2(void){
	NVIC_ENABLE_IRQ((int32_t)66);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_20, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN36UR2(void){
	NVIC_ENABLE_IRQ((int32_t)66);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_20, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN37UR2(void){
	NVIC_ENABLE_IRQ((int32_t)66);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_20, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT0RI(void){
	NVIC_ENABLE_IRQ((int32_t)67);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_21, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT2RI(void){
	NVIC_ENABLE_IRQ((int32_t)67);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_21, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT4RI(void){
	NVIC_ENABLE_IRQ((int32_t)67);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_21, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT6RI(void){
	NVIC_ENABLE_IRQ((int32_t)67);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_21, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT1RI(void){
	NVIC_ENABLE_IRQ((int32_t)68);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_22, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT3RI(void){
	NVIC_ENABLE_IRQ((int32_t)68);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_22, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT5RI(void){
	NVIC_ENABLE_IRQ((int32_t)68);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_22, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT7RI(void){
	NVIC_ENABLE_IRQ((int32_t)68);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_22, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT0SI(void){
	NVIC_ENABLE_IRQ((int32_t)69);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_6, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT2SI(void){
	NVIC_ENABLE_IRQ((int32_t)69);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_6, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT4SI(void){
	NVIC_ENABLE_IRQ((int32_t)69);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_6, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT6SI(void){
	NVIC_ENABLE_IRQ((int32_t)69);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_6, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT1SI(void){
	NVIC_ENABLE_IRQ((int32_t)70);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_7, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT3SI(void){
	NVIC_ENABLE_IRQ((int32_t)70);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_7, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT5SI(void){
	NVIC_ENABLE_IRQ((int32_t)70);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_7, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSENT7SI(void){
	NVIC_ENABLE_IRQ((int32_t)70);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_7, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTENCA0IOV(void){
	NVIC_ENABLE_IRQ((int32_t)71);
}
void UNMASK_ISR_INTENCA0I0(void){
	NVIC_ENABLE_IRQ((int32_t)72);
}
void UNMASK_ISR_INTENCA0I1(void){
	NVIC_ENABLE_IRQ((int32_t)73);
}
void UNMASK_ISR_INTENCA0IUD(void){
	NVIC_ENABLE_IRQ((int32_t)74);
}
void UNMASK_ISR_INTENCA0IEC(void){
	NVIC_ENABLE_IRQ((int32_t)75);
}
void UNMASK_ISR_IRQ0(void){
	NVIC_ENABLE_IRQ((int32_t)77);
}
void UNMASK_ISR_IRQ1(void){
	NVIC_ENABLE_IRQ((int32_t)78);
}
void UNMASK_ISR_IRQ2(void){
	NVIC_ENABLE_IRQ((int32_t)79);
}
void UNMASK_ISR_IRQ3(void){
	NVIC_ENABLE_IRQ((int32_t)80);
}
void UNMASK_ISR_IRQ4(void){
	NVIC_ENABLE_IRQ((int32_t)81);
}
void UNMASK_ISR_IRQ5(void){
	NVIC_ENABLE_IRQ((int32_t)82);
}
void UNMASK_ISR_IRQ6(void){
	NVIC_ENABLE_IRQ((int32_t)83);
}
void UNMASK_ISR_IRQ16(void){
	NVIC_ENABLE_IRQ((int32_t)84);
}
void UNMASK_ISR_IRQ18(void){
	NVIC_ENABLE_IRQ((int32_t)85);
}
void UNMASK_ISR_IRQ19(void){
	NVIC_ENABLE_IRQ((int32_t)86);
}
void UNMASK_ISR_IRQ20(void){
	NVIC_ENABLE_IRQ((int32_t)87);
}
void UNMASK_ISR_IRQ21(void){
	NVIC_ENABLE_IRQ((int32_t)88);
}
void UNMASK_ISR_IRQ22(void){
	NVIC_ENABLE_IRQ((int32_t)89);
}
void UNMASK_ISR_IRQ23(void){
	NVIC_ENABLE_IRQ((int32_t)90);
}
void UNMASK_ISR_IRQ24(void){
	NVIC_ENABLE_IRQ((int32_t)91);
}
void UNMASK_ISR_INTRTCA01S(void){
	NVIC_ENABLE_IRQ((int32_t)92);
}
void UNMASK_ISR_INTRTCA0AL(void){
	NVIC_ENABLE_IRQ((int32_t)93);
}
void UNMASK_ISR_INTRTCA0R(void){
	NVIC_ENABLE_IRQ((int32_t)94);
}
void UNMASK_ISR_INTS2H0(void){
	NVIC_ENABLE_IRQ((int32_t)95);
}
void UNMASK_ISR_INTPWGCG00(void){
	NVIC_ENABLE_IRQ((int32_t)96);
}
void UNMASK_ISR_INTPWGCG01(void){
	NVIC_ENABLE_IRQ((int32_t)97);
}
void UNMASK_ISR_INTPWGCG02(void){
	NVIC_ENABLE_IRQ((int32_t)98);
}
void UNMASK_ISR_INTPWSDQFULL(void){
	NVIC_ENABLE_IRQ((int32_t)99);
}
void UNMASK_ISR_INTCXP10TI(void){
	NVIC_ENABLE_IRQ((int32_t)100);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_8, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCXP12TI(void){
	NVIC_ENABLE_IRQ((int32_t)100);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_8, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCXP10RI(void){
	NVIC_ENABLE_IRQ((int32_t)101);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_9, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCXP12RI(void){
	NVIC_ENABLE_IRQ((int32_t)101);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_9, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCXP10SI(void){
	NVIC_ENABLE_IRQ((int32_t)102);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_10, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCXP12SI(void){
	NVIC_ENABLE_IRQ((int32_t)102);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_10, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCXP11TI(void){
	NVIC_ENABLE_IRQ((int32_t)103);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_11, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCXP13TI(void){
	NVIC_ENABLE_IRQ((int32_t)103);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_11, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCXP11RI(void){
	NVIC_ENABLE_IRQ((int32_t)104);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_12, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCXP13RI(void){
	NVIC_ENABLE_IRQ((int32_t)104);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_12, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCXP11SI(void){
	NVIC_ENABLE_IRQ((int32_t)105);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_13, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTCXP13SI(void){
	NVIC_ENABLE_IRQ((int32_t)105);
	CONFIG_MASK_IMFU(IMFU_LEVEL, IMFU_13, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRI3C0RESP(void){
	NVIC_ENABLE_IRQ((int32_t)106);
}
void UNMASK_ISR_INTRI3C0CMD(void){
	NVIC_ENABLE_IRQ((int32_t)107);
}
void UNMASK_ISR_INTRI3C0IBI(void){
	NVIC_ENABLE_IRQ((int32_t)108);
}
void UNMASK_ISR_INTRI3C0RX0(void){
	NVIC_ENABLE_IRQ((int32_t)109);
}
void UNMASK_ISR_INTRI3C0TX0(void){
	NVIC_ENABLE_IRQ((int32_t)110);
}
void UNMASK_ISR_INTRI3C0RCV(void){
	NVIC_ENABLE_IRQ((int32_t)111);
}
void UNMASK_ISR_INTRI3C0HRESP(void){
	NVIC_ENABLE_IRQ((int32_t)112);
}
void UNMASK_ISR_INTRI3C0HCMD(void){
	NVIC_ENABLE_IRQ((int32_t)113);
}
void UNMASK_ISR_INTRI3C0HRX(void){
	NVIC_ENABLE_IRQ((int32_t)114);
}
void UNMASK_ISR_INTRI3C0HTX(void){
	NVIC_ENABLE_IRQ((int32_t)115);
}
void UNMASK_ISR_INTRI3C0TEND(void){
	NVIC_ENABLE_IRQ((int32_t)116);
}
void UNMASK_ISR_INTRI3C0EEI(void){
	NVIC_ENABLE_IRQ((int32_t)117);
}
void UNMASK_ISR_INTRIIC0EE(void){
	NVIC_ENABLE_IRQ((int32_t)118);
}
void UNMASK_ISR_INTRIIC0RI(void){
	NVIC_ENABLE_IRQ((int32_t)119);
}
void UNMASK_ISR_INTRIIC0TI(void){
	NVIC_ENABLE_IRQ((int32_t)120);
}
void UNMASK_ISR_INTRIIC0TEI(void){
	NVIC_ENABLE_IRQ((int32_t)121);
}
void UNMASK_ISR_INTRIIC1EE(void){
	NVIC_ENABLE_IRQ((int32_t)122);
}
void UNMASK_ISR_INTRIIC1RI(void){
	NVIC_ENABLE_IRQ((int32_t)123);
}
void UNMASK_ISR_INTRIIC1TI(void){
	NVIC_ENABLE_IRQ((int32_t)124);
}
void UNMASK_ISR_INTRIIC1TEI(void){
	NVIC_ENABLE_IRQ((int32_t)125);
}
void UNMASK_ISR_INTCWEND(void){
	NVIC_ENABLE_IRQ((int32_t)126);
}
void UNMASK_ISR_INTDPE(void){
	NVIC_ENABLE_IRQ((int32_t)127);
}
void UNMASK_ISR_INTLPSTM0(void){
	NVIC_ENABLE_IRQ((int32_t)128);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_23, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTLPSTM2(void){
	NVIC_ENABLE_IRQ((int32_t)128);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_23, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTLPSTM4(void){
	NVIC_ENABLE_IRQ((int32_t)128);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_23, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTLPSTM1(void){
	NVIC_ENABLE_IRQ((int32_t)129);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_24, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTLPSTM3(void){
	NVIC_ENABLE_IRQ((int32_t)129);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_24, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRSIPMFATALERR(void){
	NVIC_ENABLE_IRQ((int32_t)130);
}
void UNMASK_ISR_INTWDTBATIT(void){
	NVIC_ENABLE_IRQ((int32_t)131);
}
void UNMASK_ISR_INTDCUTDI(void){
	NVIC_ENABLE_IRQ((int32_t)132);
}
void UNMASK_ISR_INTSSIF0TX(void){
	NVIC_ENABLE_IRQ((int32_t)133);
}
void UNMASK_ISR_INTSSIF0RX(void){
	NVIC_ENABLE_IRQ((int32_t)134);
}
void UNMASK_ISR_INTSSIF0(void){
	NVIC_ENABLE_IRQ((int32_t)135);
}
void UNMASK_ISR_INTSSIF1TX(void){
	NVIC_ENABLE_IRQ((int32_t)136);
}
void UNMASK_ISR_INTSSIF1RX(void){
	NVIC_ENABLE_IRQ((int32_t)137);
}
void UNMASK_ISR_INTSSIF1(void){
	NVIC_ENABLE_IRQ((int32_t)138);
}
void UNMASK_ISR_INTPDMAC1CH0(void){
	NVIC_ENABLE_IRQ((int32_t)139);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_25, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC1CH2(void){
	NVIC_ENABLE_IRQ((int32_t)139);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_25, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC1CH4(void){
	NVIC_ENABLE_IRQ((int32_t)139);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_25, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC1CH6(void){
	NVIC_ENABLE_IRQ((int32_t)139);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_25, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC1CH1(void){
	NVIC_ENABLE_IRQ((int32_t)140);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_26, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC1CH3(void){
	NVIC_ENABLE_IRQ((int32_t)140);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_26, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC1CH5(void){
	NVIC_ENABLE_IRQ((int32_t)140);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_26, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTPDMAC1CH7(void){
	NVIC_ENABLE_IRQ((int32_t)140);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_26, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I0(void){
	NVIC_ENABLE_IRQ((int32_t)141);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_27, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I2(void){
	NVIC_ENABLE_IRQ((int32_t)141);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_27, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I4(void){
	NVIC_ENABLE_IRQ((int32_t)141);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_27, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I6(void){
	NVIC_ENABLE_IRQ((int32_t)141);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_27, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I8(void){
	NVIC_ENABLE_IRQ((int32_t)141);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_27, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I10(void){
	NVIC_ENABLE_IRQ((int32_t)141);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_27, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I12(void){
	NVIC_ENABLE_IRQ((int32_t)141);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_27, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I14(void){
	NVIC_ENABLE_IRQ((int32_t)141);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_27, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I1(void){
	NVIC_ENABLE_IRQ((int32_t)142);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_28, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I3(void){
	NVIC_ENABLE_IRQ((int32_t)142);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_28, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I5(void){
	NVIC_ENABLE_IRQ((int32_t)142);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_28, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I7(void){
	NVIC_ENABLE_IRQ((int32_t)142);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_28, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I9(void){
	NVIC_ENABLE_IRQ((int32_t)142);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_28, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I11(void){
	NVIC_ENABLE_IRQ((int32_t)142);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_28, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I13(void){
	NVIC_ENABLE_IRQ((int32_t)142);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_28, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTTAUD2I15(void){
	NVIC_ENABLE_IRQ((int32_t)142);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_28, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_IRQ7(void){
	NVIC_ENABLE_IRQ((int32_t)143);
}
void UNMASK_ISR_IRQ9(void){
	NVIC_ENABLE_IRQ((int32_t)144);
}
void UNMASK_ISR_IRQ10(void){
	NVIC_ENABLE_IRQ((int32_t)145);
}
void UNMASK_ISR_IRQ11(void){
	NVIC_ENABLE_IRQ((int32_t)146);
}
void UNMASK_ISR_IRQ12(void){
	NVIC_ENABLE_IRQ((int32_t)147);
}
void UNMASK_ISR_IRQ13(void){
	NVIC_ENABLE_IRQ((int32_t)148);
}
void UNMASK_ISR_IRQ14(void){
	NVIC_ENABLE_IRQ((int32_t)149);
}
void UNMASK_ISR_IRQ15(void){
	NVIC_ENABLE_IRQ((int32_t)150);
}
void UNMASK_ISR_IRQ17(void){
	NVIC_ENABLE_IRQ((int32_t)151);
}
void UNMASK_ISR_INTADCK1ERR(void){
	NVIC_ENABLE_IRQ((int32_t)152);
}
void UNMASK_ISR_INTADCK1I0(void){
	NVIC_ENABLE_IRQ((int32_t)153);
}
void UNMASK_ISR_INTADCK1I1(void){
	NVIC_ENABLE_IRQ((int32_t)154);
}
void UNMASK_ISR_INTADCK1I2(void){
	NVIC_ENABLE_IRQ((int32_t)155);
}
void UNMASK_ISR_INTADCK1I3(void){
	NVIC_ENABLE_IRQ((int32_t)156);
}
void UNMASK_ISR_INTADCK1I4(void){
	NVIC_ENABLE_IRQ((int32_t)157);
}
void UNMASK_ISR_INTADCK1MPX(void){
	NVIC_ENABLE_IRQ((int32_t)158);
}
void UNMASK_ISR_INTADCK1SD(void){
	NVIC_ENABLE_IRQ((int32_t)159);
}
void UNMASK_ISR_INTRLIN38(void){
	NVIC_ENABLE_IRQ((int32_t)160);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_29, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN39(void){
	NVIC_ENABLE_IRQ((int32_t)160);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_29, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN310(void){
	NVIC_ENABLE_IRQ((int32_t)160);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_29, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN311(void){
	NVIC_ENABLE_IRQ((int32_t)160);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_29, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN312(void){
	NVIC_ENABLE_IRQ((int32_t)160);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_29, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN313(void){
	NVIC_ENABLE_IRQ((int32_t)160);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_29, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN314(void){
	NVIC_ENABLE_IRQ((int32_t)160);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_29, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN315(void){
	NVIC_ENABLE_IRQ((int32_t)160);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_29, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN38UR0(void){
	NVIC_ENABLE_IRQ((int32_t)161);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_30, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN39UR0(void){
	NVIC_ENABLE_IRQ((int32_t)161);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_30, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN310UR0(void){
	NVIC_ENABLE_IRQ((int32_t)161);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_30, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN311UR0(void){
	NVIC_ENABLE_IRQ((int32_t)161);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_30, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN312UR0(void){
	NVIC_ENABLE_IRQ((int32_t)161);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_30, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN313UR0(void){
	NVIC_ENABLE_IRQ((int32_t)161);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_30, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN314UR0(void){
	NVIC_ENABLE_IRQ((int32_t)161);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_30, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN315UR0(void){
	NVIC_ENABLE_IRQ((int32_t)161);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_30, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN38UR1(void){
	NVIC_ENABLE_IRQ((int32_t)162);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_31, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN39UR1(void){
	NVIC_ENABLE_IRQ((int32_t)162);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_31, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN310UR1(void){
	NVIC_ENABLE_IRQ((int32_t)162);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_31, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN311UR1(void){
	NVIC_ENABLE_IRQ((int32_t)162);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_31, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN312UR1(void){
	NVIC_ENABLE_IRQ((int32_t)162);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_31, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN313UR1(void){
	NVIC_ENABLE_IRQ((int32_t)162);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_31, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN314UR1(void){
	NVIC_ENABLE_IRQ((int32_t)162);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_31, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN315UR1(void){
	NVIC_ENABLE_IRQ((int32_t)162);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_31, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN38UR2(void){
	NVIC_ENABLE_IRQ((int32_t)163);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_32, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN39UR2(void){
	NVIC_ENABLE_IRQ((int32_t)163);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_32, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN310UR2(void){
	NVIC_ENABLE_IRQ((int32_t)163);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_32, IMFU_BIT_2, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN311UR2(void){
	NVIC_ENABLE_IRQ((int32_t)163);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_32, IMFU_BIT_3, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN312UR2(void){
	NVIC_ENABLE_IRQ((int32_t)163);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_32, IMFU_BIT_4, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN313UR2(void){
	NVIC_ENABLE_IRQ((int32_t)163);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_32, IMFU_BIT_5, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN314UR2(void){
	NVIC_ENABLE_IRQ((int32_t)163);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_32, IMFU_BIT_6, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN315UR2(void){
	NVIC_ENABLE_IRQ((int32_t)163);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_32, IMFU_BIT_7, IMFU_UNMASKED);
}
void UNMASK_ISR_INTOSTM1TINT(void){
	NVIC_ENABLE_IRQ((int32_t)164);
}
void UNMASK_ISR_INTOSTM2TINT(void){
	NVIC_ENABLE_IRQ((int32_t)165);
}
void UNMASK_ISR_INTETNF0DATA(void){
	NVIC_ENABLE_IRQ((int32_t)166);
}
void UNMASK_ISR_INTETNF0ERR(void){
	NVIC_ENABLE_IRQ((int32_t)167);
}
void UNMASK_ISR_INTETNF0MNG(void){
	NVIC_ENABLE_IRQ((int32_t)168);
}
void UNMASK_ISR_INTETNF0MAC(void){
	NVIC_ENABLE_IRQ((int32_t)169);
}
void UNMASK_ISR_IRQ8(void){
	NVIC_ENABLE_IRQ((int32_t)170);
}
void UNMASK_ISR_INTPSI50SI(void){
	NVIC_ENABLE_IRQ((int32_t)171);
}
void UNMASK_ISR_INTPSI50RI(void){
	NVIC_ENABLE_IRQ((int32_t)172);
}
void UNMASK_ISR_INTPSI50TI(void){
	NVIC_ENABLE_IRQ((int32_t)173);
}
void UNMASK_ISR_INTPSI51SI(void){
	NVIC_ENABLE_IRQ((int32_t)174);
}
void UNMASK_ISR_INTPSI51RI(void){
	NVIC_ENABLE_IRQ((int32_t)175);
}
void UNMASK_ISR_INTPSI51TI(void){
	NVIC_ENABLE_IRQ((int32_t)176);
}
void UNMASK_ISR_INTPSI5W(void){
	NVIC_ENABLE_IRQ((int32_t)177);
}
void UNMASK_ISR_INTMMCA0(void){
	NVIC_ENABLE_IRQ((int32_t)178);
}
void UNMASK_ISR_INTOSTM3TINT(void){
	NVIC_ENABLE_IRQ((int32_t)179);
}
void UNMASK_ISR_INTOSTM4TINT(void){
	NVIC_ENABLE_IRQ((int32_t)180);
}
void UNMASK_ISR_INTXCAN1FUNC(void){
	NVIC_ENABLE_IRQ((int32_t)181);
}
void UNMASK_ISR_INTXCAN1ERR(void){
	NVIC_ENABLE_IRQ((int32_t)182);
}
void UNMASK_ISR_INTXCAN1SAFETY(void){
	NVIC_ENABLE_IRQ((int32_t)183);
}
void UNMASK_ISR_INTETND00(void){
	NVIC_ENABLE_IRQ((int32_t)184);
}
void UNMASK_ISR_INTETND01(void){
	NVIC_ENABLE_IRQ((int32_t)185);
}
void UNMASK_ISR_INTETND02(void){
	NVIC_ENABLE_IRQ((int32_t)186);
}
void UNMASK_ISR_INTETND03(void){
	NVIC_ENABLE_IRQ((int32_t)187);
}
void UNMASK_ISR_INTETND04(void){
	NVIC_ENABLE_IRQ((int32_t)188);
}
void UNMASK_ISR_INTETND05(void){
	NVIC_ENABLE_IRQ((int32_t)189);
}
void UNMASK_ISR_INTETND06(void){
	NVIC_ENABLE_IRQ((int32_t)190);
}
void UNMASK_ISR_INTGPTP(void){
	NVIC_ENABLE_IRQ((int32_t)191);
}
void UNMASK_ISR_IRQ25(void){
	NVIC_ENABLE_IRQ((int32_t)192);
}
void UNMASK_ISR_INTRLIN316(void){
	NVIC_ENABLE_IRQ((int32_t)193);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_33, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN317(void){
	NVIC_ENABLE_IRQ((int32_t)193);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_33, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN316UR0(void){
	NVIC_ENABLE_IRQ((int32_t)194);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_34, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN317UR0(void){
	NVIC_ENABLE_IRQ((int32_t)194);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_34, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN316UR1(void){
	NVIC_ENABLE_IRQ((int32_t)195);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_35, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN317UR1(void){
	NVIC_ENABLE_IRQ((int32_t)195);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_35, IMFU_BIT_1, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN316UR2(void){
	NVIC_ENABLE_IRQ((int32_t)196);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_36, IMFU_BIT_0, IMFU_UNMASKED);
}
void UNMASK_ISR_INTRLIN317UR2(void){
	NVIC_ENABLE_IRQ((int32_t)196);
	CONFIG_MASK_IMFU(IMFU_PULSE, IMFU_36, IMFU_BIT_1, IMFU_UNMASKED);
}

//#pragma ghs startdata			
//#pragma ghs section bss=".application_vectors"//
vector_func my_vector_table[198] __attribute__((section(".application_vectors"))) __attribute__((__used__)) ={
#ifdef NVIC_0_ENABLED
		[0] = NVIC_ISR_0,
#else
		[0] = UNUSED_ISR,
#endif
#ifdef NVIC_1_ENABLED
		[1] = NVIC_ISR_1,
#else
		[1] = UNUSED_ISR,
#endif
#ifdef NVIC_2_ENABLED
		[2] = NVIC_ISR_2,
#else
		[2] = UNUSED_ISR,
#endif
#ifdef NVIC_3_ENABLED
		[3] = NVIC_ISR_3,
#else
		[3] = UNUSED_ISR,
#endif
#ifdef NVIC_4_ENABLED
		[4] = NVIC_ISR_4,
#else
		[4] = UNUSED_ISR,
#endif
#ifdef NVIC_5_ENABLED
		[5] = NVIC_ISR_5,
#else
		[5] = UNUSED_ISR,
#endif
#ifdef NVIC_6_ENABLED
		[6] = NVIC_ISR_6,
#else
		[6] = UNUSED_ISR,
#endif
#ifdef NVIC_7_ENABLED
		[7] = NVIC_ISR_7,
#else
		[7] = UNUSED_ISR,
#endif
#ifdef NVIC_8_ENABLED
		[8] = NVIC_ISR_8,
#else
		[8] = UNUSED_ISR,
#endif
#ifdef NVIC_9_ENABLED
		[9] = NVIC_ISR_9,
#else
		[9] = UNUSED_ISR,
#endif
#ifdef NVIC_10_ENABLED
		[10] = NVIC_ISR_10,
#else
		[10] = UNUSED_ISR,
#endif
#ifdef NVIC_11_ENABLED
		[11] = NVIC_ISR_11,
#else
		[11] = UNUSED_ISR,
#endif
#ifdef NVIC_12_ENABLED
		[12] = NVIC_ISR_12,
#else
		[12] = UNUSED_ISR,
#endif
#ifdef NVIC_13_ENABLED
		[13] = NVIC_ISR_13,
#else
		[13] = UNUSED_ISR,
#endif
#ifdef NVIC_14_ENABLED
		[14] = NVIC_ISR_14,
#else
		[14] = UNUSED_ISR,
#endif
#ifdef NVIC_15_ENABLED
		[15] = NVIC_ISR_15,
#else
		[15] = UNUSED_ISR,
#endif
#ifdef NVIC_16_ENABLED
		[16] = NVIC_ISR_16,
#else
		[16] = UNUSED_ISR,
#endif
#ifdef NVIC_17_ENABLED
		[17] = NVIC_ISR_17,
#else
		[17] = UNUSED_ISR,
#endif
#ifdef NVIC_18_ENABLED
		[18] = NVIC_ISR_18,
#else
		[18] = UNUSED_ISR,
#endif
#ifdef NVIC_19_ENABLED
		[19] = NVIC_ISR_19,
#else
		[19] = UNUSED_ISR,
#endif
#ifdef NVIC_20_ENABLED
		[20] = NVIC_ISR_20,
#else
		[20] = UNUSED_ISR,
#endif
#ifdef NVIC_21_ENABLED
		[21] = NVIC_ISR_21,
#else
		[21] = UNUSED_ISR,
#endif
#ifdef NVIC_22_ENABLED
		[22] = NVIC_ISR_22,
#else
		[22] = UNUSED_ISR,
#endif
#ifdef NVIC_23_ENABLED
		[23] = NVIC_ISR_23,
#else
		[23] = UNUSED_ISR,
#endif
#ifdef NVIC_24_ENABLED
		[24] = NVIC_ISR_24,
#else
		[24] = UNUSED_ISR,
#endif
#ifdef NVIC_25_ENABLED
		[25] = NVIC_ISR_25,
#else
		[25] = UNUSED_ISR,
#endif
#ifdef NVIC_26_ENABLED
		[26] = NVIC_ISR_26,
#else
		[26] = UNUSED_ISR,
#endif
#ifdef NVIC_27_ENABLED
		[27] = NVIC_ISR_27,
#else
		[27] = UNUSED_ISR,
#endif
#ifdef NVIC_28_ENABLED
		[28] = NVIC_ISR_28,
#else
		[28] = UNUSED_ISR,
#endif
#ifdef NVIC_29_ENABLED
		[29] = NVIC_ISR_29,
#else
		[29] = UNUSED_ISR,
#endif
#ifdef NVIC_30_ENABLED
		[30] = NVIC_ISR_30,
#else
		[30] = UNUSED_ISR,
#endif
#ifdef NVIC_31_ENABLED
		[31] = NVIC_ISR_31,
#else
		[31] = UNUSED_ISR,
#endif
#ifdef NVIC_32_ENABLED
		[32] = NVIC_ISR_32,
#else
		[32] = UNUSED_ISR,
#endif
#ifdef NVIC_33_ENABLED
		[33] = NVIC_ISR_33,
#else
		[33] = UNUSED_ISR,
#endif
#ifdef NVIC_34_ENABLED
		[34] = NVIC_ISR_34,
#else
		[34] = UNUSED_ISR,
#endif
#ifdef NVIC_35_ENABLED
		[35] = NVIC_ISR_35,
#else
		[35] = UNUSED_ISR,
#endif
#ifdef NVIC_36_ENABLED
		[36] = NVIC_ISR_36,
#else
		[36] = UNUSED_ISR,
#endif
#ifdef NVIC_37_ENABLED
		[37] = NVIC_ISR_37,
#else
		[37] = UNUSED_ISR,
#endif
#ifdef NVIC_38_ENABLED
		[38] = NVIC_ISR_38,
#else
		[38] = UNUSED_ISR,
#endif
#ifdef NVIC_39_ENABLED
		[39] = NVIC_ISR_39,
#else
		[39] = UNUSED_ISR,
#endif
#ifdef NVIC_40_ENABLED
		[40] = NVIC_ISR_40,
#else
		[40] = UNUSED_ISR,
#endif
#ifdef NVIC_41_ENABLED
		[41] = NVIC_ISR_41,
#else
		[41] = UNUSED_ISR,
#endif
#ifdef NVIC_42_ENABLED
		[42] = NVIC_ISR_42,
#else
		[42] = UNUSED_ISR,
#endif
#ifdef NVIC_43_ENABLED
		[43] = NVIC_ISR_43,
#else
		[43] = UNUSED_ISR,
#endif
#ifdef NVIC_44_ENABLED
		[44] = NVIC_ISR_44,
#else
		[44] = UNUSED_ISR,
#endif
#ifdef NVIC_45_ENABLED
		[45] = NVIC_ISR_45,
#else
		[45] = UNUSED_ISR,
#endif
#ifdef NVIC_46_ENABLED
		[46] = NVIC_ISR_46,
#else
		[46] = UNUSED_ISR,
#endif
#ifdef NVIC_47_ENABLED
		[47] = NVIC_ISR_47,
#else
		[47] = UNUSED_ISR,
#endif
#ifdef NVIC_48_ENABLED
		[48] = NVIC_ISR_48,
#else
		[48] = UNUSED_ISR,
#endif
#ifdef NVIC_49_ENABLED
		[49] = NVIC_ISR_49,
#else
		[49] = UNUSED_ISR,
#endif
#ifdef NVIC_50_ENABLED
		[50] = NVIC_ISR_50,
#else
		[50] = UNUSED_ISR,
#endif
#ifdef NVIC_51_ENABLED
		[51] = NVIC_ISR_51,
#else
		[51] = UNUSED_ISR,
#endif
#ifdef NVIC_52_ENABLED
		[52] = NVIC_ISR_52,
#else
		[52] = UNUSED_ISR,
#endif
#ifdef NVIC_53_ENABLED
		[53] = NVIC_ISR_53,
#else
		[53] = UNUSED_ISR,
#endif
#ifdef NVIC_54_ENABLED
		[54] = NVIC_ISR_54,
#else
		[54] = UNUSED_ISR,
#endif
#ifdef NVIC_55_ENABLED
		[55] = NVIC_ISR_55,
#else
		[55] = UNUSED_ISR,
#endif
#ifdef NVIC_56_ENABLED
		[56] = NVIC_ISR_56,
#else
		[56] = UNUSED_ISR,
#endif
#ifdef NVIC_57_ENABLED
		[57] = NVIC_ISR_57,
#else
		[57] = UNUSED_ISR,
#endif
#ifdef NVIC_58_ENABLED
		[58] = NVIC_ISR_58,
#else
		[58] = UNUSED_ISR,
#endif
#ifdef NVIC_59_ENABLED
		[59] = NVIC_ISR_59,
#else
		[59] = UNUSED_ISR,
#endif
#ifdef NVIC_60_ENABLED
		[60] = NVIC_ISR_60,
#else
		[60] = UNUSED_ISR,
#endif
#ifdef NVIC_61_ENABLED
		[61] = NVIC_ISR_61,
#else
		[61] = UNUSED_ISR,
#endif
#ifdef NVIC_62_ENABLED
		[62] = NVIC_ISR_62,
#else
		[62] = UNUSED_ISR,
#endif
#ifdef NVIC_63_ENABLED
		[63] = NVIC_ISR_63,
#else
		[63] = UNUSED_ISR,
#endif
#ifdef NVIC_64_ENABLED
		[64] = NVIC_ISR_64,
#else
		[64] = UNUSED_ISR,
#endif
#ifdef NVIC_65_ENABLED
		[65] = NVIC_ISR_65,
#else
		[65] = UNUSED_ISR,
#endif
#ifdef NVIC_66_ENABLED
		[66] = NVIC_ISR_66,
#else
		[66] = UNUSED_ISR,
#endif
#ifdef NVIC_67_ENABLED
		[67] = NVIC_ISR_67,
#else
		[67] = UNUSED_ISR,
#endif
#ifdef NVIC_68_ENABLED
		[68] = NVIC_ISR_68,
#else
		[68] = UNUSED_ISR,
#endif
#ifdef NVIC_69_ENABLED
		[69] = NVIC_ISR_69,
#else
		[69] = UNUSED_ISR,
#endif
#ifdef NVIC_70_ENABLED
		[70] = NVIC_ISR_70,
#else
		[70] = UNUSED_ISR,
#endif
#ifdef NVIC_71_ENABLED
		[71] = NVIC_ISR_71,
#else
		[71] = UNUSED_ISR,
#endif
#ifdef NVIC_72_ENABLED
		[72] = NVIC_ISR_72,
#else
		[72] = UNUSED_ISR,
#endif
#ifdef NVIC_73_ENABLED
		[73] = NVIC_ISR_73,
#else
		[73] = UNUSED_ISR,
#endif
#ifdef NVIC_74_ENABLED
		[74] = NVIC_ISR_74,
#else
		[74] = UNUSED_ISR,
#endif
#ifdef NVIC_75_ENABLED
		[75] = NVIC_ISR_75,
#else
		[75] = UNUSED_ISR,
#endif
#ifdef NVIC_77_ENABLED
		[77] = NVIC_ISR_77,
#else
		[77] = UNUSED_ISR,
#endif
#ifdef NVIC_78_ENABLED
		[78] = NVIC_ISR_78,
#else
		[78] = UNUSED_ISR,
#endif
#ifdef NVIC_79_ENABLED
		[79] = NVIC_ISR_79,
#else
		[79] = UNUSED_ISR,
#endif
#ifdef NVIC_80_ENABLED
		[80] = NVIC_ISR_80,
#else
		[80] = UNUSED_ISR,
#endif
#ifdef NVIC_81_ENABLED
		[81] = NVIC_ISR_81,
#else
		[81] = UNUSED_ISR,
#endif
#ifdef NVIC_82_ENABLED
		[82] = NVIC_ISR_82,
#else
		[82] = UNUSED_ISR,
#endif
#ifdef NVIC_83_ENABLED
		[83] = NVIC_ISR_83,
#else
		[83] = UNUSED_ISR,
#endif
#ifdef NVIC_84_ENABLED
		[84] = NVIC_ISR_84,
#else
		[84] = UNUSED_ISR,
#endif
#ifdef NVIC_85_ENABLED
		[85] = NVIC_ISR_85,
#else
		[85] = UNUSED_ISR,
#endif
#ifdef NVIC_86_ENABLED
		[86] = NVIC_ISR_86,
#else
		[86] = UNUSED_ISR,
#endif
#ifdef NVIC_87_ENABLED
		[87] = NVIC_ISR_87,
#else
		[87] = UNUSED_ISR,
#endif
#ifdef NVIC_88_ENABLED
		[88] = NVIC_ISR_88,
#else
		[88] = UNUSED_ISR,
#endif
#ifdef NVIC_89_ENABLED
		[89] = NVIC_ISR_89,
#else
		[89] = UNUSED_ISR,
#endif
#ifdef NVIC_90_ENABLED
		[90] = NVIC_ISR_90,
#else
		[90] = UNUSED_ISR,
#endif
#ifdef NVIC_91_ENABLED
		[91] = NVIC_ISR_91,
#else
		[91] = UNUSED_ISR,
#endif
#ifdef NVIC_92_ENABLED
		[92] = NVIC_ISR_92,
#else
		[92] = UNUSED_ISR,
#endif
#ifdef NVIC_93_ENABLED
		[93] = NVIC_ISR_93,
#else
		[93] = UNUSED_ISR,
#endif
#ifdef NVIC_94_ENABLED
		[94] = NVIC_ISR_94,
#else
		[94] = UNUSED_ISR,
#endif
#ifdef NVIC_95_ENABLED
		[95] = NVIC_ISR_95,
#else
		[95] = UNUSED_ISR,
#endif
#ifdef NVIC_96_ENABLED
		[96] = NVIC_ISR_96,
#else
		[96] = UNUSED_ISR,
#endif
#ifdef NVIC_97_ENABLED
		[97] = NVIC_ISR_97,
#else
		[97] = UNUSED_ISR,
#endif
#ifdef NVIC_98_ENABLED
		[98] = NVIC_ISR_98,
#else
		[98] = UNUSED_ISR,
#endif
#ifdef NVIC_99_ENABLED
		[99] = NVIC_ISR_99,
#else
		[99] = UNUSED_ISR,
#endif
#ifdef NVIC_100_ENABLED
		[100] = NVIC_ISR_100,
#else
		[100] = UNUSED_ISR,
#endif
#ifdef NVIC_101_ENABLED
		[101] = NVIC_ISR_101,
#else
		[101] = UNUSED_ISR,
#endif
#ifdef NVIC_102_ENABLED
		[102] = NVIC_ISR_102,
#else
		[102] = UNUSED_ISR,
#endif
#ifdef NVIC_103_ENABLED
		[103] = NVIC_ISR_103,
#else
		[103] = UNUSED_ISR,
#endif
#ifdef NVIC_104_ENABLED
		[104] = NVIC_ISR_104,
#else
		[104] = UNUSED_ISR,
#endif
#ifdef NVIC_105_ENABLED
		[105] = NVIC_ISR_105,
#else
		[105] = UNUSED_ISR,
#endif
#ifdef NVIC_106_ENABLED
		[106] = NVIC_ISR_106,
#else
		[106] = UNUSED_ISR,
#endif
#ifdef NVIC_107_ENABLED
		[107] = NVIC_ISR_107,
#else
		[107] = UNUSED_ISR,
#endif
#ifdef NVIC_108_ENABLED
		[108] = NVIC_ISR_108,
#else
		[108] = UNUSED_ISR,
#endif
#ifdef NVIC_109_ENABLED
		[109] = NVIC_ISR_109,
#else
		[109] = UNUSED_ISR,
#endif
#ifdef NVIC_110_ENABLED
		[110] = NVIC_ISR_110,
#else
		[110] = UNUSED_ISR,
#endif
#ifdef NVIC_111_ENABLED
		[111] = NVIC_ISR_111,
#else
		[111] = UNUSED_ISR,
#endif
#ifdef NVIC_112_ENABLED
		[112] = NVIC_ISR_112,
#else
		[112] = UNUSED_ISR,
#endif
#ifdef NVIC_113_ENABLED
		[113] = NVIC_ISR_113,
#else
		[113] = UNUSED_ISR,
#endif
#ifdef NVIC_114_ENABLED
		[114] = NVIC_ISR_114,
#else
		[114] = UNUSED_ISR,
#endif
#ifdef NVIC_115_ENABLED
		[115] = NVIC_ISR_115,
#else
		[115] = UNUSED_ISR,
#endif
#ifdef NVIC_116_ENABLED
		[116] = NVIC_ISR_116,
#else
		[116] = UNUSED_ISR,
#endif
#ifdef NVIC_117_ENABLED
		[117] = NVIC_ISR_117,
#else
		[117] = UNUSED_ISR,
#endif
#ifdef NVIC_118_ENABLED
		[118] = NVIC_ISR_118,
#else
		[118] = UNUSED_ISR,
#endif
#ifdef NVIC_119_ENABLED
		[119] = NVIC_ISR_119,
#else
		[119] = UNUSED_ISR,
#endif
#ifdef NVIC_120_ENABLED
		[120] = NVIC_ISR_120,
#else
		[120] = UNUSED_ISR,
#endif
#ifdef NVIC_121_ENABLED
		[121] = NVIC_ISR_121,
#else
		[121] = UNUSED_ISR,
#endif
#ifdef NVIC_122_ENABLED
		[122] = NVIC_ISR_122,
#else
		[122] = UNUSED_ISR,
#endif
#ifdef NVIC_123_ENABLED
		[123] = NVIC_ISR_123,
#else
		[123] = UNUSED_ISR,
#endif
#ifdef NVIC_124_ENABLED
		[124] = NVIC_ISR_124,
#else
		[124] = UNUSED_ISR,
#endif
#ifdef NVIC_125_ENABLED
		[125] = NVIC_ISR_125,
#else
		[125] = UNUSED_ISR,
#endif
#ifdef NVIC_126_ENABLED
		[126] = NVIC_ISR_126,
#else
		[126] = UNUSED_ISR,
#endif
#ifdef NVIC_127_ENABLED
		[127] = NVIC_ISR_127,
#else
		[127] = UNUSED_ISR,
#endif
#ifdef NVIC_128_ENABLED
		[128] = NVIC_ISR_128,
#else
		[128] = UNUSED_ISR,
#endif
#ifdef NVIC_129_ENABLED
		[129] = NVIC_ISR_129,
#else
		[129] = UNUSED_ISR,
#endif
#ifdef NVIC_130_ENABLED
		[130] = NVIC_ISR_130,
#else
		[130] = UNUSED_ISR,
#endif
#ifdef NVIC_131_ENABLED
		[131] = NVIC_ISR_131,
#else
		[131] = UNUSED_ISR,
#endif
#ifdef NVIC_132_ENABLED
		[132] = NVIC_ISR_132,
#else
		[132] = UNUSED_ISR,
#endif
#ifdef NVIC_133_ENABLED
		[133] = NVIC_ISR_133,
#else
		[133] = UNUSED_ISR,
#endif
#ifdef NVIC_134_ENABLED
		[134] = NVIC_ISR_134,
#else
		[134] = UNUSED_ISR,
#endif
#ifdef NVIC_135_ENABLED
		[135] = NVIC_ISR_135,
#else
		[135] = UNUSED_ISR,
#endif
#ifdef NVIC_136_ENABLED
		[136] = NVIC_ISR_136,
#else
		[136] = UNUSED_ISR,
#endif
#ifdef NVIC_137_ENABLED
		[137] = NVIC_ISR_137,
#else
		[137] = UNUSED_ISR,
#endif
#ifdef NVIC_138_ENABLED
		[138] = NVIC_ISR_138,
#else
		[138] = UNUSED_ISR,
#endif
#ifdef NVIC_139_ENABLED
		[139] = NVIC_ISR_139,
#else
		[139] = UNUSED_ISR,
#endif
#ifdef NVIC_140_ENABLED
		[140] = NVIC_ISR_140,
#else
		[140] = UNUSED_ISR,
#endif
#ifdef NVIC_141_ENABLED
		[141] = NVIC_ISR_141,
#else
		[141] = UNUSED_ISR,
#endif
#ifdef NVIC_142_ENABLED
		[142] = NVIC_ISR_142,
#else
		[142] = UNUSED_ISR,
#endif
#ifdef NVIC_143_ENABLED
		[143] = NVIC_ISR_143,
#else
		[143] = UNUSED_ISR,
#endif
#ifdef NVIC_144_ENABLED
		[144] = NVIC_ISR_144,
#else
		[144] = UNUSED_ISR,
#endif
#ifdef NVIC_145_ENABLED
		[145] = NVIC_ISR_145,
#else
		[145] = UNUSED_ISR,
#endif
#ifdef NVIC_146_ENABLED
		[146] = NVIC_ISR_146,
#else
		[146] = UNUSED_ISR,
#endif
#ifdef NVIC_147_ENABLED
		[147] = NVIC_ISR_147,
#else
		[147] = UNUSED_ISR,
#endif
#ifdef NVIC_148_ENABLED
		[148] = NVIC_ISR_148,
#else
		[148] = UNUSED_ISR,
#endif
#ifdef NVIC_149_ENABLED
		[149] = NVIC_ISR_149,
#else
		[149] = UNUSED_ISR,
#endif
#ifdef NVIC_150_ENABLED
		[150] = NVIC_ISR_150,
#else
		[150] = UNUSED_ISR,
#endif
#ifdef NVIC_151_ENABLED
		[151] = NVIC_ISR_151,
#else
		[151] = UNUSED_ISR,
#endif
#ifdef NVIC_152_ENABLED
		[152] = NVIC_ISR_152,
#else
		[152] = UNUSED_ISR,
#endif
#ifdef NVIC_153_ENABLED
		[153] = NVIC_ISR_153,
#else
		[153] = UNUSED_ISR,
#endif
#ifdef NVIC_154_ENABLED
		[154] = NVIC_ISR_154,
#else
		[154] = UNUSED_ISR,
#endif
#ifdef NVIC_155_ENABLED
		[155] = NVIC_ISR_155,
#else
		[155] = UNUSED_ISR,
#endif
#ifdef NVIC_156_ENABLED
		[156] = NVIC_ISR_156,
#else
		[156] = UNUSED_ISR,
#endif
#ifdef NVIC_157_ENABLED
		[157] = NVIC_ISR_157,
#else
		[157] = UNUSED_ISR,
#endif
#ifdef NVIC_158_ENABLED
		[158] = NVIC_ISR_158,
#else
		[158] = UNUSED_ISR,
#endif
#ifdef NVIC_159_ENABLED
		[159] = NVIC_ISR_159,
#else
		[159] = UNUSED_ISR,
#endif
#ifdef NVIC_160_ENABLED
		[160] = NVIC_ISR_160,
#else
		[160] = UNUSED_ISR,
#endif
#ifdef NVIC_161_ENABLED
		[161] = NVIC_ISR_161,
#else
		[161] = UNUSED_ISR,
#endif
#ifdef NVIC_162_ENABLED
		[162] = NVIC_ISR_162,
#else
		[162] = UNUSED_ISR,
#endif
#ifdef NVIC_163_ENABLED
		[163] = NVIC_ISR_163,
#else
		[163] = UNUSED_ISR,
#endif
#ifdef NVIC_164_ENABLED
		[164] = NVIC_ISR_164,
#else
		[164] = UNUSED_ISR,
#endif
#ifdef NVIC_165_ENABLED
		[165] = NVIC_ISR_165,
#else
		[165] = UNUSED_ISR,
#endif
#ifdef NVIC_166_ENABLED
		[166] = NVIC_ISR_166,
#else
		[166] = UNUSED_ISR,
#endif
#ifdef NVIC_167_ENABLED
		[167] = NVIC_ISR_167,
#else
		[167] = UNUSED_ISR,
#endif
#ifdef NVIC_168_ENABLED
		[168] = NVIC_ISR_168,
#else
		[168] = UNUSED_ISR,
#endif
#ifdef NVIC_169_ENABLED
		[169] = NVIC_ISR_169,
#else
		[169] = UNUSED_ISR,
#endif
#ifdef NVIC_170_ENABLED
		[170] = NVIC_ISR_170,
#else
		[170] = UNUSED_ISR,
#endif
#ifdef NVIC_171_ENABLED
		[171] = NVIC_ISR_171,
#else
		[171] = UNUSED_ISR,
#endif
#ifdef NVIC_172_ENABLED
		[172] = NVIC_ISR_172,
#else
		[172] = UNUSED_ISR,
#endif
#ifdef NVIC_173_ENABLED
		[173] = NVIC_ISR_173,
#else
		[173] = UNUSED_ISR,
#endif
#ifdef NVIC_174_ENABLED
		[174] = NVIC_ISR_174,
#else
		[174] = UNUSED_ISR,
#endif
#ifdef NVIC_175_ENABLED
		[175] = NVIC_ISR_175,
#else
		[175] = UNUSED_ISR,
#endif
#ifdef NVIC_176_ENABLED
		[176] = NVIC_ISR_176,
#else
		[176] = UNUSED_ISR,
#endif
#ifdef NVIC_177_ENABLED
		[177] = NVIC_ISR_177,
#else
		[177] = UNUSED_ISR,
#endif
#ifdef NVIC_178_ENABLED
		[178] = NVIC_ISR_178,
#else
		[178] = UNUSED_ISR,
#endif
#ifdef NVIC_179_ENABLED
		[179] = NVIC_ISR_179,
#else
		[179] = UNUSED_ISR,
#endif
#ifdef NVIC_180_ENABLED
		[180] = NVIC_ISR_180,
#else
		[180] = UNUSED_ISR,
#endif
#ifdef NVIC_181_ENABLED
		[181] = NVIC_ISR_181,
#else
		[181] = UNUSED_ISR,
#endif
#ifdef NVIC_182_ENABLED
		[182] = NVIC_ISR_182,
#else
		[182] = UNUSED_ISR,
#endif
#ifdef NVIC_183_ENABLED
		[183] = NVIC_ISR_183,
#else
		[183] = UNUSED_ISR,
#endif
#ifdef NVIC_184_ENABLED
		[184] = NVIC_ISR_184,
#else
		[184] = UNUSED_ISR,
#endif
#ifdef NVIC_185_ENABLED
		[185] = NVIC_ISR_185,
#else
		[185] = UNUSED_ISR,
#endif
#ifdef NVIC_186_ENABLED
		[186] = NVIC_ISR_186,
#else
		[186] = UNUSED_ISR,
#endif
#ifdef NVIC_187_ENABLED
		[187] = NVIC_ISR_187,
#else
		[187] = UNUSED_ISR,
#endif
#ifdef NVIC_188_ENABLED
		[188] = NVIC_ISR_188,
#else
		[188] = UNUSED_ISR,
#endif
#ifdef NVIC_189_ENABLED
		[189] = NVIC_ISR_189,
#else
		[189] = UNUSED_ISR,
#endif
#ifdef NVIC_190_ENABLED
		[190] = NVIC_ISR_190,
#else
		[190] = UNUSED_ISR,
#endif
#ifdef NVIC_191_ENABLED
		[191] = NVIC_ISR_191,
#else
		[191] = UNUSED_ISR,
#endif
#ifdef NVIC_192_ENABLED
		[192] = NVIC_ISR_192,
#else
		[192] = UNUSED_ISR,
#endif
#ifdef NVIC_193_ENABLED
		[193] = NVIC_ISR_193,
#else
		[193] = UNUSED_ISR,
#endif
#ifdef NVIC_194_ENABLED
		[194] = NVIC_ISR_194,
#else
		[194] = UNUSED_ISR,
#endif
#ifdef NVIC_195_ENABLED
		[195] = NVIC_ISR_195,
#else
		[195] = UNUSED_ISR,
#endif
#ifdef NVIC_196_ENABLED
		[196] = NVIC_ISR_196,
#else
		[196] = UNUSED_ISR,
#endif
};

//#pragma ghs section bss=default 
//#pragma ghs enddata		
