/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */

#include"lib/STD_TYPES.h"
#include"lib/BIT_MATH.h"
#include"TWS_private.h"
#include "TWS_interface.h"

void TWI_VoidInitMaster(u8 CPY_u8Address){

	/*Freq = 400 Kbps*/
	TWBR = 2 ;
	CLEAR_BIT(TWSR , TWSR_TWPS0 );
	CLEAR_BIT(TWSR , TWSR_TWPS1 );

	/*assign address*/
	if(CPY_u8Address != 0){

		TWAR = (CPY_u8Address << 1) ;
	}

	/*Enable TWI*/
	SET_BIT(TWCR , TWCR_TWEN);

}

void TWI_VoidInitSlave(u8 CPY_u8Address){

	/*assign address*/
	if(CPY_u8Address != 0)
	{
		TWAR = (CPY_u8Address << 1) ;
	}

	/*Enable TWI*/
	SET_BIT(TWCR , TWCR_TWEN);

}

void TWI_SendStartCondition(void){

	/*Set Start Condition*/
	SET_BIT(TWCR , TWCR_TWSTA);

	/*Start Job by CLEAR flag*/
	SET_BIT(TWCR , TWCR_TWINT);

	/*Wait Till Job Is Complete*/
	while (GET_BIT(TWCR , TWCR_TWINT) == 0);

	/*check if Correct*/
	//

	/*Clear to start condition*/



}




void TWI_MasterSendAddress(u8 CPY_u8Address ,u8 CPY_u8Operation){

	//u8 Local_u8Address =CPY_u8Address;

	TWDR = (CPY_u8Address <<1) | CPY_u8Operation ;
	//TWDR = Local_u8Address;


	CLEAR_BIT(TWCR ,TWCR_TWSTA);

	/*Start Job by CLEAR flag*/
	SET_BIT(TWCR , TWCR_TWINT);

	/*Wait Till Job Is Complete*/
	while (GET_BIT(TWCR , TWCR_TWINT) == 0);

	/*check if Correct*/


}





void TWI_MasterSendData(u8 CPY_u8Data){

	/*Write Data*/

	TWDR = CPY_u8Data ;

	/*Start Job by CLEAR flag*/
	SET_BIT(TWCR , TWCR_TWINT);

	/*Wait Till Job Is Complete*/
	while (GET_BIT(TWCR , TWCR_TWINT) == 0);

	/*check if Correct*/
}

void TWI_MasterReadData(u8 *CPY_u8Data){

	/*Start Job by CLEAR flag*/
	SET_BIT(TWCR , TWCR_TWINT);

	/*Wait Till Job Is Complete*/
	while (GET_BIT(TWCR , TWCR_TWINT) == 0);

	/*read data*/
	TWDR = *CPY_u8Data ;

	/*check if Correct*/

}

void TWI_SendStopCondition(void){

	/*Stop indicate*/
	SET_BIT(TWCR ,TWCR_TWSTO);

	/*Start Job by CLEAR flag*/
	SET_BIT(TWCR , TWCR_TWINT);
}

