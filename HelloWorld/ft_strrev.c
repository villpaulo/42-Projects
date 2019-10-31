#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	ft_strrev(char *str)
{
	int i;
	int j;
	char c;

	j = 0;
	i = ft_strlen(str) - 1;
	str[i + 1] = '\0';
	while (j < (ft_strlen(str)/ 2))
	{
		c = str[j];
		str[j] = str[i];
		str[i] = c;
		j++;
		i--;
	}
}

int		main()
{
	char *str;
	str = malloc(sizeof(char) * 11);

	int		i = 0;
	for (char c = 'a'; c < 'a' + 10; c++)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	ft_strrev(str);
	ft_putstr(str);
	return (0);
}
