
/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *      Author: mahamed youssry
 */
#include "lib/BIT_MATH.h"
#include "lib/STD_TYPES.h"
#include"DIO_interface.h"
#include"GIE_interface.h"
#include "TIMR_interface.h"
#include "util/delay.h"

#define Mode T0_CTC

#define T0_CTC  10
#define T0_FPMW 20
#define T0_phaseCorrectPMW 30
#define T1_FPMW  40


#if Mode == T0_CTC




u8 Arr[10] = {0b00111111,
		      0b00000110,
	      	  0b01011011,
		      0b01001111,
	          0b01100110,
		      0b01101101,
		      0b01111101,
		      0b00000111,
		      0b01111111,
		      0b01101111};


void ISR_Blink(void);

void main(){

	DIO_VidSetPortDirection(Port_D ,0xff);
	DIO_VidSetPinDirection(Port_C , pin0 , output);
	DIO_VidSetPinDirection(Port_C , pin1 , output);

	TIMR_VidInit();

	TIMR0_SetCallBack(ISR_Blink);

	GIE_VidEnable();

	while(1){

	}


}

void ISR_Blink(void){
	static u16 Loc_u16Counter1 =0 ;
	static u16 Loc_u16Counter2 =0 ;
	static u8 num =0;
	u8 index ;

	Loc_u16Counter1++;
	Loc_u16Counter2++;

	if (Loc_u16Counter1 ==1){

		DIO_VidSetPinValue(Port_C,pin0,low);
		DIO_VidSetPinValue(Port_C,pin1,high);
		index =( num % 10);
		DIO_VidSetPortValue(Port_D,Arr[index]);
	}
	else if(Loc_u16Counter1 == 2){

		Loc_u16Counter1=0;
		DIO_VidSetPinValue(Port_C,pin0,high);
		DIO_VidSetPinValue(Port_C,pin1,low);
		index =( num / 10);
		DIO_VidSetPortValue(Port_D,Arr[index]);

				}


	/*every  second will change the number*/
	if(Loc_u16Counter2 == 32){

		num++;
		Loc_u16Counter2=0;
		if(num ==100)
		{
			num=0;
		}
	 }

}

                                           /*************************************************************************/

#elif Mode == T0_FPMW

void ISR_Blink(void);


void main(){


	DIO_VidSetPinDirection(Port_B ,pin3 ,output);
	TIMR_VidInit_FastPWM();
	//TIMR_VidSetCompareMatch(250);


	while(1)
	{
		for( u8 i =0; i <=255 ;i++)
		{
			TIMR_VidSetCompareMatch(i);
			_delay_ms(100);
		}

	}


}

                                           /*************************************************************************/

#elif Mode == T0_phaseCorrectPMW


void main(){


	DIO_VidSetPinDirection(Port_B ,pin3 ,output);
	 TIMR_VidInit_PhaseCorrectPWM();

	//TIMR_VidSetCompareMatch(250);


	while(1)
	{
		for( u8 i =0; i <=255 ;i++)
		{
			TIMR_VidSetCompareMatch(i);
			_delay_ms(100);
		}

	}


}
												/*************************************************************************/

#elif Mode == T1_FPMW

void main(){


	TIMR1_VidInit();
	TIMR_VidSetICR(20000);
	while(1)
		{
			for( u16 i =1000; i <=2000 ;i++)
			{
				TIMR_VidSetOCR(i);
				_delay_ms(3);
			}

		}
}




#endif
