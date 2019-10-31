#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void		print_bit(int nb)
{
	int i;
	char c;

	i = 32;
	while (i-- != 0)
	{
		c = ((nb & ( 1 << i)) >> i);
		c += 48;
		write(1, &c, 1);
		if (!(i % 8))
			write(1, " ", 1);
	}
}

void		print_char(char c)
{
	int i;
	char ret;

	i = 8;
	while (i-- != 0)
	{
		ret = ((c & (1 << i)) >> i);
		ret += 48;
		write(1, &ret, 1);
	}
}

int			main()
{
	int nb = 2562;
	char c = 255;

	print_bit(nb);
	//print_char(c);
	return (0);
}
