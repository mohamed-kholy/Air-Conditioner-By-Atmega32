/*
 * Timer_interface.h
 *
 * Created: 4/9/2021 10:27:12 PM
 *  Author: Mohamed El-Kholy
 */ 


#ifndef _INTERFACE_H_
#define _INTERFACE_H_
	
	void MTimer_voidInit (void) ;
	s8  MTimer_s8SetTCNT(u16 copy_u16Time);
	s8  MTimer_s8CheckFlag(u8 copy_u8Flag);
	void  MTimer_voidClearFlag(void);
	void MTimer_voidSetCallBack(void (*ptrfunc)(void ));
	void MTimer_voidEnableGIE (void);
	void MTimer_voidDisableGIE (void);

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
	
#endif /* INTERFACE_H_ */