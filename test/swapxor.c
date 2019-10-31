#include <stdio.h>

void	affichebinc(char c)
{
	for (int i = 7; i >= 0; i--)
		printf("%d", (c & (1 << i)) >> i);
	printf("\n");
}

void	affichebinint(int nb)
{
	int i = 31;

	while (i-- != 0)
	{
		printf("%d", (nb & (1 << i)) >> i);
		if (!(i % 8))
			printf(" ");
	}
	printf("\n");
}

int		main()
{
	char c = 8;
	int nb = 2562;

	int i =  42;
	int j = 33;

	printf("i =");
	affichebinint(i);
	printf("\n");
	printf("j =");
	affichebinint(j);
	printf("\n");
	printf("i ^ j =");
	i = i ^ j;
	j = i ^ j;
	i = i ^ j;
	affichebinint(i);
	affichebinint(j);
	printf("j %d\n", j);
	printf("i %d\n", i);
	return (0);
}
