#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		block(int i)
{
	return (i - i % 3);
}

int		is_valid(int **grid, int row, int col, int position)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		if (grid[i][col] == position || grid[row][i] == position)
			return (1);
		i++;
	}
	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
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

	row = position / 9;
	col = position % 9;
	i = 1;
	if (position >= 81)
		return (1);
	if (grid[row][col] != 0)
		return (solve(grid, position + 1));
	while (i < 10)
	{
		if (!(is_valid(grid, row, col, i)))
		{
			grid[row][col] = i;
			if (solve(grid, position+ 1))
				return (1);
		}
		grid[row][col] = 0;
		i++;
	}
	return (0);
}

void	display_grid(int **grid)
{
	int row;
	int col;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			if (grid[row][col] == 0)
				printf(".");
			else
				printf("%d", grid[row][col]);
			if (col != 8)
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

	grid = (int **)malloc(sizeof(int *) * 9);
	row = 0;
	while (row < 9)
	{
		if (strlen(argv[row]) != 9)
			return (NULL);
		grid[row] = (int *)malloc(sizeof(int) * 9);
		col = 0;
		while (col < 9)
		{
			if (argv[row][col] == '.')
				grid[row][col] = 0;
			else if (argv[row][col] >= '1' && argv[row][col] <= '9')
				grid[row][col] = argv[row][col] - '0';
			else
				return (NULL);
			col++;
		}
		row++;
	}
	return (grid);
}

int		main(int argc, char **argv)
{
	int **grid;

	if (argc == 10)
	{
		int i = 0;
		int j = 0 ;

		grid = read_args(&argv[1]);
		/*while (i < 9)
		{
			j = 0;
			while (j < 9)
			{
				printf("%d ", grid[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}*/
		printf("\n\n\n\n");
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

