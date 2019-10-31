#include <stdio.h>
#include <stdlib.h>
#include "../filler.h"

void		getlines(char ***tab, int size, char *str)
{
	*tab = (char **)malloc(sizeof(char *) * (size));
	int i;
	int fd;

	i = 0;
	while (size != 0)
	{
		get_next_line(0, &str);
		printf("%s\n", str);
		*tab[i] = ft_strsub(str, 4, ft_strlen(str));
		printf("%s\n", *tab[i]);
		free(str);
		i++;
		size--;
	}
		printf("1\n");
		tab[i] = NULL;
}

int		main()
{
	char *str;
	char **tab;
	int i = 0;

		printf("%p\n", tab);
		getlines(&tab, 8, str);
		printf("%p\n", tab);
		printf("IIICIII\n");
	while (i < 8)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
