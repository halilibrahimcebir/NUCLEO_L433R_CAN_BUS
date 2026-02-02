/*
 * Uart_Parse_Data.c
 *
 *  Created on: Apr 24, 2025
 *      Author: Administrator
 */

#include "Uart_Parse_Data.h"
char UART_Parsed_Message [UART_DATA_COUNT][UART_BUFFER_SIZE];
	void Update_UART_Data()
{
    sprintf(UART_Parsed_Message[0], "%.2f", f_m0_pos);
    sprintf(UART_Parsed_Message[1], "%.2f", f_m0_vel);
    sprintf(UART_Parsed_Message[2], "%.2f", f_m0_iq_measured);
    sprintf(UART_Parsed_Message[3], "%.2f", f_m0_iq_setpoint);
    sprintf(UART_Parsed_Message[4], "%lu", i_m1_Motor_Error);
    sprintf(UART_Parsed_Message[5], "%lu", i_m0_Encoder_Error);
    sprintf(UART_Parsed_Message[6], "%lu", i_m0_Sensorless_Error);
    sprintf(UART_Parsed_Message[7], "%d", b_SW_1);
    sprintf(UART_Parsed_Message[8], "%u", i_m0_current_state);
    sprintf(UART_Parsed_Message[9], "%.2f", f_m1_pos);
    sprintf(UART_Parsed_Message[10], "%.2f", f_m1_vel);
    sprintf(UART_Parsed_Message[11], "%.2f", f_m1_iq_measured);
    sprintf(UART_Parsed_Message[12], "%.2f", f_m1_iq_setpoint);
    sprintf(UART_Parsed_Message[13], "%lu", i_m1_Motor_Error);
    sprintf(UART_Parsed_Message[14], "%lu", i_m0_Encoder_Error);
    sprintf(UART_Parsed_Message[15], "%lu", i_m1_Sensorless_Error);
    sprintf(UART_Parsed_Message[16], "%d", b_SW_2);
    sprintf(UART_Parsed_Message[17], "%u", i_m1_current_state);
}
