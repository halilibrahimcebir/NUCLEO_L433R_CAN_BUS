/*
 * PIDCONTROL.h
 *
 *  Created on: Feb 18, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_PIDCONTROL_H_
#define INC_PIDCONTROL_H_

#include "stdint.h"
#include "stdbool.h"
#include <stdio.h>



float Calculate_M0(float currentValue);
void PID_Control_M0(float kp, float ki, float kd, float initialSetPoint);
void SetSetPoint_M0(float newSetPoint);
void Reset_M0();

extern float Kp_M0; // Proportional constant
extern float Ki_M0; // Integral constant
extern float Kd_M0; // Derivative constant
extern float final_out_0;



extern float setPoint_M0; // Target set point
extern float integral_M0, previousError_M0;

extern float error_M0;
extern float derivative_M0;
extern float output_M0;

extern float M0_Power_Value;







#endif /* INC_PIDCONTROL_H_ */
