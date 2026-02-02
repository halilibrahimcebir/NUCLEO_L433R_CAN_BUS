/*
 * CAN_Set_Messages.h
 * CAN Message Setting Utilities
 *
 * This module provides utilities to format and prepare CAN messages
 * with different data types.
 *
 *  Created on: Jan 8, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_CAN_SET_MESSAGES_H_
#define INC_CAN_SET_MESSAGES_H_

#include "CAN_Remote_Send_Message.h"

extern CAN_HandleTypeDef hcan1;

/**
 * @brief Set float values in CAN message
 * @param sayi1 First float value
 * @param sayi2 Second float value
 * @param CAN_id CAN message identifier
 * @param length Message length
 */
void CAN_Set_Values(float sayi1, float sayi2, uint32_t CAN_id, uint32_t length);

/**
 * @brief Convert signed 32-bit integers to byte array for CAN transmission
 * @param num1 First 32-bit value
 * @param num2 Second 32-bit value
 * @param length Output length (4 or 8 bytes)
 * @param output_result Output buffer
 */
void CAN_Set_Signed_int32(uint32_t num1, uint32_t num2, uint32_t length, uint8_t *output_result);

#endif /* INC_CAN_SET_MESSAGES_H_ */
