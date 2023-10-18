#include "main.h"

/**
 * _printf - function that produces output according to format
 * @format: The format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int string_len;
	char character;
	
	va_list elements;
	va_start(elements, format);

	string_len = 0;

	while(*format)
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
			{
				va_end(elements);
				return (-1);
			}
			switch (*format)
			{
				case 'c':
				{
				character = va_arg(elements, int);
				_putchar((char)character);
				string_len++;
				break;
				}
				case 's':
			{
				const char *str = va_arg(elements, const char *);

				if (str == NULL)
				{
					str = "(null)";
				}
					while (*str)
					{
						_putchar(*str);
						str++;
						string_len++;
					}
					break;
				}

				case '%':
			{
				_putchar('%');
				string_len++;
				break;
			}
				default:
				_putchar('%');
				putchar(*format);
				string_len += 2;
				break;
			}
		}
		format++;
	}
	va_end(elements);
	return (string_len);
}

/**
 * print_number - Print an integer using _putchar
 * @n: The integer to print
 * @len: Pointer to the lenght counter
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
