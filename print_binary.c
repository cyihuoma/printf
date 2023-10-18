#include "main.h"

/**
 * _printf - function that produces output according to format
 * @format: The format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int int_len = 0;
	int num;
	unsigned int u_num;
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
			num = va_arg(elements, int);
			u_num = num;
			i = 0;

			if (num == 0)
			{
				u_num = UINT_MAX + num + 1;
			}

			if (u_num == 0)
			{
				_putchar('0');
				int_len++;
			}
			else
			{
				while (u_num > 0)
				{
					bit = u_num % 2;
					binary[i] = bit;
					u_num /= 2;
					i++;
				}
				for(i -=1; i >= 0; i--)
				{
					_putchar(binary[i] + '0');
					int_len++;
				}
			}
		}
		}
		format++;
	}
	va_end(elements);
	return (int_len);
}
				

