#include "main.h"

/**
 * convert_S - Converts argument to string
 * @args: va_list pointing to argument
 * @flags: Flag modifiers
 * @wid: Width modifier
 * @prec: Precision modifier
 * @len: Length modifier
 * @output: Buffer_t struct containing char array
 *
 * Description: Non-printable characters (ASCII values < 32 or >= 127)
 *              are stored as \x followed by hex ACII code value
 *
 * Return: Number of bytes stored to buffer
 */

unsigned int convert_S(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	int size, index;
	unsigned int ret = 0;

	(void)len;
	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; str[size];)
		size++;

	ret += print_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	for (index = 0; *(str + index) != '\0' && index < prec; index++)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
			ret += _memcpy(output, hex, 2);
			if (*(str + index) < 16)
				ret += _memcpy(output, &zero, 1);
			ret += convert_ubase(output, *(str + index),
					     "0123456789ABCDEF", flags, 0, 0);
			continue;
		}
		ret += _memcpy(output, (str + index), 1);
	}

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
