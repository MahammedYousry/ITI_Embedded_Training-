#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"
#include "TWI_private.h"
#include "TWI_interface.h"
#include "TWI_config.h"
#include "util/delay.h"


/*write*/
void EEPROM_VidWrite(u8 cpy_u8EepromAddress , u8 cpy_u8ByteAddress , u8 cpy_u8Data){

	TWI_SendStartCondition();

	TWI_MasterSendAddress(cpy_u8EepromAddress , TWI_WRITE);

	TWI_MasterSendData(cpy_u8ByteAddress);

	TWI_MasterSendData(cpy_u8Data);

	TWI_SendStopCondition();

}


/*read*/
u8 EEPROM_VidRead(u8 cpy_u8EepromAddress , u8 cpy_u8ByteAddress){

	TWI_SendStartCondition();

	TWI_MasterSendAddress(cpy_u8EepromAddress , TWI_WRITE);

	TWI_MasterSendData(cpy_u8ByteAddress);

	TWI_SendStartCondition();

	TWI_MasterSendAddress(cpy_u8EepromAddress , TWI_Read);

	u8 read = TWI_MasterReadData();

	TWI_SendStopCondition();

	return read;

}

/*write block of data*/
void EEPROM_VidWriteBlock(u8 cpy_u8EepromAddress , u8 cpy_u8StartAddress , u8 *cpy_u8Data){
	for(u16 i = 0 ; cpy_u8Data[i] != '\0' ; i++){
		EEPROM_VidWrite( cpy_u8EepromAddress , cpy_u8StartAddress + i , cpy_u8Data[i]);

		_delay_ms(1);
	}
}




/*read block of data*/
void EEPROM_VidReadBlock(u8 cpy_u8EepromAddress , u8 cpy_u8ByteAddress , u8 *GlobCpy_u8ReadData){
	u8 x ;

	for (int i = 0 ; GlobCpy_u8ReadData[i]!='\0' ; i++){
		GlobCpy_u8ReadData[i] = 0 ;
	}

	for(u16 i = cpy_u8ByteAddress ; x != 0xff ; i++){
		_delay_ms(1);

		GlobCpy_u8ReadData[i] = EEPROM_VidRead(cpy_u8EepromAddress , i);
		x = GlobCpy_u8ReadData[i];
	}
}

/*delete memory*/
void EEPROM_VidDelete(u8 cpy_u8EepromAddress ){

	for(u16 i = 0 ; i <255 ; i++){
		EEPROM_VidWrite( cpy_u8EepromAddress , 0x00 + i , 0xff);

		_delay_ms(1);
	}
}




