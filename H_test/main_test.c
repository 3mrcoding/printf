#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

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
    int *num = argu;
    int i, divisor, digit, digits = 0;
    int temp = *num;

    while (temp != 0)
    {
        digits++;
        temp /= 10;
    }
    while (digits > 0)
    {
        divisor = 1;
        for (i = 0; i < digits; i++)
        {
            divisor *= 10;
        }
        digit = *num / divisor;
        digits--;
        write(STDOUT_FILENO, (digit + '0'), 1);
    }
}

int is_incude(const char *format, int i, fun *p, va_list args)
{
    int j;
    int st;
    for (j = 0; j < 2; j++)
    {
        if (format[i + 1] == print[j].symbols)
        {
            st = print[j].f(args);
            printf("%d\n", st);
            return (st);
            break;
        }
    }
    
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
            is_incude(format, i, print, args);
            i++;
        }
        else
        {
            c = &format[i];
            write(STDOUT_FILENO, c, 1);
        }
    }
    va_end(args);
}

int main(void)
{
    int coun = 0;

    coun = _printf("dgdfsd\n%s\n", "hello\n");
    printf("%d\n", coun);
    coun = printf("dgdfsd\n%s\n", "hello\n");
    printf("%d\n", coun);
    return(coun);
}
