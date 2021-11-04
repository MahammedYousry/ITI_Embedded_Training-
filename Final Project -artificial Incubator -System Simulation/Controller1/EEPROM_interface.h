#ifndef      EEPROM_INTERFACE_H_
#define      EEPROM_INTERFACE_H_



void EEPROM_VidWrite(u8 cpy_u8EepromAddress , u8 cpy_u8ByteAddress , u8 cpy_u8Data);

void EEPROM_VidRead(u8 cpy_u8EepromAddress , u8 cpy_u8ByteAddress , u8 *cpy_u8ReadData);












#endif
