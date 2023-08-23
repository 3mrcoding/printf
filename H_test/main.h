#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

int print_char(va_list argu);
int print_string(va_list argu);

typedef struct main
{
    char symbols;
    int(*f)(va_list argu);
}fun;

    fun print[] = {
        {'s', &print_string},
        {'c', &print_char}
    };

fun *p = print;


#endif
