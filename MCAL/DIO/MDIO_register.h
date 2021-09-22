/************************************************************************************/
/* Author     : Mohamed El_KHoly                                                    */
/* Version    : V01                                                                 */
/* Date       : 02/9/2021                                            		        */
/************************************************************************************/

#ifndef _MDIO_REGISTER_H_
#define _MDIO_REGISTER_H_


/* 			 DIO Registers		    	 */

/*					A					*/
#define 	PORTA_REGISTER			(*(volatile u8*)(0x3B))
#define 	DDRA_REGISTER			(*(volatile u8*)(0x3A))
#define 	PINA_REGISTER			(*(volatile u8*)(0x39))
/*					B					*/
#define 	PORTB_REGISTER			(*(volatile u8*)(0x38))
#define 	DDRB_REGISTER			(*(volatile u8*)(0x37))
#define 	PINB_REGISTER			(*(volatile u8*)(0x36))
/*					C					*/
#define 	PORTC_REGISTER			(*(volatile u8*)(0x35))
#define 	DDRC_REGISTER			(*(volatile u8*)(0x34))
#define 	PINC_REGISTER			(*(volatile u8*)(0x33))
/*					D					*/
#define 	PORTD_REGISTER			(*(volatile u8*)(0x32))
#define 	DDRD_REGISTER			(*(volatile u8*)(0x31))
#define 	PIND_REGISTER			(*(volatile u8*)(0x30))

#endif
