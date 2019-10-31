#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct stc_param
	{
	char *str;
	int i;
	int j;
    };

int	main()
{
	struct stc_param toto;

	toto.str = "jaimelveau\n";
	toto.i = 42;

	printf("&toto = %p\n", &toto);
	printf("&toto.str = %p\n", &toto.str);
	printf("&toto.i = %p\n", &toto.i);
	printf("&toto.j = %p\n", &toto.j);
	printf("adr just toto = %p\n", toto);
	printf("adr toto.str = %p\n", toto.str);
	printf(" prcs toto =%s\n", toto);
	return (0);
}
