#include <stdlib.h>
#include <stdio.h>

int		main()
{
	char *s1;
	char *s2;

	s1 = (char *)malloc(sizeof(char) * 5);
	s1[0] = 't';
	s1[1] = 't';
	s1[2] = 't';
	s1[3] = 't';
	s1[4] = '\0';
	printf("s1 = %s\n", s1);
	free(s1);
	//s1[3] = 'p';
	//s1[2] = 'a';
	printf("s1 = %s\n", s1);
	return (0);
}
