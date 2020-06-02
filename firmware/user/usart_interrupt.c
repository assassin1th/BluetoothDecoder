#include "stm32f0xx.h"
#include "usart_interrupt.h"

enum buff_id {USART1_BUFF = 0, USART2_BUFF};
static byte_queue_t *buffers[2];

void bind_buffer (USART_TypeDef *usart, byte_queue_t *buff)
{
	if (usart == USART1) {
		buffers[USART1_BUFF] = buff;
	} else if (USART1 == USART2){
		buffers[USART2_BUFF] = buff;
	} else {
	}
}

void USART1_IRQHandler(void)
{
	if (is_queue_empty (buffers[USART1_BUFF])) {
		USART1->CR1 &= ~USART_CR1_TCIE;
	} else {
		uint8_t byte = byte_queue_remove (buffers[USART1_BUFF]);
		USART1->TDR = byte;
	}
}
void USART2_IRQHandler(void)
{
	if (USART2->ISR | USART_ISR_RXNE) {
		byte_queue_insert (buffers[USART2_BUFF], USART2->RDR);
	}
}
