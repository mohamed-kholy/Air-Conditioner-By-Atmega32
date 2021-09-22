/*
 * Timer_config.h
 *
 * Created: 4/9/2021 10:28:12 PM
 *  Author: Mohamed El-Kholy
 */ 

#ifndef _TIMER_CONFIG_H_
#define _TIMER_CONFIG_H_
	
#define		TIMER0              DISABLE
#define		TIMER1              ENABLE

/*
Options 
		NORMAL
		PWM_PHASE_CORRECT
		CTC
		FAST_PWM
*/
#define 	TIMER0_MODE					NORMAL

/* Timer 1 Mode Config */
/* Options = NORMAL
			 FAST_PWM
			 CTC */

#define      TIMER1_MODE             NORMAL

		/* Timer 0 Interrupt */ 
#define 	TIMER0_OVERFLOW_INTERRUPT		DISABLE
#define 	COMPARE0_MATCH_INTERRUPT 		DISABLE
		/* Timer 1 Interrupt	*/
		
#define TIMER1_OVF_INTERRUPT_INIT              ENABLE
#define TIMER1_CTC_CHANNEL_A_INTERRUPT_INIT    DISABLE
#define TIMER1_CTC_CHANNEL_B_INTERRUPT_INIT    DISABLE

	/* 
		Options
			NO_CLK
			NO_PRESCALING
			CLK_DIV_BY_8
			CLK_DIV_BY_64
			CLK_DIV_BY_256
			CLK_DIV_BY_1024
			EX_CLK_FALLING
			EX_CLK_RISING
		*/
#define 	TIMER0_CLOCK_SELECT					CLK_DIV_BY_8

	/* 
		Options
			NO_CLK
			NO_PRESCALING
			CLK_DIV_BY_8
			CLK_DIV_BY_64
			CLK_DIV_BY_256
			CLK_DIV_BY_1024
			EX_CLK_FALLING
			EX_CLK_RISING
		*/
#define 	TIMER1_CLOCK_SELECT					CLK_DIV_BY_64

/*
		Options 
			ENABLE
			DISABLE
		*/

	
	/**************  Define Pins as Macros *****************/
	
	/*  TCCR0 Bits */

	#define TCCR0_FOC0              7
	#define TCCR0_WGM00             6
	#define TCCR0_COM01             5
	#define TCCR0_COM00             4
	#define TCCR0_WGM01             3
	#define TCCR0_CS02              2
	#define TCCR0_CS01				1
	#define TCCR0_CS00				0


	/*  TCCR1A Bits */

	#define TCCR1A_COM1A1            7
	#define TCCR1A_COM1A0            6
	#define TCCR1A_COM1B1            5
	#define TCCR1A_COM1B0            4
	#define TCCR1A_FOC1A             3
	#define TCCR1A_FOC1B             2
	#define TCCR1A_WGM11			 1
	#define TCCR1A_WGM10			 0

	/*  TCCR1B Bits */

	#define TCCR1B_ICNC1             7
	#define TCCR1B_ICES1             6
	#define TCCR1B_WGM13             4
	#define TCCR1B_WGM12             3
	#define TCCR1B_CS12              2
	#define TCCR1B_CS11			     1
	#define TCCR1B_CS10			     0

	/* TIMSK Bits */
	#define TIMSK_TOIE0             0
	#define TIMSK_OCIE0             1
	#define TIMSK_TOIE1             2
	#define TIMSK_OCIE1B            3
	#define TIMSK_OCIE1A            4
	#define TIMSK_TICIE             5
	
	/* TIFR bits	*/
	#define TIFR_TOV0				0
	#define TIFR_OCF0				1
	#define TIFR_TOV1				2
	#define TIFR_OCF1B				3
	#define TIFR_OCF1A				4
	#define TIFR_ICF1				5
	#define TIFR_TOV2				6
	#define TIFR_OCF2				7
	
	
	
	#define			NORMAL					0
	#define			PWM_PHASE_CORRECT		1
	#define			CTC						2
	#define			FAST_PWM				3
	
	#define 		ENABLE					1
	#define 		DISABLE					0




#endif /* TIMER_CONFIG_H_ */