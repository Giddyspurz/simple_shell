#include "header.h"
/**
 * _print_u - convert a decimal in unsigned
 *  @flist: list of arguments int
 *  Return: len
 */
int _print_u(va_list flist)
{
	unsigned int base = 10;
	int c = 1, len = 0;
	unsigned int n = va_arg(flist, unsigned int);
	char w = '\0';

	if (n < 10)
		w = n + '0', write(1, &w, 1);
	else
	{
		while (c > 0)
		{
			if ((n / base) >= 10)
			{
				base *= 10;
				c++;
			}
			else
			{
				w = (n / base) + '0';
				write(1, &w, 1);
				n %= base;
				base /= 10;
				len++;
				c--;
			}
		}
		w = n + '0';
		write(1, &w, 1);
	}
	return (++len);
}
