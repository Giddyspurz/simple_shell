#include "header.h"
/**
 *_atoi - convert a string to an integer
 *@s: pointer to a string of characters
 *
 *Return: integer
 */
int _atoi(char *s)
{
	int sign, num, i;

	sign = num = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign++;
		else if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + (s[i] - '0');
		else if (num > 0)
			break;
	}
	if (sign % 2 == 0)
		return (num);
	else
		return (num *= -1);
}
