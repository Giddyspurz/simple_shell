#include "header.h"
/**
 * compare_str - search word PATH in environment
 * @str: string with environment.
 * @PATH: string with word PATH.
 *Return: 1 on success or 0 on failure
 */
int compare_str(char *str, char *PATH)
{
	while (*PATH && *str)
	{
		if (*PATH == *str)
			PATH++, str++;
		else
			return (0);
	}

	return (1);
}
/**
 * add_argv - adds / plus command name to a ditectory (e.g. /bin ---> /bin/ls)
 * @argv: command name
 * @str_tok: directory
 * Return: pointer to the pathname of the command
 */
char *add_argv(char *argv, char *str_tok) /* argv = pwd buffer = "+/ls -la" */
{
	int i = 0, j = 0, len1 = str_len(argv), len2 = str_len(str_tok);
	char *buff;

	buff = malloc(sizeof(char *) * (len1 + len2 + 2));
	if (!buff)
	{
		free(buff);
		_printf("Error: can not allocate memory\n");
		exit(EXIT_FAILURE);
	}
	while (str_tok[i])
		buff[i] = str_tok[i], i++;
	buff[i] = '/', i++;
	while (argv[j])
	{
		buff[i + j] = argv[j], j++;
	}
	buff[i + j] = '\0';

	return (buff);

}
/**
 * count_env - counts the number of environment variables
 * @envp: array of strings with the enviroment variables
 * Return: number of envorment variables
 */
int count_env(char **envp)
{
	int i = 0;

	while (envp[i])
		i++;

	return (i);
}
/**
 * cpy_dptr - copy a double pointer content to another double pointer
 * @dest: first array - string.
 * @from: second array - string.
 * Return: void nothing.
 */
void cpy_dptr(char **dest, char **from)
{
	int i = 0;

	while (from[i])
	{
		dest[i] = malloc(sizeof(char) * (strlen(from[i]) + 1));
		if (!dest[i])
		{
			free_malloc(dest);
			_printf("Error: can not allocate memory\n");
			exit(EXIT_FAILURE);
		}
		strcpy(dest[i], from[i]);
		i++;
	}
}
/**
 * copy_strtok - copy strtok in aux.
 * @aux_strtok: pointer strtok values.
 * Return: aux char *.
 */
char *copy_strtok(char *aux_strtok)
{
	int len = 0, i = 0;
	char *aux;

	while (aux_strtok[len] != '\0')
		len++;
	aux = malloc(sizeof(char) * (len + 1));
	if (!aux)
	{
		_printf("Error: can not allocate memory\n");
		exit(EXIT_FAILURE);
	}
	while (i < len)
	{
		aux[i] = aux_strtok[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
/**
 * _PATH - search for a command in the PATH variable
 * @arguments: pointer past arguments.
 * @envp: double pointer past the env variable.
 * Return: NULL or exit.
 */
char *_PATH(char *arguments, char **envp)
{
	int aux_stat_2 = 0, aux_comp = 0, number_env = 0, i = 0;
	char *PATH = "PATH=", *aux_stat = NULL, **aux_strtok = NULL;
	char **env = NULL;

	number_env = count_env(envp);
	env = malloc(sizeof(char *) * (number_env + 1));
	if (!env)
	{
		free_malloc(env);
		_printf("Error: can not allocate memory\n");
		exit(EXIT_FAILURE);
	}
	while (i < number_env + 1)
		env[i] = NULL, i++;
	cpy_dptr(env, envp);
	i = 0;
	while (env[i] != NULL)
	{
		aux_comp = compare_str(env[i], PATH);/* Look for PATH in env */
		if (aux_comp == 1)
			break;
		i++;
	}
	/* We have env[i] = PATH */
	aux_strtok = str_tok(env[i], " =:"); /* recommended to work with copy */
	i = 0;
	while (aux_strtok[i] != NULL)
	{
		/*  add /command return directory/command */
		aux_stat = add_argv(arguments, aux_strtok[i]);
		/* look for directory/command */
		aux_stat_2 = access(aux_stat, X_OK);
		if (aux_stat_2 == 0)
		{
			free_malloc(aux_strtok);
			return (aux_stat);
		}
		i++;
		free(aux_stat);
	}
	free_malloc(aux_strtok);
	free_malloc(env);
	return (NULL);
}
