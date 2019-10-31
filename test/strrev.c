#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	len(char *s)
{
	return (*s? len(++s) + 1 : 0);
}

int	main()
{
	int deb;
	int end;
	char c;

	char str[15] = "jaime le veau";
//	char *str = "jaime le veau\n";

	c = 0;
	deb = 0;
	end = len(str) - 1;	
	printf("%d\n", len(str));	
	printf("%c\n", str[len(str)]);	
	while (deb < end)
	{
		c = *(str + deb);
		*(str + deb) = *(str + end);
		*(str + end) = c;
		deb++;
		end--;
	}
	printf("%s\n", str);

	return (0);
}


