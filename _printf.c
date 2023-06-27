#include "main.h"

/**
 *  *_printf - print string with argument
 *   *@format: string and specfier
 *    *Return: number of specfier
 *     */

int _printf(const char *format, ...)
{
		int count = 0;

			va_list args;

				va_start(args, format);

					if (*format == '\0' || (*format == '%' && *(format + 1) == '\0'))
							{
										return (-1);
											}

						while (*format)
								{
											if (*format != '%')
														{
																		_putchar(*format);
																				}
													else
																{
																				++format;
																							if (*format == '\0')
																											{
																																break;
																																			}
																										if (*format == '%')
																														{
																																			_putchar('%');
																																							count++;
																																										}
																													else if (*format == 'c')
																																	{
																																						_putchar((char)va_arg(args, int));
																																										count++;
																																													}
																															}
															format++;
																}
							return (0);
}

/**
 *  *_putchar - print character
 *   *@c: character
 *    *Return: void
 *     */

void _putchar(char c)
{
		write(1, &c, 1);
}
