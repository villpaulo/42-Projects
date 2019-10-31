#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

char	*funread(char *str, char *av)
{
	int fd;
	int ret;

	fd = open(av, O_RDONLY);
	ret = read(fd, str, 1000000);
	str[ret] = '\0';
	return (str);
}


int		main(int ac, char **av)
{
	char *str;
	int fd;
	int ret;

	str = NULL;
	str = (char *)malloc(sizeof(char) * 1000000);
	str = funread(str, av[1]);
	printf("%s\n", str);
	return (0);
}
