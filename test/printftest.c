#include "printf.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int		ft_strlen4(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		main()
{
	char str;

	char c;
	char *tab = "asf";
	char *s1;
	int	 ret;
	int i;
	int j = -2147483648;
	char *su = "llll";
	int n = 42;
	int o = 32;
	int retp;

	s1 = NULL;
	i = 42;
	setlocale(LC_ALL, "en_us");
	//ret = ft_sprintf(s1, "%s", "egera");
	str = 'a'; // CAS DERREUR NON TRAITE l et L h et H, MON ORDRE DES MODIFFIERS
/*
	printf("%d\n", ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',	'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';','<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W','X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's','t', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}'));
	  printf("%d\n", printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',	'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';','<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W','X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's','t', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}'));
	 */ 
	/*ft_printf("@moulitest: %5.x, %5.0x", 0, 0);
	printf("\n");
	printf("@moulitest: %5.x, %5.0x", 0, 0);
	//printf("%-05o\n", 2500);*/
	printf("%d\n", printf("toto%dtata%42cto.  .5to%-4ctyty%cnn%42stoto%-42spopo%spapa%020dplpl%o%.3Xmedhiestunbogoss\n", j, 'l', 'k', 'j', su, tab, "common", i, 42, 42));
	printf("%d\n", ft_printf("toto%dtata%42cto.  .5to%-4ctyty%cnn%42stoto%-42spopo%spapa%020dplpl%o%.3Xmedhiestunbogoss\n", j, 'l', 'k', 'j', su, tab, "common", i, 42, 42));
	//ft_printf("{%-15p}\n", 0);
	//ft_printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"�M-^Dح�M-^E خ�M-^Fز�M-^Jر");
	//printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"�M-^Dح�M-^E خ�M-^Fز�M-^Jر");
	//ft_printf("%S\n", L"toto");
	//ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"�M-^ZM-^V�M-^BM-^I", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'�M-^TM-^L');
	//printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"�M-^ZM-^V�M-^BM-^I", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'�M-^TM-^L');
	//ft_printf("%hhd - %hhd", SHRT_MAX - 42,  SHRT_MAX - 4200);
	//printf("%hhd - %hhd", SHRT_MAX - 42,  SHRT_MAX - 4200);
	//printf("%S\n", L"�M-^Dح�M-^E خ�M-^Fز�M-^Jر");
	/*printf("%d\n", ft_printf("%s", "abc"));
	  printf("%d\n", ft_printf("%s", "abc"));
	  printf("str=%s\n", str);
	  printf("\n");
	  printf("%d\n", printf("%s", "abc"));*/
	//printf("%d\n", ft_printf("{%30S}\n", L"我是一只猫。"));
	//printf("%d\n", printf("{%30S}\n", L"我是一只猫。"));
	//write(1, "\1", 1);
	//ft_printf("%.i, %.0i\n", 0, 0);
	//ft_printf("% p|%+p", 42, 42);
	//ft_printf("{%*s}\n", 5, 0);
	//ft_printf("%s\n", 3);
	//ft_printf("{%030X}\n", 0xFFFF);
	//printf("{%030X}\n", 0xFFFF);
	//printf("{%05.Z}", 0);
	//ft_printf("{%#5.4x}\n", 1);
	//printf("{%#5.4x}\n", 1);
	//printf("{%}\n");
	//ft_printf("%D\n", -1L);
	//printf("%D\n", -1L);
	//ft_printf("%D\n", 42L);
	//printf("%D\n", 42L);
	//printf("%p\n", 0);
	//ft_printf("%c\n", ' ');
	//ft_printf("%s\n", NULL);
	//printf("%s\n", NULL);
	//printf("%d\n", printf("%c\n", 0));
	//ft_printf("gigi%s", "toto\n");
	//printf("gigi%s", "toto\n");
	//printf("%c\n", 0);
	//ft_printf("null %c and text\n", 0);
	//printf("null %c and text\n", 0);
	//ft_printf("%0 d\n", 42);
	//printf("%0 d\n", 42);
	//ft_printf("%0 d\n", 42);
	//printf("%0 d\n", 42);
	//printf("%03.2d\n", 0);
	//ft_printf("%03 2d\n", 0);
	//printf("%03 2d\n", 0);
	//printf("0123456789\n");
	//ft_printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi");
	//printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi");
	//printf("%d\n", j);
	//printf("%10.5d\n", 4242);
	//printf("%llx\n", 9223372036854775808);
	return (0);
}
