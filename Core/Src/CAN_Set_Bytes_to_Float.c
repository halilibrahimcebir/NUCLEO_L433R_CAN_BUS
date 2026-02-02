/*
 * CAN_Set_Axis_Node_Id_1.c
 *
 *  Created on: Feb 4, 2025
 *      Author: seken.durmaz
 */


#include "CAN_Remote_Send_Message.h"
#include "CAN_Bytes_to_Float.h"

void CAN_Set_Bytes_to_Float (float input1,float input2,uint8_t*combined)
{

	unsigned char bytes[4];
	unsigned char bytes2[8];




    floatToBytes(input1, bytes);
    floatToBytes(input2, bytes2);

    memcpy(combined, bytes, 4);
    memcpy(combined + 4, bytes2, 4);




}
