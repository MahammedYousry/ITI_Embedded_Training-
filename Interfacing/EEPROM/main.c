/*
 * main.c
 *
 *  Created on: 30Aug.,2021
 *  
 *  Author: Mohammed Yousry
 *  
 */


#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"
#include "TWI_interface.h"
#include "TWI_config.h"
#include "EEPROM_interface.h"
#include "util/delay.h"

	u8 value;
	u8 *ptr = &value;
	u8 temp[20];
	u8 name[] = "Amr Elkholy";

	u8 value2[10];
	u8 *ptr2 = value2;

void main (){


	TWI_VidInitMaster(0);


	EEPROM_VidWriteBlock(0x51 , 0x00 , name);
	_delay_ms(1);
	EEPROM_VidReadBlock(0x51 , 0x00 , value2);
	_delay_ms(1);
	EEPROM_VidWriteBlock(0x51 , 0x48 , value2);

	//EEPROM_VidDelete(0x51);








/*
	EEPROM_VidWrite(0x51 , 0x00 , 0x18);
	_delay_ms(1);
	EEPROM_VidRead(0x51 , 0x00 , &ptr);
	_delay_ms(1);
	EEPROM_VidWrite(0x51 , 0x03 , value);
	_delay_ms(1);
*/
	while(1){


	}
}











