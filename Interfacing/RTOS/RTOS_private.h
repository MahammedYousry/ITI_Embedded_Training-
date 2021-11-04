/*
 * RTOS_private.h
 *
 *  Created on: Sep 6, 2021
 *      Author: mahamed youssry
 */

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

#define MCUCR (*((volatile u8 *)0x55))
#define MCUCR_SE   7



typedef struct {
	u16 periodicity ; //excuted every 200 MS
	u16 taskCounter;	//Counts to calculate every 200 MS
	void (*taskfunc)(void); //task CallBack
	u8 RunMe; //Flag
}taskControlBlock_t;

static void voidAlgrothim (void);
static void voidSleep (void);


#endif /* RTOS_PRIVATE_H_ */
