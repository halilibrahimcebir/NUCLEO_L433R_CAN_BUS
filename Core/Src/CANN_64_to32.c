/*
 * CANN_64_to32.c
 * CAN 64-bit to 32-bit Converter Implementation
 *
 *  Created on: Jan 29, 2025
 *      Author: seken.durmaz
 */

#include "CANN_64to32.h"

TwointValues CANN_64to32(uint8_t message[8]) {
    TwointValues result;
    result.value1 = 0;
    result.value2 = 0;

    result.value1 = (message[3] << 24) |
                    (message[2] << 16) |
                    (message[1] <<  8) |
                     message[0];

    result.value2 = (message[7] << 24) |
                    (message[6] << 16) |
                    (message[5] <<  8) |
                     message[4];

    return result;
}

