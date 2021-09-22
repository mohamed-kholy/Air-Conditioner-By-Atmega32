/************************************************************************************/
/* Author     : Mohamed El_Kholy                                                    */
/* Version    : V01                                                                 */
/* Date       : 28 JAN 2021		                                                    */
/************************************************************************************/

#ifndef  ADC_PRIVATE_H
#define  ADC_PRIVATE_H


#define   	ADCMUX				*((volatile u8*)		0x27)
#define   	ADCSRA				*((volatile u8*)		0x26)
#define   	ADCH				*((volatile u8*)		0x25)
#define   	ADCL				*((volatile u8*)		0x24)
								   
#define   	ADC 				*((volatile u16*)		0x24)


#define 		REFS1			7
#define 		REFS0			6
#define 		ADLAR			5

#define 		ADIE			3
#define 		ADIF			4
#define 		ADATE			5
#define 		ADSC			6
#define 		ADEN			7


#define 		AREF					00
#define 		AVCC					01	
#define 		INTERNAL_2_HALF_VOLT		11

#define 		RIGHT_ADJUST			0
#define 		LEFT_ADJUST				1



#define			ENABLE					1
#define			DISABLE					0


#define 		DIV_BY_2				0b000
#define			DIV_BY_4				0b010
#define			DIV_BY_8				0b011
#define			DIV_BY_16				0b100
#define			DIV_BY_32				0b101
#define			DIV_BY_64				0b110
#define			DIV_BY_128				0b111

 void __vector_17 (void ) __attribute__((signal)) ;

#endif 
