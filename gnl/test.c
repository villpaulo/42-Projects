#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int fd;
	char *str;

	str = (char *)malloc(sizeof(char) * 10000);
	fd = open(av[1], O_RDONLY);
	//read(fd, str, 10000);
		while (get_next_line(fd, &str) > 0)
			continue;
			printf("%s\n", str);
	return (0);
}
