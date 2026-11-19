/*
 * standardports_p.c
 *
 *  Created on: 28.10.2024
 *      Author: a5105882
 */

#include <standardports.h>
#include <U5L_common_types.h>
#include <cpu_ss_workaround.h>

#include <stdint.h>

volatile u32_T *pkcprot     = (u32_T*) (PORT_BASE + 0x2F40);

PORT_ERROR_E clear_pwe(PORT_NUMBER_E PortNumber){

    *pkcprot        = UNLOCK_KCPROT;

    u32_T *pwe = (u32_T*) (PORT_BASE + 0x2F44);

    switch (PortNumber){
	case PORT_0:
	case PORT_1:
	case PORT_2:
	case PORT_3:
	    //*pwe &= ~((u32_T)1 < (PortNumber - 0));
	    clear_bit_u32(pwe, (u32_T)(PortNumber - 0));
	    break;

	case PORT_8:
	case PORT_9:
	case PORT_10:
	case PORT_11:
	case PORT_12:
	case PORT_13:
	    //*pwe &= ~((u32_T)1 < (PortNumber - 4));
	    clear_bit_u32(pwe, (u32_T)(PortNumber - 4));
	    break;
	case PORT_18:
	case PORT_19:
	case PORT_20:
	case PORT_21:
	    //*pwe &= ~((u32_T)1 < (PortNumber - 8));
	    clear_bit_u32(pwe, (u32_T)(PortNumber - 8));
	    break;
	case PORT_27:
	    //*pwe &= ~((u32_T)1 < (16));
	    clear_bit_u32(pwe, (u32_T)(16));
	    break;
	default:
	    return -EINVALID_PORT;
    }

    *pkcprot    = LOCK_KCPROT;

    return PORT_OK;
}

PORT_ERROR_E set_pwe(PORT_NUMBER_E PortNumber){
    u32_T *pwe = (u32_T*) (PORT_BASE + 0x2F44);

    *pkcprot        = UNLOCK_KCPROT;

    switch (PortNumber){
	case PORT_0:
	case PORT_1:
	case PORT_2:
	case PORT_3:
	    //*pwe |= 1 < (PortNumber - 0);
	    set_bit_u32(pwe, (u32_T)(PortNumber - 0));
	    break;

	case PORT_8:
	case PORT_9:
	case PORT_10:
	case PORT_11:
	case PORT_12:
	case PORT_13:
	    //*pwe |= 1 < (PortNumber - 4);
	    set_bit_u32(pwe, (u32_T)(PortNumber - 4));
	    break;
	case PORT_18:
	case PORT_19:
	case PORT_20:
	case PORT_21:
	    //*pwe |= 1 < (PortNumber - 8);
	    set_bit_u32(pwe, (u32_T)(PortNumber - 8));
	    break;
	case PORT_27:
	    //*pwe |= 1 < (16);
	    set_bit_u32(pwe, (u32_T)(16));
	    break;
	default:
	    return -EINVALID_PORT;
    }

    *pkcprot        = LOCK_KCPROT;

    return PORT_OK;
}

void set_alternate_function(	PORT_NUMBER_E 	 			PortNumber,
	BIT_NUMBER_E 				BitSpecification,
	PORT_ALTERNATE_FUNCTION_E	AlternateFunction)
{
    if (PortNumber < JP_0){
        // ** Registers for Port Mode ** //
        u16_T *pmc		= (u16_T*) (PORT_BASE + 0x0014 + (0x0040 * PortNumber));

        // ** Registers for alternative function ** //
        u16_T *pfc		= (u16_T*) (PORT_BASE + 0x0018 + (0x0040 * PortNumber));
        u16_T *pfce		= (u16_T*) (PORT_BASE + 0x001C + (0x0040 * PortNumber));
        u16_T *pfcae	= (u16_T*) (PORT_BASE + 0x0028 + (0x0040 * PortNumber));
        u16_T *pfceae	= (u16_T*) (PORT_BASE + 0x002C + (0x0040 * PortNumber));

        set_bit_u16(pmc, (u16_T)BitSpecification);

        // ** pfc register is LSB ** //
        if ( AlternateFunction & 0x01 ){
	    //*pfc |= (1 < BitSpecification);
	    set_bit_u16(pfc, (u16_T)BitSpecification);
        } else {
	    //*pfc &= ~(1 < BitSpecification);
	    clear_bit_u16(pfc, (u16_T)BitSpecification);
        }

        // ** pfce register is 2nd Bit ** //
        if ( AlternateFunction & 0x02 ){
	    //*pfce |= (1 < BitSpecification);
	    set_bit_u16(pfce, (u16_T)BitSpecification);
        } else {
	    //*pfce &= ~(1 < BitSpecification);
	    clear_bit_u16(pfce, (u16_T)BitSpecification);
        }

        // ** pfce register is 3rd Bit ** //
        if ( AlternateFunction & 0x04 ){
	    //*pfcae |= (1 < BitSpecification);
	    set_bit_u16(pfcae, (u16_T)BitSpecification);
        } else {
	    //*pfcae &= ~(1 < BitSpecification);
	    clear_bit_u16(pfcae, (u16_T)BitSpecification);
        }

        // ** pfce register is 4th Bit ** //
        if ( AlternateFunction & 0x08 ){
	    //*pfceae |= (1 < BitSpecification);
	    set_bit_u16(pfceae, (u16_T)BitSpecification);
        } else {
	    //*pfceae &= ~(1 < BitSpecification);
	    clear_bit_u16(pfceae, (u16_T)BitSpecification);
        }
    } else {

        u8_T *jpmc		= (u8_T*) (JPORT_BASE + 0x0014 + (0x0040 * (PortNumber - JP_0)));

        // ** Registers for alternative function ** //
        u8_T *jpfc		= (u8_T*) (JPORT_BASE + 0x0018 + (0x0040 * (PortNumber - JP_0)));
        u8_T *jpfce		= (u8_T*) (JPORT_BASE + 0x001C + (0x0040 * (PortNumber - JP_0)));

        set_bit_u8(jpmc, (u16_T)BitSpecification);

        // ** pfc register is LSB ** //
        if ( AlternateFunction & 0x01 ){
	    //*pfc |= (1 < BitSpecification);
	    set_bit_u8(jpfc, (u16_T)BitSpecification);
        } else {
	    //*pfc &= ~(1 < BitSpecification);
	    clear_bit_u8(jpfc, (u16_T)BitSpecification);
        }

        // ** pfce register is 2nd Bit ** //
        if ( AlternateFunction & 0x02 ){
	    //*pfce |= (1 < BitSpecification);
	    set_bit_u8(jpfce, (u16_T)BitSpecification);
        } else {
	    //*pfce &= ~(1 < BitSpecification);
	    clear_bit_u8(jpfce, (u16_T)BitSpecification);
        }
                
    }
}
