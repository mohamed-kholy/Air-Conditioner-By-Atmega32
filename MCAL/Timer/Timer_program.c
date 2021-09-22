/*
 * Timer_program.c
 *
 * Created: 4/9/2021 10:27:12 PM
 *  Author: Mohamed El-Kholy
 */ 
#include  	 "../../LIB/BIT_MATH/BIT_MATH.h"
#include  	 "../../LIB/STD_TYPES/STD_TYPES.h"
#include "Timer_register.h"
#include "Timer_config.h"
#include "Timer_interface.h"

/* Global Pointer To Function */
static void (*ptr) (void) ;
/* Define NULL pointer */
#define			NULL    ((void*)0)

/********************************************************************************************************************************
* Parameters:(in) : None
* Parameters:(out): Initialize Timer
* Return value	  : none
* Description	  : Function used to initialize the timer based on the Configuration file
**********************************************************************************************************************************/

	
void MTimer_voidInit (void)
{
	#if (TIMER0 == DISABLE)
	TCCR0 &= ~(1<<TCCR0_CS02);
	TCCR0 &= ~(1<<TCCR0_CS01);
	TCCR0 &= ~(1<<TCCR0_CS00);
	#elif (TIMER0 == ENABLE)
	//Check if OVF INT is enabled
	#if (TIMER0_OVERFLOW_INTERRUPT == ENABLE)
	TIMSK |= (1<<TIMSK_TOIE0) ;
	#elif (TIMER0_OVERFLOW_INTERRUPT == DISABLE)
	TIMSK &= ~ (1<<TIMSK_TOIE0) ;
	#endif
	//Check if CTC INT is enabled
	#if (COMPARE0_MATCH_INTERRUPT == ENABLE)
	TIMSK |= (1<<TIMSK_OCIE0) ;
	#elif COMPARE0_MATCH_INTERRUPT == DISABLE
	TIMSK &= ~(1<<TIMSK_OCIE0) ;
	#endif
	
	//Choose The Mode of the timer and the prescaler
	#if (TIMER0_MODE == FAST_PWM)
	//Set Fast Pwm Mode
	TCCR0 |= (1<<TCCR0_WGM00) ;
	TCCR0 |= (1<TCCR0_<WGM01);
	#elif TIMER0_MODE == NORMAL
	TCCR0 &= ~(1<<TCCR0_WGM00) ;
	TCCR0 &= ~(1<<TCCR0_WGM01) ;
	#elif TIMER0_MODE == CTC
	TCCR0 &= ~(1<<TCCR0_WGM00) ;
	TCCR0 |= (1<<TCCR0_WGM01);
	#endif
	/* Select the Prescaler value to start the timer to count */
	TCCR0 |= TIMER0_CLOCK_SELECT;
	#endif
	
	#if (TIMER1 == DISABLE )
	
	TCCR1B &= ~ (1<<TCCR1B_CS10);
    TCCR1B &= ~ (1<<TCCR1B_CS11);
	TCCR1B &= ~ (1<<TCCR1B_CS12);
	#elif (TIMER1 == ENABLE )
	//Check OVF Int
	#if (TIMER1_OVF_INTERRUPT_INIT == ENABLE)
	TIMSK|=(1<<TIMSK_TOIE1);
	#elif (TIMER1_OVF_INTERRUPT_INIT == DISABLE)
	TIMSK &= ~(1<<TIMSK_TOIE1);
	#endif
	
	//Check CTC INT
	#if (TIMER1_CTC_CHANNEL_A_INTERRUPT_INIT == ENABLE)
	TIMSK |= (1<<TIMSK_OCIE1A) ;
	#elif (TIMER1_CTC_CHANNEL_A_INTERRUPT_INIT == DISABLE)
	TIMSK &= ~(1<<TIMSK_OCIE1A) ;
	#endif
	
	#if (TIMER1_CTC_CHANNEL_B_INTERRUPT_INIT == ENABLE)
	TIMSK |= (1<<TIMSK_OCIE1B) ;
	#elif (TIMER1_CTC_CHANNEL_B_INTERRUPT_INIT == DISABLE)
	TIMSK &= ~(1<<TIMSK_OCIE1B) ;
	#endif
	
	//Choose The Timer 1 Mode
	#if TIMER1_MODE == FAST_PWM
	TCCR1B |= (1<<TCCR1B_WGM13) ;
	TCCR1B |= (1<<TCCR1B_WGM12) ;
	TCCR1A |= (1<<TCCR1A_WGM11) ;
	TCCR1A |= (1<<TCCR1A_WGM10) ;

	#elif TIMER1_MODE  == NORMAL
	TCCR1B &= ~(1<<TCCR1B_WGM13) ;
	TCCR1B &= ~(1<<TCCR1B_WGM12) ;
	TCCR1A &= ~(1<<TCCR1A_WGM11) ;
	TCCR1A &= ~(1<<TCCR1A_WGM10) ;
	#endif
	
	/* Set the Prescaler value as configured at the configuration file */
	TCCR1B |= TIMER1_CLOCK_SELECT;
	#endif

}

