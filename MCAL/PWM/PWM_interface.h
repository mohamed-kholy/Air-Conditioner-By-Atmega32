
#ifndef _PWM_INTERFACE_H_
#define _PWM_INTERFACE_H_

void MPWM_voidPwmInit(void) ;
void MPWM_voidSetDutyCycle (float copy_u8DutyPercentage );
void MPWM_voidStopPWM(void) ;
void MPWM_voidStartPWM(void); 
#endif