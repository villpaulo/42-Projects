#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>
#include <stdlib.h>

int		main()
{
	int x;
	char* l = setlocale(LC_ALL, "");
	char *str;
	char a;
	char b;

	str = (char *)malloc(sizeof(char) * 3);
	if (l == NULL) 
		printf("Locale not set\n"); 
	else
		printf("Locale set to %s\n", l);

	x = 945;
	printf("%S\n", 945);
	/*if (x <= 0x7FF)
	  {
	  a = ((x >> 6) + 0xC0);
	  b = ((x & 0x3F) + 0x80);
	//write(1, &a, 1);
	//write(1, &b, 1);
	str[0] = a;
	str[1] = b;
	str[2] = '\0';
	write(1, str, 2);
	}*/
	return (0);
}
