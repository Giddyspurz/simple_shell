#include "header.h"
/**
 * get_dir - search for variable that have a directory (e.g: HOME, PWD)
 * @envp: array of environment variables
 * @variable: variable with the route to search
 * Return: double pointer to an array of string with the route split
 * (e.g: PWD=/home/usr---->{"PWD", "/home/usr", NULL})
*/
char **get_dir(char **envp, char *variable)
{
	ssize_t i = 0;
	char **aux_str_tok = NULL;

	while (envp[i])
	{
		if (!str_cmp(envp[i], variable, str_len(variable) - 1))
		{
			aux_str_tok = str_tok(envp[i], "=");
			if (!aux_str_tok)
				return (NULL);
			return (aux_str_tok);
		}
		i++;
	}
	return (NULL);
}
/**
 * copy_cwd - copy rute envp.
 * @envp: environment variable.
 * @NEW_WD: new working directory.
 * @length: count length.
 * @header: pointer structure.
 * Return: nothing void.
 */
void copy_cwd(char **envp, char *NEW_WD, int length, ssh *header)
{
	ssize_t i = 0, temp = 0;

	while (envp[i])
	{
		if (!str_cmp(envp[i], "PWD=", 4))
		{
			if (header->OLD_WD != NULL)
				free_PWD(header);
			envp[i] = malloc(sizeof(char) * (length + 5));
			if (!envp[i])
				return;
			envp[i][0] = 'P';
			envp[i][1] = 'W';
			envp[i][2] = 'D';
			envp[i][3] = '=';
			temp = i;
			i = 4;
			while (i < length + 4)
				envp[temp][i] = NEW_WD[i - 4], i++;
			envp[temp][i] = '\0';
			break;
		}
		i++;
	}
}
/**
 * print_error - prints a error message
 * @str: name of the program
 * @aux: aux to check if something is failing
 * Return: void
 */
void print_error(char *str, int aux)
{
	if (aux == -1)
		perror(str);
}
/**
 * _cd - changes the current working directory
 * @header: pointer structure.
 * @copy: copy of buffer string
 * @token: array of pointers to string which is the buffer split it
 * Return: NULL or OLD_WD.
 */
int _cd(char *copy, char **token, ssh *header)
{
	char NEW_WD[LEN_BUFFER] = "\0", *OLD_WD = header->OLD_WD, *PWD = NULL;
	char *HOME = NULL, **temp = NULL;
	int aux_chdir = 0;

	(void)copy;
	if (token[1] == NULL)
	{
		temp = get_dir(header->envp, "HOME=");
		HOME = temp[1];
		aux_chdir = chdir(HOME);
		print_error(header->argv[0], aux_chdir);
	}
	else if (!str_cmp(token[1], "-", 1))
	{
		if (OLD_WD == NULL)
		{
			_printf("%s: cd: OLDPWD not set\n", header->argv[0]);
			header->OLD_WD = NULL;
		}
		else
		{
			aux_chdir = chdir(OLD_WD);
			print_error(header->argv[0], aux_chdir);
		}
	}
	else
	{
		aux_chdir = chdir(token[1]);
		print_error(header->argv[0], aux_chdir);
	}
	if (aux_chdir != -1)
	{
		getcwd(NEW_WD, LEN_BUFFER), temp = get_dir(header->envp, "PWD");
		PWD = temp[1], free(OLD_WD);
		OLD_WD = str_cpy(OLD_WD, PWD, str_len(PWD));
		copy_cwd(header->envp, NEW_WD, str_len(NEW_WD), header);
		free_malloc(temp);
		header->OLD_WD = OLD_WD;
	}
	return (0);
}
