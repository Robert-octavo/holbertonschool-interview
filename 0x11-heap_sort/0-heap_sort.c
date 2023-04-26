#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void heap_sort(int *array, size_t size)
{
    size_t i;
    int temp;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2; i > 0; i--)
        heapify(array, size, i - 1, size);

    for (i = size - 1; i > 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        print_array(array, size);
        heapify(array, i, 0, size);
    }
}

/**
 * heapify - Heapifies a binary tree
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @i: Index of the root node
 * @size_orig: Original size of the array
 */

void heapify(int *array, size_t size, size_t i, size_t size_orig)
{
    size_t largest, left, right;
    int temp;

    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        print_array(array, size_orig);
        heapify(array, size, largest, size_orig);
    }
}
