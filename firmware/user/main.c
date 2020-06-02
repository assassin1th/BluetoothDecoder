#include "stm32f0xx.h"
#include "io.h"
#define DEFAULT_STEP (uint8_t) 2

usart_io_t writer;
usart_io_t reader;

void init (void); // init all usable peref, such as USART1 and 2
void bind_interupts (void); // enable usable interupts
uint8_t decode_byte (uint8_t, uint8_t);
int main (void)
{
	uint8_t byte;
	init ();
	
	bind_interupts ();
	
	while (1) {
		byte = read_byte (&reader);
		
		byte = decode_byte (byte, DEFAULT_STEP);
		
		write_byte (&writer, byte);
	}
}

void init (void)
{
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER |= 0x80080;
	GPIOA->PUPDR |= 0x80080;
	GPIOA->OSPEEDR |=0x40040;
	GPIOA->AFR[0] |= 0x1 << 12;
	GPIOA->AFR[0] |= 0x1 << 4;
	
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	
	USART1->BRR |= 0x0341;
	USART2->BRR |= 0x0341;
	
	USART1->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_TCIE;
	USART2->CR1 |= USART_CR1_UE | USART_CR1_RE | USART_CR1_RXNEIE;
	
	init_usart_io (&writer, USART1);
	init_usart_io (&reader, USART2);
}

void bind_interupts (void)
{
	__enable_irq ();
	
	NVIC->ISER[0] |= 0x3 << 27;
	bind_usart_io_interrupt (&writer);
	bind_usart_io_interrupt (&reader);
}

uint8_t decode_byte (uint8_t byte, uint8_t step)
{
	return (byte != '\0') ? (byte + step) : byte;
}
