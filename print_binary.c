#include "main.h"

/**
 * _printf - function that produces output according to format
 * @format: The format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int int_len = 0;
	unsigned int num;
	int bit, binary[32], i;
	va_list elements;
	va_start(elements, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			int_len++;
		}
		else
		{
			format++;
			if (*format == 'b')
			{
			num = va_arg(elements, unsigned int);
			i = 0;
			
			if (num == 0)
			{
				_putchar('0');
				int_len++;
			}
			else
			{
				if (num & (1 <<31))
				{
					num = UINT_MAX - num + 1;
				}
				while (num > 0)
				{
					bit = num % 2;
					binary[i] = bit;
					num /= 2;
					i++;
				}
				for(i -=1; i >= 0; i--)
				{
					_putchar(binary[i] + '0');
					int_len++;
				}
			}
		}
			else
			{
				;
			}
		}
		format++;
	}
	va_end(elements);
	return (int_len);
}
				

