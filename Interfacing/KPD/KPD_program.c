#include"lib/STD_TYPES.h"
#include "avr/delay.h"
#include "DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"

u8 KPD_u8GetPressKey(void)
{
	u8 Local_KeyPressed = NOT_PRESSED ;
	u8 Local_u8KPDArr[4][4] = KPD_u8ARR;
	u8 Local_u8ColumnIdx = 0;
	u8 Local_u8RowIdx = 0;

	u8 Local_u8State = 1;

	/*Array of cols and rows*/
	u8 Local_u8ColumnArr[]= { KPD_u8COLUMN0_PIN , KPD_u8COLUMN1_PIN , KPD_u8COLUMN2_PIN , KPD_u8COLUMN3_PIN };
	u8 Local_u8RowArr[]={ KPD_u8ROW0_PIN , KPD_u8ROW1_PIN , KPD_u8ROW2_PIN , KPD_u8ROW3_PIN };

	/*Search the Column*/

	for(Local_u8ColumnIdx = 0 ; Local_u8ColumnIdx < 4 ; Local_u8ColumnIdx++ )
	{

		DIO_VidSetPinValue( KPD_u8PORT , Local_u8ColumnArr[Local_u8ColumnIdx],low );

		/*Search the Row*/

		for(Local_u8RowIdx =0 ; Local_u8RowIdx < 4; Local_u8RowIdx++)
		{

			DIO_VidGetPinValue(KPD_u8PORT , Local_u8RowArr[Local_u8RowIdx] , &Local_u8State);

			if (Local_u8State == low)
			{
				/*Finding the Key*/

				Local_KeyPressed = Local_u8KPDArr[Local_u8ColumnIdx][Local_u8RowIdx];
				while(Local_u8State == low)
				{

					DIO_VidGetPinValue(KPD_u8PORT , Local_u8RowArr[Local_u8RowIdx] ,&Local_u8State);

				}

				return Local_KeyPressed;
			}
		}
		DIO_VidSetPinValue(KPD_u8PORT , Local_u8ColumnArr[Local_u8ColumnIdx] , high );
		_delay_ms(10);
	}

	return Local_KeyPressed;


}
