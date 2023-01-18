#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *current;
	int i, j, len, *arr;

	if (head == NULL || *head == NULL)
		return (1);
	current = *head;
	len = 0;
	while (current != NULL) /* */
	{
		current = current->next;
		len++;
	}
	arr = malloc(sizeof(int) * len);
	if (arr == NULL)
		return (0);
	current = *head;
	for (i = 0; i < len; i++)
	{
		arr[i] = current->n;
		current = current->next;
	}
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		if (arr[i] != arr[j])
		{
			free(arr);
			return (0);
		}
	}
	free(arr);
	return (1);
}
