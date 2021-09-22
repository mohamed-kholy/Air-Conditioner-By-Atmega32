
#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"

#include "../../MCAL/DIO/MDIO_interface.h"
#include "../../MCAL/PWM/PWM_interface.h"
#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_config.h"


void EUDCMOTOR_voidDcMotorInit(void)
{
	#if (DCMOTOR_NUM == 1)
	{
		MDIO_voidSetPinDirection(DCMOTOR_PORT_MOTOR1,DCMOTOR_PIN1_WIRE1,HIGH);
		MDIO_voidSetPinDirection(DCMOTOR_PORT_MOTOR1,DCMOTOR_PIN2_WIRE1,HIGH);
	}
	#elif (DCMOTOR_NUM == 2)
	{
		MDIO_voidSetPinDirection(DCMOTOR_PORT_MOTOR1,DCMOTOR_PIN1_WIRE1,HIGH);
		MDIO_voidSetPinDirection(DCMOTOR_PORT_MOTOR1,DCMOTOR_PIN2_WIRE1,HIGH);
		MDIO_voidSetPinDirection(DCMOTOR_PORT_MOTOR2,DCMOTOR_PIN1_WIRE2,HIGH);
		MDIO_voidSetPinDirection(DCMOTOR_PORT_MOTOR2,DCMOTOR_PIN2_WIRE2,HIGH);
	}
	#endif
	

}

void EUDCMOTOR_voidSetMotorSpeed(u8 copy_u8Speed)
{
		MPWM_voidSetDutyCycle(copy_u8Speed);

}
void EUDCMOTOR_voidStartMotor(void)
{
	MPWM_voidStartPWM();
}
void EUDCMOTOR_voidStopMotor(void)
{
	MPWM_voidStopPWM();
}

