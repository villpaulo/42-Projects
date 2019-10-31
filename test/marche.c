#include <stdio.h>
#include "../libft/libft.h"

int		main()
{
	char *str;
	int		lol = 0x11223344;

	ft_memcpy(str, (char *)&lol, sizeof(int));
	str[4] = '\0';
	for (int i = 0; i < 4; i++)
		printf("%#hhx %c\n", str[i], str[i]);
	return (0);
}
