
#include <standardports.h>
#include <U5L_common_types.h>
#include <cpu_ss_workaround.h>

#include <stdint.h>





//bit PORT_GetStatus( u16  PortNumber_u16,
//                           u16  BitSpecification_u16,
//                           pu08 PortDirection_pu08,
//                           pu08 PeripheralMode_pu08,
//                           pu08 AlternateFunction_pu08 )

extern volatile u32_T *pkcprot;

PORT_ERROR_E PORT_Enable( 	PORT_NUMBER_E 	 			PortNumber /*PORT_n*/,
        BIT_NUMBER_E 	 			BitSpecification /*BIT_n*/,
	PORT_DIRECTION_E 			PortDirection /*PORT_DIR_x*/,
	PORT_MODE_CONTROL_E 		PeripheralMode /*PORT_MODE_x*/,
	PORT_ALTERNATE_FUNCTION_E	AlternateFunction /*PORT_FUNCTION_x*/ )
{

    if (PortNumber < JP_0){
        // ** Registers for PIN Mode ** //
        u16_T *pm 	= (u16_T*) (PORT_BASE + 0x0010 + (0x0040 * PortNumber));

        // ** Registers for Port Mode ** //
        u16_T *pipc	= (u16_T*) (PORT_BASE + 0x4008 + (0x0040 * PortNumber));
        u16_T *pmc  	= (u16_T*) (PORT_BASE + 0x0014 + (0x0040 * PortNumber));

        // ** Unlock Write Protection ** //
        set_pwe(PortNumber);

        // ** Set PMC, PFCxxx ** //
        switch(AlternateFunction){
	    case PORT_FUNCTION_KEEP: break; //do nothing
	    case PORT_FUNCTION_NORMAL:
	        //*pmc &= ~(1 < BitSpecification);
	        clear_bit_u16(pmc, (u16_T)BitSpecification);
	        break;
	    case PORT_FUNCTION_ALTERN1:
	    case PORT_FUNCTION_ALTERN2:
	    case PORT_FUNCTION_ALTERN3:
	    case PORT_FUNCTION_ALTERN4:
	    case PORT_FUNCTION_ALTERN5:
	    case PORT_FUNCTION_ALTERN6:
	    case PORT_FUNCTION_ALTERN7:
	    case PORT_FUNCTION_ALTERN8:
	    case PORT_FUNCTION_ALTERN9:
	    case PORT_FUNCTION_ALTERN10:
	    case PORT_FUNCTION_ALTERN11:
	    case PORT_FUNCTION_ALTERN12:
	    case PORT_FUNCTION_ALTERN13:
	    case PORT_FUNCTION_ALTERN14:
	    case PORT_FUNCTION_ALTERN15:
	    case PORT_FUNCTION_ALTERN16:
	        set_alternate_function(PortNumber, BitSpecification, AlternateFunction);
	        break;
	    default:
	        return -1; //TODO error definition
	        break;
        }

        // ** Set PIPCn_m ** //
        switch(PeripheralMode){
	    case PORT_MODE_KEEP: break; //Nothing to do here
	    case PORT_MODE_IO:
	        clear_bit_u16(pipc, BitSpecification);
	        break;
	    case PORT_MODE_PERIPHERAL:
	        set_bit_u16(pipc, BitSpecification);
	        break;
	    default:
	        return -1; //TODO error definition
	        break;
        }

        switch(PortDirection){
	    case PORT_DIR_KEEP: break; //Nothing to do here
	    case PORT_DIR_OUTPUT:
	        clear_bit_u16(pm, (u16_T)BitSpecification);
	        break;
	    case PORT_DIR_INPUT:
	        set_bit_u16(pm, BitSpecification);
	        break;
	    default:
	        return -1; //TODO error definition
	        break;
        }


        clear_pwe(PortNumber);


    } else if (PortNumber < AP_0) {
        u08_T* jpm 	= (u16_T*) (JPORT_BASE + 0x0010 + (0x0040 * ( PortNumber - JP_0)));
        u08_T* jpmc 	= (u16_T*) (JPORT_BASE + 0x0014 + (0x0040 * ( PortNumber - JP_0)));

        switch(AlternateFunction){
	    case PORT_FUNCTION_KEEP: break; //do nothing
	    case PORT_FUNCTION_NORMAL:
	        //*pmc &= ~(1 < BitSpecification);
	        clear_bit_u16(jpmc, (u16_T)BitSpecification);
	        break;
	    case PORT_FUNCTION_ALTERN1:
	    case PORT_FUNCTION_ALTERN2:
	    case PORT_FUNCTION_ALTERN3:
	    case PORT_FUNCTION_ALTERN4:
	    case PORT_FUNCTION_ALTERN5:
	    case PORT_FUNCTION_ALTERN6:
	    case PORT_FUNCTION_ALTERN7:
	    case PORT_FUNCTION_ALTERN8:
	    case PORT_FUNCTION_ALTERN9:
	    case PORT_FUNCTION_ALTERN10:
	    case PORT_FUNCTION_ALTERN11:
	    case PORT_FUNCTION_ALTERN12:
	    case PORT_FUNCTION_ALTERN13:
	    case PORT_FUNCTION_ALTERN14:
	    case PORT_FUNCTION_ALTERN15:
	    case PORT_FUNCTION_ALTERN16:
	        set_alternate_function(PortNumber, BitSpecification, AlternateFunction);
	        break;
	    default:
	        return -1; //TODO error definition
	        break;
        }

        switch(PortDirection){
	    case PORT_DIR_KEEP: break; //Nothing to do here
	    case PORT_DIR_OUTPUT:
	        clear_bit_u8(jpm, (u8_T)BitSpecification);
	        break;
	    case PORT_DIR_INPUT:
	        set_bit_u8(jpm, (u8_T)BitSpecification);
	        break;
	    default:
	        return -1; //TODO error definition
	        break;
        }

    } else {
        // ** Registers for PIN Mode ** //
        u16_T *apm 	= (u16_T*) (PORT_BASE + 0x0C90 + (0x0040 * (PortNumber - AP_0)));

        switch(PortDirection){
	    case PORT_DIR_KEEP: break; //Nothing to do here
	    case PORT_DIR_OUTPUT:
	        clear_bit_u16(apm, (u16_T)BitSpecification);
	        break;
	    case PORT_DIR_INPUT:
	        set_bit_u16(apm, BitSpecification);
	        break;
	    default:
	        return -1; //TODO error definition
	        break;
        }   
    }

    return PORT_OK;
}

