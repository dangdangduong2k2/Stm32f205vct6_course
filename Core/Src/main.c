#include "main.h"
#include "clock.h" 
#include "gpio.h" 
#include "timer.h" 
#include "uart.h" 
#include <stdio.h>
#include <math.h>
#include <string.h>
uint32_t time20ms = 0;
uint32_t time5000ms = 0;
uint8_t data;

uart2 Uart2;
uint32_t temp=0;
uint32_t count;
int state=0;
int run=0;
int acc=0;
int rerun=0;

void TIM1_UP_TIM10_IRQHandler(void) 
{   
    TIM1->SR &= ~TIM_SR_UIF; 
    if (++ time20ms == 20)
    {
        time20ms=0;     
    }
    else
    {
        
    }
    
}
void TIM2_IRQHandler(void) 
{    
  
 
  TIM2->SR &= ~TIM_SR_UIF;   
}

void TIM3_IRQHandler(void) 
{    
  
  if(Uart2.accept==1)
  {
      Uart2.timer50ms++;
  }
  if(Uart2.timer50ms==50)
  {
      Uart2.index = 0;     
      Uart2.user_buffer[0]=Uart2.buffer[0];
      Uart2.user_buffer[1]=Uart2.buffer[1];
      Uart2.user_buffer[2]=Uart2.buffer[2];
      Uart2.user_buffer[3]=Uart2.buffer[3];
      Uart2.user_buffer[4]=Uart2.buffer[4];

      Uart2.accept=0;
      Uart2.timer50ms=0;
      Uart2.buffer[0]='\0';
      Uart2.buffer[1]='\0';
      Uart2.buffer[2]='\0';
      Uart2.buffer[3]='\0';
      Uart2.buffer[4]='\0';
  }
  TIM3->SR &= ~TIM_SR_UIF;   
}

void USART2_IRQHandler(void) {
    if (USART2->SR & USART_SR_RXNE) 
    {
        Uart2.accept=1;
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
  gpio_init(GPIOC,6,1);//b2
  gpio_init(GPIOC,7,1);//b3
  gpio_init(GPIOE,14,1);//b4
  gpio_init(GPIOA,15,1);//sw

  while (1)
  {
    
    
    
    
    
  
  
  
  }
  

}





