/*
 * CAN_Querny_Sent.h
 *
 *  Created on: May 13, 2025
 *      Author: Administrator
 */
#include "stm32l4xx_hal.h"  // veya kullandığınız STM32 serisinin uygun başlık dosyası
#include "stdio.h"
#include <stdbool.h>
#define CAN_TX_QUEUE_SIZE 10

 typedef struct {
    uint32_t id;
    uint8_t  data[8];
    uint8_t  len;
} CAN_Message;

extern CAN_Message txQueue[CAN_TX_QUEUE_SIZE];
extern volatile int txQueueHead ;
extern volatile int txQueueTail ;
extern volatile int txInProgress ;
extern bool Can_Sent;
void CAN_ResetQueue(void);

#ifndef INC_CAN_QUERNY_SENT_H_
#define INC_CAN_QUERNY_SENT_H_

extern CAN_HandleTypeDef hcan1;
void CAN_QueueMessage(uint32_t id, const uint8_t *data, uint8_t len);
void CAN_Send_Extended(uint32_t ext_id, uint8_t* data, uint8_t len);

void CAN_SendNextFromQueue(void);


#endif /* INC_CAN_QUERNY_SENT_H_ */
