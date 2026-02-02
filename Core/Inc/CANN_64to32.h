/*
 * CANN_64to32.h
 * CAN 64-bit to 32-bit Converter
 *
 * This module converts 8-byte CAN messages into two 32-bit values
 * for processing motor control data.
 *
 *  Created on: Jan 29, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_CANN_64_TO32_H_
#define INC_CANN_64_TO32_H_

#include "stm32l4xx_hal.h"
#include "stdio.h"
#include <math.h>

/**
 * @brief Structure to hold two 32-bit values extracted from CAN message
 */
typedef struct {
    uint32_t value1;  // First 32-bit value (bytes 0-3)
    uint32_t value2;  // Second 32-bit value (bytes 4-7)
} TwointValues;

/**
 * @brief Convert 8-byte CAN message to two 32-bit values
 * @param message 8-byte array from CAN message
 * @return TwointValues structure containing two 32-bit values
 */
TwointValues CANN_64to32(uint8_t message[8]);


#endif /* INC_CANN_64_TO32_H_ */
