#include "usart_io.h"

uint8_t usart_read_byte (usart_io_t *reader)
{
	while (is_queue_empty (&reader->buff))
		;
	return byte_queue_remove (&reader->buff);
}

void usart_write_byte (usart_io_t *writer, uint8_t byte)
{
	if (is_queue_empty (&writer->buff)) {
		writer->usart->CR1 |= USART_CR1_TCIE;
		USART1->TDR = byte;
	} else {
		byte_queue_insert (&writer->buff, byte);
	}
}
