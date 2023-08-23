#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * print_string - function returns the no. of printed bytes
 * @argu: va_list
 * Return: no. of printed bytes
*/


int print_string(va_list argu)
{
	int coun;
	char *s;
	int len;

	s = va_arg(argu, char*);
	if (s == NULL || strlen(s) == 1)
	{
		return (-1);
	}
	else
	{
		len = strlen(s);
		coun = write(STDOUT_FILENO, s, len);
		return (coun);
	}
}
