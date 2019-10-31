#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	print_bit(char  c)
{
	int i = 8;
	char ret;

	while (--i)
		printf("%d", (c & (1 << i)) >> i);
	printf("\n");
}

void	print_hex(int nb)
{
	char c;

	if (nb > 16)
		print_hex(nb / 16);
	c = nb % 16 + (nb % 16 > 10 ? '0' : 'a' - 10);
	write(1, &c , 1);
}

void	print_memory(void *addr, size_t size)
{
	unsigned char *str;
	int i;
	int col;
	int tmp;

	col = -1;
	i = 0;
	str = (unsigned char *) addr;
	while (i < size)
	{
		tmp = i;
		while (++col < 16)
		{
			if (str[i] < 16)
				ft_putchar('0');
			print_hex(str[i]);
			if (!(i % 2))
				ft_putchar(' ');
			i++;
		}
		i = tmp;
	}

}

int		main()
{
	char c = 8;
	int tab[10] = {42, 53, 245, 0, 41 , 32};
	print_memory(tab, sizeof(tab));
	print_bit(c);
	return (0);
}
