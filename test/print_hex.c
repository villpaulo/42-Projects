#include <stdio.h>
#include <unistd.h>

void	print_hex(int n)
{
	if (n >= 16)
		print_hex(n / 16);
	n = n % 16;
	n += n < 10 ? '0': 'a' - 10;
	write(1, &n, 1);
}

int		main()
{
	//int nb = 42;
	char c = 42;
	print_hex(c);
	return (0);
}
