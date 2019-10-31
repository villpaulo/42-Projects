#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *s)
{
	return (*s?ft_strlen(++s) + 1: 0);
}

int		main()
{
	char *str = "nouveau test\n";

	printf("%d\n", ft_strlen(str));

	return (0);
}
