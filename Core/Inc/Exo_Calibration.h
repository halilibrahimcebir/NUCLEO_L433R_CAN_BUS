/*
 * Exo_Calibration.h
 * Exoskeleton Calibration Module
 *
 * This module handles calibration of the exoskeleton system
 * using switch inputs to determine proper positioning.
 *
 *  Created on: Feb 11, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_EXO_CALIBRATION_H_
#define INC_EXO_CALIBRATION_H_

#include <stdbool.h>

/**
 * @brief Perform exoskeleton calibration
 * @param SW_1 State of switch 1
 * @param SW_2 State of switch 2
 */
void Exo_Calibration(bool SW_1,bool SW_2);

extern bool b_Exo_Calibration_State;
extern bool b_calibration_tried;
extern bool Calibration_Fail;

// Motor positions and velocities
extern float f_m0_vel;
extern float f_m1_vel;
extern float f_m0_pos;
extern float f_m1_pos;
extern bool b_SW_1;
extern bool b_SW_2;
extern bool Can_Sent;
extern bool Uart_Reset;

#endif /* INC_EXO_CALIBRATION_H_ */
