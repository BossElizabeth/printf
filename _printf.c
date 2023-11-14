#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - to emulate the real printf function.
 * @format: Formated string.
 *
 * Return: shows how many characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			switch (*format)
			{
			case 'c':
				count += putchar(va_arg(args, int));
				break;
			case 's':
				count += _printstr(va_arg(args, char *));
				break;
			case '%':
				count += putchar('%');
				break;
			default:
				count += putchar('%');
				count += putchar(*format);
			}
		}
		else
		{
			count += putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}

/**
 * _printstr - combine characters to produce a string.
 * @str: String to display.
 *
 * Return: how many characters printed.
 */
int _printstr(const char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
	{
		count += putchar(*str);
		str++;
	}

	return (count);
}
