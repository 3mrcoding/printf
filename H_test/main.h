#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

typedef struct main
{
    char symbols;
    void(*f)(va_list argu);
}fun;

void print_symbole(va_list argu);
void print_char(va_list argu);
void print_int(va_list argu);
void print_float(va_list argu);
void print_string(va_list argu);

int _putchar(char c);
int _printf(const char *format, ...);


#endif
