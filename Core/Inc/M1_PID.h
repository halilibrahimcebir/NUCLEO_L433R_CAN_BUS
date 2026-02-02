/*
 * M1_PID.h
 * Motor 1 PID Controller
 *
 * This module implements a PID (Proportional-Integral-Derivative) controller
 * for Motor 1 position/velocity control.
 *
 *  Created on: Feb 25, 2025
 *      Author: Administrator
 */

#ifndef INC_M1_PID_H_
#define INC_M1_PID_H_
#include "stdint.h"
#include "stdbool.h"

/**
 * @brief Calculate PID output for Motor 1
 * @param currentValue Current measured value (position or velocity)
 * @return Normalized PID output (0.0 to 1.0)
 */
float Calculate_M1(float currentValue);

/**
 * @brief Initialize PID controller for Motor 1
 * @param kp Proportional gain constant
 * @param ki Integral gain constant
 * @param kd Derivative gain constant
 * @param initialSetPoint Initial target setpoint
 */
void PID_Control_M1(float kp, float ki, float kd, float initialSetPoint);

/**
 * @brief Update the setpoint for Motor 1
 * @param newSetPoint New target setpoint value
 */
void SetSetPoint_M1(float newSetPoint);

/**
 * @brief Reset PID controller state for Motor 1
 */
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
