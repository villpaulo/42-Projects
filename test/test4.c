#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		main()
{
	char *str;

	str = (char *)malloc(sizeof(char) * 5);
	str = NULL;
	free(str);
	return (0);
}
