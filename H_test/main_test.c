#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

void _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int len = strlen(format);
    
    char *s = va_arg(args, char*);
    char *s2 = va_arg(args, char*);
    /*int num = va_arg(args, int);*/
    int len2 = strlen(s);
    int len3 = strlen(s2);
    write(1, format, len);
    write(1, s, len2);
    write(1, s2, len3);
    va_end(args);
}

int main(void)
{
    char *text = "hello\n";
    char *txet2 = "world\n";
    _printf("hjhjhkjh\n", text, txet2);
}
