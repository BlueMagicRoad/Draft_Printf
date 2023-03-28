#include "main.h"

/**
 * handle_length - Match length modifier with corresponding value
 * @modifier: Pointer to potential length modifier
 * @index: Index counter for original string
 *
 * Return: Corresponding value, if length modifier is matched
 *         Otherwise: 0
 */

unsigned char handle_length(const char *modifier, char *index)
{
	if (*modifier == 'h')
	{
		(*index)++;
		return (SHORT);
	}

	else if (*modifier == 'l')
	{
		(*index)++;
		return (LONG);
	}

	return (0);
}
