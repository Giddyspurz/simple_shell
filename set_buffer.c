#include "header.h"
/**
 * set_buffer - sets the buffer with null character from aux_read position
 * @buffer: string with line caught by read
 * @aux_read: Number of bytes read by read
 * Return: void
 */
void set_buffer(char *buffer, ssize_t aux_read)
{
	ssize_t i = aux_read;

	while (buffer[i])
		buffer[i] = '\0', i++;
}
