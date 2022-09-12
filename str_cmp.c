#include "header.h"
/**
 * str_cmp - compare if the first bytes of str2 are include in str
 * @str: first string to look into in
 * @str2: second string to look for
 * @bytes: count num bytes.
 * Return: EXIT_SUCCES if str2 is contained in str or EXIT_FAILURE on failure
 */
ssize_t str_cmp(char *str, char *str2, int bytes)
{
	int i = 0;

	while (str[i] == str2[i] && i < bytes)
		i++;
	if (i == bytes)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
