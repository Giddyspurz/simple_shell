#include "header.h"
/**
 * free_malloc - function that free malloc.
 * @str: pointer that travel to malloc.
 * Return: nothing.
 */
void free_malloc(char **str)
{
	unsigned int i = 0;

	if (str == NULL)
	{
		return;
	}
	else
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		if (str[i] == NULL)
		{
			free(str[i]);
		}
	}
	free(str);
}
