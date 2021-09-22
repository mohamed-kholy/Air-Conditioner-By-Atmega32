#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "BUTTON_interface.h"
#include "../../MCAL/DIO/MDIO_interface.h"

#define ERROR		-1


s8 EUButton_init(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8ConnectionType ) 
{
	if ( ((copy_u8Port == GPIOA ) || (copy_u8Port== GPIOB) || (copy_u8Port == GPIOC) || (copy_u8Port == GPIOD)) && ((copy_u8Pin <=7)))
	{
		MDIO_voidSetPinDirection(copy_u8Port,copy_u8Pin,LOW);
		if ( copy_u8ConnectionType == PULL_UP ){
			MDIO_voidSetPinValue ( copy_u8Port , copy_u8Pin , HIGH ) ;
		}
		else if ( copy_u8ConnectionType == PULL_DOWN ){
			MDIO_voidSetPinValue ( copy_u8Port , copy_u8Pin , LOW ) ;
		}
	}
	else {
		return ERROR ;
	}
}





/************************************************************************************
* Parameters  :(in): PORT Name , Pin Number , Type OF the Connection (Pull Up or Pull Down )
* Parameters  :(out): Button Pressed or None 
* Return value: 8-bit signed Char , if Pressed return 1 , not pressed return 0 otherwise return -1 
* Description : Check If the Button Pressed Or Not 
************************************************************************************/

s8	EUButtonPressed(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8ConnectionType )
{
	/* Local Variable hold the Return Value */
	u8 copy_u8LocalReturn = 0 ;
	/* In case of Pull Up Connection */
	if (copy_u8ConnectionType == PULL_UP)
	{	
		/* Read the Value */ 
		copy_u8LocalReturn=MDIO_voidGetPinValue(copy_u8Port,copy_u8Pin);
		/* If Pressed Return  */
		if (copy_u8LocalReturn == 0 )
			return 1 ;
		/* Otherwise Return 0 */
		else 
			return 	 0 ;
	}
	/* In case of PULL Down */
	else if (copy_u8ConnectionType == PULL_DOWN)
	{
		/* Read the Value */ 
		copy_u8LocalReturn=MDIO_voidGetPinValue(copy_u8Port,copy_u8Pin);
		/* If Pressed */
		if (copy_u8LocalReturn == 1 )
			return 1 ;
		/* Otherwise */
		else 
			return 	0 ;
		
	}
	/* if Error */
	else 
		return -1 ;
	
}