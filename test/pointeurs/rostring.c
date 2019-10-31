#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define FONC(str) while(*str != '\0' && (*str == ' ' || *str =='\t'))str++

void	rostring(char **str)
{
	while (**str != '\0' && **str != ' ' && **str != '\t')
	{
		write(1, *str, 1);
		(*str)++;
	}
}

int		main(int ac, char **av)
{
	char *ret;

	ret = NULL;
	if (ac == 2)
	{
		ret = av[1];
		//write(1, ret, ft_strlen(ret));
		FONC(av[1]);
		while (*av[1] != ' ' && *av[1] != '\t' && *av[1] != '\0')
			av[1]++;
		while (*av[1] != '\0')
		{
		FONC(av[1]);
		rostring(&av[1]);
		write(1, " ", 1);
		}
		FONC(ret);
		rostring(&ret);
	}
	write(1, "\n", 1);
	return (0);
}
