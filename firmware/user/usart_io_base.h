#ifndef USART_IO_BASE_H_
#define USART_IO_BASE_H_

#include "stm32f0xx.h"
#include "queue.h"

typedef struct 
{
	byte_queue_t buff;
	USART_TypeDef *usart;
} usart_io_t;

void init_usart_io (usart_io_t *io, USART_TypeDef *usart);
void bind_usart_io_interrupt (usart_io_t *io);

#endif // USART_IO_BASE_H_
