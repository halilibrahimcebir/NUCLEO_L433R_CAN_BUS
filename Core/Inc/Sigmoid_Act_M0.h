/*
 * Sigmoid_Act_M0.h
 *
 *  Created on: May 8, 2025
 *      Author: Administrator
 */

#ifndef INC_SIGMOID_ACT_M0_H_
#define INC_SIGMOID_ACT_M0_H_

float predict_motor_state_M0(float speed_norm, float pos_diff_norm, float current_norm);
float sigmoid_M0(float z);
 float Reverse_predict_motor_state_M0(float speed_norm, float pos_diff_norm, float current_norm);
 float Reverse_sigmoid_M0(float z);

#endif /* INC_SIGMOID_ACT_M0_H_ */
