/*
 * RTOS_interface.h
 *
 *  Created on: Sep 6, 2021
 *      Author: mahamed youssry
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void RTOS_voidStart (void);
u8 RTOS_u8CreateTask(u8 Cpy_u8Priority ,u16 CPY_u8initialDelay, u16 Cpy_u16Perriodicity ,void(*func)(void));
void RTOS_voidDispather(void);

#endif /* RTOS_INTERFACE_H_ */
