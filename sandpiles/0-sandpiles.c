#include "sandpiles.h"

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

void sandpile_reduc(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i - 1 >= 0)
					grid[i - 1][j] += 1;
				if (j - 1 >= 0)
					grid[i][j - 1] += 1;
				if (i + 1 < 3)
					grid[i + 1][j] += 1;
				if (j + 1 < 3)
					grid[i][j + 1] += 1;
			}
		}
	}
}

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
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int grid_sum[3][3] = {0};
	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid_sum[i][j] = grid1[i][j] + grid2[i][j];
			printf("%d ", grid_sum[i][j]);
		}
		printf("\n");
	}
	while(sandpiles_check(grid_sum))
	{
		printf("=\n");
		sandpile_reduc(grid_sum);
		print_grid(grid_sum);
	}
}