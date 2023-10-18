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

	while(*format)
	{
		if (*format == '%')
		{
		format++;
			if (*format == '\0')
			{
				return (-1);
			}
			if (*format == '%')
			{
				_putchar('%');
				string_len++;
			}
			else if (*format =='c')
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
				else
				{
					while (*str)
					{
						_putchar(*str);
						str++;
						string_len++;
					}
				}

			}
			else
			{
				_putchar(*format);
				string_len++;
			}
		format++;
	}
	va_end(elements);
	}
	return (string_len);
}
