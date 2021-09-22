#ifndef _BUTTON_INTERFACE_H_
#define _BUTTON_INTERFACE_H_

	/* Prototype of the Functions that used in .c file */
	s8 EUButton_init(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8ConnectionType ) ;
	s8	EUButtonPressed(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8ConnectionType );
	/* Macros Makes the Function more Readable */
	#define		 PULL_UP			0
	#define		 PULL_DOWN			1


#endif
