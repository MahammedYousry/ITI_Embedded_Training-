#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"

/* Driver includes */
#include "GIE_Interface.h"
#include "GIE_Private.h"
#include "GIE_config.h"

void GIE_vidEnable(void)
{
	SET_BIT(SREG , SREG_I);
}

void GIE_vidDisable(void)
{
	CLR_BIT(SREG , SREG_I);
}
