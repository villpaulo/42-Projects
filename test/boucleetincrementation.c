#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		main()
{
	int numb;
	numb = 0;

	/*while (++numb != 42) // sortie = 42, preincremente boom = 42 il sort
		printf("%d\n", numb);*/
/*	while (numb++ != 42) // different de 42 affiche et incremente, seconde tour ->egal a 42, ne rentre pas dans le while mais incremente quand meme avant de sortir sortie = 42
		printf("%d\n", numb);*/
	while (numb != 42) // classic, sortie = 42
	{
		numb++;
		printf("%d\n", numb);
	}
	printf("sortie == %d\n", numb);
	return (0);
}
