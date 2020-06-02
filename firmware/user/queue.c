#include "queue.h"

uint8_t is_queue_empty (byte_queue_t *queue)
{
	return queue->first == queue->last;
}

uint8_t byte_queue_remove (byte_queue_t *queue)
{
		return queue->buff[queue->first++];
}

void byte_queue_insert (byte_queue_t *queue, uint8_t byte)
{
	if (++queue->last == queue->first)
		++queue->first;
	
	queue->buff[queue->last] = byte;
}

void byte_queue_init (byte_queue_t *queue)
{
	queue->first = queue->last = 0;
}
