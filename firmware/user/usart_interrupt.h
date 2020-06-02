#ifndef USART_INTERRUPT_H_
#define USART_INTERRUPT_H_

#include "stm32f0xx.h"
#include "queue.h"

void bind_buffer (USART_TypeDef *usart, byte_queue_t *buff);

#endif // USART_INTERRUPT_H_
