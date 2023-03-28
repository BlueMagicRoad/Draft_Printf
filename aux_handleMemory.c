#include "main.h"

/**
 * _memcpy - Copies n bytes from memory area src to
 *           buffer contained in buffer_t struct
 * @output: Buffer_t struct
 * @src: Pointer to memory area to copy
 * @n: Number of bytes to copy
 *
 * Return: Number of bytes copied
 */

unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(output->buffer) = *(src + index);
		(output->len)++;

		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}

		else
			(output->buffer)++;
	}

	return (n);
}

/**
 * free_buffer - Frees buffer_t struct
 * @output: Buffer_t struct to free
 *
 * Return: None
 */

void free_buffer(buffer_t *output)
{
	free(output->start);
	free(output);
}

/**
 * init_buffer - Inits variable buffer_t (struct type
 *
 * Return: Pointer to init'd buffer_t.
 */

buffer_t *init_buffer(void)
{
	buffer_t *output;

	output = malloc(sizeof(buffer_t));
	if (output == NULL)
		return (NULL);

	output->buffer = malloc(sizeof(char) * 1024);
	if (output->buffer == NULL)
	{
		free(output);
		return (NULL);
	}

	output->start = output->buffer;
	output->len = 0;

	return (output);
}
