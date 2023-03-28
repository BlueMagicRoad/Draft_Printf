# include "main.h"

/**
 * _printf - Output formatted string
 * @format: String to print
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	ret = run_printf(format, args, output);

	return (ret);
}
