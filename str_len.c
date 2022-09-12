#include "header.h"
/**
 * str_len - Find the length of a string including the null character
 * @str: String
 * Return: i length of the string
 */
int str_len(char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}
