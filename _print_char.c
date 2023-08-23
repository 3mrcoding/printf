#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
/**
 * print_char - function returns the no. of printed bytes
 * @argu: va_list
 * Return: no. of printed bytes
*/
int print_char(va_list argu)
{
	int coun;
	char c;


	if (sizeof(va_arg(argu, int)) != sizeof(int))
	{
		return (-1);
	}
	else
	{
		c = (char)va_arg(argu, int);
		coun = write(STDOUT_FILENO, &c, 1);
		return (coun);
	}
}
