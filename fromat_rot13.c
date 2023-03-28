#include "main.h"

/**
 * convert_R - Convert a string to ROT13
 * @args: va_list pointing to argument
 * @flags: Flag modifiers
 * @wid: Width modifier
 * @prec: Precision modifier
 * @len: Length modifier
 * @output: Buffer_t struct containing char array
 *
 * Return: Number of bytes stored to buffer
 */

unsigned int convert_R(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)";
	int i, j, size;
	unsigned int ret = 0;

	(void)flags;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	ret += print_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	for (i = 0; *(str + i) != '\0' && i < prec; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(str + i) == *(alpha + j))
			{
				ret += _memcpy(output, (rot13 + j), 1);
				break;
			}
		}
		if (j == 52)
			ret += _memcpy(output, (str + i), 1);
	}

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
