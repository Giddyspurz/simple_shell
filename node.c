#include "header.h"
/**
 * add_node - function that add node to save position to search env.
 * @head: take structure arguments pointer.
 * @setenv: aux to set env variable.
 * Return: new node with position.
 */
node *add_node(node **head, char *setenv)
{
	node *new_node;

	new_node = malloc(sizeof(node));
	if (!new_node)
		return (NULL);
	new_node->setenv = setenv;
	if (!*head)
		*head = new_node, new_node->next = NULL;
	else
		new_node->next = *head, *head = new_node;

	return (new_node);
}
/**
 *free_listint - frees a listint_t list
 *@head: head of the list
 *Return: void
 */
void free_listint(node *head)
{
	node *aux;

	aux = head;
	while (head)
		head = head->next, free(aux->setenv), free(aux), aux = head;
}
/**
 *delete_nodein - deletes the node at index of a listint_t
 *@head: head of the list
 *@index: index
 *Return: -1 if the operation fails or 1 if it succeeded
 */
int delete_nodein(node **head, unsigned int index)
{
	unsigned int i = 0;
	node *aux, *aux2;

	aux = *head;
	if (!index && *head)
		*head = (*head)->next, free(aux->setenv), free(aux);
	else
	{
		while (aux && i < index - 1)
			aux = aux->next, i++;
		if (!aux)
			;
		else
		{
			aux2 = aux->next, aux->next = aux->next->next;
			free(aux2->setenv), free(aux2);
		}
	}

	return (!aux ? -1 : 1);
}
/**
 * owrenv - fucntion that overwrite a variable existent.
 * @header: pointer structure header.
 * @name: pointer name variable to search.
 * @nvar: pointer new variable to change.
 * Return: void nothing.
 */
void owrenv(ssh *header, char *name, char *nvar)
{
	char *envnew = NULL;
	int i = 0, j = 0, temp = 0;

	envnew = malloc(sizeof(char) * (str_len(name) + str_len(nvar) + 2));
	if (!envnew)
	{
		_printf("Error: can not allocate memory\n");
		exit(EXIT_FAILURE);
	}
	envnew[0] = '\0';
	i = _searchenv2(name);
	header->envp[i] = envnew, temp = i, i = 0;
	while (name[i])
		header->envp[temp][i] = name[i], i++;
	header->envp[temp][i] = '=', i++;
	while (nvar[j])
		header->envp[temp][i] = nvar[j], i++, j++;
	header->envp[temp][i] = '\0';
	header->head = add_node(&header->head, header->envp[temp]);
	temp++;
	header->envp[temp] = NULL;
}
/**
 * addenv - function that add enviroment variable.
 * @header: pointer structure header.
 * @name: name variable environment.
 * @nvar: name new variable env.
 * @envnew: aux new variable env.
 * Return: succes all good.
 */
int addenv(ssh *header, char *name, char *nvar, char *envnew)
{
	size_t i = 0, j = 0, temp = 0;

	envnew[0] = '\0';
	while (header->envp[i]) /* search the end of envp */
		++i;
	header->envp[i] = envnew, temp = i, i = 0;
	while (name[i])
		header->envp[temp][i] = name[i], i++;
	header->envp[temp][i] = '=', i++;
	while (nvar[j])
		header->envp[temp][i] = nvar[j], i++, j++;
	header->envp[temp][i] = '\0';
	header->head = add_node(&header->head, header->envp[temp]);
	temp++;
	header->envp[temp] = NULL;
	return (EXIT_SUCCESS);
}
