#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * is_include - function returns the no. of printed bytes
 * @format: format
 * @i: index of format which '%' is found
 * @print: struct
 * @args: va_list
 * Return: no. of printed bytes
*/
int is_include(const char *format, int i, fun print[], va_list args)
{
	int j;
	int st = 0;
	char c = '%';

	if (format[i + 1] == '%')
	{
		st = +write(STDOUT_FILENO, &c, 1);
	}

	for (j = 0; j < 4; j++)
	{
		if (format[i + 1] == print[j].symbols)
		{
			st = +print[j].f(args);
			break;
		}
	}
	return (st);
}
