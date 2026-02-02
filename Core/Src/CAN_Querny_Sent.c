#include <string.h>
#include "CAN_Querny_Sent.h"





void CAN_QueueMessage(uint32_t id, const uint8_t *data, uint8_t len) {
    int nextTail = (txQueueTail + 1) % CAN_TX_QUEUE_SIZE;

    if (nextTail == txQueueHead) {
        printf("Tx kuyruğu dolu, mesaj düşürüldü!\n");
        txQueueHead = (txQueueHead + 1) % CAN_TX_QUEUE_SIZE;

        txQueueHead = 0;
           txQueueTail = 0;
           txInProgress = false;
        return;
    }

    txQueue[txQueueTail].id = id;
    memcpy(txQueue[txQueueTail].data, data, len);
    txQueue[txQueueTail].len = len;
    txQueueTail = nextTail;

    if (!txInProgress) {
        CAN_SendNextFromQueue();
    }
}

void CAN_SendNextFromQueue(void) {

    if (txQueueHead == txQueueTail) {
        txInProgress = 0;
       // printf("Queue empty, nothing to send\n");
        return;
    }

    CAN_TxHeaderTypeDef header;
    header.StdId = txQueue[txQueueHead].id;
    header.IDE   = CAN_ID_STD;
    header.RTR   = CAN_RTR_DATA;
    header.DLC   = (txQueue[txQueueHead].len > 8) ? 8 : txQueue[txQueueHead].len;

    uint32_t mailbox;
  //  printf("CAN TX Data: ");


    if (HAL_CAN_AddTxMessage(&hcan1, &header, txQueue[txQueueHead].data, &mailbox) == HAL_OK) {
        txInProgress = 1;
    } else {
        printf("Tx gönderme hatası\n");
        txInProgress = 0;
    }
	HAL_Delay(1);
}
void CAN_Send_Extended(uint32_t ext_id, uint8_t* data, uint8_t len) {
	  if (txQueueHead == txQueueTail) {
	        txInProgress = 0;
	       // printf("Queue empty, nothing to send\n");
	        return;
	    }

	    CAN_TxHeaderTypeDef header;
	    header.ExtId = ext_id;
	    header.IDE   = CAN_ID_STD;
	    header.RTR   = CAN_RTR_DATA;
	    header.DLC   = (txQueue[txQueueHead].len > 8) ? 8 : txQueue[txQueueHead].len;

	    uint32_t mailbox;
	  //  printf("CAN TX Data: ");


	    if (HAL_CAN_AddTxMessage(&hcan1, &header, txQueue[txQueueHead].data, &mailbox) == HAL_OK) {
	        txInProgress = 1;
	    } else {
	        printf("Tx gönderme hatası\n");
	        txInProgress = 0;
	    }
		HAL_Delay(1);
}
