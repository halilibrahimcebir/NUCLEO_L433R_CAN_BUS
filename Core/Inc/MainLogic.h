/*
 * pid.h
 *
 *  Created on: Feb 17, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_PID_H_
#define INC_PID_H_

#include "stm32l4xx_hal.h"
#include <stdbool.h>
extern float f_m1_pos_for_PID;
extern float f_m0_pos;
extern float f_m1_pos;
extern float f_m0_vel;
extern float f_m1_vel;
extern float new_pos_1;
extern float new_pos_2;
extern float old_pos_1;
extern float old_pos_2;


extern float new_vel_1;
extern float new_vel_2;
extern float old_vel_1;
extern float old_vel_2;

extern float new_cur_1;
extern float new_cur_2;
extern float old_cur_1;
extern float old_cur_2;


extern float f_m0_iq_setpoint;
extern float f_m1_iq_setpoint;
extern bool pid_can_run_1;
extern bool pid_can_run_2;
extern float f_Dif_Pos;
extern float f_m0_Input_Vel;
extern float VelDivCurrent_M0;
extern float VelDivCurrent_M1;

extern float movement_1;
extern float movement_2;
extern float Chc_Vel_1;
extern float Chc_Vel_2;
extern float Chc_Cur_1;
extern float Chc_Cur_2;
extern bool b_SW_2;
extern float sample;
extern float sample2;


int Logic();

#endif /* INC_PID_H_ */
