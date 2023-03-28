#include "main.h"

/**
 * convert_r - Reverse a string
 * @args: va_list pointing to argument
 * @flags: Flag modifiers
 * @wid: Width modifier
 * @prec: Precision modifier
 * @len: Length modifier
 * @output: Buffer_t struct containing char array
 *
 * Return: Number of bytes stored to buffer
 */

unsigned int convert_r(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int size, end, i;
	unsigned int ret = 0;

	(void)flags;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	ret += print_string_width(output, flags, wid, prec, size);

	end = size - 1;
	prec = (prec == -1) ? size : prec;
	for (i = 0; end >= 0 && i < prec; i++)
	{
		ret += _memcpy(output, (str + end), 1);
		end--;
	}

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
