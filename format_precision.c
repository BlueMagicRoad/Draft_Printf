#include "main.h"

/**
 * handle_precision - Match precision modifier with corresponding value
 * @args: va_list of args
 * @modifier: Pointer to potential precision modifier
 * @index: Index counter for original string
 *
 * Return: Corresponding value, if precision modifier is matched
 *         If precision modifier is empty || zero || negative: 0
 *         Otherwise: -1
 */

int handle_precision(va_list args, const char *modifier, char *index)
{
	int value = 0;

	if (*modifier != '.')
		return (-1);

	modifier++;
	(*index)++;

	if ((*modifier <= '0' || *modifier > '9') &&
	     *modifier != '*')
	{
		if (*modifier == '0')
			(*index)++;
		return (0);
	}

	while ((*modifier >= '0' && *modifier <= '9') ||
	       (*modifier == '*'))
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
