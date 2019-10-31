#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	display_grid(int **grid);
int		block(int i)
{
	return (i - i % 4);
}

int		is_valid(int **grid, int row, int col, int position)
{
	int i;
	int j;

	i = 0;
	while (i < 16)
	{
		if (grid[i][col] == position || grid[row][i] == position)
			return (1);
		i++;
	}
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[block(row) + i][block(col) + j] == position)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		solve(int **grid, int position)
{
	int row;
	int col;
	int i;

display_grid(grid);
printf("----------------\n");
	row = position / 16;
	col = position % 16;
	i = 0;
	if (position >= 256)
		return (1);
	if (grid[row][col] != 78)
		return (solve(grid, position + 1));
	while (i < 16)
	{
		if (!(is_valid(grid, row, col, i)))
		{
			grid[row][col] = i;
			if (solve(grid, position+ 1))
				return (1);
		}
		grid[row][col] = 78;
		i++;
	}
	return (0);
}

void	display_grid(int **grid)
{
	int row;
	int col;

	row = 0;
	while (row < 16)
	{
		col = 0;
		while (col < 16)
		{
			if (grid[row][col] == 0)
				printf(".");
			else
				printf("%d", grid[row][col]);
			if (col != 15)
				printf(" ");
			col++;
		}
		printf("\n");
		row++;
	}
}

int		**read_args(char **argv)
{
	int row;
	int col;
	int **grid;

	grid = (int **)malloc(sizeof(int *) * 17);
	row = 0;
	while (row < 16)
	{
		if (strlen(argv[row]) != 16)
		{
			return (NULL);

		}
		grid[row] = (int *)malloc(sizeof(int) * 16);
		col = 0;
		while (col < 16)
		{
			if (argv[row][col] == '.')
				grid[row][col] = 'N';
			else if (argv[row][col] >= '0' && argv[row][col] <= '9')
					grid[row][col] = argv[row][col] - '0';
			else if ( (argv[row][col] >= 'A' && argv[row][col] <= 'F'))
			{
				grid[row][col] = argv[row][col] - 'A' + 10;
				//grid[row][col] = 3;
			}
			else
			{
				return (NULL);
			}
			//grid[row][col] = 3;
			col++;
		}
		row++;
	}
	grid[row] = NULL;
	return (grid);
}

int		main(int argc, char **argv)
{
	int **grid;

	if (argc == 17)
	{
		grid = read_args(&argv[1]);

		//AFFICHAGE GRID
	/*
	int i = 0;
	int j = 0;
	printf("\n\n");
	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			printf("%d ", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n\n\n");
	*/

		if (grid == NULL)
		{
			printf("Erreur1\n");
			return (1);
		}
		if (solve(grid, 0))
			display_grid(grid);
		else
		{
			printf("Erreur2\n");
			return (1);
		}
	}
	else
	{
		printf("Erreur3\n");
		return (1);
	}
	return (0);
}
