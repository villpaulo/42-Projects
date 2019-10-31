#include <stdio.h>

int		singletown(int ret, int b)
{
	static int r;

	if (b == 0)
		r = ret;
	return (r);
}

int		main()
{
	int i;
	int e;

	i = 42;
	e = 0;
	e = singletown(i, 0);
	printf("e=%d\n", e);
	printf("i=%d\n", i);
	i = 42 + 3;
	printf("i=%d\n", i);
	i = singletown(i, 1);
	printf("i=%d\n", i);
	return (0);
}
