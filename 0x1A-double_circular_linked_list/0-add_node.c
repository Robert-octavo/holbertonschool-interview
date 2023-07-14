#include "list.h"

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: pointer to the first element of the list
 * @str: string to be added to the list
 *
 * Return: address of the new element, or NULL if it failed
 */

List *add_node_end(List **head, char *str)
{
	List *new_node, *last_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (!*head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
		return (new_node);
	}

	last_node = (*head)->prev;
	new_node->next = *head;
	new_node->prev = last_node;
	(*head)->prev = new_node;
	last_node->next = new_node;

	return (new_node);
}

/**
 * add_node_begin - adds a new node at the beginning of a list_t list.
 * @head: pointer to the first element of the list
 * @str: string to be added to the list
 *
 * Return: address of the new element, or NULL if it failed
 */

List *add_node_begin(List **head, char *str)
{
	List *new_node, *last_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (!*head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
		return (new_node);
	}

	last_node = (*head)->prev;
	new_node->next = *head;
	new_node->prev = last_node;
	(*head)->prev = new_node;
	last_node->next = new_node;
	*head = new_node;

	return (new_node);
}
