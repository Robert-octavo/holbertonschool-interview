#include "binary_trees.h"

/**
 * heap_size - get size of heap
 * @root: root of heap
 * Return: size of heap
 */

int heap_size(heap_t *root)
{
	int size = 0;

	if (!root)
		return (0);
	size = heap_size(root->left) + heap_size(root->right) + 1;
	return (size);
}

/**
 * get_last_node - get last node in heap
 * @root: root of heap
 * Return: last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *node = NULL;
	int size = 0, i = 0;

	size = heap_size(root);
	for (i = 1; i <= size; i <<= 1)
		;
	i >>= 2;
	for (node = root; i > 0; i >>= 1)
	{
		if (size & i)
			node = node->right;
		else
			node = node->left;
	}
	return (node);
}

/**
 * heapify - heapify tree
 * @root: root of heap
 */
void heapify(heap_t *root)
{
	heap_t *node = NULL;
	int temp = 0;

	if (!root)
		return;
	node = root;
	while (node->left)
	{
		if (!node->right || node->left->n > node->right->n)
		{
			if (node->n < node->left->n)
			{
				temp = node->n;
				node->n = node->left->n;
				node->left->n = temp;
			}
			node = node->left;
		}
		else
		{
			if (node->n < node->right->n)
			{
				temp = node->n;
				node->n = node->right->n;
				node->right->n = temp;
			}
			node = node->right;
		}
	}
}

/**
 * heap_extract - extract root node from heap
 * @root: root of heap
 * Return: value of root node
 */
int heap_extract(heap_t **root)
{
	heap_t *node = NULL;
	int value = 0;

	if (!root || !*root)
		return (0);
	node = *root;
	value = node->n;
	if (!node->left && !node->right)
	{
		*root = NULL;
		free(node);
		return (value);
	}
	node = get_last_node(*root);
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	(*root)->n = node->n;
	free(node);
	heapify(*root);
	return (value);
}
