#include "main.h"

/* @print: print a number*/

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

