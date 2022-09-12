#include "header.h"
/**
 *_print_X - print a number in hexadecimal with uppercase letters
 *@flist: list to search into the value to print
 *
 *Return: len length of the printed characters
 */
int _print_X(va_list flist)
{
	unsigned int base = 16, c = 1, len = 0, i = 0;
	char w;
	unsigned int n = va_arg(flist, unsigned int);

	if (n < 16)
	{
		if (n >= 10)
			w = exchange_X(n), write(1, &w, 1);
		else
			w = n + '0', write(1, &w, 1);
	}
	else
	{
		while (c > 0)
		{
			if ((n / base) >= 16)
				base *= 16, c++;
			else
			{
				i = n / base;
				if (i > 10)
				{
					w = exchange_X(i), write(1, &w, 1);
					len++, n %= base, base /= 16, c--;
				}
				else
				{
					w = (n / base) + '0', write(1, &w, 1);
					n %= base, base /= 16, len++, c--;
				}
			}
		}
		if (n >= 10)
			w = exchange_X(n), write(1, &w, 1);
		else
			w = n + '0', write(1, &w, 1);
	}
	return (++len);
}
/**
 *exchange_X - exchanges values for letters in hexadecimal
 *@n: number to search its parent in letrer
 *
 *Return: char equivalento to the digit in hexadecimal
 */
char exchange_X(unsigned int n)
{
	int j = 0;
	char *str = "ABCDEF";
	unsigned int str2[6] = {10, 11, 12, 13, 14, 15};

	while (j < 6)
	{
		if (str2[j] == n)
			return (str[j]);
		j++;
	}
	return (-1);
}
