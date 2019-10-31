#include <stdio.h>

int		main()
{
	int i;
	int *a;

	i = 42;
	a = &i;
	*a = 32;

	printf("%p eperluette i\n", &i);
	printf("%d valeur de i\n", i);
	printf("%p eperluette a\n", &a);
	printf("%p adresse pointee par a sur i\n", a);
	printf("%d valeur de l'adresse pointe par a , soit valeur de int *a\n", *a);
}
