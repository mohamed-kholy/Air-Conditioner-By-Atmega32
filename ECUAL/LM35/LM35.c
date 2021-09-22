/*
 * LM35.c
 *
 * Created: 9/17/2021 4:16:55 AM
 *  Author: Ahmed SemSem
 */ 
#include "LM35.h"

#define 	VREF 		5000UL			// as Milli Volt

/********************************************************************************************************************************
* Parameters:(in) : void
* Parameters:(out): Call the ADC initialization function
* Return value	  : none
* Description	  : Function used to make the internal ADC ready to be used
**********************************************************************************************************************************/
void EULM35_voidInit(void){
	MADC_voidInit();
	
}
/********************************************************************************************************************************
* Parameters:(in) : ADC Channel pin (ADC0,ADC1,ADC2,.....)
* Parameters:(out): Read the analog signal from temperature sensor
* Return value	  : integer value from Sensor
* Description	  : Function used to read the LM35 Signal
**********************************************************************************************************************************/
u16 EULM35_u16LM35ReadValue(u8 copy_u8ChannelNum)
{
	u16 Local_u16DigitalValue = 0 ;
	u16 Local_u16AnalogValue ;
	u8 Local_u16Temperature ;
	Local_u16DigitalValue = MADC_u16Read(copy_u8ChannelNum) ;
	Local_u16AnalogValue = (Local_u16DigitalValue * VREF) / 1024 ;
	Local_u16Temperature = Local_u16AnalogValue/10  ;
	return Local_u16Temperature;
}