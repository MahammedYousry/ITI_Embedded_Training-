
/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *      Author: mahamed youssry
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#define F_CPU 8000000
#include "util/delay.h"

#include"DIO_interface.h"
#include"GIE_interface.h"
#include "TIMR_interface.h"
#include "ADC_interface.h"


void Servo_Control (void);


void main(){


	DIO_VidSetPinDirection(Port_A ,pin0 ,input);
	DIO_VidSetPinDirection(Port_D ,pin5 ,output);

	ADC_VoidIntit();
	TIMR1_VidInit();
	GIE_VidDisEnable();

	/*Over flow time 20 MS*/
	TIMR_VidSetICR(20000);

	while(1)
		{

			Servo_Control();
			_delay_us(3000);
		}
}

void Servo_Control (void)
{
	/* Read potentiometer  */
	s32 adc_read = ADC_u8ReadChannel(ADC_0);

	/* Map the value to Generate needed PWM*/
	s32 servo_pwm = map(0 , 255 , 1000 , 2000 , adc_read);

	/* Generate the pulse */
	TIMR_VidSetOCR(servo_pwm);
}








