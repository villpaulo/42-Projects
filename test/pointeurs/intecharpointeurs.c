#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	change2(char  **str)
{

	printf("&str=%p\n", &str);
	printf("str=%p\n", str);
	printf("&(str[0])=%p\n", &(str[0]));
	printf("*str=%p\n", *str);
	*str = "vive la france\n";
	/*printf("*str[0]=%c\n", *str[0]);
	printf("%c\n", *(str)[0]);*/
}

void	change(int *t)
{

	printf("&t%p\n", &t);
	printf("t%p\n", t);
	printf("*t%d\n", *t);
	*t = 42;
}
int		main()
{
	char *str = "jkhir";
	int i = 32;

	printf("avant &i%p\n", &i);
	change(&i);
	printf("%d\n", i);

	//change2(&str);
	//printf("%s\n", str);
	return (0);
}
