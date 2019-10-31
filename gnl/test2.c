#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	f(char **toto)
{
	printf("adresse de toto dans f= :%x\n", &toto);
	printf("adresse de la valeur poite par la premiere adresse toto f= :%x\n", toto);
	printf("valeur de toto %s\n", *toto);
	*toto = "jaimeleveau";
	printf("%c\n", *toto[0]);
	printf("toto[0]=%c\n", **toto);
	printf("valeur de toto apres modifs %s\n", *toto);
}

int		main()
{
	char *str;

	str = "tatitatou";
	printf("adresse de str = :%x\n", &str);
	f(&str);
	printf("sortie de la fonction\n");
	printf("str[0]=%c\n", str[0]);
	printf("str = %s\n", str);
	return (0);
}
