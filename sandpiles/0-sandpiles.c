#include "sandpiles.h"

/**
 * init_grid - init 3x3 grid
 * @grid: 3x3 grid
 *
 */
void init_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++) /* initialisation */
	{
		for (j = 0; j < 3; j++)
			grid[i][j] = 0;
	}
}

/**
 * sandpile_reduc - topple 3x3 grid of sandboxes
 * @grid: 3x3 grid
 *
 */
void sandpile_reduc(int grid[3][3])
{
	int i, j, num;
	int next_grid[3][3];

	init_grid(next_grid);
	for (i = 0; i < 3; i++) /* copy boxes <= 3 */
	{
		for (j = 0; j < 3; j++)
		{
			num = grid[i][j];
			if (num <= 3)
				next_grid[i][j] = grid[i][j];
		}
	}
	for (i = 0; i < 3; i++) /* Topple boxes > 3 */
	{
		for (j = 0; j < 3; j++)
		{
			num = grid[i][j];
			if (num > 3)
			{
				next_grid[i][j] += (num - 4);
				if (i - 1 >= 0)
					next_grid[i - 1][j]++;
				if (j - 1 >= 0)
					next_grid[i][j - 1]++;
				if (i + 1 < 3)
					next_grid[i + 1][j]++;
				if (j + 1 < 3)
					next_grid[i][j + 1]++;
			}
		}
	}
	for (i = 0; i < 3; i++) /* Topple boxes > 3 */
	{
		for (j = 0; j < 3; j++)
			grid[i][j] = next_grid[i][j];
	}
}

/**
 * sandpiles_check - check stability of 3x3 grid
 * @grid: 3x3 grid
 *
 * Return: 1 if sandpile is not stable, 0 if it is
 */
int sandpiles_check(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid(int grid[3][3])
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
 * sandpiles_sum - make sum od two 3x3 grid
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int grid_sum[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid_sum[i][j] = grid1[i][j] + grid2[i][j];
	}
	while (sandpiles_check(grid_sum))
	{
		printf("=\n");
		print_grid(grid_sum);
		sandpile_reduc(grid_sum);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid_sum[i][j];
	}
}
