#include "sandpiles.h"

void print_grid2(int **grid)
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

void free_grid(int **grid)
{
	int i;

	for (i = 0; i < 3; i++)
		free(grid[i]);
	free(grid);
}

void init_grid(int **grid)
{
	int i, j;

	for (i = 0; i < 3; i++) /* initialisation */
	{
		for (j = 0; j < 3; j++)
			grid[i][j] = 0;
	}
}
