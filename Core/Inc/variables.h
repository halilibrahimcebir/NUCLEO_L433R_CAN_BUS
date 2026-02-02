/*
 * variables.h
 *
 *  Created on: Jan 30, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_VARIABLES_H_
#define INC_VARIABLES_H_

#include <stdbool.h>

#include "CANN_Get_Message.h"
#include "CANN_64to32.h"
#include "CAN_Set_Messages.h"
#include "CANN_Motor0_Error.h"
#include "CANN_Motor1_Error.h"
#include "CANN_Encoder0_Error.h"
#include "CANN_Encoder1_Error.h"
#include "CAN_Sensorless0_Error.h"
#include "CAN_SensorlessM1_Error.h"
#include "MainLogic.h"
#include "M0_PID.h"
#include "M1_PID.h"
#include "CAN_Remote_Send_Message.h"
#include "CAN_Bytes_to_Float.h"
#include "Button_Handler.h"
#include "Exo_Calibration.h"
#include "UART_Received_Data.h"
#include "UART_Send_Data.h"
#include "Uart_Parse_Data.h"
#include "CAN_Querny_Sent.h"



uint32_t  CAN_Adresler[] = {0x201,0x203,0x204,0x205,0x209,0x214,0x301,0x303,0x304,0x305,0x309,0x314,0x405,0x406};
uint32_t  CAN_Adress;
uint8_t   CAN_Messages[18][8] =
{
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};

TwointValues  CAN_64to32values;

uint32_t      CAN_Driver_Error;

bool        b_Exo_Calibration_State;
bool		b_Exo_StartUp;
bool 		b_Exo_Start_Button;
bool		b_Exo_Reset;

uint32_t i_m0_Sensorless_Error,
i_m1_Sensorless_Error,
i_m0_Encoder_Error,
i_m1_Encoder_Error,
i_m0_Motor_Error,
i_m1_Motor_Error;

uint8_t 	  i_Current_State;

/*-------AXIS 0-----------------------------------------AXIS 1-------*///////
float f_m0_vel;									float f_m1_vel;//////////////
float f_m0_pos;									float f_m1_pos;//////////////
float f_m0_pos_for_PID;									float f_m1_pos_for_PID;//////////////
float f_m0_error;								float f_m1_error;////////////
float f_encoder0_error;							float f_encoder1_error;//////
float f_sensorless0_error;						float f_sensorless1_error;///
float f_m0_iq_measured;							float f_m1_iq_measured;//////
float f_m0_iq_setpoint;							float f_m1_iq_setpoint;//////
bool  b_SW_1;									bool  b_SW_2;////////////////
uint8_t i_m0_current_state;						uint8_t i_m1_current_state;//
float f_m0_pos_for_Alive;									float f_m1_pos_for_Alive;
/////////////////////////////////////////////////////////////////////////////

float f_m0_Input_Torque;
float f_m0_Input_Vel=40.0;
float f_m0_Input_Pos;

float f_m1_Input_Torque;
float f_m1_Input_Vel;
float f_m1_Input_Pos;

float new_pos_1;
float new_pos_2;
float old_pos_1;
float old_pos_2;

float new_vel_1;
float new_vel_2;
float old_vel_1;
float old_vel_2;

float new_cur_1;
float new_cur_2;
float old_cur_1;
float old_cur_2;

bool pid_can_run_1;
bool pid_can_run_2;
float sample;
float sample2;
float movement_1;
float movement_2;
 float Chc_Vel_1;
 float Chc_Vel_2;
 float Chc_Cur_1;
 float Chc_Cur_2;
float f_Dif_Pos;
float VelDivCurrent_M0;
float VelDivCurrent_M1;
bool b_calibration_tried;
bool salata;
uint8_t M0_Walking_Steps;
uint8_t M1_Walking_Steps;
uint8_t b_Mode_With_Move_Can;
bool b_Mode_With_Move;
bool b_Mode_First_Trig;

uint8_t Lift_Steps;




//M0_PID_Variables
float Kp_M0,Ki_M0,Kd_M0,setPoint_M0,integral_M0,error_M0,derivative_M0,output_M0,previousError_M0,final_out_0;

