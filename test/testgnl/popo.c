#include <stdio.h>
#include "get_next_line.h"
//#include "libft/libft.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	char *str;

	int fd = open(av[1], O_RDONLY);

			printf("%d\n", get_next_line(fd, &str));
			printf("%s\n", str);
	return (0);
}
