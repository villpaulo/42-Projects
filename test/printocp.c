#include <stdio.h>

int		main()
{
	char c;

	c = 0;

	c = (c << 2) + 1;
	c = (c << 2) + 2;
	c = (c << 2) + 2;
	c = c << 2;
	printf("%hhd\n", c);
	return (0);
}

