#include <stdio.h>

void	test(int **i)
{
	printf("dans test \n");
	printf("&i= %p\n", &i);
	printf("i= %p\n", i);
	printf("*i= %p\n", *i);
	**i += 1;
	printf("**i= %d\n", **i);
}


/*void	test2(int *i)
{
	*i += 1;
}
*/
void	t(int *i)
{
	printf("dans t \n");
	printf("&i= %p \n", &i);
	printf("i= %p\n", i);
	printf("&(*i)= %p\n", &(*i));
	*i += 42;
	test(&i);
}


int		main()
{
	int i;

	i = 0;
	printf("&i =%p\n", &i);
	printf("i= %d\n", i);
	t(&i);
	printf("i = %d\n", i);
	return (0);
}
