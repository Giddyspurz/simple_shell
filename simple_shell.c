#include "header.h"
/**
 * handle_signal - function with the handle signals.
 * @_signal: take signal to print.
 * Return: nothing void.
 */
void handle_signal(int _signal)
{
	int HANDLE_SIGNAL = 1;

	(void)HANDLE_SIGNAL;
	if (_signal != SIGINT && _signal != SIGTSTP)
		HANDLE_SIGNAL = 0;
	else
		write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * _prompt - make subprocess to shell - prompt( father and child)
 * @header: struct pointer.
 * Return: nothing void.
 */
int _prompt(ssh *header)
{
	ssize_t aux_read = 1, aux_write = 0;
	char buffer[LEN_BUFFER] = "\0";
	size_t bytes = LEN_BUFFER;
	int HANDLE_SIGNAL = 1, status = 0;

	signal(SIGINT, handle_signal);
	while (aux_read && HANDLE_SIGNAL)
	{
		if (isatty(STDIN_FILENO) == 1)
			aux_write = write(STDOUT_FILENO, "$ ", 2);
		_perror(aux_write, header->argv[0]);
		aux_read = read(STDIN_FILENO, &buffer, bytes);
		set_buffer(buffer, aux_read);
		header->buffer = str_cpy(header->buffer, buffer, aux_read);
		split_buffer(header);
		if (aux_read)
		{
			_perror(aux_read, header->argv[0]);
			status = _execve(header);
		}
		free_malloc(header->arguments), free(header->buffer);
		free_commands(header), header->buffer = NULL;
	}
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
	free(header->OLD_WD);
	return (status);
}
/**
 * set_struct - inicialization variables structure.
 * @header: pointer structure.
 * @argv: take argv structure.
 * @envp: enviroment variable
 * Return: header structure ssh.
 */
ssh *set_struct(ssh *header, char **argv, char **envp)
{
	header->argv = argv;
	header->envp = envp;
	header->buffer = NULL;
	header->arguments = NULL;
	header->OLD_WD = NULL;
	header->head = NULL;
	header->head_cmd = NULL;
	return (header);
}
/**
 * free_PWD - free variable PWD
 * @header: pointer structure.
 * Return: nothing void.
 */
void free_PWD(ssh *header)
{
	int i = 0;

	if (header->OLD_WD != NULL)
	{
		while (header->envp[i])
		{
			if (!str_cmp(header->envp[i], "PWD=", 4))
			{
				free(header->envp[i]);
				break;
			}
			i++;
		}
	}
}
/**
 * main - main shell.
 * @argc: count arguments.
 * @argv: array arguments.
 * @envp: environment variables.
 * Return: 0 success or errors
 */
int main(int argc, char **argv, char **envp)
{
	ssh *header = NULL;
	int status = 0;

	if (argc != 1)
		_error("Error: usage ./hsh - too many arguments");
	header = malloc(sizeof(ssh)); /*DO VALIDATION*/
	header = set_struct(header, argv, envp);
	status = _prompt(header);
	free_PWD(header);
	free_listint(header->head);
	free_commands(header);
	free(header);

	return (status);
}
