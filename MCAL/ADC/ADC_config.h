/************************************************************************************/
/* Author     : Mohamed El_Kholy                                                    */
/* Version    : V01                                                                 */
/* Date       : 28 JAN 2021		                                                    */
/************************************************************************************/
#ifndef ADC_CONFIG_H
#define  ADC_CONFIG_H

/*	Options
	AREF				//AREF, Internal Vref turned off
	AVCC				//AVCC with external capacitor at AREF pin
	INTERNAL_2_HALF_VOLT	//Internal 2.56V Voltage Reference with external capacitor at AREF pin
*/
#define 		VOLTAGE_REF				AVCC

/* Options

	RIGHT_ADJUST
	LEFT_ADJUST	
	
	*/
	
#define 		ADC_ADJUST				RIGHT_ADJUST
/* Options 
	ADC0
	ADC1
	ADC2
	ADC3
	ADC4
	ADC5
	ADC6
	ADC7
	*/

#define 		ANALOG_CHANNEL			ADC0

/* Options
	ENABLE
	DISABLE
*/
#define 		ADC_ENABLE				ENABLE

#define 		ADC_INTERRUPT			DISABLE
/*When this bit is written to one, Auto Triggering of the ADC is enabled. The ADC will start
a conversion on a positive edge of the selected trigger signal. The trigger source is
selected by setting the ADC Trigger Select bits, ADTS in SFIOR. */
#define 		AUTO_TRIGGER			DISABLE

/*	Options

	DIV_BY_2
	DIV_BY_4
	DIV_BY_8
	DIV_BY_16
	DIV_BY_32
	DIV_BY_64
	DIV_BY_128
	
	*/
	
#define 		ADC_PRE_SCALER			DIV_BY_2	




#endif 
