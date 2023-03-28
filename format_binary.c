#include "main.h"

/**
 * convert_b - Convert int to binary
 * @args: va_list pointing to argument
 * @flags: Flag modifiers
 * @wid: Width modifier
 * @prec: Precision modifier
 * @len: Length modifier
 * @output: Buffer_t struct containing char array
 *
 * Return: Number of bytes stored to buffer
 */

unsigned int convert_b(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)len;

	return (convert_ubase(output, num, "01", flags, wid, prec));
}

