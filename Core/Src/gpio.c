#include "gpio.h"

void gpio_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t GPIO_Type)//0 :output,1: input
{
    
    if ( GPIO_Type == 1 )
    {
        GPIOx->MODER    &= ~(1 << GPIO_Pin*2);
        GPIOx->MODER    &= ~(1 << (GPIO_Pin*2+1));
        GPIOx->PUPDR    |= (1<< GPIO_Pin*2);
        GPIOx->PUPDR    &= ~(1<<(GPIO_Pin*2+1));
    }
    
    if ( GPIO_Type == 0 )
    {
        GPIOx->MODER    |= (1<<(GPIO_Pin*2));
        GPIOx->MODER    &= ~(1<<(GPIO_Pin*2+1));
        GPIOx->OSPEEDR  |= (1<<(GPIO_Pin*2));
        GPIOx->OSPEEDR  &= ~(1<<(GPIO_Pin*2+1));
        GPIOx->OTYPER   &= ~(1 << GPIO_Pin*2);
    }
    
    
}

uint8_t gpio_read(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    uint8_t bitstatus = 0;
  
    if ((GPIOx->IDR & (1 <<(GPIO_Pin))) != 0)
    {
        bitstatus = 1;
    }
    
    else
    {
        bitstatus = 0;
    }
    
    return bitstatus;
}


void gpio_write(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t State)//1 : set, 0, reset
{
    
    if(State == 1)
    {
        GPIOx->BSRR |= (1<< GPIO_Pin);
    }
    
    if(State == 0)
    {
        GPIOx->BSRR |= (1<< (GPIO_Pin+16));
    }
}