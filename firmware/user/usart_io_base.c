#include "usart_io_base.h"
#include "usart_interrupt.h"

void init_usart_io (usart_io_t *io, USART_TypeDef *usart)
{
	byte_queue_init (&io->buff);
	io->usart = usart;
}

void bind_usart_io_interrupt (usart_io_t *io)
{
	bind_buffer (io->usart, &io->buff);
}
