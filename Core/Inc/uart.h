#ifndef __UART_H
#define __UART_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f2xx_hal.h"
void uart2_init(void);
void uart_sendchar(uint8_t ch);
void uart_sendstring(const char* str);

typedef struct
{
    uint8_t data;
    uint8_t index;
    
    uint8_t buffer[5];
    
} uart2;

extern uart2 Uart2;
#ifdef __cplusplus
}
#endif

#endif 