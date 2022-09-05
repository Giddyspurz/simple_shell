

#include "header.h"
/**
 * free_commands - frees the command's list
 * @header: struct with global variables
 * Return: void
 */
void free_commands(ssh *header)
{
	commands *aux = NULL;

	aux = header->head_cmd;
	while (aux)
	{
		header->head_cmd = aux->next;
		free_malloc(aux->split_command);
		free(aux);
		aux = header->head_cmd;
	}
}
/**
 * identify_directory - identifies if the first argument of the buffer is a
 * directory or not
 * @to_search: first argument of the buffer.
 * @envp: array of the strings with environment variables.
 * Return: pathname or null.
 */
char *identify_directory(char *to_search, char **envp)
{
	int i = 0;
	char *pathname = NULL;

	if (to_search[i] == '/' || to_search[i] == '.')
	{
		return (NULL);
	}
	else
	{
		pathname = _PATH(to_search, envp);
	}
	return (pathname);
}
/**
 * super_free - frees everything
 * @header: struct with global variables
 * @pathname: string with a pathname
 *Return: void
 */
void super_free(ssh *header, char *pathname)
{
	free_malloc(header->arguments);
	free(pathname), free(header->buffer);
	free(header->OLD_WD), free_PWD(header);
	free_listint(header->head);
	free_commands(header), free(header);
}
/**
 * _execve - executes a command if the command exist in the direcotires stored
 * in the variable PATH
 * @header: struct pointer.
 * Return: void
 */
int _execve(ssh *header)
{
	pid_t aux_fork = 0;
	int auxexe = 0, aux_wait = 0, status_wait = 0, aux_check = 0, i = 0;
	char *pathname = NULL;
	commands *aux = NULL;

	aux = header->head_cmd;
	while (aux)
	{
		aux_check = check_buffer(header->arguments[i], header);
		if (aux_check == 1)
		{
			aux_fork = fork();
			aux_wait = wait(&status_wait);
			if (aux_fork != 0)
				_perror(aux_wait, header->argv[0]);
			if (aux_fork == 0)
			{
				pathname = identify_directory(
					aux->split_command[0], header->envp);
				if (pathname == NULL)
					auxexe = execve(aux->split_command[0],
					aux->split_command, header->envp);
				else
					auxexe = execve(pathname,
					aux->split_command, header->envp);
				if (auxexe == -1)
				{
					_printf("%s: command %s not found\n",
						header->argv[0],
						aux->split_command[0]);
					super_free(header, pathname);
					exit(errno);
				}
			}
		}
		aux = aux->next, i++, status_wait = aux_check == 0 ? 0 :
		aux_check == 2 ? 2 : WEXITSTATUS(status_wait);
	}
	return (status_wait == 2 ? aux_check == 2 ? 2 : 127 : status_wait);
}
