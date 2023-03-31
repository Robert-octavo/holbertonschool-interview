#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t mid;

	if (array == NULL || size == 0)
		return (NULL);

	mid = (size - 1) / 2;
	root = calloc(1, sizeof(avl_t));
	if (root == NULL)
		return (NULL);

	root->n = array[mid];
	root->parent = NULL;

	if (mid > 0)
		root->left = sorted_array_to_avl(array, mid);
	if (mid + 1 < size)
		root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;

	return (root);
}
