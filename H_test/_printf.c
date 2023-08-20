#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - prints anything.
 * @format: the string to print between argu..
 * Return: not return.
 */


void is_incude(va_list argu)
{

}

/**
 * print_char - Prints a char.
 * @argu: A list of arguments pointing to
 *       the character to be printed.
 */

int print_char(va_list argu)
{
    int coun;
	char c;
	c = va_arg(argu, int);
	coun = write(STDOUT_FILENO, c, 1);
    return (coun);
}



/**
 * print_string - Prints a string.
 * @argu: A list of arguments pointing to
 *       the string to be printed.
 */

void print_string(va_list argu)
{
    int coun;
	char *s;
	s = va_arg(argu, char*);
	int len = strlen(s);
    coun == write(STDOUT_FILENO, s, len);
    return (coun);
}

int _printf(const char *format, ...)
{

    va_list args;


    va_start(args, format);
    fun print[] = {
        {'c', print_char},
        {'s', print_string}
    };

    va_end(args);

}
