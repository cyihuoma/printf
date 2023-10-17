#include "main.h"

/**
 * _printf - function that prints values to the stdout
 * @format: The format specifier
 * Return: values count
 */
int _printf(const char *format, ...)
{
	int string_len;
	char character;
	
	va_list elements;
	va_start(elements, format);

	string_len = 0;

	while(*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			string_len++;
		}
		else
		{
			format++;

			if (*format == 'c')
			{
				character = va_arg(elements, int);
				_putchar(character);
				string_len++;
			}
			else if (*format == 's')
			{
				const char *str = va_arg(elements, const char *);

				if (str == NULL)
				{
					str = "(null)";
				}
					while (*str != '\0')
					{
						_putchar(*str);
						str++;
						string_len++;
					}
				}

			}
			else if (*format == '%')
			{
				_putchar('%');
				string_len++;
			}
		}
		format++;
	}
	_putchar('\n');
	va_end(elements);
	return (string_len);
}
