/*
 * CANN_64_to32.h
 *
 *  Created on: Jan 29, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_CANN_64_TO32_H_
#define INC_CANN_64_TO32_H_

#include "stm32l4xx_hal.h"
#include "stdio.h"
#include <math.h>

typedef struct {
    uint32_t value1;
    uint32_t value2;
} TwointValues;



TwointValues CANN_64to32(uint8_t message[8]);


#endif /* INC_CANN_64_TO32_H_ */
