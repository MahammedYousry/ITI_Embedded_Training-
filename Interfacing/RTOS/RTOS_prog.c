/*
 * RTOS_prog.c
 *
 *  Created on: Sep 6, 2021
 *      Author: mahamed youssry
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TIMR_interface.h"

#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"

taskControlBlock_t TaskBlockArr[RTOS_TASK_NUM] ={{NULL}};

void RTOS_voidStart (void)
{
	//Initial Timer CTC Mode
	TIMR_VidInit();
	(void)
	//Set Call Back Algorithm
	TIMR0_SetCallBack(voidAlgrothim);

	//Enable Global interrupt
	GIE_VidEnable();

}
u8 RTOS_u8CreateTask(u8 Cpy_u8Priority ,u16 CPY_u8initialDelay, u16 Cpy_u16Perriodicity ,void(*func)(void))
{
	u8 Local_err = OK ;

	if ((Cpy_u8Priority < RTOS_TASK_NUM) && (func != NULL)){

		TaskBlockArr[Cpy_u8Priority].periodicity = Cpy_u16Perriodicity ;
		TaskBlockArr[Cpy_u8Priority].taskfunc = func ;
		TaskBlockArr[Cpy_u8Priority].RunMe = 0 ;
		TaskBlockArr[Cpy_u8Priority].taskCounter = CPY_u8initialDelay ;
	}

	else
	{
		Local_err = N_OK;
	}

	return Local_err ;
}

void RTOS_voidDispather(void)
{
	//check all the task
		for(u8 i =0 ; i <RTOS_TASK_NUM ; i++)
		{
			//check if task exist
			if(TaskBlockArr[i].taskfunc != NULL)
			{
				//check is Flag Raised
				if(TaskBlockArr[i].RunMe == 1)
				{
					//Clear flag
					TaskBlockArr[i].RunMe = 0 ;

					//Run Task
					TaskBlockArr[i].taskfunc() ;

				}

			}
		}
}
static void voidAlgrothim (void)
{
	//check all the task
	for(u8 i =0 ; i <RTOS_TASK_NUM ; i++)
	{
		//check if task exist
		if(TaskBlockArr[i].taskfunc != NULL)
		{
			//check counter if counter ==0
			if(TaskBlockArr[i].taskCounter == 0)
			{
				//set flag
				TaskBlockArr[i].RunMe = 1 ;
				//update counter = Periodicity
				TaskBlockArr[i].taskCounter =TaskBlockArr[i].periodicity;
			}
			else
			{
				//decrement the counter
				TaskBlockArr[i].taskCounter-- ;
			}
		}
	}
}


static void voidSleep(void){
	SET_BIT(MCUCR , MCUCR_SE);
	__asm__ __volatile__ ("SLEEP" ::);

}
