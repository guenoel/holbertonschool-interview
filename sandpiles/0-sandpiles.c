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

int **sandpile_reduc(int **grid)
{
	int i, j, num;
	int **next_grid;
	next_grid = (int **)malloc(sizeof(int *) * 3);
	for (i = 0; i < 3; i++)
		next_grid[i] = (int *)malloc(sizeof(int) * 3);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			num = grid[i][j];
			if (num <= 3)
			{
				next_grid[i][j] = grid[i][j];
			}
		}
	}

	for (i = 0; i < 3; i++)
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
	free(grid);
	return (next_grid);
}

int sandpiles_check(int **grid)
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
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int **grid_sum;
	grid_sum = (int **)malloc(sizeof(int *) * 3);
	for (i = 0; i < 3; i++)
		grid_sum[i] = (int *)malloc(sizeof(int) * 3);

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid_sum[i][j] = grid1[i][j] + grid2[i][j];
	}
	while(sandpiles_check(grid_sum))
	{
		printf("=\n");
		print_grid2(grid_sum);
		grid_sum = sandpile_reduc(grid_sum);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid_sum[i][j];
	}
	free(grid_sum);
}