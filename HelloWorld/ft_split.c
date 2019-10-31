#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		count_word(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			count++;
		while (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
			i++;
	}
	return (count);
}

int		count_len(char *str, int i)
{
	int count;

	count = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		i++;
		count++;
	}
	return (count);
}

int			skip(char *str, int j)
{
	while (str[j] && (str[j] == ' ' || str[j] == '\n' || str[j] == '\t'))
		j++;
	return (j);
}

char		**ft_split(char *str)
{
	char **ret;
	int i[2];
	int j;

	j = 0;
	if (!str)
		return (NULL);
	if (count_word(str) == 0)
	{
		ret = (char **)malloc(sizeof(char *) * 1);
		ret[0] = NULL;
		return (ret);
	}

	ret = (char **)malloc(sizeof(char *) * (count_word(str) + 1));
	i[0] = 0;

	while (str[j])
	{
		i[1] = 0;
		j = skip(str, j);
		ret[i[0]] = (char *)malloc(sizeof(char) * (count_len(str, j) + 1));
		while (1)
		{
			ret[i[0]][i[1]] = str[j];
			j++;
			i[1]++;
			if (str[j] == ' ' || str[j] == '\n' || str[j] == '\t' || str[j] == '\0')
			{
				ret[i[0]][i[1]] = '\0';
				i[0]++;
				break;
			}
		}
		if (str[skip(str, j)] == '\0')
		{
			ret[i[0]] = NULL;
			break;
		}
	}
	return (ret);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		char **tab;
		int i;

		i = 0;
		tab = ft_split(av[1]);
		while (tab[i])
		{
			printf("%s", tab[i++]);
			printf("\n");
		}
		return (0);
	}
}
