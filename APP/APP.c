/*
 * APP.c
 *
 * Created: 9/17/2021 4:16:44 AM
 *  Author: Ahmed SemSem
 */ 
#include "APP.h"
/*- GLOBAL EXTERN VARIABLES TO STORE THE DATA FROM USER AND SENSOR
-------------------------------*/
u16 global_u16CurrentTemp = 0;
u8 global_u8ArrayOfKeys [3] ;
u8 global_u8ValidateState = 0 ;
u8 global_u8IntegerKey  ;

/********************************************************************************************************************************
* Parameters:(in) : none
* Parameters:(out): Initialize the LCD, PWM, Motor and KEYPAD
* Return value	  : none
* Description	  : initialize the Air Conditioner to work by initializing the modules used in it
**********************************************************************************************************************************/
void APP_Init(void)
{
	
	EULLCD_voidLCDInit();
	EUKeypad_voidKeypadInit();
	MPWM_voidPwmInit();
	EUDCMOTOR_voidDcMotorInit();
	EULM35_voidInit();
	APP_UpdateScreen();
	
}
/************************************************************************************
* Parameters (in): None
* Parameters (out): none
* Return value: none
* Description: main task of the control system, handles all application cases
************************************************************************************/
void APP_update(void)
{
	/* local Variable holds the value return from Keypad */
	u8 local_u8ReturnKeypadValue ;
	/* local variable used in the iteration */
	u8 local_u8Iterator = 0;
	/* loop  */
	while (local_u8Iterator < 3)
	{
		/* Get The Input From the Keypad */
		local_u8ReturnKeypadValue = EUKeypad_voidKeyPressed() ;
		/* if the Keypad Pressed */
		if (local_u8ReturnKeypadValue != 0xFF)
		{
			/* if the User entered '=' break the while loop*/
			if (local_u8ReturnKeypadValue == '=')
			break ;
			/* Store The Input in the Array */
			global_u8ArrayOfKeys[local_u8Iterator]= local_u8ReturnKeypadValue ;
			/* Write the Input To The LCD */
			EULCD_voidLCDWriteChar(local_u8ReturnKeypadValue);
			/* increment the iterator */
			local_u8Iterator ++ ;
		}
	}
	
	/* When User Enter "=" Call Validate Function */
	if (local_u8ReturnKeypadValue == '=')
	{
			APP_validate();
	}

}
/************************************************************************************
* Parameters (in): None
* Parameters (out): turn on or off the fan.
* Return value: none
* Description: function used to turn on or off the fan according to the wanted temperature and the current temperature.
************************************************************************************/
void APP_validate(void)
{

	global_u8IntegerKey = atoi(global_u8ArrayOfKeys);	
	global_u16CurrentTemp = EULM35_u16LM35ReadValue(ADC0);
	if (global_u16CurrentTemp > global_u8IntegerKey )
	{
		App_Fan_ON();
	}
	else
	{
		App_Fan_OFF();
	}
		 		
		
}
/************************************************************************************
* Parameters (in): None
* Parameters (out): None
* Return value: none
* Description: function used to update the screen after any user input.
************************************************************************************/
void APP_UpdateScreen(void)
{		
	EULCD_voidLCDWriteCommand(CLEAR_SCREEN);
	EULCD_voidLCDWriteString ("PLease Set The");
	EULCD_voidLCDGoto (1 ,1);
	EULCD_voidLCDWriteString ("Temperature:");						
	
	
}
/************************************************************************************
* Parameters (in): None
* Parameters (out): turn on the fan.
* Return value: none
* Description: function used to turn on the fan with speed 90%.
************************************************************************************/
void App_Fan_ON(void)
{
	 EULCD_voidLCDWriteCommand(CLEAR_SCREEN);
	 EULCD_voidLCDGoto (0,1);
	 EULCD_voidLCDWriteString ("Current temp:");
	 EULCD_voidLCDGoto (0 ,14);
	 EULCD_voidLCDDisplayInteger(global_u16CurrentTemp);
	 EULCD_voidLCDGoto (1,1);
	 EULCD_voidLCDWriteString ("Fan turned on");
	 EUDCMOTOR_voidStartMotor();
	 EUDCMOTOR_voidSetMotorSpeed(90);
	 MDIO_voidSetPinValue(DCMOTOR_PORT_MOTOR1,DCMOTOR_PIN1_WIRE1,HIGH);
	 MDIO_voidSetPinValue(DCMOTOR_PORT_MOTOR1,DCMOTOR_PIN2_WIRE1,LOW);
	 _delay_ms(1000);
	 APP_UpdateScreen();
	
}
/************************************************************************************
* Parameters (in): None
* Parameters (out): turn off the fan.
* Return value: none
* Description: function used to turn off the fan.
************************************************************************************/
void App_Fan_OFF(void)
{
	EULCD_voidLCDWriteCommand(CLEAR_SCREEN);
	EULCD_voidLCDGoto (0,1);
	EULCD_voidLCDWriteString ("Current temp:");
	EULCD_voidLCDGoto (0 ,14);
	EULCD_voidLCDDisplayInteger(global_u16CurrentTemp);
	EULCD_voidLCDGoto (1 ,1);
	EULCD_voidLCDWriteString ("Fan turned off");
	EUDCMOTOR_voidStopMotor();
	 MDIO_voidSetPinValue(DCMOTOR_PORT_MOTOR1,DCMOTOR_PIN1_WIRE1,LOW);
	 MDIO_voidSetPinValue(DCMOTOR_PORT_MOTOR1,DCMOTOR_PIN2_WIRE1,LOW);
	_delay_ms(1000);
	APP_UpdateScreen();
	
}
