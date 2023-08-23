#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int print_char(va_list argu);
int print_string(va_list argu);

typedef struct {
    char symbol;
    int (*f)(va_list argu);
} fun;

fun print[] = {
    {'s', &print_string},
    {'c', &print_char}
};

int print_char(va_list argu) {
    int coun;
    char c;
    c = (char)va_arg(argu, int); // Cast the int to char
    coun = write(STDOUT_FILENO, &c, 1);
    return coun;
}

int print_string(va_list argu) {
    int coun;
    char *s;
    s = va_arg(argu, char*);
    int len = strlen(s);
    coun = write(STDOUT_FILENO, s, len);
    return coun;
}

void is_include(const char *format, int i, fun *p, va_list args) {
    int j;
    for (j = 0; j < 2; j++) {
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
    _printf("dgdfsd\n %s\n", "hello");
    return 0;
}
