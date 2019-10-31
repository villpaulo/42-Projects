#include "../libft/libft.h"
#include <stdio.h>


char*memrevcpy(char	 *dest, char *source, size_t n)
{
		int i;

		i = 0;
		while (n-- != 0)
		{
			dest[i] = source[n];
			i++;
		}
		return (dest);
}

int		main()
{
	char *str;
	unsigned int toto = -100;
	int size = sizeof(int);

	printf("toto=%d\n", toto);
	str = memrevcpy(str, (char *)&toto, size);
	for (int i = 0; i < size; i++)
		printf("%#hhx\n", str[i]);
	return (0);
}
