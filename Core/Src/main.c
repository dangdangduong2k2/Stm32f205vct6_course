#include "main.h"
#include "clock.h" 
#include "gpio.h" 
#include "timer.h" 
#include "uart.h" 
#include <stdio.h>
#include <math.h>
#include <string.h>
uint32_t time20ms = 0;
uint8_t data;

uart2 Uart2;
uint32_t temp=0;
uint32_t count;


void TIM1_UP_TIM10_IRQHandler(void) 
{   
    TIM1->SR &= ~TIM_SR_UIF; 
    if (++ time20ms == 20)
    {
        time20ms=0;
        
        if(gpio_read(GPIOC,6)==0)
        {
          gpio_write(GPIOB,0,1);
        }
    }
    else
    {
        
    }
    
}
void TIM2_IRQHandler(void) 
{    
  if(temp>0)
  {
    count++;
    if(count==temp)
    {
      gpio_write(GPIOB,0,1);
      count=0;
      temp=0;
    }
  }
  TIM2->SR &= ~TIM_SR_UIF;   
}


void USART2_IRQHandler(void) {
    if (USART2->SR & USART_SR_RXNE) 
    {
        Uart2.data = USART2->DR;
        if (Uart2.data == 0x0A) //enter
        {    
            Uart2.index = 0;
            
        } 
        else 
        {
            Uart2.buffer[Uart2.index++] = Uart2.data;

            if (Uart2.index >= 5) 
            {  
                Uart2.index = 0;        
            }
        }
        temp = convert(Uart2.buffer);
        
        USART2->SR &= ~USART_SR_RXNE;
    } 
}

int main(void)
{
  
  HAL_Init();
  SystemClock_Config();
  system_clock_peripheral_init();
  
  gpio_init(GPIOA,7,0);
  gpio_init(GPIOB,2,0);
  timer1_init();
  timer2_init();
  uart2_init();
  
  //IO init
  gpio_init(GPIOD,11,1);//b1
  gpio_init(GPIOD,12,1);//s1 *****logic1*****
  gpio_init(GPIOD,13,1);//s2    *****logic1*****
  gpio_init(GPIOC,6,1);//b2
  gpio_init(GPIOC,7,1);//b3
  gpio_init(GPIOE,14,1);//b4
  gpio_init(GPIOB,0,0);//relay
  gpio_init(GPIOA,15,1);//sw
  
  gpio_write(GPIOB,0,1);
  while (1)
  {
    if(gpio_read(GPIOA,15)==0)
    {
        
        if(gpio_read(GPIOD,13)==1)
        {
          gpio_write(GPIOB,0,0);
        }
        if(gpio_read(GPIOD,12)==1||gpio_read(GPIOC,6)==0)
        {
          gpio_write(GPIOB,0,1);
        }
        
    }
    else
    {
        if(gpio_read(GPIOD,11)==0)
        {
          gpio_write(GPIOB,0,0);
        }
        if(gpio_read(GPIOC,6)==0)
        {
          gpio_write(GPIOB,0,1);
        }
    }
    
    
  }

}





