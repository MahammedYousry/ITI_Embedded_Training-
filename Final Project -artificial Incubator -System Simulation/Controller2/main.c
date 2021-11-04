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
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "KPD_interface.h"
#include "KPD_config.h"
#include "USART_config.h"
#include "USART_interface.h"
#include "GIE_interface.h"
#include "util/delay.h"

/*Prototypes*/
void clearArr(u8 *arr);
void UART_VidRead_ISR(void);


/*global variables*/
char result[70]="";
char math_opration;
u8 lastFlag=1;
u8 addressFlag=0;
u8 ReceiveChar ;
u8 ReceiveData[10];
u8 ReceiveTemp[10];
u8 ReceiveHumid[10];


void main(){

	DIO_vidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,output);
	DIO_vidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,output);
	DIO_vidSetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN ,output);

	DIO_vidSetPortDirection(CLCD_DATA_PORT,High_Port);

	DIO_vidSetPinDirection(KPD_u8PORT,KPD_u8COLUMN0_PIN ,output);
	DIO_vidSetPinDirection(KPD_u8PORT,KPD_u8COLUMN1_PIN ,output);
	DIO_vidSetPinDirection(KPD_u8PORT,KPD_u8COLUMN2_PIN ,output);
	DIO_vidSetPinDirection(KPD_u8PORT,KPD_u8COLUMN3_PIN ,output);

	DIO_vidSetPinDirection(KPD_u8PORT,KPD_u8ROW0_PIN ,input);
	DIO_vidSetPinDirection(KPD_u8PORT,KPD_u8ROW1_PIN ,input);
	DIO_vidSetPinDirection(KPD_u8PORT,KPD_u8ROW2_PIN ,input);
	DIO_vidSetPinDirection(KPD_u8PORT,KPD_u8ROW3_PIN ,input);

	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW0_PIN ,High);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW1_PIN ,High);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW2_PIN ,High);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW3_PIN ,High);

	CLCD_VidInit();
	UART_VidInit();


	u8 Temp_Array[10];
    u8 counter=1;
    u8 setFlag = 0;
    u8 On_Off_Flag = 0 ;
    u8 num_valueFlag = 0 ;
    u8 max_value;
    u8 error[50];
    u8 receivedT1 , receivedT2;
    u8 receivedH1 , receivedH2;

    /********UART RECEIVE BY INTERRUPT**************/

	/*enable GIE */
	GIE_vidEnable();

	/*enable receive complete interrupt*/
	UART_VidRec_INT(enable);

    UART_SetCallBack(UART_VidRead_ISR , &ReceiveChar);

	while(1){

		u8 Local_u8KPDInput = KPD_u8GetPressedKey();

		receivedT1 = atoi(ReceiveTemp);
		if((On_Off_Flag) && (!setFlag) && (receivedT1 != receivedT2)){
			CLCD_VidGotoXY(0 , 10);
			CLCD_VidSendString("          ");
			CLCD_VidGotoXY(0 , 10);
			CLCD_VidSendString(ReceiveTemp);
			CLCD_VidGotoXY(0 , 13);
			CLCD_VidSendString("C");
			//clearArr(ReceiveTemp);
		}
		receivedT2 = atoi(ReceiveTemp);

		receivedH1 = atoi(ReceiveHumid);
		if((On_Off_Flag) && (!setFlag) && (receivedH1 != receivedH2)){
			CLCD_VidGotoXY(1 , 10);
			CLCD_VidSendString("          ");
			CLCD_VidGotoXY(1 , 10);
			CLCD_VidSendString(ReceiveHumid);
			CLCD_VidGotoXY(1 , 13);
			CLCD_VidSendString("%");
			//clearArr(ReceiveHumid);
		}
		receivedH2 = atoi(ReceiveHumid);


		if(Local_u8KPDInput == 'f'){
			On_Off_Flag = ! On_Off_Flag ;
			_delay_ms(30);
			UART_VidSendString("f\r");
			num_valueFlag = 0 ;
			setFlag = 0;
			if(On_Off_Flag == 1){
				CLCD_ClearDisplay();

				CLCD_VidGotoXY(0 , 0);
				CLCD_VidSendString("Temperat: ");
				CLCD_VidSendString(ReceiveTemp);
				CLCD_VidGotoXY(0 , 13);
				CLCD_VidSendString("C");

				CLCD_VidGotoXY(1 , 0);
				CLCD_VidSendString("Humidity: ");
				CLCD_VidSendString(ReceiveHumid);
				CLCD_VidGotoXY(1 , 13);
				CLCD_VidSendString("%");
			}
			else{
				CLCD_ClearDisplay();
			}
		}


		if ((Local_u8KPDInput != NOT_PRESSED)){

			if(On_Off_Flag == 1){

				switch(Local_u8KPDInput){
					case('t'):{
						setFlag = 1 ;
						num_valueFlag = 0 ;
						CLCD_ClearDisplay();
						CLCD_VidSendString("Set Temp:");
						clearArr(Temp_Array);
						Temp_Array[0] = Local_u8KPDInput;
						counter = 1 ;
						max_value = 50 ;
						strcpy(error , "max value : 50");
					}break ;

					case('h'):{
						setFlag = 1 ;
						num_valueFlag = 0 ;
						CLCD_ClearDisplay();
						CLCD_VidSendString("Set humidity:");
						clearArr(Temp_Array);
						Temp_Array[0] = Local_u8KPDInput;
						counter = 1 ;
						max_value = 100 ;
						strcpy(error , "max value : 100");
					}break ;

					case('a'):{
						setFlag = 1 ;
						num_valueFlag = 0 ;
						CLCD_ClearDisplay();
						CLCD_VidSendString("Set Angle:");
						clearArr(Temp_Array);
						Temp_Array[0] = Local_u8KPDInput;
						counter = 1 ;
						max_value = 60 ;
						strcpy(error , "max value : 60");
					}break ;

					case('p'):{
						setFlag = 1 ;
						num_valueFlag = 0 ;
						CLCD_ClearDisplay();
						CLCD_VidSendString("Set Perio:");
						clearArr(Temp_Array);
						Temp_Array[0] = Local_u8KPDInput;
						counter = 1 ;
						max_value = 24 ;
						strcpy(error , "max value : 24");
					}break ;

					default:{
						num_valueFlag = 1 ;
					}
				}
			}


			if((setFlag == 1) && (On_Off_Flag == 1) && (num_valueFlag == 1)){

				if(counter != 0){
					CLCD_VidSendData(Local_u8KPDInput);
				}
				Temp_Array[counter] = Local_u8KPDInput;
				counter++ ;

				if(Local_u8KPDInput == '\r'){

					u8 *ptr = &Temp_Array[1] ;
					u8 temp_X[10] ;
					strcpy(temp_X , ptr);
					u8 int_temp_X = atoi(temp_X);

					if(int_temp_X <= max_value ){
						if(counter > 2){
							UART_VidSendString(Temp_Array);
						}

						CLCD_ClearDisplay();

						CLCD_VidGotoXY(0 , 0);
						CLCD_VidSendString("Temperat: ");
						CLCD_VidSendString(ReceiveTemp);
						CLCD_VidGotoXY(0 , 13);
						CLCD_VidSendString("C");

						CLCD_VidGotoXY(1 , 0);
						CLCD_VidSendString("Humidity: ");
						CLCD_VidSendString(ReceiveHumid);
						CLCD_VidGotoXY(1 , 13);
						CLCD_VidSendString("%");
					}
					else{
						CLCD_ClearDisplay();
						CLCD_VidSendString(error);
					}
					setFlag = 0 ;
					counter = 1 ;
					clearArr(Temp_Array);
				}
			}

			else if((Local_u8KPDInput == '\r') && (On_Off_Flag == 1)){
				CLCD_ClearDisplay();
				CLCD_VidGotoXY(0 , 0);
				CLCD_VidSendString("Temperat: ");
				CLCD_VidSendString(ReceiveTemp);
				CLCD_VidGotoXY(0 , 13);
				CLCD_VidSendString("C");

				CLCD_VidGotoXY(1 , 0);
				CLCD_VidSendString("Humidity: ");
				CLCD_VidSendString(ReceiveHumid);
				CLCD_VidGotoXY(1 , 13);
				CLCD_VidSendString("%");
			}
		}
	}
}

/**********************************
 ********functions*****************
 **********************************/

void clearArr(u8 *arr){
	for (int i = 0 ; arr[i] != '\0' ; i++){
		arr[i] = 0 ;
	}
}



void UART_VidRead_ISR(void){
	static u8 counter = 0 ;

		if(ReceiveChar != '\r'){
			ReceiveData[counter] = ReceiveChar ;
			counter++;
		}
		else if(ReceiveChar == '\r'){
			counter = 0 ;

			if(ReceiveData[0] == 'h'){
				clearArr(ReceiveHumid);
				for (int i = 0 ; ReceiveData[i+1] !='\0' ; i++){
					ReceiveHumid[i] = ReceiveData[i+1] ;
				}
			}

			else if(ReceiveData[0] == 't'){
				clearArr(ReceiveTemp);
				for (int i = 0 ; ReceiveData[i+1] !='\0' ; i++){
					ReceiveTemp[i] = ReceiveData[i+1] ;
				}
			}

			clearArr(ReceiveData);
		}
}
