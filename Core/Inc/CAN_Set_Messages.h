/*
 * CAN_Set_Messages.h
 *
 *  Created on: Jan 8, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_CAN_SET_MESSAGES_H_
#define INC_CAN_SET_MESSAGES_H_


#include "CAN_Remote_Send_Message.h"

extern CAN_HandleTypeDef hcan1;

void CAN_Set_Values(float sayi1, float sayi2, uint32_t CAN_id, uint32_t length);
void CAN_Set_Signed_int32(uint32_t num1, uint32_t num2, uint32_t length, uint8_t *output_result);























#endif /* INC_CAN_SET_MESSAGES_H_ */
