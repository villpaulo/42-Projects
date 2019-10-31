#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char *str;

	str = NULL;
	while (get_next_line(0, &str))
		{
			if (ft_strlen(str) == 0)
			{
			printf("got it");
				break;
			}
			printf("%s\n", str);
		}
}
