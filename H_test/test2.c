#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int print_char(va_list argu);
int print_string(va_list argu);
int print_unmber (va_list argu);

typedef struct {
    char symbol;
    int (*f)(va_list argu);
} fun;

fun print[] = {
    {'s', &print_string},
    {'c', &print_char},
    {'d', &print_unmber},
    {'i', &print_unmber}
};

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
	s = va_arg(argu, char*);
	int len = strlen(s);
    coun = write(STDOUT_FILENO, s, len);
    return (coun);
}

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


void is_include(const char *format, int i, fun *p, va_list args) {
    int j;
    for (j = 0; j < 4; j++) {
        if (format[i + 1] == print[j].symbol) {
            print[j].f(args);
            break;
        }
    }
}

int _printf(const char *format, ...) {
    va_list args;
    int i;
    const char *c;

    va_start(args, format);

    int len = strlen(format);
    for (i = 0; i < len; i++) {
        if (format[i] == '%') {
            is_include(format, i, print, args);
            i++;
        } else {
            c = &format[i];
            write(STDOUT_FILENO, c, 1);
        }
    }
    va_end(args);
}

int main(void) {
    _printf("dgdfsd\n %s\n%d\n", "hello", -5120);
    return 0;
}
