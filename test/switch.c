#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		main()
{
	char *str = "jaomeleveau\n";
	int i = 0;
	while (str[i])
	{
		printf("%d\n", i);
		switch(str[i])
		{
			case 'j': printf("trouve j\n");
				break;
			case 'e': printf("troue e\n");
				break;
		}
		i++;
	}
	return (0);
}

