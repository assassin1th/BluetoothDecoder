#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdint.h>
#define DEFAULT_SIZE 256

typedef struct
{
	uint8_t first;
	uint8_t last;
	uint8_t buff[DEFAULT_SIZE];
} byte_queue_t;

void byte_queue_insert (byte_queue_t *queue, uint8_t byte);
uint8_t byte_queue_remove (byte_queue_t *queue);
uint8_t is_queue_empty (byte_queue_t *queue);
void byte_queue_init (byte_queue_t *queue);

#endif // QUEUE_H_
