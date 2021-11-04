/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */
//file Guard

#ifndef   WD_PRIVATE_H_
#define  WD_PRIVATE_H_

          /*define watch dog timer register*/

#define WDTCR  *((volatile u8 *)0x41)
           
		   /*define watch dog timer Pins*/
		
#define WDTCR_WDTOE   4
#define WDTCR_WDE     3
#define WDTCR_WDP2    2
#define WDTCR_WDP1    1
#define WDTCR_WDP0	  0

#endif
