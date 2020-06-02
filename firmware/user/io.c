#include "io.h"
#include "usart_io.h"

uint8_t read_byte (usart_io_t *reader)
{
	return usart_read_byte (reader);
}

void write_byte (usart_io_t *writer, uint8_t byte)
{
	usart_write_byte (writer, byte);
}
