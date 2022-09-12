#include "header.h"
/**
 * _print_o - convert a decimal in a base 8
 *  @flist: list of arguments int
 *  Return: len
 */
int _print_o(va_list flist)
{
	long int base = 8;
	long int n = (long int)va_arg(flist, unsigned int);
	int c = 1, len = 0;
	char w = '\0';

	if (n < 8)
	{
		w = n + '0', write(1, &w, 1);
	}
	else
	{
		while (c > 0)
		{
			if ((n / base) >= 8)
			{
				base *= 8;
				c++;
			}
			else
			{
				w = (n / base) + '0';
				write(1, &w, 1);
				n %= base;
				base /= 8;
				len++;
				c--;
			}
		}
		w = n + '0';
		write(1, &w, 1);
	}
	return (++len);
}
