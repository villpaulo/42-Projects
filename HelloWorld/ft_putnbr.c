#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int neg;

	neg = (nb > 0) ? 0 : 1;
	if (neg)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9 || nb < -9)
		ft_putnbr(nb/ 10);
	ft_putchar((nb % 10) + '0');
}

int		main()
{
	ft_putnbr(-34324);
	return (0);
}

