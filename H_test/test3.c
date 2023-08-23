#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>


int main (void)
{
    int num = 123456;
    int i, j, temp, divisor, digit, digits = 0;
    int is_negative = 0;

    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }

temp = num;
    while (temp != 0)
    {
        digits++;
        temp /= 10;
    }
    char arr[digits + 2];
    arr[digits + 1] = '\0';
    if (is_negative)
    {
        arr[0] = '-';
        j = 1;
    }
    else
        j = 0;
    while (digits > 0)
    {
        divisor = 1;
        for (i = 0; i < digits - 1; i++)
        {
            divisor *= 10;
        }
        digit = num / divisor;
        num %= divisor;
        digits--;
        arr[j] = digit + '0';
        j++;
    }
    write(STDOUT_FILENO, arr, j);
}
