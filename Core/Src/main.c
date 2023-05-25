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
        
        if(gpio_read(GPIOD,11)==0)
        {
            run=1;
            strcpy(Uart2.buffer, "");
        }
        if(gpio_read(GPIOC,6)==0||(Uart2.buffer[0]=='S'&&Uart2.buffer[1]=='t'&&Uart2.buffer[2]=='o'&&Uart2.buffer[3]=='p'))
        {
            run=0;
            rerun=0;
            count=0;
        }  
        if(gpio_read(GPIOC,7)==0)
        {
            time5000ms=0;
            run=0;
        }  
    }
    else
    {
        
    }
    
}
void TIM2_IRQHandler(void) 
{    
  if(run>0)
  {
    gpio_write(GPIOB,0,0);
  }
  else
  {
    gpio_write(GPIOB,0,1);
  }
  if(acc==1 && run==0)
  {
    time5000ms++;
    if(time5000ms==5000)
    {
      run=1;
    }
  }
  TIM2->SR &= ~TIM_SR_UIF;   
}

void TIM3_IRQHandler(void) 
{    
  
  TIM3->SR &= ~TIM_SR_UIF;   
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
  gpio_init(GPIOD,13,1);//s2 *****logic1*****
  gpio_init(GPIOC,6,1);//b2
  gpio_init(GPIOC,7,1);//b3
  gpio_init(GPIOE,14,1);//b4
  gpio_init(GPIOB,0,0);//relay
  gpio_init(GPIOA,15,1);//sw
  
  gpio_write(GPIOB,0,1);
  while (1)
  {
    
    if(gpio_read(GPIOD,13)==1 )
    {
        acc=1;
        rerun=0;

    }
    if(gpio_read(GPIOD,12)==1 && state==0)
    {
        run=0;
        if(acc==1)
        {
          acc=0;
          count++;
          uart_sendstring(revert(count));
          while(gpio_read(GPIOD,12)>0);
          state=1;
          rerun=1;
        }
        
    }
    if(gpio_read(GPIOD,12)==0)
    {
      if(rerun==1)
      {
        run=1;
      }
        
      state=0;
    }
    
    
  
  
  
  }
  

}





