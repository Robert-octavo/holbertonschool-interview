#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */

typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
