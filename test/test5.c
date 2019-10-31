#include <stdio.h>

char	*toto(int *a, char *str)
{
	printf("%s\n", str);
	*a = 43;
	return (str);
}

int		main()
{
	char *str;
	int i = 42;

	str = "toto\n";
	printf("%d\n", i);
	toto(&i, str);
	printf("%d\n", i);
	return (0);
}
