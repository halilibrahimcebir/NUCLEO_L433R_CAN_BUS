#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "UART_Received_Data.h"



void Parse_Data()
{

	if(Uart_Total_Pac==1)
	{
		printf("Received Message: \n");


					if(strcmp(UART_DataMessages[0], "Chk") == 0)
						{

						UART_COM_OK=true;

						}
					if(strcmp(UART_DataMessages[0], "STR") == 0)
											{




											}
					if(strcmp(UART_DataMessages[0], "RST") == 0)
												{



												}
					if(strcmp(UART_DataMessages[0], "STP") == 0)
											{




											}






		Uart_Total_Pac=0;

	}
}







