#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>


int main (void)
{
    int num = -123456;
    int n = num;
    int i, j, temp, divisor, digit, digits = 0;

if (n < 0)
{
    num = -num;
    j = 1;
}
else
{
    j = 0;
}

temp = num;
    while (temp != 0)
    {
        digits++;
        temp /= 10;
    }
    char arr[digits + 2];

    arr[digits + 1] = '\0';


    while (digits > 0)
    {
        if (n < 0)
        {
            arr[0] = '-';
        }
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
    printf("\n");
}
