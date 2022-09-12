#include "header.h"
/**
 * _searchenv - take the pointer to an environment variable
 * @name: variable name.
 * Return: exist pointer to variable, or NULL.
 */
char *_searchenv(char *name)
{
	char **env;
	int len;

	env = environ;
	len = str_len(name);
	while (*env != NULL)
	{
		if (_strncmp(*env, name, len) == 0)
			return (*env);
		env++;
	}
	return (NULL);
}
/**
 * _envset - add or modify environment var.
 * @header: take structure data.
 * Return: name of variable.
 */
int _envset(char *copy, char **tok, ssh *header)
{
	char *nvar = NULL, *name = NULL;
	char *envnew = NULL;
	int len = 0, len2 = 0;

	(void)copy;
	name = tok[1], nvar = tok[2];
	if (nvar == NULL || name == NULL) /* setenv hola=mundo */
	{
		return (-1);
	}
	len = str_len(name), len2 = str_len(nvar);
	if (_searchenv(name) == NULL)
	{
		envnew = malloc(sizeof(char) * (len + len2 + 2));
		if (!envnew)
		{
			free(envnew);
			_printf("Error: can not allocate memory\n");
			exit(EXIT_FAILURE);
		}
		if (!addenv(header, name, nvar, envnew))
		{
			return (EXIT_SUCCESS);
		}
	}
	else
	{
		if (nvar == NULL)
			;
		else
		{
			owrenv(header, name, nvar);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}
/**
 * _searchenv2 - take the pointer to an environment variable
 * @name: variable name.
 * Return: integer.
 */
int _searchenv2(char *name)
{
	char **env;
	int len = 0, i = 0;

	env = environ;
	len = str_len(name);
	while (env[i] != NULL)
	{
		if (_strncmp(env[i], name, len) == 0)
			return (i);
		i++;
	}
	return (0);
}
