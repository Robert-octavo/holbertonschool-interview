#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: pointer on the first node where value is located, or NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = NULL, *next = NULL;

	if (list == NULL)
		return (NULL);

	while (list->express != NULL)
	{
		prev = list;
		list = list->express;
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (list->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu] \n",
				   prev->index, list->index);
			break;
		}
	}

	if (list->express == NULL)
	{
		prev = list;
		while (list->next != NULL)
			list = list->next;
		printf("Value found between indexes [%lu] and [%lu] \n",
			   prev->index, list->index);
	}

	while (prev != NULL)
	{
		printf("Value checked at index [%lu] = [%d] \n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
