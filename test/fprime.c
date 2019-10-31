#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *s)
{
	return (*s++? ft_strlen(s) + 1 : 0);
}

int		ft_atoi(char *str)
{
	int nb;
	int neg;
	int len;
	int i;

	neg = 1;
	i = 0;
	nb = 0;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] && (str[i] > 47 && str[i] < 58))
	{
		nb *= 10;
		nb = nb + (str[i] - 48);
		i++;
	}
	return( nb * neg);
}

void	fprime(int nb)
{
	int i;

	i = 1;
	if (nb == 1)
		printf("%d\n", nb);
	while (nb > 1)
	{
		if ((nb % ++i) == 0)
		{
			printf("%d", i);
			nb /= i;
			if (nb > 1)
				printf("*");
			i--;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(ft_atoi(av[1]));
	printf("\n");
	return (0);
}
