/*
 * Button_Handler.h
 * GPIO Button Handler
 *
 * This module provides utilities for handling GPIO button inputs.
 *
 *  Created on: Feb 10, 2025
 *      Author: seken.durmaz
 */

#ifndef INC_BUTTON_HANDLER_H_
#define INC_BUTTON_HANDLER_H_

#include "stm32l4xx_hal.h"
#include "stdio.h"

/**
 * @brief Initialize GPIO for button handling
 */
void GPIO_Init(void);

/**
 * @brief Check the state of a button
 * @param buttonName Name of the button (for debugging)
 * @param GPIOx GPIO port
 * @param GPIO_Pin GPIO pin number
 * @return GPIO_PIN_SET if button not pressed, GPIO_PIN_RESET if pressed
 */
GPIO_PinState CheckButtonState(const char *buttonName, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#define BUTTON1_PIN GPIO_PIN_13
#define BUTTON1_GPIO_PORT GPIOA

#endif /* INC_BUTTON_HANDLER_H_ */
