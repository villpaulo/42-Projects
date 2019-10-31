#define FONC(str) while(*str != '\0' && (*str == ' ' || *str == '\t')) str++
#define FONC2(str) while(*str != '\0' && *str != ' ' && *str != '\t') str++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	rostring(char *str)
{
	while (*str != ' ' && *str != '\t' && *str != '\0')
		{
			//printf("bus\n");
			write(1, str, 1);
			//printf("bus1\n");
			(*str)++;
			printf("bus2\n");
		}
}
void	test(char *str)
{
	while (*str != '\0' && *str != ' ' && *str != '\t')
		str++;
}
int		main()
{
	char *str = "  111111      ierie    DDDDDD    eeeeee   ";;
	/*while (*str != '\0')
	{
		FONC(str);
		rostring(str);
	}*/
	//FONC(str);
	//FONC2(str);
/*	while (*str != '\0' && *str != ' ' && *str != '\t')
		str++;*/
	//test(str);
	printf("%s\n", str);
	printf("&str[0] =%p\n", &str[0]);
	printf("(*str)adress =%p\n", &(*str));
	printf("&str =%p\n", &str);
	str++;
	//str++;
	printf("&str[0] =%p\n", &str[0]);
	printf("&str =%p\n", &str);
	//	write(1, "\n", 1);
	return (0);
}
