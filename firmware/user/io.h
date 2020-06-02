#ifndef IO_H_
#define IO_H_

#include "usart_io_base.h"

uint8_t read_byte (usart_io_t *reader);
void write_byte (usart_io_t *writer, uint8_t byte);

#endif // IO_H_
