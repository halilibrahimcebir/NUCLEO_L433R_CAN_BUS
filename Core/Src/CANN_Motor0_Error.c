/*
 * CANN_Motor0_Error.c
 *
 *  Created on: Jan 31, 2025
 *      Author: seken.durmaz
 */
#include "CANN_Motor0_Error.h"


void CANN_Motor0_Error(TwointValues can_64to32values)
{
	typedef struct
	{
		char error_name[50];   // Hata adı (örneğin: "CONTROL_ITERATION_MISSED")
		char hex_value[12];    // Hata değeri (hexadecimal formatında, örneğin: "0x1")
		char error_message[100]; // Hata mesajı
	} ErrorCode;

	uint32_t bit;
	ErrorCode motor_errors_msb[32]=
		{
			{"PHASE_RESISTANCE_OUT_OF_RANGE", "0x1", "The phase resistance is out of range."},		// 0
		    {"PHASE_INDUCTANCE_OUT_OF_RANGE", "0x2", "The phase inductance is out of range."},		// 1
			{"", "", ""},																			// 2
			{"DRV_FAULT","0x8", "The DRV fault occurred."},										    // 3
			{"CONTROL_DEADLINE_MISSED", "0x10", "The control deadline was missed."},				// 4
			{"", "", ""},																			// 5
			{"", "", ""},								   											// 6
			{"MODULATION_MAGNITUDE", "0x80", "The modulation magnitude is out of bounds."},			// 7
			{"", "", ""},																			// 8
			{"", "", ""},																			// 9
			{"CURRENT_SENSE_SATURATION", "0x400", "The current sense is saturated."},				//10
			{"", "", ""},																			//11
			{"CURRENT_LIMIT_VIOLATION", "0x1000", "The current limit violation occurred."},			//12
			{"", "", ""},																			//13
			{"", "", ""},																			//14
			{"", "", ""},																			//15
			{"MODULATION_IS_NAN", "0x10000", "The modulation is NaN (not a number)."},				//16
			{"MOTOR_THERMISTOR_OVER_TEMP", "0x20000", "The motor thermistor is overheated."},		//17
			{"FET_THERMISTOR_OVER_TEMP", "0x40000", "The FET thermistor is overheated."},			//18
			{"TIMER_UPDATE_MISSED", "0x80000", "The timer update was missed."},						//19
			{"CURRENT_MEASUREMENT_UNAVAILABLE", "0x100000", "Current measurement is unavailable."}, //20
			{"CONTROLLER_FAILED", "0x200000", "The controller has failed."},						//21
			{"I_BUS_OUT_OF_RANGE", "0x400000", "The I_bus value is out of range."},					//22
			{"BRAKE_RESISTOR_DISARMED", "0x800000", "The brake resistor was disarmed."},			//23
			{"SYSTEM_LEVEL", "0x1000000", "System level error."},									//24
			{"BAD_TIMING", "0x2000000", "Bad timing detected."},									//25
			{"UNKNOWN_PHASE_ESTIMATE", "0x4000000", "The phase estimate is unknown."},				//26
			{"UNKNOWN_PHASE_VEL", "0x8000000", "The phase velocity is unknown."},  					//27
			{"UNKNOWN_TORQUE", "0x10000000", "The torque is unknown."},          					//28
			{"UNKNOWN_CURRENT_COMMAND", "0x20000000", "The current command is unknown."}, 			//29
			{"UNKNOWN_CURRENT_MEASUREMENT", "0x40000000", "The current measurement is unknown."},   //30
			{"UNKNOWN_VBUS_VOLTAGE", "0x80000000", "The Vbus voltage is unknown."}					//31
		};
	ErrorCode motor_errors_lsb[4] =
		{
			{"UNKNOWN_VOLTAGE_COMMAND", "0x100000000", "The voltage command is unknown."},	        // 0 (32)
			{"UNKNOWN_GAINS", "0x200000000", "The gains are unknown."},						        // 1 (33)
			{"CONTROLLER_INITIALIZING", "0x400000000", "The controller is initializing."},	   		// 2 (34)
			{"UNBALANCED_PHASES", "0x800000000", "The phases are unbalanced."}				   		// 3 (35)
		};

	for (int b =0; b < 2;b++)
	{
		if (b==0) //MSB Control
		{
			for (int i =0; i < 32; i++)
			{
				bit = (can_64to32values.value1 >> (i)) & 1;
				if (bit == 1)
				{
					printf("Axis 0 Name: %s\n", motor_errors_msb[i].error_name);
			        printf("Hex: %s\n", motor_errors_msb[i].hex_value);
			        printf("Description: %s\n", motor_errors_msb[i].error_message);

				}
			}


		}
		else if(b==1)
		{	  //LSB Control
			for (int j =0; j < 4; j++)
			{
				bit = (can_64to32values.value2 >> (j)) & 1;
				if (bit == 1)
				{
					printf("Axis 0 Name: %s\n", motor_errors_lsb[j].error_name);
			        printf("	   Hex: %s\n", motor_errors_lsb[j].hex_value);
			        printf("	   Description: %s\n", motor_errors_lsb[j].error_message);
				}
			}

		}

     }



}


