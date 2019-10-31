
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define FONC(str) while (*str++ && (*str == ' ' || *str == '\t'))

int		main()
{
	char *str = "   jaimelveuau\n";


	FONC(str);
	printf("%c\n", *str);
	return (0);
}
