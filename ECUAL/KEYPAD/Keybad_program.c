

#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "../../MCAL/DIO/MDIO_interface.h"
#include "Keybad_interface.h"
#include "Keybad_config.h"
#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif
#include <util/delay.h>



 const u8 array_data [4][4] =		{{'7','4','1','C'},
									 {'8','5','2','0'},
									 {'9','6','3','='},
									 {'/','*','-','+'}  };

u8 col [8] = {Col0,Col1,Col2,Col3};
u8 row [8] = {Row0,Row1,Row2,Row3};

void EUKeypad_voidKeypadInit (void)
{
	// Make Columns as Output Pins 
	MDIO_voidSetPinDirection (Col0 , HIGH ) ;
	MDIO_voidSetPinDirection (Col1 , HIGH ) ;
	MDIO_voidSetPinDirection (Col2 , HIGH ) ;
	MDIO_voidSetPinDirection (Col3 , HIGH ) ;
	// Make Rows as Input Pins 
	MDIO_voidSetPinDirection (Row0 , LOW ) ;
	MDIO_voidSetPinDirection (Row1 , LOW ) ;
	MDIO_voidSetPinDirection (Row2 , LOW ) ;
	MDIO_voidSetPinDirection (Row3 , LOW ) ;
	// Send High Voltage To Columns 
	MDIO_voidSetPinValue 	 (Col0 , HIGH ) ;
	MDIO_voidSetPinValue 	 (Col1 , HIGH ) ;
	MDIO_voidSetPinValue 	 (Col2 , HIGH ) ;
	MDIO_voidSetPinValue 	 (Col3 , HIGH ) ;
	// Make Rows As Pull Up Resistors 
	MDIO_voidSetPinValue	 (Row0 , HIGH ) ;
	MDIO_voidSetPinValue	 (Row1 , HIGH ) ;
	MDIO_voidSetPinValue	 (Row2 , HIGH ) ;
	MDIO_voidSetPinValue	 (Row3 , HIGH ) ;
}					

u8 EUKeypad_voidKeyPressed (void)
{
	u8 LOC_u8Retrun = 0xFF;

		
	for (u8 colum =0 ; colum <=3 ; colum ++)
	{
		MDIO_voidSetPinValue(col[colum*2],col[colum*2+1] , LOW ) ;
		
		for (u8 rows =0 ; rows <=3 ; rows ++ )
		{
			if ((MDIO_voidGetPinValue(row[rows*2],row[rows*2+1])==0))
			{
				while (MDIO_voidGetPinValue(row[rows*2],row[rows*2+1])==0);
				LOC_u8Retrun = array_data [colum][rows] ;

			}
		}
		MDIO_voidSetPinValue(col[colum*2],col[colum*2+1] , HIGH ) ;
	}
	return LOC_u8Retrun ;

	
}
