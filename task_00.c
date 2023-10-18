#include "main.h"

/**
 * _printf - mimics printf
 * @format: the character it takes
 * Return: The result
 */
int _printf(const char *format, ...)
{
	int char_count = 0;

	va_list args;

	va_start(args, format);

	while(*format)
	{
		if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' || *(format + 1) == '%'))
		{
			putchar((*(format + 1) == 'c') ? va_arg(args, int) : (*format == '%') ? '%' : 0);
			char_count += (*(format + 1) == 's') ? printf("%s", va_arg(args, char *)) : 1;
			format++;
		}
		else
		{
			putchar(*format);
			char_count++;
		}
		format++;
	}
	va_end(args);
	return (char_count);
}
