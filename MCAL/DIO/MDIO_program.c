/************************************************************************************/
/* Author     : Mohamed El_KHoly                                                    */
/* Version    : V01                                                                 */
/* Date       : 02/9/2021                                            		        */
/************************************************************************************/

#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include	 "MDIO_register.h"
#include 	 "MDIO_config.h"
#include	 "MDIO_interface.h"


/********************************************************************************************************************************
* Parameters:(in) : PORT Name , Pin Number , Direction (Input or Output )
* Parameters:(out): Make Specific Pin Output 
* Return value	  : none
* Description	  : Function used to get the input Parameters and make the Specific Pin as output According to the Input Parameters
**********************************************************************************************************************************/

void MDIO_voidSetPinDirection (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Direction ) 
{
	
	if (copy_u8Direction == OUTPUT ) // Configure as Output 
	{
		switch (copy_u8Port )
		{
			
			case GPIOA :
				if (copy_u8Pin <=7 )
				SET_BIT (DDRA_REGISTER , copy_u8Pin ) ;
			break ;
			case GPIOB :
				if (copy_u8Pin <=7 )
				SET_BIT (DDRB_REGISTER , copy_u8Pin ) ;
			break ;
			case GPIOC :
				if (copy_u8Pin <=7 )
				SET_BIT (DDRC_REGISTER , copy_u8Pin ) ;
			break ;
			case GPIOD :
				if (copy_u8Pin <=7 )
				SET_BIT (DDRD_REGISTER , copy_u8Pin ) ;
			break ;
	
		}
	}
	else if (copy_u8Direction == INPUT )
	{
		switch (copy_u8Port)
		{
			case GPIOA :
				if (copy_u8Pin <=7 )
				CLR_BIT (DDRA_REGISTER , copy_u8Pin ) ;
			break ;
			case GPIOB :
				if (copy_u8Pin <=7 )
				CLR_BIT (DDRB_REGISTER , copy_u8Pin ) ;
			break ;
			case GPIOC :
				if (copy_u8Pin <=7 )
				CLR_BIT (DDRC_REGISTER , copy_u8Pin ) ;
			break ;
			case GPIOD :
				if (copy_u8Pin <=7 )
				CLR_BIT (DDRD_REGISTER , copy_u8Pin ) ;
			break ;
		}
	}
}

/********************************************************************************************************************************
* Parameters:(in) : PORT Name ,  Direction (Input or Output )
* Parameters:(out): Make Specific Port Output
* Return value	  : none
* Description	  : Function used to get the input Parameters and make the Specific Port as output According to the Input Parameters
**********************************************************************************************************************************/

void MDIO_voidSetPortDirection (u8 copy_u8Port  , u8 copy_u8Direction ) 
{
	if (copy_u8Direction == OUTPUT ) // Configure as Output 
	{
		switch (copy_u8Port )
		{
			
			case GPIOA :
				DDRA_REGISTER = 0xff ;
			break ;
			case GPIOB :
				DDRB_REGISTER = 0xff ;
			break ;
			case GPIOC :
				DDRC_REGISTER = 0xff ;
			break ;
			case GPIOD :
				DDRD_REGISTER = 0xff ;
			break ;
	
		}
	}
	else if (copy_u8Direction == INPUT )
	{
		switch (copy_u8Port)
		{
			case GPIOA :
				DDRA_REGISTER = 0x00 ;
			break ;
			case GPIOB :
				DDRA_REGISTER = 0x00 ;
			break ;
			case GPIOC :
				DDRA_REGISTER = 0x00 ;
			break ;
			case GPIOD :
				DDRA_REGISTER = 0x00 ;
			break ;
		}
	}		
}

