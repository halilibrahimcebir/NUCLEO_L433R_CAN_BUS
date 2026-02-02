/*
 * M0_PID.h
 * Motor 0 PID Controller
 *
 * This module implements a PID (Proportional-Integral-Derivative) controller
 * for Motor 0 position/velocity control.
 *
 *  Created on: Feb 18, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_M0_PID_H_
#define INC_M0_PID_H_

#include "stdint.h"
#include "stdbool.h"
#include <stdio.h>

/**
 * @brief Calculate PID output for Motor 0
 * @param currentValue Current measured value (position or velocity)
 * @return Normalized PID output (0.0 to 1.0)
 */
float Calculate_M0(float currentValue);

/**
 * @brief Initialize PID controller for Motor 0
 * @param kp Proportional gain constant
 * @param ki Integral gain constant
 * @param kd Derivative gain constant
 * @param initialSetPoint Initial target setpoint
 */
void PID_Control_M0(float kp, float ki, float kd, float initialSetPoint);

/**
 * @brief Update the setpoint for Motor 0
 * @param newSetPoint New target setpoint value
 */
void SetSetPoint_M0(float newSetPoint);

/**
 * @brief Reset PID controller state for Motor 0
 */
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







#endif /* INC_M0_PID_H_ */
