#ifndef USART_IO_H_
#define USART_IO_H_

#include "usart_io_base.h"

uint8_t usart_read_byte (usart_io_t *reader);
void usart_write_byte (usart_io_t *writer, uint8_t byte);


#endif // USART_IO_H_
