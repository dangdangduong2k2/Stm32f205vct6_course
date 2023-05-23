#ifndef __GPIO_H
#define __GPIO_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f2xx_hal.h"
  
void gpio_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t GPIO_Type);//0 :output,1: input
uint8_t gpio_read(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void gpio_write(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t State);//1 : set, 0, reset

#ifdef __cplusplus
}
#endif

#endif 