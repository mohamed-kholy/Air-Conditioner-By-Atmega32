#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "PWM_config.h"
#include "PWM_private.h"
#include "PWM_interface.h"
#include "../DIO/MDIO_interface.h"



void MPWM_voidPwmInit(void) 
{
	#if (TIMER0 == DISABLE)
	TCCR0 &= ~(1<<TCCR0_CS02);
	TCCR0 &= ~(1<<TCCR0_CS01);
	TCCR0 &= ~(1<<TCCR0_CS00);
	#elif (TIMER0 == ENABLE)
	#if (PWM0_TYPE == FAST_PWM)
	//Set Fast PWM Mode
	TCCR0 |= (1<<TCCR0_WGM00) ;
	TCCR0 |= (1<<TCCR0_WGM01);
	/* Make PIN B3 output */
	MDIO_voidSetPinDirection(GPIOB , PIN3 , HIGH);
	//Set PWM Phase Correct Mode 
	#elif (PWM0_TYPE == PWM_PHASE_CORRECT )
	TCCR0 |= (1<<TCCR0_WGM00) ;
	TCCR0 &= ~(1<<TCCR0_WGM01);
	/* Make PIN B3 output */
	MDIO_voidSetPinDirection(GPIOB , PIN3 , HIGH);
	#endif 
	
	#if (PWM0_MODE == NON_INVERTING)
	TCCR0 |= (1<<TCCR0_COM01);
	TCCR0 &= ~(1<<TCCR0_COM00);
	#elif (PWM0_MODE == INVERTING)
	TCCR0 |= (1<<TCCR0_COM01);
	TCCR0 |= (1<<TCCR0_COM00);
	#endif
	
	#endif 
	
	#if (TIMER1 == DISABLE )
	TCCR1B &= ~ (1<<TCCR1B_CS10);
	TCCR1B &= ~ (1<<TCCR1B_CS11);
	TCCR1B &= ~ (1<<TCCR1B_CS12);
	#elif (TIMER1 == ENABLE )
	//Choose The PWM 1 Mode
	#if PWM1_TYPE == FAST_PWM
	TCCR1B |= (1<<TCCR1B_WGM13) ;
	TCCR1B |= (1<<TCCR1B_WGM12) ;
	TCCR1A |= (1<<TCCR1A_WGM11) ;
	TCCR1A &= ~(1<<TCCR1A_WGM10) ;
	/* Make PIN D4 and D5 Output pins */
	MDIO_voidSetPinDirection(GPIOD , PIN4 ,HIGH);
	MDIO_voidSetPinDirection(GPIOD,PIN5,HIGH);
	#elif PWM1_TYPE == PWM_PHASE_CORRECT
	TCCR1B |= (1<<TCCR1B_WGM13) ;
	TCCR1B &= ~(1<<TCCR1B_WGM12) ;
	TCCR1A |= (1<<TCCR1A_WGM11) ;
	TCCR1A |= (1<<TCCR1A_WGM10) ;
	/* Make PIN D4 and D5 Output pins */
	MDIO_voidSetPinDirection(GPIOD,PIN4,HIGH);
	MDIO_voidSetPinDirection(GPIOD,PIN5,HIGH);
	#endif
	
	#if (PWM1_MODE == NON_INVERTING)
	TCCR1A |= (1<<TCCR1A_COM1A1);
	TCCR1A |= (1<<TCCR1A_COM1B1);
	TCCR1A &= ~(1<<TCCR1A_COM1A0);
	TCCR1A &= ~(1<<TCCR1A_COM1B0);
	#elif (PWM1_MODE == INVERTING)
	TCCR1A |= (1<<TCCR1A_COM1A1);
	TCCR1A |= (1<<TCCR1A_COM1B1);
	#endif

	#endif
}

void MPWM_voidSetDutyCycle (float copy_u8DutyPercentage )
{
	float local_u8DutyValue = 0 ;
	if (TIMER0 == ENABLE)
	{
		local_u8DutyValue=((copy_u8DutyPercentage/100) * PWM0_MAX_VALUE );
		OCR0 = local_u8DutyValue ;
	}
	else if (TIMER1 == ENABLE)
	{
		ICR1 = TIMER1_ICR1_VALUE ;
		local_u8DutyValue=	(copy_u8DutyPercentage/100) * (TIMER1_ICR1_VALUE+1) ;
		OCR1A = local_u8DutyValue ;
		OCR1B = local_u8DutyValue ;
	}

}
void MPWM_voidStartPWM(void)
{
	#if (TIMER0 == ENABLE)
	/* Select the Prescaler value to start the timer to count */
	TCCR0 |= TIMER0_CLOCK_SELECT;
	#endif
	#if (TIMER1 == ENABLE)
	/* Set the Prescaler value as configured at the configuration file */
	TCCR1B |= TIMER1_CLOCK_SELECT;
	#endif
}

void MPWM_voidStopPWM(void)
{
	#if (TIMER0 == ENABLE)
	TCCR0 &= 0b11111000;
	#endif
	#if (TIMER1 == ENABLE)
	TCCR1B |= 0b11111000;
	#endif

}
