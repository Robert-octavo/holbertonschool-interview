#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 */

void menger(int level)
{
	int size, row, col, i, j, k, l;

	if (level < 0)
		return;

	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			i = row;
			j = col;
			while (i > 0 || j > 0)
			{
				k = i % 3;
				l = j % 3;
				if (k == 1 && l == 1)
				{
					printf(" ");
					break;
				}
				i /= 3;
				j /= 3;
			}
			if (i == 0 && j == 0)
				printf("#");
		}
		printf("\n");
	}
}
