#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

typedef struct main
{
	char symbols;
	int(*f)(va_list argu);
} fun;

int print_char(va_list argu);
int print_string(va_list argu);
int is_include(const char *format, int i, fun print[], va_list args);
int _printf(const char *format, ...);

#endif
