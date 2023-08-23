#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 * _printf - function returns the no. of printed bytes
 * @format: entered format
 * Return: no. of printed bytes
*/
int _printf(const char *format, ...)
{
	va_list args;
	int i;
	int k = 0;
	const char *c;
	int len;

	fun print[] = {
		{'s', &print_string},
		{'c', &print_char},
		{'d', &print_number},
		{'i', &print_number}
	};

	va_start(args, format);
	len = strlen(format);

	if (format == NULL || !format || strlen(format) == 0)
		return (-1);

	for (i = 0; i < len; i++)
	{
		if (format[i] == '\0')
			return (-1);
		if (format[i] == '%')
		{
			k += is_include(format, i, print, args);
			i++;
		}
		else
		{
			c = &format[i];
			k += write(STDOUT_FILENO, c, 1);
		}
	}
	return (k);
	va_end(args);
}
