#include "main.h"

/**
 * convert_sbase - Convert signed long to inputted base and store
 *                 result to buffer contained in struct
 * @output: Buffer_t struct containing char array
 * @num: Signed long to convert
 * @base: Pointer to string containing the base
 * @flags: Flag modifiers
 * @wid: Width modifier
 * @prec: Precision modifier
 *
 * Return: Number of bytes stored to buffer
 */

unsigned int convert_sbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	int size;
	char digit, pad = '0';
	unsigned int ret = 1;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size || num <= -size)
		ret += convert_sbase(output, num / size, base,
				flags, wid - 1, prec - 1);

	else
	{
		for (; prec > 1; prec--, wid--) /* Handle precision */
			ret += _memcpy(output, &pad, 1);

		if (NEG_FLAG == 0) /* Handle width */
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memcpy(output, &pad, 1);
		}
	}

	digit = base[(num < 0 ? -1 : 1) * (num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}

/**
 * convert_ubase - Convert unsigned long to inputted base and
 *                 store result to buffer contained in struct
 * @output: Buffer_t struct containing char array
 * @num: Unsigned long to convert
 * @base: Pointer to string containing the base
 * @flags: Flag modifiers
 * @wid: Width modifier
 * @prec: Precision modifier
 *
 * Return: Number of bytes stored to buffer
 */

unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	unsigned int size, ret = 1;
	char digit, pad = '0', *lead = "0x";

	for (size = 0; *(base + size);)
		size++;

	if (num >= size)
		ret += convert_ubase(output, num / size, base,
				flags, wid - 1, prec - 1);

	else
	{
		if (((flags >> 5) & 1) == 1) /* Printing a ptr address */
		{
			wid -= 2;
			prec -= 2;
		}
		for (; prec > 1; prec--, wid--) /* Handle precision */
			ret += _memcpy(output, &pad, 1);

		if (NEG_FLAG == 0) /* Handle width */
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memcpy(output, &pad, 1);
		}
		if (((flags >> 5) & 1) == 1) /* Print 0x for ptr address */
			ret += _memcpy(output, lead, 2);
	}

	digit = base[(num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}
