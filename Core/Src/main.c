#include "main.h"
#include "clock.h" 
#include "gpio.h" 
#include "timer.h" 
#include "uart.h" 

uint32_t time20ms = 0;
uint8_t data;
void TIM1_UP_TIM10_IRQHandler(void) 
{   
    TIM1->SR &= ~TIM_SR_UIF; 
    if (++ time20ms == 500)
    {
        time20ms=0;
        gpio_write(GPIOB,2,0);
    }
    else
    {
        gpio_write(GPIOB,2,1);
    }
    
}
void TIM2_IRQHandler(void) 
{    
     TIM2->SR &= ~TIM_SR_UIF;   
}


void USART2_IRQHandler(void) {
    if (USART2->SR & USART_SR_RXNE) 
    {
        
        
        
         data = USART2->DR;
        
        
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
  
  while (1)
  {
    
    
  }

}





