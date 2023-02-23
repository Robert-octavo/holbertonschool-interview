#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers
 * @size: number of elements in array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else
		slide_right(line, size);
	return (1);
}

/**
 * slide_left - slides and merges an array of integers to the left
 *
 * @line: points to an array of integers
 * @size: size of array
 */

void slide_left(int *line, size_t size)
{
	size_t i, j, k;
	int temp;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
		{
			for (j = i; j < size; j++)
			{
				if (line[j] != 0)
				{
					temp = line[i];
					line[i] = line[j];
					line[j] = temp;
					break;
				}
			}
		}
	}
	for (k = 0; k < size - 1; k++)
	{
		if (line[k] == line[k + 1])
		{
			line[k] = line[k] + line[k + 1];
			line[k + 1] = 0;
		}
	}
	check_next_left(line, size);
}

/**
 * check_next_left - checks if next element is 0
 *
 * @line: points to an array of integers
 * @size: size of array
 */

void check_next_left(int *line, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
		{
			for (j = i; j < size; j++)
			{
				if (line[j] != 0)
				{
					temp = line[i];
					line[i] = line[j];
					line[j] = temp;
					break;
				}
			}
		}
	}
}

/**
 * slide_right - slides and merges an array of integers to the right
 *
 * @line: points to an array of integers
 * @size: size of array
 */

void slide_right(int *line, size_t size)
{
	size_t i, j, k;
	int temp;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] == 0)
		{
			for (j = i; j > 0; j--)
			{
				if (line[j] != 0)
				{
					temp = line[i];
					line[i] = line[j];
					line[j] = temp;
					break;
				}
			}
		}
	}
	for (k = size - 1; k > 0; k--)
	{
		if (line[k] == line[k - 1])
		{
			line[k] = line[k] + line[k - 1];
			line[k - 1] = 0;
		}
	}

	check_next_right(line, size);
}

/**
 * check_next_right - checks if next element is 0
 *
 * @line: points to an array of integers
 * @size: size of array
 */

void check_next_right(int *line, size_t size)
{
	size_t i, j;
	int temp;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] == 0)
		{
			for (j = i; j > 0; j--)
			{
				if (line[j] != 0)
				{
					temp = line[i];
					line[i] = line[j];
					line[j] = temp;
					break;
				}
			}
		}
	}
}
