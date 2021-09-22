/*
 * APP.h
 *
 * Created: 9/17/2021 4:16:55 AM
 *  Author: Ahmed SemSem
 */ 
#include "../LIB/STD_TYPES/STD_TYPES.h"
#include "../MCAL/DIO/MDIO_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../ECUAL/LCD/lcd.h"
#include "../ECUAL/KEYPAD/Keybad_interface.h"
#include "../ECUAL/LM35/LM35.h"
#include "../ECUAL/DC Motor/DC_MOTOR_interface.h"
#include "../ECUAL/DC Motor/DC_MOTOR_config.h"
#include <util/delay.h>
#ifndef APP_H_
#define APP_H_

void APP_Init (void);void APP_update(void);
void APP_validate(void);
void APP_UpdateScreen(void);
void App_Fan_ON(void);
void App_Fan_OFF(void);


#endif /* APP_H_ */