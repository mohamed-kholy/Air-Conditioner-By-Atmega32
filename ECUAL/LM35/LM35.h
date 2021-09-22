/*
 * LM35.h
 *
 * Created: 9/17/2021 4:16:55 AM
 *  Author: Ahmed SemSem
 */ 
#include "../../MCAL/ADC/ADC_interface.h"

#ifndef LM35_H_
#define LM35_H_

void EULM35_voidInit(void);
u16 EULM35_u16LM35ReadValue(u8 copy_u8ChannelNum);

#endif /* LM35_H_ */