/********************************************************************************************************************************
* Parameters:(in) : 16 bit unsigned char , holds the initaile value of the TCNT
* Parameters:(out): Write The initial  value to TCNT
* Return value	  : 8bit signed char , return -1 if error occurs
* Description	  : Function used to Set The TCNT Register with the initial value
**********************************************************************************************************************************/

s8  MTimer_s8SetTCNT(u16 copy_u16Time)
{
	/* local Variable holds the retun value */
	u8 local_u8Return = 0;
	/* incase of Timer 0 Enable */
	if (TIMER0 == ENABLE)
	{
		if (copy_u16Time <= 256 )
		TCNT0 = copy_u16Time ;
		else
		return local_u8Return = -1 ;
	}
	/* incase of Timer 1 Enable */
	if	( TIMER1 == ENABLE )
	{
		if (copy_u16Time <= 65536 )
		TCNT1 = copy_u16Time ;
		else
		return local_u8Return = -1 ;
	}
	
}


/********************************************************************************************************************************
* Parameters:(in) : 8 bit unsigned char , holds the flag Name
* Parameters:(out): None
* Return value	  : 8bit signed char , return -1 if error occurs
* Description	  : Function used to Check of the Required flag became one
**********************************************************************************************************************************/


s8  MTimer_s8CheckFlag(u8 copy_u8Flag)
{
	if (TIMER0 == ENABLE )
	{
		switch (copy_u8Flag) 
		{
			case OVERFLOW			 : while (!(TIFR & (1<<TIFR_TOV0))); break ;
			case OUTPUT_COMPARE_0	 : while (!(TIFR & (1<<TIFR_OCF0))); break ;
		}
	}
	
	if ( TIMER1 == ENABLE )
	{
		switch (copy_u8Flag)
		{
			case OVERFLOW			 : while (!(TIFR & (1<<TIFR_TOV1))); break ;
			case OUTPUT_COMPARE_A	 : while (!(TIFR & (1<<TIFR_OCF1A))); break ;
			case OUTPUT_COMPARE_B	 : while (!(TIFR & (1<<TIFR_OCF1B))); break ;
		}
	}

	return -1;

}


/********************************************************************************************************************************
* Parameters:(in) : None
* Parameters:(out): None
* Return value	  : None
* Description	  : Function used to Clear All The Flags
**********************************************************************************************************************************/

void  MTimer_voidClearFlag(void)
{
	if (TIMER0 == ENABLE )
	{
		TIFR |=(1<<TIFR_TOV0);
		TIFR |=(1<<TIFR_OCF0);

	}
	
	if ( TIMER1 == ENABLE )
	{
		TIFR |=(1<<TIFR_TOV1);
		TIFR |=(1<<TIFR_OCF1A);
		TIFR |=(1<<TIFR_OCF1B);
		
	}
}

/********************************************************************************************************************************
* Parameters:(in) : None
* Parameters:(out): None
* Return value	  : None
* Description	  : Function to Enable Global Interrupt
**********************************************************************************************************************************/

void MTimer_voidEnableGIE (void)
{
	SET_BIT	(SREG ,7 );
}

/********************************************************************************************************************************
* Parameters:(in) : None
* Parameters:(out): None
* Return value	  : None
* Description	  : Function to Disable  Global Interrupt
**********************************************************************************************************************************/
void MTimer_voidDisableGIE (void)
{
	CLR_BIT	(SREG ,7 );
}

/********************************************************************************************************************************
* Parameters:(in) : Pointer to Function
* Parameters:(out): None
* Return value	  : None
* Description	  : Function to Take pointer to function from the main Application and pass it to the local Pointer 
**********************************************************************************************************************************/
void MTimer_voidSetCallBack(void (*ptrfunc)(void ))
{
	ptr = ptrfunc ;
}

/* Vector Function fot Timer 0 and Timer 1 Intterrupts */

void __vector_7  (void)
{
	if (ptr != NULL )
	{
		ptr();
	}
}
void __vector_8 (void)
{
	if (ptr != NULL )
	{
		ptr();
	}
}
void __vector_9 (void)
{

		ptr();
}
void __vector_10 (void)
{
	if (ptr != NULL )
	{
		ptr();
	}
}
void __vector_11 (void)
{
	if (ptr != NULL )
	{
		ptr();
	}
}