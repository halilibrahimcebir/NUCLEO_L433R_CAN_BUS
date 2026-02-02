/*
 * CAN_Sensorless0_Error.c
 *
 *  Created on: Feb 11, 2025
 *      Author: seken.durmaz
 */
#include "CAN_Sensorless0_Error.h"

void CAN_Sensorless0_Error(TwointValues can_64to32values)
{
	typedef struct
	{
		char error_name[50];   // Error name (e.g., "CONTROL_ITERATION_MISSED")
		char hex_value[12];    // Error value in hexadecimal format (e.g., "0x1")
		char error_message[100]; // Error message
	} ErrorCode;

	uint32_t bit;

	ErrorCode sensorles_errors[10]=
	{
		{"UNSTABLE_GAIN","0x1", "The gain is unstable."},						 	// 0
		{"UNKNOWN_CURRENT_MEASUREMENT","0x2", "Mismatch in CPR and pole pairs."},	// 1
	};

	for (int i =0; i < 2; i++)
	{
		bit = (can_64to32values.value1 >> (i)) & 1;
		if (bit == 1)
		{
			printf("Axis 0 Name: %s\n", sensorles_errors[i].error_name);
		    printf("	   Hex: %s\n", sensorles_errors[i].hex_value);
			printf("	   Description: %s\n", sensorles_errors[i].error_message);
		}
	}

}
