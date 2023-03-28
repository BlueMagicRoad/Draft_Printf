#include "main.h"

/**
 * handle_width - Match width modifier with corresponding value
 * @args: va_list of args
 * @modifier: Pointer to potential width modifier
 * @index: Index counter for original string
 *
 * Return: Corresponding value, if width modifier is matched
 *         Otherwise: 0
 */

int handle_width(va_list args, const char *modifier, char *index)
{
	int value = 0;

	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}

	return (value);
}
