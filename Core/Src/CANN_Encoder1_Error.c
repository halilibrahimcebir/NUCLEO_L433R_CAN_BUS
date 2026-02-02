/*
 * CAN_Encoder1_Error.c
 *
 *  Created on: Jan 28, 2025
 *      Author: seken.durmaz
 */

#include "CANN_Encoder1_Error.h"

void CANN_Encoder1_Error(TwointValues can_64to32values)
{
	typedef struct
	{
		char error_name[50];   // Hata adı (örneğin: "CONTROL_ITERATION_MISSED")
		char hex_value[12];    // Hata değeri (hexadecimal formatında, örneğin: "0x1")
		char error_message[100]; // Hata mesajı
	} ErrorCode;

	uint32_t bit;

	ErrorCode encoder_errors[10]=
	{
		{"UNSTABLE_GAIN","0x1", "The gain is unstable."},						 // 0
		{"CPR_POLEPAIRS_MISMATCH","0x2", "Mismatch in CPR and pole pairs."},	 // 1
		{"NO_RESPONSE","0x4", "No response from encoder."},						 // 2
		{"UNSUPPORTED_ENCODER_MODE","0x8", "The encoder mode is unsupported."},  // 3
		{"ILLEGAL_HALL_STATE","0x10", "Illegal hall state detected."},			 // 4
		{"INDEX_NOT_FOUND_YET","0x20", "Index has not been found yet."},		 // 5
		{"ABS_SPI_TIMEOUT","0x40", "SPI timeout occurred."},					 // 6
		{"ABS_SPI_COM_FAIL","0x80", "SPI communication failure."},			 	 // 7
		{"ABS_SPI_NOT_READY","0x100", "SPI is not ready."},						 // 8
		{"HALL_NOT_CALIBRATED_YET","0x200", "Hall sensor not calibrated yet."}   // 9
	};

	for (int i =0; i < 10; i++)
	{
		bit = (can_64to32values.value1 >> (i)) & 1;
		if (bit == 1)
		{
			printf("Axis 1 Name: %s\n", encoder_errors[i].error_name);
		    printf("	   Hex: %s\n", encoder_errors[i].hex_value);
			printf("	   Description: %s\n", encoder_errors[i].error_message);
		}
	}
}
