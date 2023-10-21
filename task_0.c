#include "main.h"

/**
 * print_binary - print an unsigned int in binary
 * @n: the unsigned int to print
 * @len: pointer to length
 */
void print_binary(unsigned int n, int *len)
{
    if (n / 2)
        print_binary(n / 2, len);
    _putchar((n % 2) + '0');
    *len += 1;
}

/**
 * print_string - function that prints a string
 * @str: the string to print
 * @len: pointer to length
 */
void print_string(const char *str, int *len)
{
    if (str == NULL)
        str = "(null)";
    while (*str)
    {
        _putchar(*str);
        str++;
        *len += 1;
    }
}

/**
 * print_number - function that prints an integer
 * @n: the integer to print
 * @len: pointer to length
 */
void print_number(int n, int *len)
{
    unsigned int num;

    if (n < 0)
    {
        _putchar('-');
        *len += 1;
        num = -n;
    }
    else
    {
        num = n;
    }
    if (num / 10)
        print_number(num / 10, len);
    _putchar((num % 10) + '0');
    *len += 1;
}

int _printf(const char *format, ...)
{
    int string_len = 0;
    va_list args;

    va_start(args, format);
    while (format && *format)
    {
        if (*format != '%')
        {
            _putchar(*format);
            string_len++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;

            switch (*format)
            {
                case 'c':
                    _putchar(va_arg(args, int));
                    string_len++;
                    break;

                case 's':
                    print_string(va_arg(args, const char *), &string_len);
                    break;

                case '%':
                    _putchar('%');
                    string_len++;
                    break;

                case 'd':
                case 'i':
                    print_number(va_arg(args, int), &string_len);
                    break;

                case 'b':
                    print_binary(va_arg(args, unsigned int), &string_len);
                    break;

                case 'u':
                    print_number(va_arg(args, unsigned int), &string_len);
                    break;

                case 'o':
                    print_number(va_arg(args, unsigned int), &string_len);
                    break;

                case 'x':
                    print_number(va_arg(args, unsigned int), &string_len);
                    break;

                case 'X':
                    print_number(va_arg(args, unsigned int), &string_len);
                    break;

                default:
                    _putchar('%');
                    _putchar(*format);
                    string_len += 2;
            }
        }
        format++;
    }
    va_end(args);
    return string_len;
}
