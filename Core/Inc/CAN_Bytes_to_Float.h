/*
 * CAN_Bytes_to_Float.h
 *
 *  Created on: Feb 10, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_CAN_BYTES_TO_FLOAT_H_
#define INC_CAN_BYTES_TO_FLOAT_H_
#include "main.h"
#include <string.h>
float bytesToFloat(unsigned char* bytes);
void floatToBytes(float f, unsigned char* bytes);
void CAN_Set_Bytes_to_Float (float input1,float input2,uint8_t*combined);
void CAN_Set_Bytes_to_FloatM1 (float input1,float input2,uint32_t CAN_id);
extern CAN_HandleTypeDef hcan1;
#endif /* INC_CAN_BYTES_TO_FLOAT_H_ */
