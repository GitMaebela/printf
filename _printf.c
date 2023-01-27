#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
* print_string - function that prints a string
* @valist: list of arguments passed to _printf
*
* Return: number of characters printed
*/
int print_string(va_list valist)
{
    char *str = va_arg(valist, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";
    for (; *str; str++)
    {
        count += print_char(*str);
    }
    return (count);
}


/**
* print_char - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int print_char(char c)
{
    return (write(1, &c, 1));
}

/**
* print_number - prints an integer
* @n: integer to be printed
*
* Return: the number of characters printed
*/
int print_number(int n)
{
    int count = 0;
    unsigned int num;

    if (n < 0)
    {
        count += print_char('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num >= 10)
    {
        count += print_number(num / 10);
    }
    count += print_char(num % 10 + '0');
    return (count);
}

/**
* _printf - produces output according to a format
* @format: character string. The format string is composed of zero or more directives
*
* Return: the number of characters printed (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
    va_list args;
    int len = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    len += print_char(va_arg(args, int));
                    break;
                case 's':
                    len += print_string(args);
                    break;
                case '%':
                    len += print_char('%');
                    break;
                case 'd':
                case 'i':
                    len += print_number(va_arg(args, int));
                    break;
                default:
                    len = -1;
                    goto end;
            }
        }
        else
        {
            len += print_char(*format);
        }
        format++;
    }

end:
    va_end(args);
    return (len);
}
