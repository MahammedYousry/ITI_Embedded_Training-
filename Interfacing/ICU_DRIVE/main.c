
/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *      Author: mahamed youssry
 */
#include "lib/BIT_MATH.h"
#include "lib/STD_TYPES.h"
#define F_CPU 8000000
#include"DIO_interface.h"
#include"GIE_interface.h"
#include "TIMR_interface.h"

#include "TIMR_private.h"
#include "util/delay.h"


#define Mode T1_ICU

#define T0_CTC  10
#define T0_FPMW 20
#define T0_phaseCorrectPMW 30
#define T1_FPMW  40
#define T1_ICU   50

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


	DIO_VidSetPinDirection(Port_A ,pin0 ,input);


	ADC_VoidIntit();
	TIMR_VidInit_FastPWM();

	u8 read;



	while(1)
	{
		read =ADC_u8ReadChannel(ADC_0);			/*Convert analog to digtal*/
		read=(read *5)/256;						/*Convert digital to analog*/


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


	DIO_VidSetPinDirection(Port_A ,pin0 ,input);
	DIO_VidSetPinDirection(Port_D ,pin5 ,output);

	ADC_VoidIntit();
	TIMR1_VidInit();
	GIE_VidEnable();

	u16 read;

	/*Over flow time 20 ms*/
	TIMR_VidSetICR(20000);





	while(1)
		{
			read =ADC_u8ReadChannel(ADC_0);			/*Convert analog to digtal*/
			//read=(read *5)/256;						/*Convert digital to analog*/
			//read =(read*1000)+1000;
			 maping( 0 ,255 ,1000 ,2000 ,read);

			TIMR_VidSetOCR(read);
		}
}


#elif Mode == T1_ICU

void ISR_Blink(void);

u16 period ,on_time;
u16 period_arr[20];
u16 on_time_arr[20];
u16 state ;

void main(){

	DIO_VidSetPinDirection(Port_A ,pin0,output);
	DIO_VidSetPinDirection(Port_A ,pin1,output);
	DIO_VidSetPinDirection(Port_A ,pin2,output);
	DIO_VidSetPortDirection(Port_C,0xff);

	ICU_INIT();
	TIMR1_SetCallBack(ISR_Blink);
	GIE_VidEnable();
	CLCD_VidInit();

	while(1){

		if (state =1)
		{
			CLCD_VidGotoXY(1,1);
			sprintf(period_arr,"period =%i ",period);
			CLCD_String2(period_arr);

			CLCD_VidGotoXY(2,1);
			sprintf(on_time_arr,"on_time =%i ",on_time);
			CLCD_String2(on_time_arr);

			state =0;

		}
	}


}

void ISR_Blink(void){
	static u8 counter =1;
	static u16 snip1, snip2 ,snip3;

	if(counter == 1){

		snip1 = ICR1L;

		counter=2;
	}

	else if(counter == 2){
		snip2 =ICR1L;
		period = snip2 -snip1 ;

		CLEAR_BIT(TCCR1B ,TCCR0_ICES1_PIN);   //Falling edge

		counter = 3;
	}
	else if(counter == 3)
	{
		snip3 =ICR1L;
		on_time=snip3-snip2;

		GIE_VidDisEnable()	;
		SET_BIT(TCCR1B ,TCCR0_ICES1_PIN); 		//raising edge

		state =1;
	}


}
#endif
