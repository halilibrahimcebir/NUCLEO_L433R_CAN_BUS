/*
 * Button_Handler.c
 *
 *  Created on: Feb 10, 2025
 *      Author: seken.durmaz
 */

#include "Button_Handler.h"


void GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // GPIOA portunun saatini etkinleştir
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // GPIO pinini giriş olarak yapılandır (örnek: PIN0)
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;  // Buton genellikle Pull-up ile kullanılır
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}


GPIO_PinState CheckButtonState(const char *buttonName, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    GPIO_PinState state = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);

    if (state == GPIO_PIN_SET) {
        // Butona basılmadığı durumda (Pull-up kullanılıyorsa)
    	//printf("%s is pressed.\n", buttonName);
    } else {
        // Butona basıldığı durumda
        //printf("%s is not pressed.\n", buttonName);
    }

    return state;
}