//M1_PID_Variables

float Kp_M1,Ki_M1,Kd_M1,setPoint_M1,integral_M1,error_M1,derivative_M1,output_M1,previousError_M1,final_out_1;

 float M0_Power_Value;
 float M1_Power_Value;
//UART Variables

uint8_t UART_Received_Data;
bool Uart_Ok;
int UART_Data_Len;
int Desire_Of_Lift=0;
volatile uint32_t lastReceiveTime = 0;


 uint8_t Rx_Buffer[255];
 uint8_t UART_Message[255];
 uint16_t rx_index=0 ;
 uint8_t receiving = 0;
#define RX_BUFFER_SIZE 100
#define STX 0x02  // Start Byte
#define ETX 0x03  // End Byte
 char* UART_DataMessages[255];
 char sent_message[255];
 uint8_t Uart_Total_Pac;
 bool UART_COM_OK;
 bool UART_Received;
 bool CHKED;
 bool b_Start;
 bool b_Reset;
bool Exo_RUN;
bool Exo_Sho_Reset;
bool Exo_Ready;
bool Panel_Start;
bool Panel_Reset;
bool Panel_Stop;
bool Uart_TimeOut;
uint8_t Uart_TimeOut_indicater;
 uint32_t timerValue;


 void F_Can_Seperate(void);
 void F_SW_Read(void);
 void F_Can_Seperate(void);
 void F_UART_Seperater(void);
 void S_System_Check(void);
 void System_Reset(bool Panel_Reset);
 void F_Start_Exo(bool Panel_Start);
 void F_Stop_Exo(bool Panel_Stop);
 void F_Starup_Check(void);
 extern float predict_motor_state_M0(float speed_norm, float pos_diff_norm, float current_norm);
 extern float Reverse_predict_motor_state_M0(float speed_norm, float pos_diff_norm, float current_norm);
 extern float Reverse_sigmoid_M0(float z);
 extern float Reverse_predict_motor_state_M1(float speed_norm, float pos_diff_norm, float current_norm);
 extern float Reverse_sigmoid_M1(float z);
extern float predict_motor_state_M1(float speed_norm, float pos_diff_norm, float current_norm);
void Delay_Of_Sending(void);
extern int classify_motor_state(float* output);
float m0_Sigmoid_result;
float m1_Sigmoid_result;
float m0_Sigmoid_result_Rev;
float m1_Sigmoid_result_Rev;
int Class_indx;
bool Calibraion_For_Profile;
void send_heartbeat();

// Error System
bool E_Driver_Fault;
bool E_Can_Fault;
bool E_Uart_Fault;
bool E_System_Fault;
bool E_Exo_Fault;
bool E_EMG_Pressed;
bool E_EMG_Status;
bool Can_Sent;

// Status Data
bool S_Running;
bool S_Stopped;
bool S_Should_Reset;
bool S_Resetted;
bool Can_Reset;
bool Calibration_Fail;
bool Reset_Ack;
bool Panel_Life_Error;
uint16_t Panel_Life_Counter = 0;
bool Mode_Walk;
uint32_t Panel_Mode_Value;
uint32_t Panel_Status_Value;
float Panel_Power_Value;
float Panel_Battery_Lev;

#define CAN_ID_RESET 0

// For Query

// For BPM Machina
void F_BPM_BPM_Start_Up_Chk();
void F_BPM_Logic();
void F_BPM_Forward();
void F_BPM_Reverse();
void F_BPM_Start(bool Start_Req);
void F_BPM_Stop(bool Stop_Req);
void F_BPM_Reset(bool Reset_Req);
void BPM_Calibration(bool SW_1,bool SW_2);
bool BPM_Start_req;
bool BPM_Start_Up;
bool BPM_Reverse;
bool BPM_Forward;
bool BPM_Calibration_Fail;
bool b_BPM_Stopped;
void F_BPM_Stop_Seq();

void send_Batary_Req();
void F_Panel_Alive();

CAN_Message txQueue[CAN_TX_QUEUE_SIZE];
volatile int txQueueHead = 0;
volatile int txQueueTail = 0;
volatile int txInProgress = 0;

#endif /* INC_VARIABLES_H_ */
