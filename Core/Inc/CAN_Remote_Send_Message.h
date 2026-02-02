/*
 * r.h
 *
 *  Created on: Jan 2, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_R_H_
#define INC_R_H_

#include "stm32l4xx_hal.h"  // veya kullandığınız STM32 serisinin uygun başlık dosyası
#include "stdio.h"
extern uint32_t CAN_Adresler[];
extern uint8_t adres_sayaci;

extern CAN_RxHeaderTypeDef RxHeader;
extern CAN_TxHeaderTypeDef TxHeader;
extern uint8_t Received_Data[8];
extern uint32_t TxMailbox;

void CAN_Com_Init(void);
void CAN_SendRemoteMessage(void);
void CAN_ReceiveMessage(void);

#endif /* INC_R_H_ */
