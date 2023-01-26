#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
* _printf - produces output according to a format
* @format: character string. The format string is composed of zero or more directives
*
* Return: the number of characters printed (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...) {
    va_list args; // variable argument list
    int count = 0;
    va_start(args, format); // initialize variable argument list

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'c':
                    putchar(va_arg(args, int)); // print single character
                    count++;
                    break;
                case 's':
                    fputs(va_arg(args, char *), stdout); // print string
                    count += strlen(va_arg(args, char *));
                    break;
                case 'd':
                case 'i':
                    printf("%d", va_arg(args, int)); // print decimal number
                    count += numberOfDigit(va_arg(args, int));
                    break;
                case '%':
                    putchar('%'); // print %
                    count++;
                    break;
                default:
                    putchar(format[i]);
                    count++;
                    break;
            }
        } else {
            putchar(format[i]);
            count++;
        }
    }

    va_end(args); // end variable argument list
    return count;
}

/**
* numberOfDigit - count the number of digits in a number
* @number: number to count digits
*
* Return: number of digits
*/
int numberOfDigit(int number) {
    int count = 0;
    if (number == 0)
        return 1;
    if (number < 0) {
        count++;
        number *= -1;
    }
    while (number > 0) {
        count++;
        number /= 10;
    }
    return count;
}
