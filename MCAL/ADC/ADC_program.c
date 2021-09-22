/************************************************************************************/
/* Author     : Mohamed El_Kholy                                                    */
/* Version    : V01                                                                 */
/* Date       : 28 JAN 2021		                                                    */
/************************************************************************************/

#include 	"ADC_interface.h"

/* Global Pointer To Function */
static void (*ptr) (void) ;
/* Define NULL pointer */
#define			NULL    ((void*)0)
/********************************************************************************************************************************
* Parameters:(in) : void
* Parameters:(out): initialize Port A to work as ADC
* Return value	  : none
* Description	  : Function used to make the internal ADC ready to be used
**********************************************************************************************************************************/
void MADC_voidInit 		(void)
{
	// Select Voltage Reference 
	#if  VOLTAGE_REF == AREF 
	CLR_BIT(ADCMUX , REFS0 ) ;
	CLR_BIT(ADCMUX , REFS1 ) ;
	#elif VOLTAGE_REF == AVCC 
	SET_BIT(ADCMUX , REFS0 ) ;
	CLR_BIT(ADCMUX , REFS1 ) ;
	#elif VOLTAGE_REF == INTERNAL_2_HALF_VOLT
	SET_BIT(ADCMUX , REFS0 ) ;
	SET_BIT(ADCMUX , REFS1 ) ;
	#endif 
	// Select Adjustment
	#if  ADC_ADJUST == RIGHT_ADJUST 
	CLR_BIT(ADCMUX , ADLAR ) ;
	#elif ADC_ADJUST == LEFT_ADJUST
	SET_BIT(ADCMUX , ADLAR ) ;
	#endif 
	// select Pre_Scalaer 
	ADCSRA |= ADC_PRE_SCALER  ; 
	// Select Interrupt ADC 
	#if	 ADC_INTERRUPT == ENABLE
	SET_BIT(ADCSRA , ADIE ) ;
	#elif ADC_INTERRUPT == DISABLE
	CLR_BIT(ADCSRA , ADIE ) ;
	#endif 
	// Select Auto Trigger 
	#if AUTO_TRIGGER ==ENABLE	
	SET_BIT(ADCSRA , ADATE ) ;
	#elif AUTO_TRIGGER == DISABLE
	CLR_BIT(ADCSRA , ADATE ) ;
	#endif 
	//Enable ADC
	SET_BIT(ADCSRA , ADEN ) ;
		
}
/********************************************************************************************************************************
* Parameters:(in) : ADC Channel pin (ADC0,ADC1,ADC2,.....)
* Parameters:(out): Read the analog signal from the ADC channel
* Return value	  : integer value from the ADC
* Description	  : Function used to read the ADC signal
**********************************************************************************************************************************/
u16  MADC_u16Read(u8 copy_u8ChannelId )
{
	u16 Local_16ReadValue = 0 ;
	// Clear Old Channel Number 
	ADCMUX &= 0b11100000 ;
	// Choose Channel ID 
	ADCMUX |= copy_u8ChannelId ;
	// Start Conversion 
	SET_BIT(ADCSRA , ADSC ) ;
	// Wait till The Conversion is Done 
	while (!(GET_BIT(ADCSRA , ADIF)));
	/* Clear Flag */
	SET_BIT(ADCSRA,ADIF);
	//Get The Digital Value form ADCL and ADCH Registers
	Local_16ReadValue = ADC ; 
	return Local_16ReadValue;
}

/********************************************************************************************************************************
* Parameters:(in) : Pointer to Function
* Parameters:(out): None
* Return value	  : None
* Description	  : Function to Take pointer to function from the main Application and pass it to the local Pointer
**********************************************************************************************************************************/
void MADC_voidSetCallBack(void (*ptrfunc)(void ))
{
	ptr = ptrfunc ;
}
/* Vector Function for ADC Interrupt */
void ADC_vect (void)
{
	if (ptr != NULL )
	{
		ptr();
	}
}
