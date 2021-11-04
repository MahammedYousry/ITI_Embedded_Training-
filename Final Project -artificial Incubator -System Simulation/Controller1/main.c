/*
*  iti graduation project by
*  Mohammed Yousry
*  Amr Elkholy
*  Moataz Tarek
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"
#include "util/delay.h"
#define F_CPU 8000000

/*MCAL*/
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "USART_interface.h"
#include "USART_config.h"
#include "GIE_interface.h"
#include "TIMR_interface.h"


/*Prototypes*/
void UART_VidRead_ISR(void);

void Servo_angle ( f32 CPY_u8servo_angle);         	 	/*convert angle into pulse*/
u32 Servo_Time (u16 CPY_u16Time);   					/*Convert time to counts*/
void Servo_Control (void);
f32 map (f32 Cpy_InputMini , f32 Cpy_InputMax , f32 Cpy_OutMini , f32 Cpy_OutMax ,  f32 Cpy_val);


/*Global Variables*/
u8 ReceiveChar ;
u8 command;
u8 *commandPtr = &command ;
s8 MaxTemp ;
s8 MaxHumid  ;
u8 ReceiveData[10];
u8 Temp[10];

//s8 *ptrMaxTemp = &MaxTemp ;

/*Servo Variables*/
f32 count1 , count2;                            		/*For Servo_angle Function*/
f32 *ptrCount1 = &count1 ;
f32 *ptrCount2 = &count2 ;

f32 servo_angle = 45;									/* Choose Angle Servo in Degree  */
u16 servo_time = 1 ;      								/*Choose Time Servo in Seconds  */
/*
/*EEPROM Variables*//*
u8 EE_MaxTemp[10];
u8 EE_MaxHumid[10];
u8 EE_servo_angle[10];
u8 EE_servo_time[10];
*/

void main(){
	u8 temp_val[10];////
	u8 humid_val[10];////
	f32 temp_read;/////
	f32 humid_Read;
	u8 On_Off_Flag = 0 ;

	UART_VidInit();
	ADC_int();



	DIO_VidSetPinDirection(Port_A,Pin_0,input);
	DIO_VidSetPinDirection(Port_A,Pin_1,input);

	DIO_VidSetPinDirection(Port_C , Pin_4 , output);
	DIO_VidSetPinDirection(Port_C , Pin_5 , output);

	/********UART RECEIVE BY INTERRUPT**************/

	/*enable GIE */
	GIE_vidEnable();

	/*enable receive complete interrupt*/
	UART_VidRec_INT(enable);

	UART_SetCallBack(UART_VidRead_ISR , &ReceiveChar);


	/*servo*/
	DIO_VidSetPinDirection(Port_D ,Pin_5 ,output);       /*For ServoMotor*/
	DIO_VidSetPinDirection(Port_D ,Pin_6 ,output);		/*For Fan*/



	TIMR1_VidInit();
	TIMR_VidInit();
	TIMR0_SetCallBack(Servo_Control);                   /*ISR*/



	while(1){
		f32 temp_read1 = temp_read ;
		f32 humid_Read1 = humid_Read ;

		humid_Read = ADC_Read(ADC1);
		temp_read = ADC_Read(ADC0);

		_delay_ms(10);
		temp_read = (((temp_read  * 5000.0)/256.0)/10.0);
		sprintf(temp_val , "t%i\r" , (u32)temp_read );

		_delay_ms(10);
		humid_Read = ((humid_Read  - 38.0) * 0.61) ;
		sprintf(humid_val , "h%i\r" , (u32)humid_Read );

		if(temp_read != temp_read1){
			UART_VidSendString(temp_val);
			_delay_ms(100);
		}

		if(humid_Read != humid_Read1){
			UART_VidSendString(humid_val);
			_delay_ms(100);
		}

		/////////////////////////////////////////////

		if(On_Off_Flag == 1){
			DIO_VidSetPinValue(Port_D ,Pin_6 ,High);
			DIO_VidSetPinDirection(Port_D ,Pin_5 ,output);
		}
		else if(On_Off_Flag == 0){
			_delay_ms(10);
			DIO_VidSetPinValue(Port_D ,Pin_6 ,Low);
			DIO_VidSetPinDirection(Port_D ,Pin_5 ,input);
		}

		switch(command){

			/*set max temperature*/
			case('t'):{
				MaxTemp = atoi(Temp);
				_delay_ms(1);
				command = '\r' ;
			}break;

			/*set max humidity*/
			case('h'):{
				MaxHumid = atoi(Temp);
				_delay_ms(1);
				command = '\r' ;
			}break;

			/*set turning angle*/
			case('a'):{
				_delay_ms(50);
				_delay_ms(1);
				servo_angle = atoi(Temp);
				command = '\r' ;
			}break;

			/*set turning periodicity*/
			case('p'):{
				servo_time = atoi(Temp);
				_delay_ms(1);
				command = '\r' ;
			}break;

			case('f'):{
				On_Off_Flag = ! On_Off_Flag;
				command = '\r' ;
			}break;

			default:{
				DIO_VidSetPinValue(Port_C , Pin_4 , Low);
				DIO_VidSetPinValue(Port_C , Pin_5 , Low);
			}

		}
		if((MaxTemp > temp_read) && (On_Off_Flag)){
			DIO_VidSetPinValue(Port_C , Pin_4 , High);
		}

		if((MaxHumid > humid_Read) && (On_Off_Flag)){
			DIO_VidSetPinValue(Port_C , Pin_5 , High);
		}

	}
}

