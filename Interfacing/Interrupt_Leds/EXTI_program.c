#include"lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"





//EXIT ENABLE
void EXTI0_VidInti0()
{

//sense control
	#if EXIT_SENSE_CONTROL_Int0    ==     EXIT_LOW_LEVEL_SC

		CLEAR_BIT(MCUCR ,MCUCR_ISC01_PIN );
		CLEAR_BIT(MCUCR ,MCUCR_ISC00_PIN);

	#elif EXIT_SENSE_CONTROL_Int0  ==     EXIT_FALLING_EDGE_SC

		SET_BIT(MCUCR ,MCUCR_ISC01_PIN );
		CLEAR_BIT(MCUCR ,MCUCR_ISC00_PIN);

	#elif EXIT_SENSE_CONTROL_Int0  ==     EXIT_RISING_EDGE_SC

		SET_BIT(MCUCR ,MCUCR_ISC00_PIN ) ;
		CLEAR_BIT(MCUCR ,MCUCR_ISC01_PIN);

	#elif EXIT_SENSE_CONTROL_Int0  ==       EXIT_ONCHANGE_SC

		SET_BIT(MCUCR ,MCUCR_ISC00_PIN );
		SET_BIT(MCUCR ,MCUCR_ISC01_PIN );
	#else
	#warning "no sense control selected back to confing file"

#endif
	//enable interrupt
	SET_BIT(GICR ,GICR_INT0_PIN) ;

}
void EXTI1_VidInti1(){
	//sense control
	#if EXIT_SENSE_CONTROL_Int1    ==     EXIT_LOW_LEVEL_SC

		CLEAR_BIT(MCUCR ,MCUCR_ISC10_PIN );
		CLEAR_BIT(MCUCR ,MCUCR_ISC11_PIN);

	#elif EXIT_SENSE_CONTROL_Int1  ==     EXIT_FALLING_EDGE_SC

		SET_BIT(MCUCR ,MCUCR_ISC11_PIN );
		CLEAR_BIT(MCUCR ,MCUCR_ISC10_PIN);

	#elif EXIT_SENSE_CONTROL_Int1  ==     EXIT_RISING_EDGE_SC

		SET_BIT(MCUCR ,MCUCR_ISC10_PIN ) ;
		CLEAR_BIT(MCUCR ,MCUCR_ISC11_PIN);

	#elif EXIT_SENSE_CONTROL_Int1  ==       EXIT_ONCHANGE_SC

		SET_BIT(MCUCR ,MCUCR_ISC10_PIN );
		SET_BIT(MCUCR ,MCUCR_ISC11_PIN );
		#else
		#warning "no sense control selected back to confing file"

	#endif
		//enable interrupt
	SET_BIT(GICR ,GICR_INT1_PIN) ;




}
void EXTI2_VidInti2(){

	//sense control


		#if EXIT_SENSE_CONTROL_Int2  ==     EXIT_FALLING_EDGE_SC

			CLEAR_BIT(MCUCSR ,MCUCR_ISC01_PIN );


		#elif EXIT_SENSE_CONTROL_Int2  ==     EXIT_RISING_EDGE_SC

			SET_BIT(MCUCSR ,MCUCR_ISC00_PIN ) ;



		#else
		#warning "no sense control selected back to confing file"

	#endif
		//enable interrupt
		CLEAR_BIT(GICR ,GICR_INT2_PIN) ;

}








