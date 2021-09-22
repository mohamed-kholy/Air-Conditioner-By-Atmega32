/*
 * Timer_register.h
 *
 * Created: 4/9/2021 10:27:12 PM
 *  Author: Mohamed El-Kholy
 */ 
 
 /* Define Timer Registers */
 
 #ifndef _TIMER_REGISTER_H_
 #define _TIMER_REGISTER_H_
 
 /* 			Timer 0 Register			*/
 #define 			TCCR0		(*(volatile u8*) (0X53))
 #define 			TCNT0		(*(volatile u8*) (0X52))
 #define 			OCR0		(*(volatile u8*) (0X5C))
 /* 			Timer 1 Registers 			*/	   
 #define 			TCCR1A		(*(volatile u8*) (0X4F))
 #define 			TCCR1B		(*(volatile u8*) (0X4E))
 #define 			TCNT1		(*(volatile u16*)(0X4C))
 #define 			TCNT1H		(*(volatile u8*) (0X4D))
 #define 			TCNT1L		(*(volatile u8*) (0X4C))
 #define 			OCR1AH		(*(volatile u8*) (0X4B))
 #define 			OCR1AL		(*(volatile u8*) (0X4A))
 #define 			OCR1BH		(*(volatile u8*) (0X49))
 #define 			OCR1BL		(*(volatile u8*) (0X48))
 #define 			ICR1H		(*(volatile u8*) (0X47))
 #define 			ICR1L		(*(volatile u8*) (0X46))
 /* 			Timer 2 Registers			*/	   
 #define 			TCCR2		(*(volatile u8*) (0X45))
 #define 			TCNT2		(*(volatile u8*) (0X44))
 #define 			OCR2		(*(volatile u8*) (0X43))
 /*				Timer Interrupt Register 	*/	   
 #define 			TIMSK		(*(volatile u8*) (0X59))
 #define 			TIFR		(*(volatile u8*) (0X58))
 
 /*					Global Interrupt Register		*/
#define 			SREG	    (*(volatile u8*) (0x5F))
	 

 #if (TIMER1_CTC_CHANNEL_A_INTERRUPT_INIT == ENABLE )
 void __vector_7 (void ) __attribute__((signal)) ;
 #endif

 #if (TIMER1_CTC_CHANNEL_B_INTERRUPT_INIT == ENABLE )
 void __vector_8 (void ) __attribute__((signal)) ;
 #endif
 
 #if (TIMER1_OVF_INTERRUPT_INIT == ENABLE )
 void __vector_9 (void) __attribute__((signal)) ;
 #endif
 
 #if (COMPARE0_MATCH_INTERRUPT == ENABLE )
 void __vector_10 (void ) __attribute__((signal)) ;
 #endif
  
 #if (TIMER0_OVERFLOW_INTERRUPT )
 void __vector_11  (void ) __attribute__((signal)) ;
 #endif
	 
	 
 #endif