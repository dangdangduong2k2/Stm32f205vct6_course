#include "uart.h"

void uart2_init(void)
{
    GPIOA->AFR[0] |= 0x0700; 
    GPIOA->AFR[0] |= 0x7000; 
    GPIOA->MODER &= ~(GPIO_MODER_MODER2 | GPIO_MODER_MODER3);
    GPIOA->MODER |= (GPIO_MODER_MODER2_1 | GPIO_MODER_MODER3_1);
    GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_2 | GPIO_OTYPER_OT_3);
    
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR2 | GPIO_PUPDR_PUPDR3);
    
    
    USART2->CR1 &= ~USART_CR1_UE;
    USART2->BRR = 0x00000683; 
    USART2->CR1 &= ~USART_CR1_M; 
    USART2->CR2 &= ~USART_CR2_STOP; 
    USART2->CR1 &= ~(USART_CR1_PCE | USART_CR1_PS); 
    USART2->CR3 &= ~USART_CR3_HDSEL; 
    USART2->CR1 |= (USART_CR1_TE | USART_CR1_RE |USART_CR1_RXNEIE); 
    USART2->CR1 |= USART_CR1_UE;
    
    NVIC->ISER[1] |= (1 << 6);
}


void uart_sendchar(uint8_t ch)
{
   
    while (!(USART2->SR & USART_SR_TXE));

    USART2->DR = ch;
}


void uart_sendstring(const char* str)
{
    while (*str != '\0')
    {
        uart_sendchar(*str); 
        str++; 
    }
    
}

int convert(const char* chuoi) {
    int so = 0;
    int i = 0;
    
    while (chuoi[i] != '\0') {
        if (chuoi[i] >= '0' && chuoi[i] <= '9') {
            so = so * 10 + (chuoi[i] - '0');
        }
        i++;
    }
    return so;
}

char* revert(int so) {
    char* chuoi;
    int chieu_dai = snprintf(NULL, 0, "%d", so); 
    chuoi = (char*)malloc((chieu_dai + 1) * sizeof(char));  
    
    snprintf(chuoi, chieu_dai + 1, "%d", so); 
    
    return chuoi;
}

