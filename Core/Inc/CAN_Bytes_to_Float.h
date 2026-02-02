/*
 * CAN_Bytes_to_Float.h
 * CAN Float Conversion Utilities
 *
 * This module provides utilities to convert between byte arrays and float values
 * for CAN bus communication.
 *
 *  Created on: Feb 10, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_CAN_BYTES_TO_FLOAT_H_
#define INC_CAN_BYTES_TO_FLOAT_H_
#include "main.h"
#include <string.h>

/**
 * @brief Convert 4-byte array to float value
 * @param bytes Pointer to 4-byte array
 * @return Float value
 */
float bytesToFloat(unsigned char* bytes);

/**
 * @brief Convert float value to 4-byte array
 * @param f Float value to convert
 * @param bytes Output buffer for 4 bytes
 */
void floatToBytes(float f, unsigned char* bytes);

/**
 * @brief Combine two floats into 8-byte array for CAN transmission
 * @param input1 First float value
 * @param input2 Second float value
 * @param combined Output buffer for 8 bytes
 */
void CAN_Set_Bytes_to_Float (float input1,float input2,uint8_t*combined);

void CAN_Set_Bytes_to_FloatM1 (float input1,float input2,uint32_t CAN_id);
extern CAN_HandleTypeDef hcan1;
#endif /* INC_CAN_BYTES_TO_FLOAT_H_ */
