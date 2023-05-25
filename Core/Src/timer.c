#include "timer.h"

void timer1_init(void)
{   
    TIM1->CR1 &= ~TIM_CR1_DIR;
    TIM1->CR1 &= ~TIM_CR1_CMS;
    TIM1->CNT = 0;
    TIM1->PSC = 16;
    TIM1->ARR = 999;
    TIM1->DIER |= TIM_DIER_UIE;    
    NVIC->ISER[0] |= (1 << 25);
    TIM1->CR1 |= TIM_CR1_CEN;
}

void timer2_init(void)
{    
    TIM2->CR1 &= ~TIM_CR1_DIR;
    TIM2->CR1 &= ~TIM_CR1_CMS;
    TIM2->CNT = 0;
    TIM2->PSC = 16; 
    TIM2->ARR = 999; 
    TIM2->DIER |= TIM_DIER_UIE;  
    NVIC->ISER[0] |= (1 << 28);
    TIM2->CR1 |= TIM_CR1_CEN;
}    

void timer3_init(void)
{    
    TIM3->CR1 &= ~TIM_CR1_DIR;
    TIM3->CR1 &= ~TIM_CR1_CMS;
    TIM3->CNT = 0;
    TIM3->PSC = 16; 
    TIM3->ARR = 999; 
    TIM3->DIER |= TIM_DIER_UIE;  
    NVIC->ISER[0] |= (1 << 29);
    TIM3->CR1 |= TIM_CR1_CEN;
}   