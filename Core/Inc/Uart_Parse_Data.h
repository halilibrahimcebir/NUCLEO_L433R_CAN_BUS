/*
 * Uart_Parse_Data.h
 *
 *  Created on: Apr 24, 2025
 *      Author: Administrator
 */

#ifndef INC_UART_PARSE_DATA_H_
#define INC_UART_PARSE_DATA_H_
#include <stdint.h>
#include "stdbool.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef UART_DATA_H
#define UART_DATA_H

#define UART_DATA_COUNT 18
#define UART_BUFFER_SIZE 18

// Tüm verileri dışarıya açmak için
extern char UART_Parsed_Message[UART_DATA_COUNT][UART_BUFFER_SIZE];

// Veri güncelleme fonksiyonu
void Update_UART_Data();

#endif // UART_DATA_H


extern float f_m0_vel;								extern	float f_m1_vel;//////////////
extern float f_m0_pos;								extern	float f_m1_pos;//////////////
extern float f_m0_pos_for_PID;						extern	float f_m1_pos_for_PID;//////////////
extern float f_m0_error;							extern	float f_m1_error;////////////


extern float f_m0_iq_measured;						extern	float f_m1_iq_measured;//////
extern float f_m0_iq_setpoint;						extern	float f_m1_iq_setpoint;//////
extern bool  b_SW_1;								extern	bool  b_SW_2;////////////////
extern uint8_t i_m0_current_state;					extern	uint8_t i_m1_current_state;//
extern uint32_t i_m0_Sensorless_Error;
extern uint32_t i_m1_Sensorless_Error;

extern uint32_t i_m0_Encoder_Error;
extern uint32_t i_m1_Encoder_Error;
extern uint32_t i_m0_Motor_Error;
extern uint32_t i_m1_Motor_Error;


#endif /* INC_UART_PARSE_DATA_H_ */