/********************************************************************************************************************************
* Parameters:(in) : PORT Name , Pin Number ,  Pin Value   (High  or Low )
* Parameters:(out): Make Specific Pin High of Low 
* Return value	  : none
* Description	  : Function used to make the Specific Pin High of Low According to the Input Parameters
**********************************************************************************************************************************/
void MDIO_voidSetPinValue (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value ) 
{
	if (copy_u8Value == HIGH )
	{
		switch (copy_u8Port )
		{
			
			case GPIOA :
				if (copy_u8Pin <=7 )
				SET_BIT (PORTA_REGISTER , copy_u8Pin ) ;
			break ;
			case GPIOB :
				if (copy_u8Pin <=7 )
				SET_BIT (PORTB_REGISTER , copy_u8Pin ) ;
			break ;
			case GPIOC :
				if (copy_u8Pin <=7 )
				SET_BIT (PORTC_REGISTER , copy_u8Pin ) ;
			break ;
			case GPIOD :
				if (copy_u8Pin <=7 )
				SET_BIT (PORTD_REGISTER , copy_u8Pin ) ;
			break ;
	
		}
	}
	else if (copy_u8Value == LOW )
	{
		switch (copy_u8Port )
		{
			
			case GPIOA :
				if (copy_u8Pin <=7 )
				CLR_BIT (PORTA_REGISTER , copy_u8Pin ) ;
			break ;
			case GPIOB :
				if (copy_u8Pin <=7 )
				CLR_BIT (PORTB_REGISTER , copy_u8Pin ) ;
			break ;
			case GPIOC :
				if (copy_u8Pin <=7 )
				CLR_BIT (PORTC_REGISTER , copy_u8Pin ) ;
			break ;
			case GPIOD :
				if (copy_u8Pin <=7 )
				CLR_BIT (PORTD_REGISTER , copy_u8Pin ) ;
			break ;
	
		}
		
	}
	
}
/********************************************************************************************************************************
* Parameters:(in) : PORT Name ,  Pin Value   (High  or Low )
* Parameters:(out): Make Specific Port High of Low
* Return value	  : none
* Description	  : Function used to make the Specific Port High of Low According to the Input Parameters
**********************************************************************************************************************************/
void MDIO_voidSetPortValue (u8 copy_u8Port , u8 copy_u8Value ) 
{
	if (copy_u8Value == HIGH ) // Configure as High Output  
	{
		switch (copy_u8Port )
		{
			
			case GPIOA :	PORTA_REGISTER = 0xff ; break ;
			case GPIOB :    PORTB_REGISTER = 0xff ; break ;
			case GPIOC :	PORTC_REGISTER = 0xff ; break ;
			case GPIOD :    PORTD_REGISTER = 0xff ; break ;
	
		}
	}
	else if (copy_u8Value == LOW )
	{
		switch (copy_u8Port)
		{
			case GPIOA :	PORTA_REGISTER = 0x00 ;  break ;
			case GPIOB :	PORTB_REGISTER = 0x00 ;	break ;
			case GPIOC :	PORTC_REGISTER = 0x00 ;  break ;
			case GPIOD :	PORTD_REGISTER = 0x00 ;  break ;
		}
	}
	else
	{
		switch (copy_u8Port)
				{
					case GPIOA :	PORTA_REGISTER = copy_u8Value ;  break ;
					case GPIOB :	PORTB_REGISTER = copy_u8Value ;	break ;
					case GPIOC :	PORTC_REGISTER = copy_u8Value ;  break ;
					case GPIOD :	PORTD_REGISTER = copy_u8Value ;  break ;
				}
	}
	
}

/********************************************************************************************************************************
* Parameters:(in) : PORT Name , Pin Number 
* Parameters:(out): Get The Value Of the Specific Pin (Low or High )
* Return value	  :  Return 8-Bit unsigned Char that holds the value of specific Pin
* Description	  : Function used to get the Specific Pin Value High of Low 
**********************************************************************************************************************************/

u8 MDIO_voidGetPinValue (u8 copy_u8Port , u8 copy_u8Pin )
{
	u8 LocGetValue = 0 ;
	switch (copy_u8Port )
	{
		case GPIOA : LocGetValue = GET_BIT (PINA_REGISTER ,  copy_u8Pin ); break ;
		case GPIOB : LocGetValue = GET_BIT (PINB_REGISTER ,  copy_u8Pin ); break ;
		case GPIOC : LocGetValue = GET_BIT (PINC_REGISTER ,  copy_u8Pin ); break ;
		case GPIOD : LocGetValue = GET_BIT (PIND_REGISTER ,  copy_u8Pin ); break ;
		
	}
	return LocGetValue ; 
}
/********************************************************************************************************************************
* Parameters:(in) : PORT Name , Pin Number
* Parameters:(out): Toggle The Value Of the Specific Pin 
* Return value	  :  None
* Description	  : Function used to Toggle the Specific Pin Value (High To Low) OR (Low To High )
**********************************************************************************************************************************/

void MDIO_voidTogglePin (u8 copy_u8Port , u8 copy_u8Pin ) 
{
	switch (copy_u8Port ) 
	{
		case GPIOA :   TOG_BIT (PORTA_REGISTER ,copy_u8Pin ); break ;
		case GPIOB :   TOG_BIT (PORTB_REGISTER ,copy_u8Pin ); break ;
		case GPIOC :   TOG_BIT (PORTC_REGISTER ,copy_u8Pin ); break ;
		case GPIOD :   TOG_BIT (PORTD_REGISTER ,copy_u8Pin ); break ;
	}
	
}

