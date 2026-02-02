/*
 * CAN_Bytes_to_Float.c
 *
 *  Created on: Feb 10, 2025
 *      Author: seken.durmaz
 */


#include "CAN_Remote_Send_Message.h"
#include "CAN_Bytes_to_Float.h"
typedef union {
    unsigned char bytes[4];
    float value;
} FloatUnion;
float bytesToFloat(unsigned char* bytes) {
    FloatUnion fu;
    for (int i = 0; i < 4; i++) {
        fu.bytes[i] = bytes[i];
    }
    return fu.value;
}

void floatToBytes(float f, unsigned char* bytes) {
    FloatUnion fu;
    fu.value = f; // Float değerini union'a atayın
    for (int i = 0; i < 4; i++) {
        bytes[i] = fu.bytes[i]; // Byte'ları çıkarın
    }
}
