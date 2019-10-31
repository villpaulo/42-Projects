#include <stdio.h>
#include <stdlib.h>

void	toto(char *str)
{
	str[0] = 'p';
}
void	tata(char *str)
{
	str = "fwfew";
	//str[0] = 'l'; seg pace que pas d'attribution et pas de malloc non plus 
}

int		main()
{
	char *str;
	char *new;

	str = NULL;
	str = (char *)malloc(sizeof(char) * 42);
	toto(str);
	tata(new);
	printf("%s\n", str);
	printf("%s\n", new);
	return (0);
}
