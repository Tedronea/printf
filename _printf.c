#include "main.h"
#include <stdarg.h>
/**
 * _printf - Custom printf function
 * @format: character array to print
 * @...: variable arguments to print
 * Return: 0 if function runs without errors
 */
int _printf(const char *format, ...)
{
	char c;                      /** stores each character if flag is %c */
	char *s;                     /** stores each character if flag is %s */
	int d;                     /** stores each character if flag is %d */
	int i;                     /** stores each character if flag is %i */
	va_list ls;

	va_start(ls, format);

	while (*format != '\0')      /** while EOF isnt reached */
	{
		if (*format == '%')         /** if character is % */
		{
			format += 1;        /** go to next character */

			if (*format == 'c')  /** if next character is c */
			{
				c = va_arg(ls, int); /** fetch the next argument in va_list ls */
				_putchar(c);           /** print that argument's value */
				format += 1;           /** continue to the next char in the program */
			}
			if (*format == 's')               /** if next character is s */
			{
				s = va_arg(ls, char *); /** fetch string and store in variable s */
				while (*s != '\0')        /** while EOF isnt reached */
				{
					_putchar(*s);     /** print character */
					s += 1;           /** move to next character */
				}
				format += 1; /** continue printing the rest of the string */
			}
			if (*format == "i" || *format == "d") /** if an integer or a decimal */
			{
				d = va_arg(ls, int);  /** store argument in va_list */
				_putchar(d);   /** print the value of the argument */
				format++;   /** go to next character */
			}
		}
		_putchar(*format);
		format += 1;
	}
	return (0);
}
