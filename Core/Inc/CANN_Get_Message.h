/*
 * CAN_Get_Message.h
 *
 *  Created on: Jan 29, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_CAN_GET_MESSAGE_H_
#define INC_CAN_GET_MESSAGE_H_

#include "stm32l4xx_hal.h"
#include <stdio.h>
uint8_t* CANN_Get_Message(uint32_t addr_can);

#endif /* INC_CAN_GET_MESSAGE_H_ */