PORT_ERROR_E PORT_Disable( PORT_NUMBER_E PortNumber_u16,
        BIT_NUMBER_E BitSpecification_u16 )
{
    PORT_ERROR_E error = PORT_OK;

    error |=  PORT_Enable( PortNumber_u16,
	    BitSpecification_u16,
	    PORT_DIR_INPUT,
	    PORT_MODE_KEEP,
	    PORT_FUNCTION_KEEP );

    error |= PORT_Enable( PortNumber_u16,
	    BitSpecification_u16,
	    PORT_DIR_INPUT,
	    PORT_MODE_IO,
	    PORT_FUNCTION_KEEP );
    return( -error );
}




PORT_ERROR_E PORT_Write( PORT_NUMBER_E PortNumber,
        u16_T PortData_u16 )
{
    if (PortNumber < JP_0){
        u16_T *p 		= (u16_T*) (PORT_BASE + 0x0000 + (0x0040 * PortNumber));
        *p = PortData_u16;
    } else {
        u8_T *jp 		= (u16_T*) (JPORT_BASE + 0x0000 + (0x0040 * (PortNumber-JP_0)));
        *jp = (u8_T) PortData_u16;
    }
    return PORT_OK;
}


PORT_ERROR_E PORT_Read( PORT_NUMBER_E  PortNumber,
        u16_T* PortData_pu16 )
{
    if (PortNumber < JP_0){
        u16_T *p 		= (u16_T*) (PORT_BASE + 0x0000 + (0x0040 * PortNumber));
        *PortData_pu16  = WA(*p);
    } else {
        u8_T *jp 	= (u16_T*) (JPORT_BASE + 0x0000 + (0x0040 * (PortNumber-JP_0)));
        *PortData_pu16  = WA(*jp);
    }

    return PORT_OK;
}

PORT_ERROR_E PORT_WriteBit( PORT_NUMBER_E PortNumber,
        BIT_NUMBER_E BitSpecification,
	u16_T BitValue_u16 )
{
    if (PortNumber < JP_0){
        set_pwe(PortNumber);
        u16_T *p = (u16_T*) (PORT_BASE + 0x0000 + (0x0040 * PortNumber));

        if (BitValue_u16 & 0x01)
	    set_bit_u16(p, BitSpecification);
        else
	    clear_bit_u16(p, BitSpecification);

        clear_pwe(PortNumber);

    } else if (PortNumber < AP_0) {
        u8_T *jp 	= (u16_T*) (JPORT_BASE + 0x0000 + (0x0040 * (PortNumber-JP_0)));
        if (BitValue_u16 & 0x01)
	    set_bit_u16(jp, BitSpecification);
        else
	    clear_bit_u16(jp, BitSpecification);
    } else {
        u8_T *ap 	= (u16_T*) (PORT_BASE + 0x0C80 + (0x0040 * (PortNumber-AP_0)));

        if (BitValue_u16 & 0x01)
	    set_bit_u16(ap, BitSpecification);
        else
	    clear_bit_u16(ap, BitSpecification);
    }
    return PORT_OK;
}



PORT_ERROR_E PORT_ReadBit( PORT_NUMBER_E  PortNumber,
        BIT_NUMBER_E  BitSpecification,
	u16_T* BitValue_u16 )
{
    u16_T *p = (u16_T*) (PORT_BASE + 0x0000 + (0x0040 * PortNumber));
    u16_T bitValue = WA(*p);
    *BitValue_u16 = (bitValue & (1<BitSpecification));
    return PORT_OK;
}

PORT_ERROR_E PORT_SetDriveStrength ( PORT_NUMBER_E  PortNumber,
        BIT_NUMBER_E  BitSpecification,
	PORT_DRIVE_STRENGTH_E DriveStrength)
{
    *pkcprot 		= UNLOCK_KCPROT;

    u16_T* pdsc = (u16_T*) (PORT_BASE + 0x0000 + (0x0040 * PortNumber));
    if (DriveStrength == PORT_DRIVE_STRENGTH_LOW){
	clear_bit_u16(pdsc, BitSpecification);
    } else if (DriveStrength == PORT_DRIVE_STRENGTH_HIGH) {
	set_bit_u16(pdsc, BitSpecification);
    } else {
	return -1; //TODO Error Definition
    }

    *pkcprot	= LOCK_KCPROT;

    return PORT_OK;
}