/***************************************************************
 ************ Functions ****************************************
 ***************************************************************/

void UART_VidRead_ISR(void){
	static u8 counter = 0 ;

		if(ReceiveChar != '\r'){
			ReceiveData[counter] = ReceiveChar ;
			counter++;
		}
		else if(ReceiveChar == '\r'){
			counter = 0 ;
			*commandPtr = ReceiveData[0] ;

			for (int i = 0 ; ReceiveData[i]!='\0' ; i++){

				Temp[i] = ReceiveData[i+1] ;
				ReceiveData[i] = 0 ;
			}
		}
}

/*************************************
 ********* Servo Functions ***********
 *************************************/

/*Convert Angle*/
void Servo_angle ( f32 CPY_u8servo_angle){

	*ptrCount1 = (90 - CPY_u8servo_angle) ;
	*ptrCount2 = (90 + CPY_u8servo_angle);

}
												/*****************************************************************/

/*Convert Time wanted to stand from (Seconds) To (Counts)*/
u32 Servo_Time (u16 CPY_u16Time){

	u32 local_Time =(CPY_u16Time * 32);

	return local_Time;
}
												/*****************************************************************/
/*ISR TO Control the Servomotor*/
void Servo_Control (void)
{
	Servo_angle ( servo_angle);
	f32 servo_pwm;
	static u8 Local_counter1 = 0 ;
	static u8 Local_counter2 = 0 ;
	Local_counter2 ++;

	/*Over flow time 20 MS For Servo Pulse*/
	TIMR_VidSetICR(20000);//>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	switch(Local_counter1){
	case 0 :
			/* Map the value to Generate needed PWM 0 degree*/
			servo_pwm = (map(0.0 , 180.0 , 1000.0 , 2000.0 , 90.0) - 0.2);//1500
			break;
	case 1 :
			/* Map the value to Generate needed PWM needed degree*/
			servo_pwm = (map(0.0 , 180.0 , 1000.0 , 2000.0 , count1) -1.0);
			break;
	case 2 :
			/* Map the value to Generate needed PWM for 0 degree*/
			servo_pwm = (map(0.0 , 180.0 , 1000.0 , 2000.0 , 90.0) - 0.2);
			break;
	case 3 :
			/* Map the value to Generate needed PWM needed degree*/
			servo_pwm = (map(0.0 , 180.0 , 1000.0 , 2000.0 , count2) -0.5);
			break;
	}


	/* Generate the pulse */
	TIMR_VidSetOCR(servo_pwm);//>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	/*every (servo_time) second will change the Angle*/
	if(Local_counter2 == Servo_Time (servo_time))
	{
		Local_counter1++ ;
		Local_counter2 = 0 ;

		if(Local_counter1 == 4)
		{
			Local_counter1 = 0 ;
		}
	 }
}

/*For Maping ServoMotor Pulse*/

f32 map (f32 Cpy_InputMini , f32 Cpy_InputMax , f32 Cpy_OutMini , f32 Cpy_OutMax ,  f32 Cpy_val)
{
	f32 local_holder = Cpy_val - Cpy_InputMax ;
	local_holder *= (Cpy_OutMini - Cpy_OutMax);
	local_holder /= (Cpy_InputMini - Cpy_InputMax);
	local_holder += Cpy_OutMax ;
	return local_holder ;
}


/*************************************
 ****** End Of Servo Functions *******
 *************************************/

































