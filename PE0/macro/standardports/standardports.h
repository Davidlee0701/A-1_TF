/*
 * standardports.h
 *
 *  Created on: 25.10.2024
 *      Author: a5105882
 */

#ifndef SRC_MACRO_STANDARDPORTS_STANDARDPORTS_H_
#define SRC_MACRO_STANDARDPORTS_STANDARDPORTS_H_

#define PORT_BASE 0x5C190000
#define JPORT_BASE 0x5C1A0000

#include <U5L_common_types.h>

typedef enum {
	PORT_OK = 0,
	EINVALID_PORT,
}PORT_ERROR_E;

typedef enum port_number {
	PORT_0 	= 0,
	PORT_1 	= 1,
	PORT_2 	= 2,
	PORT_3 	= 3,
	PORT_4 	= 4,
	PORT_5 	= 5,
	PORT_6 	= 6,
	PORT_7 	= 7,
	PORT_8 	= 8,
	PORT_9 	= 9,
	PORT_10 = 10,
	PORT_11 = 11,
	PORT_12 = 12,
	PORT_13 = 13,
	PORT_14 = 14,
	PORT_15 = 15,
	PORT_16 = 16,
	PORT_17 = 17,
	PORT_18 = 18,
	PORT_19 = 19,
	PORT_20 = 20,
	PORT_21 = 21,
	PORT_27 = 27,
	JP_0	= 28,
	AP_0	= JP_0 + 1,
	AP_2	= AP_0 + 2,
	
}PORT_NUMBER_E;

typedef enum {
	BIT_0 	= 0,
	BIT_1 	= 1,
	BIT_2 	= 2,
	BIT_3 	= 3,
	BIT_4 	= 4,
	BIT_5 	= 5,
	BIT_6 	= 6,
	BIT_7 	= 7,
	BIT_8 	= 8,
	BIT_9 	= 9,
	BIT_10 = 10,
	BIT_11 = 11,
	BIT_12 = 12,
	BIT_13 = 13,
	BIT_14 = 14,
	BIT_15 = 15,
}BIT_NUMBER_E;

typedef enum {
	PORT_DIR_INPUT 	= 1,
	PORT_DIR_OUTPUT = 0,
	PORT_DIR_KEEP 	= 2,
} PORT_DIRECTION_E;

typedef enum {
	PORT_MODE_PERIPHERAL = 1,
	PORT_MODE_IO 		 = 0,
	PORT_MODE_KEEP 		 = 2,
} PORT_MODE_CONTROL_E;

typedef enum {
	PORT_FUNCTION_NORMAL	= 0xF0,
	PORT_FUNCTION_ALTERN1	= 0x0,
	PORT_FUNCTION_ALTERN2	= 0x01,
	PORT_FUNCTION_ALTERN3	= 0x02,
	PORT_FUNCTION_ALTERN4	= 0x03,
	PORT_FUNCTION_ALTERN5	= 0x04,
	PORT_FUNCTION_ALTERN6	= 0x05,
	PORT_FUNCTION_ALTERN7	= 0x06,
	PORT_FUNCTION_ALTERN8	= 0x07,
	PORT_FUNCTION_ALTERN9	= 0x08,
	PORT_FUNCTION_ALTERN10	= 0x09,
	PORT_FUNCTION_ALTERN11	= 0x0A,
	PORT_FUNCTION_ALTERN12	= 0x0B,
	PORT_FUNCTION_ALTERN13	= 0x0C,
	PORT_FUNCTION_ALTERN14	= 0x0D,
	PORT_FUNCTION_ALTERN15	= 0x0E,
	PORT_FUNCTION_ALTERN16	= 0x0F,
	PORT_FUNCTION_KEEP		= 0xFF,
} PORT_ALTERNATE_FUNCTION_E;

typedef enum {
	PORT_DRIVE_STRENGTH_LOW  = 0,
	PORT_DRIVE_STRENGTH_HIGH = 1,
} PORT_DRIVE_STRENGTH_E;

extern void set_alternate_function( PORT_NUMBER_E PortNumber, BIT_NUMBER_E BitSpecification, PORT_ALTERNATE_FUNCTION_E AlternateFunction);
PORT_ERROR_E set_pwe(PORT_NUMBER_E PortNumber);
PORT_ERROR_E clear_pwe(PORT_NUMBER_E PortNumber);

PORT_ERROR_E PORT_Enable( 	PORT_NUMBER_E 	 			PortNumber,
                 	 	 	BIT_NUMBER_E 	 			BitSpecification,
							PORT_DIRECTION_E 			PortDirection,
							PORT_MODE_CONTROL_E 		PeripheralMode,
							PORT_ALTERNATE_FUNCTION_E	AlternateFunction  );

PORT_ERROR_E PORT_Disable( PORT_NUMBER_E PortNumber_u16,
                  	  	   BIT_NUMBER_E BitSpecification_u16 );

PORT_ERROR_E PORT_Write( PORT_NUMBER_E PortNumber,
                       	 u16_T PortData_u16 );

PORT_ERROR_E PORT_Read( PORT_NUMBER_E  PortNumber,
                      	u16_T* PortData_pu16 );

PORT_ERROR_E PORT_WriteBit( PORT_NUMBER_E PortNumber,
                            BIT_NUMBER_E BitSpecification,
							u16_T BitValue_u16 );

PORT_ERROR_E PORT_ReadBit( PORT_NUMBER_E  PortNumber,
                           BIT_NUMBER_E  BitSpecification,
						   u16_T* BitValue_u16 );

PORT_ERROR_E PORT_SetDriveStrength ( PORT_NUMBER_E  PortNumber,
        							 BIT_NUMBER_E  BitSpecification,
									 PORT_DRIVE_STRENGTH_E DriveStrength);


#endif /* SRC_MACRO_STANDARDPORTS_STANDARDPORTS_H_ */
