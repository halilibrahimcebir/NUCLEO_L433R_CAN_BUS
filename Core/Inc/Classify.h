/*
 * Classify.h
 * Motor State Classification Module
 *
 * This module classifies motor state based on neural network output.
 *
 *  Created on: May 9, 2025
 *      Author: Administrator
 */

#ifndef INC_CLASSIFY_H_
#define INC_CLASSIFY_H_

/**
 * @brief Classify motor state from neural network output
 * @param output Array of 4 float values from neural network
 * @return Class index (0: stationary, 1: lifting, 2: moving, 3: stopping)
 */
int classify_motor_state(float* output);

#endif /* INC_CLASSIFY_H_ */
