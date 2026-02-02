/*
 * Button_Handler.h
 *
 *  Created on: Feb 10, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_BUTTON_HANDLER_H_
#define INC_BUTTON_HANDLER_H_

#include "stm32l4xx_hal.h"
#include "stdio.h"


void GPIO_Init(void);

GPIO_PinState CheckButtonState(const char *buttonName, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#define BUTTON1_PIN GPIO_PIN_13
#define BUTTON1_GPIO_PORT GPIOA

#endif /* INC_BUTTON_HANDLER_H_ */
