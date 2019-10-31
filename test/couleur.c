#include <stdio.h>
#include <unistd.h>

int		main()
{
	printf("\033[31m%s\033[00m", "mon super texte en rouge\n");
	write(1, "\033[31m toto\n", 11);
	return (0);
}

