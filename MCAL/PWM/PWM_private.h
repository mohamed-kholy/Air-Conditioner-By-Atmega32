
#ifndef PWM_PRIVATE_H_
#define PWM_PRIVATE_H_

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
#define 			OCR1A		(*(volatile u16*) (0X4A))
#define 			OCR1BH		(*(volatile u8*) (0X49))
#define 			OCR1BL		(*(volatile u8*) (0X48))
#define 			OCR1B		(*(volatile u16*) (0X48))
#define 			ICR1H		(*(volatile u8*) (0X47))
#define 			ICR1L		(*(volatile u8*) (0X46))
#define 			ICR1		(*(volatile u16*) (0X46))
/* 			Timer 2 Registers			*/
#define 			TCCR2		(*(volatile u8*) (0X45))
#define 			TCNT2		(*(volatile u8*) (0X44))
#define 			OCR2		(*(volatile u8*) (0X43))
/*				Timer Interrupt Register 	*/
#define 			TIMSK		(*(volatile u8*) (0X59))
#define 			TIFR		(*(volatile u8*) (0X58))


/*  	Definitions makes the code more Readable	 */
#define 		NO_CLK						0b000
#define 		NO_PRESCALING				0b001
#define 		CLK_DIV_BY_8				0b010
#define 		CLK_DIV_BY_64				0b011
#define 		CLK_DIV_BY_256				0b100
#define 		CLK_DIV_BY_1024				0b101
#define 		EX_CLK_FALLING				0b110
#define 		EX_CLK_RISING				0b111

#define			OVERFLOW					0
#define			OUTPUT_COMPARE_0			1
#define			OUTPUT_COMPARE_A			2
#define			OUTPUT_COMPARE_B			3

#define			PWM0_MAX_VALUE				255
#define			PWM1_MAX_VALUE				65535


#endif /* PWM_PRIVATE_H_ */