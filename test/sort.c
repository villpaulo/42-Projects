#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	swap(int *elem1, int *elem2)
{
	*elem1 = *elem1 ^ *elem2;
	*elem2 = *elem1 ^ *elem2;
	*elem1 = *elem1 ^ *elem2;
}

int	*sort(int *tab, int length)
{
	int tmp;
	int i;

	i = 1;
	tmp = 0;
	while (i < length)
		{
		if (tab[i - 1] > tab[i])
		{
			swap(&tab[i], &tab[i - 1]);
			i = 0;
			}
		i++;
		}

	return (tab);
}

int	main()
{
	int i;

	i = 0;
	int tab[5] = {45, 12, 0, 22, -5};
	sort(tab, 5);

	while (i < 5)
		{
			printf("%d\n", tab[i]);
			i++;
		}

	return (0);
}
