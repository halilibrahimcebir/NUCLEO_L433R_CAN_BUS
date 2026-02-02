/*
 * UART_Received_Data.h
 *
 *  Created on: Mar 10, 2025
 *      Author: Administrator
 */

#ifndef INC_UART_RECEIVED_DATA_H_
#define INC_UART_RECEIVED_DATA_H_
#include <stdint.h>
#include "stdbool.h"



extern uint8_t UART_Received_Data;
extern int UART_Data_Len;
extern bool Uart_Ok;
extern uint8_t Uart_Total_Pac;
extern char* UART_DataMessages[255];

extern bool UART_COM_OK;
void Parse_Data();

extern bool UART_Received;


extern bool   CHKED;

extern bool Exo_RUN;
extern bool Exo_Sho_Reset;
extern bool Exo_Ready;
extern bool Uart_Start;
extern bool Uart_Reset;
extern bool Uart_Button;
extern bool b_Start;
extern bool b_Reset;
extern bool S_Should_Reset;

extern bool E_Driver_Fault;
extern  bool E_Can_Fault;
extern bool E_Uart_Fault;
extern bool E_System_Fault;
extern bool E_Exo_Fault;
extern bool E_EMG_Pressed;
#endif /* INC_UART_RECEIVED_DATA_H_ */
