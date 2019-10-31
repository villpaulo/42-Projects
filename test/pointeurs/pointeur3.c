#include <stdio.h>

int		main()
{
	int a = 42;
	int *b;

	b = &a;

	printf("%d\n", &a);
	printf("%d\n", a);
	printf("%d\n", &b);
	printf("%d\n", b);
	printf("%d\n", *b);

}
