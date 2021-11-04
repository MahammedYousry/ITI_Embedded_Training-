#include "Lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "util/delay.h"


void CLCD_VidSendCommand(u8 Copy_u8Command){
	/*set RS as low*/

	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,Low);

	/*set RW pin as low to write*/

	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,Low);

	/*send command to data pins D0 to D7*/

	DIO_VidSetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*set Enable pin*/

	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,High);

	/*delay*/

	_delay_ms(3);

	/*CLR Enable pin*/

	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,Low);

}

void CLCD_VidSendData(u8 Copy_u8Data){
	/*set RS as high*/

	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,High);

	/*set RW pin as low to write*/

	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,Low);

	/*send data to data pins D0 to D7*/

	DIO_VidSetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*set Enable pin*/

	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,High);

	/*delay*/

	_delay_ms(3);

	/*CLR Enable pin*/

	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,Low);

}

void CLCD_VidInit(void){

	_delay_ms(40);

	/*function set*/
	CLCD_VidSendCommand(0b00111111);

	/*display on of*/
	CLCD_VidSendCommand(0b00001100);

	/*display clear*/
	CLCD_VidSendCommand(1);

}
/*Clear Display*/

void CLCD_ClearDisplay(void){
	CLCD_VidSendCommand(1);
}

/*going to any place in LCD*/

void CLCD_VidGotoXY(u8 Copy_u8XPos,u8 Copy_u8YPos){

	u8 Local_u8Address = 0;

	Local_u8Address = (Copy_u8XPos * (0x40)) + Copy_u8YPos;

	CLCD_VidSendCommand(128+Local_u8Address);

}


void CLCD_VidCreatSpecialCharacter(u8 *Copy_pu8Pattern,u8 Copy_u8MemoryLocation){

	u8 Local_u8Address = 0;

	Local_u8Address = 8 *Copy_u8MemoryLocation;

	CLCD_VidSendCommand(64 + Local_u8Address);

	for(u8 i =0 ;i < 8;i++){

		CLCD_VidSendData(Copy_pu8Pattern[i]);
	}
}
void CLCD_VidSendString(const char* Copy_pcString ) {


	for (int i = 0 ; Copy_pcString[i]!='\0' ; i++){

		CLCD_VidSendData(Copy_pcString[i]) ;
	}

}
























