#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	if (nb > 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int		main()
{
	int nb = -4213523;

	ft_putnbr(nb);
	return (0);
}
