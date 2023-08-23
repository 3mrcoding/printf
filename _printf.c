#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

int print_char(va_list argu)
{
	int coun;
	char c;

	c = (char)va_arg(argu, int);
	coun = write(STDOUT_FILENO, &c, 1);
	return (coun);
}

int print_string(va_list argu)
{
	int coun;
	char *s;
	int len;

	s = va_arg(argu, char*);
	len = strlen(s);
	coun = write(STDOUT_FILENO, s, len);
	return (coun);
}

int is_incude(const char *format, int i, fun print[], va_list args)
{
	int j;
	int st;

	for (j = 0; j < 2; j++)
	{
		if (format[i + 1] == print[j].symbols)
		{
			st = print[j].f(args);
			break;
		}
	}
	return (st);
}

int _printf(const char *format, ...)
{

	va_list args;
	int i;
	int k = 0;
	const char *c;
	int len;
	fun print[] = {
		{'s', &print_string},
		{'c', &print_char}
	};

	if (!format || format == NULL || strlen(format) == 0)
	{
		return (-1);
	}

	va_start(args, format);

	len = strlen(format);
	for (i = 0; i < len; i++)
	{
		if (format[i] == '%')
		{
			k += is_incude(format, i, print, args);
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
