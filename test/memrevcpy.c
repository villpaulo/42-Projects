#include "../libft/libft.h"
#include <stdio.h>


int		findsize(int lol)
{
	if (lol <= 0x7F)
		return (1);
	else if (lol <= 0x7FFF)
		return (2);
	else if (lol <= 0x7FFFFF)
		return (3);
	else if (lol <= 0x7FFFFFFF)
		return (4);
	return (0);
}

char	*memrevcpy(char *dest, int lol, size_t argsize)
{
	int i;
	int n;
	char *source;
	int size;
	int c;

	n = 0;
	i = 0;
	source = (char *)&lol;
	size = findsize(lol);
	c = argsize - size;
	while (c > 0)
	{
		dest[i] = 0;
		i++;
		c--;
	}
	while (source[size] == 0)
		size--;
	while (size-- != 0)
	{
		dest[i] = source[size];
		i++;
		size--;
	}
	return (dest);
}


int		main()
{
	char *str;
	int lol = 42;
	int	size = sizeof(int);

	str = memrevcpy(str, lol, size);
	for (int i = 0; i < size; i++)
		printf("%#hhx\n", str[i]);
	return (0);
}
