#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
char	*ft_bzero(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
*/
void brainfuck(char *str)
{
	char ret[2048];
	int i;
	int c;
	int j;
	int b;

	j = 0;
	i = 0;
	c = 0;
	while (i < 2048)
	{
		ret[i] = 0;
		i++;
	}
	i = 0;
	b = 0;
	while (str[i])
	{
		if (str[i] == '>')
			j++;
		else if (str[i] == '<')
			j--;
		else if (str[i] == '+')
			ret[j]++;
		else if (str[i] == '-')
			ret[j]--;
		else if (str[i] == '.')
			write(1, ret + j, 1);
		else if (str[i] == '[' && ret[j] == 0)
		{
			while (str[i])
			{
				if (str[i] == '[')
					b++;
				if (str[i] == ']')
					b--;
				if ( b == 0)
					break;
				i++;
			}
		}
		else if (str[i] == ']' && ret[j] != 0)
		{
			while (str[i])
			{
				if (str[i] == ']')
					b++;
				if (str[i] == '[')
					b--;
				if (b == 0)
					break;
				i--;
			}
			i--;
		}
			i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		brainfuck(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
