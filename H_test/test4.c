#include <unistd.h>  // for write
#include <stdarg.h>  // for va_list
#include <stdlib.h>  // for malloc

int main (void)
{
    int num = -12356;  // Extract the integer from va_list
    
    int is_negative = 0;
    if (num < 0) {
        is_negative = 1;
        num = -num;  // Convert negative to positive for processing
    }

    int i, j, divisor, digit, digits = 0;
    int temp = num;

    while (temp != 0)
    {
        digits++;
        temp /= 10;
    }

    char arr[digits + 2];  // +1 for possible '-' sign, +1 for '\0'
    arr[digits + 1] = '\0';  // Null-terminate the string

    if (is_negative) {
        arr[0] = '-';
        j = 1;  // Start from the second position for digits
    } else {
        j = 0;
    }
    
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

    write(STDOUT_FILENO, arr, j);  // Write the whole array
}
