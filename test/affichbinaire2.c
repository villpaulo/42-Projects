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

	//affichebinc(c);
	affichebinint(nb);
	return (0);
}
