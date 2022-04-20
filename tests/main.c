#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

void _print(long n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
		_print(n / 10);
	_putchar(n % 10 + '0');
}

int _printf(const char *format, ...)
{

	char c;  
	char *s;
	int i;  
	va_list ls; 
	va_start(ls, format); 

	while (*format != '\0')
	{
		if(*format == '%')
		{
            
			format++;
            
		
			if(*format == 'c')
			{
				c = va_arg(ls, int);
				_putchar(c);
				format++; 
			}
			if(*format == 's')
			{
				s = va_arg(ls, char *);
				while (*s != '\0')
				{
					_putchar(*s);
					s++;
				}
				format++;
			}
			if (*format == 'i' || *format == 'd') /** if an integer or a decimal */
			{
				i = va_arg(ls, int);  /** store argument in va_list */
				_print(i);   /** print the value of the argument */
				format++;   /** go to next character */
			}
		}
		_putchar(*format);
		format++;
	}

	va_end(ls);

	return 0;
}

int main(){
    _printf("Code a %d here\n", 5435);
	return (0);
}

