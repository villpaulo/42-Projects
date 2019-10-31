#include <stdio.h>
int		ft_strcmp(char *s1, char *s2);

int		main()
{
	char *s1 = "%:toto";
	char *s2 = "toto";

	printf("%d\n", ft_strcmp(s1 + 2, s2));
	return (0);
}
