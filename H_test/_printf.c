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


void is_incude(const char *format, int i, fun *p)
{
    int j;
    for (j = 0; print[j].symbols != '\0'; j++)
    {
        if (format[i + 1] == print[j].symbols)
        {
            print[j].f;
        }
        else
        {
            return;
        }
    }
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

int print_string(va_list argu)
{
    int coun;
	char *s;
	s = va_arg(argu, char*);
	int len = strlen(s);
    coun = write(STDOUT_FILENO, s, len);
    return (coun);
}

int _printf(const char *format, ...)
{
    va_list args;
    int i;
    const char *c;

    va_start(args, format);

    int len = strlen(format);
    for (i = 0; i < len; i++)
    {
        if (format[i] == '%')
        {
            
        }
        else
        {
            c = &format[i];
            write(STDOUT_FILENO, c, 1);
        }
    }
    va_end(args);

}
