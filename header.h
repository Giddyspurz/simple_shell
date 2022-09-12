#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdarg.h>
#include <limits.h>


#define LEN_BUFFER 1024
extern char **environ;
extern int HANDLE_SIGNAL;

/**
 * struct simple_shell - struct with global variables
 * @argv: array arguments.
 * @envp: take envorinment variable.
 * @buffer: buffer variable.
 * @arguments: arguments.
 * @OLD_WD: OLD WORKING DIRECTORY
 * @head: pointer to the head node structure.
 * @head_cmd: pointer to the head node of the command's list
 * @flag_exit: a flag for the exit command
 */
typedef struct simple_shell
{
	char **argv;
	char **envp;
	char *buffer;
	char **arguments;
	char *OLD_WD;
	struct node *head;
	struct commands *head_cmd;
} ssh;
/**
 * struct node - structure list nodes.
 * @setenv: setenv value add or modify.
 * @next: pointer to the next node.
 */
typedef struct node
{
	char *setenv;
	struct node *next;
} node;
/**
 * struct comparisons - struct compare function name between function
 * @comp: pointer comparator with function.
 * @function_int: pointer to the fucntions.
 */
typedef struct comparisons
{
	char *comp;
	int (*function_int)();
} comparison_id;
/**
 * struct commands - struct to create a list of diferents commands supplied to
 * the program
 * @split_command: array of pointers to strings with command and command's
 * arguments
 * @next: pointer to the next node
 */
typedef struct commands
{
	char **split_command;
	struct commands *next;
} commands;
/**
 * struct id_function - structure of functions and id
 * @id: identifiers of conversion
 * @f:function pointer of id
 */
typedef struct id_function
{
	char id;
	int (*f)();
} function_t;

char **str_tok(char *buffer, char *delimiter);
char *str_cpy(char *dest, char *src, int bytes);
int str_len(char *str);
size_t _strlen(const char *str);
int _strncmp(char *s1, char *s2, int n);
char *_strchr(char *str, char c);
int _atoi(char *s);
void free_malloc(char **str);
void free_PWD(ssh *header);
void free_listint(node *head);
void free_commands(ssh *header);
void super_free(ssh *header, char *pathname);
int _cd(char *copy, char **token, ssh *header);
int _envset(char *copy, char **, ssh *);
int _unsetenv(char *copy, char **token, ssh *header);
char *_PATH(char *arguments, char **envp);
void _error(char *s);
void _perror(int aux, const char *argv);
void print_error(char *str, int aux);
ssize_t str_cmp(char *str, char *str2, int bytes);
int check_buffer(char *buffer, ssh *header);
char *_searchenv(char *name);
int _searchenv2(char *name);
int _strncmp(char *s1, char *s2, int n);
int addenv(ssh *header, char *name, char *nvar, char *envnew);
void owrenv(ssh *header, char *name, char *nvar);
void set_buffer(char *buffer, ssize_t aux_read);
void split_buffer(ssh *header);
int _execve(ssh *header);
int delete_nodein(node **head, unsigned int index);
commands *add_node_end(commands **head, char **command);
int exit_(char *, char **, ssh *);
int _env(char *, char **, ssh *);
node *add_node(node **head, char *setenv);
void handle_signal(int _signal);
int _prompt(ssh *header);
ssh *set_struct(ssh *header, char **argv, char **envp);
int cmp_char_str(char _char, char *_str);
int count_words(char *str, char *delimiter);
int length_word(char *str, char *delimiter, int flag);
void copy_word(char *str, char *str_tok, int flag, char *delimiter);
char **get_dir(char **envp, char *variable);
void copy_cwd(char **envp, char *NEW_WD, int length, ssh *header);
char *identify_directory(char *to_search, char **envp);
int _printf(const char *format, ...);
int _putchar(char c);
int _printf_c(va_list flist);
int _printf_s(va_list flist);
int print_number(va_list flist);
int _print_b(va_list flist);
int _print_o(va_list flist);
int _print_u(va_list flist);
int _print_x(va_list flist);
char exchange_x(unsigned int n);
int _print_X(va_list flist);
char exchange_X(unsigned int n);
#endif
