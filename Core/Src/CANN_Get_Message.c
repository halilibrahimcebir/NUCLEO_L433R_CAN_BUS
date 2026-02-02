/*
 * CAN_Get_Message.c
 *
 *  Created on: Jan 29, 2025
 *      Author: seken.durmaz
 */

#include "CANN_Get_Message.h"
extern uint32_t CAN_Adresler[];
extern uint8_t CAN_Messages[18][8];
extern size_t totalAdressAmount;


uint8_t* CANN_Get_Message(uint32_t addr_can) {

    for (int i = 0; i < 18; i++) {
        if (CAN_Adresler[i] == addr_can) {
            return CAN_Messages[i];
        }
    }
    return NULL;
}


