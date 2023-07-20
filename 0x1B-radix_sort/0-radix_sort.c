#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
	int *tmp, max = 0, exp = 1, i, j, k;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	while (max / exp > 0)
	{
		int bucket[10] = {0};

		for (j = 0; j < (int)size; j++)
			bucket[array[j] / exp % 10]++;

		for (k = 1; k < 10; k++)
			bucket[k] += bucket[k - 1];

		for (j = (int)size - 1; j >= 0; j--)
			tmp[--bucket[array[j] / exp % 10]] = array[j];

		for (j = 0; j < (int)size; j++)
			array[j] = tmp[j];

		print_array(array, size);
		exp *= 10;
	}
	free(tmp);
}
