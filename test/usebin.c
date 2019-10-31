#include <stdio.h>

int		ocpright(char c)
{
	char bit = 0;
	int i = 7;

	while (i >= 6)
	{
		bit = (c & (1 << i)) >> i;
		printf("%d", bit);
		i--;
	}
	return (0);
}


int		main()
{
	char c = 63;
	ocpright(c);
	return (0);
}
