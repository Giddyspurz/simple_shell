#include "header.h"
/**
 * _error - print error message and exit with a number status
 * @s: pointer to error message
 * Return: void
 */
void _error(char *s)
{
	write(STDERR_FILENO, s, str_len(s));
	exit(EXIT_FAILURE);
}
/**
 * _perror - check for a condition and print error message and exit with a
 * EXIT FAILURE
 * @aux: condition to check
 * @argv: name of the program
 * Return: void
 */
void _perror(int aux, const char *argv)
{
	if (aux == -1)
	{
		perror(argv);
		exit(EXIT_FAILURE);
	}
}
