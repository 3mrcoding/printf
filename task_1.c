#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_number - function returns the no. of printed bytes
 * @argu: va_list
 * Return: no. of printed bytes
*/

int print_unmber (va_list argu)
{
	int num = va_arg(argu, int);
	int i, j, divisor, digit, digits = 0;
	int temp = num;

	while (temp != 0)
	{
		digits++;
		temp /= 10;
	}
	char arr[digits + 1];
	arr[digits] = '\0';
	while (digits > 0)
	{
		j = 0;
		divisor = 1;
		for (i = 0; i < digits - 1; i++)
		{
			divisor *= 10;
		}
		digit = num / divisor;
		num %= divisor;
		digits--;
		arr[j] = digit + '0';
		write(STDOUT_FILENO, &arr[j], 1);
		j++;
	}
}
