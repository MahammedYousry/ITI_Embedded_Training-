#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_private.h"
#include "GIE_interface.h"

/*GIE Enable*/

void GIE_VidEnable (void){

	SET_BIT(SREG,SREG_I_BIT);




}

/*GIE DisEnable*/

void GIE_VidDisEnable (void){



	CLR_BIT(SREG,SREG_I_BIT);



}
