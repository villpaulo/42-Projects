#include <stdio.h>

int		main()
{
	int *i;
	int c = 3;

	*i = 42;
	printf("%d\n", &i);
	printf("%d\n", i);
	printf("%d\n", *i);
	while (c-- > 0)
	{
	printf("1\n");
		(*i)++;
	}
	printf("%d\n", *i);
	return (0);
}
