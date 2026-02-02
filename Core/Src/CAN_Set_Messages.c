/*
 * CAN_Set_Messages.c
 * CAN Message Setting Implementation
 *
 *  Created on: Jan 8, 2025
 *      Author: seken.durmaz
 */

#include "CAN_Set_Messages.h"

void CAN_Set_Signed_int32(uint32_t num1, uint32_t num2, uint32_t length, uint8_t *output_result)
{
    int32_t out1;
    int32_t out2;

    if (length == 4)
    {
        if (num1 & (1 << 31))
            out1 = (int32_t)(num1 | 0xFFFFFFFF00000000);
        else
            out1 = num1;

        for (int i = 0; i < 4; i++)
            output_result[i] = (out1 >> (8 * i)) & 0xFF;
    }
    else if (length == 8)
    {
        if (num1 & (1 << 31))
            out1 = (int32_t)(num1 | 0xFFFFFFFF00000000);
        else
            out1 = num1;

        if (num2 & (1 << 31))
            out2 = (int32_t)(num2 | 0xFFFFFFFF00000000);
        else
            out2 = num2;

        for (int i = 0; i < 4; i++)
            output_result[i] = (out1 >> (8 * i)) & 0xFF;

        for (int i = 0; i < 4; i++)
            output_result[i + 4] = (out2 >> (8 * i)) & 0xFF;
    }
}
