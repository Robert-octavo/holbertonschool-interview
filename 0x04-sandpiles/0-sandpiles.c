#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - check if sandpile is stable or not
 * @grid1: sandpile
 * Return: true or false
 */

bool is_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (false);
		}
	}
	return (true);
}

/**
 * stabilize_sandpile - sandpile
 * @grid1: sandpile
 */

void stabilize_sandpile(int grid1[3][3])
{
	int i, j;
	int grid2[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = grid1[i][j];
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid2[i][j] -= 4;
				if (i - 1 >= 0)
					grid2[i - 1][j] += 1;
				if (i + 1 < 3)
					grid2[i + 1][j] += 1;
				if (j - 1 >= 0)
					grid2[i][j - 1] += 1;
				if (j + 1 < 3)
					grid2[i][j + 1] += 1;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid2[i][j];
		}
	}
}

/**
 * sandpiles_sum - sum of two sandpiles
 *
 * @grid1: sandpile 1
 * @grid2: sandpile 2
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		stabilize_sandpile(grid1);
	}
}
