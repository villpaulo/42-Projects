#include <stdio.h>

int		ft_isdigit(int n)
{
	printf("%d\n", n);
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

int		main()
{
	char *str = "%0";

	if (!(ft_isdigit((int)(str + 1))))
	{
		printf("%s\n", str + 1);
		printf("no\n");
	}
	else
		printf("yes\n");
	return (0);
}
