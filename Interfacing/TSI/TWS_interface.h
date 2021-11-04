/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */

#ifndef TWS_INTERFACE_H_
#define TWS_INTERFACE_H_

#define  TWI_Write   0
#define  TWI_Read    1

void TWI_VoidInitMaster(u8 CPY_u8Address);
void TWI_VoidInitSlave(u8 CPY_u8Address);

void TWI_SendStartCondition(void);
void TWI_MasterSendAddress(u8 CPY_u8Address ,u8 CPY_u8Operation);
void TWI_MasterSendData(u8 CPY_u8Data);
void TWI_MasterReadData(u8 *CPY_u8Data);
void TWI_SendStopCondition(void);



#endif
