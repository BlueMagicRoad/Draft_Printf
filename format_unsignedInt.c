#include "main.h"

/**
 * convert_u - Convert unsigned int decimal
 * @args: va_list pointing to argument
 * @flags: Flag modifiers
 * @wid: Width modifier
 * @prec: Precision modifier
 * @len: Length modifier
 * @output: Buffer_t struct containing char array
 *
 * Return: Number of bytes stored to buffer
 */

unsigned int convert_u(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (!(num == 0 && prec == 0))
		ret += convert_ubase(output, num, "0123456789",
				flags, wid, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
