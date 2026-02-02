/*
 * r.c
 *
 *  Created on: Jan 2, 2025
 *      Author: seken.durmaz
 */

#include "CAN_Remote_Send_Message.h"

extern CAN_HandleTypeDef hcan1;

void CAN_Com_Init(void)  // Burada fonksiyon ismini değiştirdik
{
    // CAN başlatma işlemleri
    TxHeader.RTR = CAN_RTR_REMOTE;
    TxHeader.DLC = 0;
    TxHeader.IDE = CAN_ID_STD;
}

void CAN_SendRemoteMessage(void)
{
    // CAN mesajı gönderme işlemi
    TxHeader.StdId = CAN_Adresler[adres_sayaci];
    HAL_CAN_AddTxMessage(&hcan1, &TxHeader, 0, &TxMailbox);

    adres_sayaci++;
    if (adres_sayaci == 16) {
        adres_sayaci = 0; // Adresler dizisinin sonuna gelindiğinde başa dön
    }
}
