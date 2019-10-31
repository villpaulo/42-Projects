#include <stdio.h>

void	affichebin(char n)
{
		unsigned bit = 0 ;
		char	mask = 1 ;
		for (int i = 0 ; i < 8 ; ++i)
		{
			bit = (n & mask) >> i;
			printf("%d", bit);
			mask <<= 1;
		}


int		main()
{
	char c = 104;

	affichebin(c);
}
