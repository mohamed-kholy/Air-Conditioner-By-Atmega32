/************************************************************************************/
/* Author     : Mohamed El_KHoly                                                    */
/* Version    : V01                                                                 */
/* Date       : 02/9/2021                                            		        */
/************************************************************************************/

#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

/* ProtoType Of the Function That used in MDIO_program.c file */

void MDIO_voidSetPinDirection (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Direction ) ;

void MDIO_voidSetPortDirection (u8 copy_u8Port  , u8 copy_u8Direction ) ;

void MDIO_voidSetPinValue (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value ) ;

void MDIO_voidSetPortValue (u8 copy_u8Port , u8 copy_u8Value ) ;

u8 MDIO_voidGetPinValue (u8 copy_u8Port , u8 copy_u8Pin ); 

void MDIO_voidTogglePin (u8 copy_u8Port , u8 copy_u8Pin ) ;

/* Defintion used in the Implementaion */

#define    GPIOA     0
#define    GPIOB     1
#define    GPIOC     2
#define    GPIOD     3

#define    PIN0      0
#define    PIN1      1
#define    PIN2      2
#define    PIN3      3
#define    PIN4      4
#define    PIN5      5
#define    PIN6      6
#define    PIN7      7

/* High=1 , Low = 0  */
#define		HIGH	 1
#define		LOW  	 0
#define		OUTPUT	 1
#define		INPUT  	 0
#endif
