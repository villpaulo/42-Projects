#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

struct	toto
{
	void *q;
	char *str;
	int i;
	int e;
	int d;
};

int		main()
{
	struct toto new;

	//new.q = 42;
	new.str = "gkrohriueguehrbhlrtlkro4";
	new.i = 42;
	new.e = 100;
	new.d = 1245235;

	printf("adr &new %p\n", &new);
	printf("adr new %p\n", new);
	printf("adr &new.q %p\n", &new.q);
	printf("adr &new.str %p\n", &new.str);
	printf("adr &new.str[0] %p\n", &new.str[0]);
	printf("adr &new.i %p\n", &new.i);
	printf("adr &new.e %p\n", &new.e);

	return (0);
}
