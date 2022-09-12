#include "header.h"
/**
 * _strlen - count the lenght to string *s
 * @str: pointer string.
 * Return: lenght.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len])
		len++;
	return (len);
}
/**
 * _strncmp - compare strings and size
 * @s1: first string pointer.
 * @s2: second string pointer.
 * @n: lenght of string to compare.
 * Return: integer value of characters.
 */
int _strncmp(char *s1, char *s2, int n)
{
	char str1, str2;

	while (n > 0)
	{
		str1 = *s1++;
		str2 = *s2++;
		if (str1 == '\0' || str1 != str2)
			return (str1 - str2);
		n--;
	}
	return (str1 - str2);
}
/**
 * _strchr - locates character in a string
 * @str: string to compare.
 * @c: character to copare.
 * Return: pointer firs occurence success or NULL fail.
 */
char *_strchr(char *str, char c)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (ptr = str; *ptr; ptr++)
	{
		if (*ptr == c)
			return (ptr);
	}
	return (NULL);
}
/**
 * _unsetenv - function that delete the variable name from environment
 * @header: pointer structure.
 * @copy: save the copy buffer and allocate memory.
 * @token: double pointer take token.
 * Return: 0 on success or -1 error.
 */
int _unsetenv(char *copy, char **token, ssh *header)
{
	char **env = NULL, *name = token[1];
	node *aux = header->head;
	int len = 0, i = 0, len2 = 0;

	(void)copy;
	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	len = str_len(name);
	env = environ;
	while (*env != NULL)
	{
		if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			while (*env != NULL)
			{
				while (aux)
				{
					len2 = str_len(name);
					if (!_strncmp(aux->setenv, name, len2))
					{
						delete_nodein(&header->head, i);
						break;
					}
					aux = aux->next, i++;
				}
				*env = *(env + 1);
				env++;
			}
		}
		else
		{
			env++;
		}
	}
	return (EXIT_SUCCESS);
}
