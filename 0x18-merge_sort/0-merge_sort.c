#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	merge_sort_rec(array, size, tmp);
	free(tmp);
}

/**
 * merge_sort_rec - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 * @tmp: temp array
 */

void merge_sort_rec(int *array, size_t size, int *tmp)
{
	size_t mid;

	if (size < 2)
		return;

	mid = size / 2;

	merge_sort_rec(array, mid, tmp);
	merge_sort_rec(array + mid, size - mid, tmp);

	merge(array, size, mid, tmp);
}

/**
 * merge - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 * @mid: mid point
 * @tmp: temp array
 */

void merge(int *array, size_t size, size_t mid, int *tmp)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);

	for (i = 0, j = mid, k = 0; k < size; k++)
	{
		if (j == size)
		{
			tmp[k] = array[i];
			i++;
		}
		else if (i == mid)
		{
			tmp[k] = array[j];
			j++;
		}
		else if (array[j] < array[i])
		{
			tmp[k] = array[j];
			j++;
		}
		else
		{
			tmp[k] = array[i];
			i++;
		}
	}

	for (i = 0; i < size; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(array, size);
}
