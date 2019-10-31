#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		main()
{
	char *bott = "jritjhiorokgortotorkh";
	char *aiguille = "toto";
	char *ret;

	ret = strstr(bott, aiguille);
	printf("%s\n", ret);
	return (0);
}
