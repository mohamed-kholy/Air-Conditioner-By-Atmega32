/************************************************************************************/
/* Author     : Mohamed El_Kholy                                                    */
/* Version    : V01                                                                 */
/* Date       : 28 JAN 2021		                                                    */
/************************************************************************************/
#include 	"../../LIB/BIT_MATH/BIT_MATH.h"
#include 	"../../LIB/STD_TYPES/STD_TYPES.h"
#include 	"ADC_private.h"
#include 	"ADC_config.h"

#ifndef ADC_INTERFACE_H
#define  ADC_INTERFACE_H

void MADC_voidInit 		(void);
u16  MADC_u16Read		(u8 copy_u8Channel);
void MADC_voidSetCallBack(void (*ptrfunc)(void ));

#define 		ADC0					0b00000
#define 		ADC1					0b00001
#define 		ADC2					0b00010
#define 		ADC3					0b00011
#define 		ADC4					0b00100
#define 		ADC5					0b00101
#define 		ADC6					0b00110
#define 		ADC7					0b00111

#endif 
