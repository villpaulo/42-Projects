#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_memcpy(void *, void *, size_t);

typedef struct	s_domaine
{
	char *str;
	int i;
	char *toto;
}				t_dom;

char	*ftmemcpy(char *s1, void *s2, size_t s)
{
	int i;
	char *new;

	new = (char *)s2;
	i = 0;
	while (i < s)
	{
		s1[i] = new[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int		main()
{
	char *str;
	t_dom t;

	t.str = "tdestr";
	t.i = 5252;
	t.toto = "toto";

	str = (char *)malloc(sizeof(char) * (sizeof(10000)));
	str = ft_memcpy(str, &t, sizeof(t_dom));
	int i = 0;
	while (i < sizeof(t_dom))
		printf("%c", str[i++]);
	printf("\n");

	//printf("str=%s\n", str);
	return (0);
}
