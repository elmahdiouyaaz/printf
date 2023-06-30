#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - Prints formatted output to stdout.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' */

			/* Check for conversion specifier characters */
			switch (*format)
			{
			case 'c':
			{
				int c = va_arg(args, int);
				putchar(c);
				count++;
				break;
			}
			case 's':
			{
				char *s = va_arg(args, char *);
				fputs(s, stdout);
				count += strlen(s);
				break;
			}
			case '%':
			{
				putchar('%');
				count++;
				break;
			}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);

	return count;
}

