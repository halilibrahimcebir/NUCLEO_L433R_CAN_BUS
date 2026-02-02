/*
 * M1.PID.h
 *
 *  Created on: Feb 25, 2025
 *      Author: Administrator
 */

#ifndef INC_M1_PID_H_
#define INC_M1_PID_H_
#include "stdint.h"
#include "stdbool.h"





float Calculate_M1(float currentValue);
void PID_Control_M1(float kp, float ki, float kd, float initialSetPoint);
void SetSetPoint_M1(float newSetPoint);
void Reset_M1();

extern float Kp_M1; // Proportional constant
extern float Ki_M1; // Integral constant
extern float Kd_M1; // Derivative constant
extern float final_out_1;


extern float setPoint_M1; // Target set point
extern float integral_M1, previousError_M1;

extern float error_M1;
extern float derivative_M1;
extern float output_M1;

extern float M1_Power_Value;


#endif /* INC_M1_PID_H_ */
