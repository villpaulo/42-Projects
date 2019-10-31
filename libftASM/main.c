/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 15:05:43 by pvillene          #+#    #+#             */
/*   Updated: 2015/05/27 14:36:47 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>

int			ft_isallower(char *str);
void		ft_bzero(void *s, size_t n);
char		*ft_strcat(char *s1, const char *s2);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_puts(const char *s);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, void *src, size_t n);
char		*ft_strdup(const char *s1);
int			ft_cat(int fd);
int			ft_islower(int c);
int			ft_isupper(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_isspace(int c);

void		test_bzero(void)
{
	printf("======= Test bzero =======\n");

	//test 1
	char	*temoin1 = strdup("bonjour");
	char	*str_test1 = strdup("bonjour");
	bzero(temoin1, 3);
	ft_bzero(str_test1, 3);
	printf("memcmp bzero 1 : %d\n", memcmp(temoin1, str_test1, 7));

	//test 2
	char	*temoin2 = strdup("caca");
	char	*str_test2 = strdup("caca");
	bzero(temoin2, 0);
	ft_bzero(str_test2, 0);
	printf("memcmp bzero 2 : %d\n", memcmp(temoin2, str_test2, 4));

	//test 3
	char	*temoin3 = strdup("bon");
	char	*str_test3 = strdup("bon");
	bzero(temoin3, 4);
	ft_bzero(str_test3, 4);																	printf("memcmp bzero 3 : %d\n", memcmp(temoin3, str_test3, 4));
	putchar('\n');
}

void		test_strcat(void)
{
	printf("======= Test strcat =======\n");

	//test 1
	char	*s1 = malloc(sizeof(char) * 10);
	char	*temoin_s1 = malloc(sizeof(char) * 10);
	char	*s2 = "LOL";
	strcat(temoin_s1, s2);
	ft_strcat(s1, s2);
	printf("memcmp strcat 1 : %d\n", memcmp(s1, temoin_s1, 10));

	//test 2
	char	*test2_s2 = "";
	strcat(temoin_s1, test2_s2);
	ft_strcat(s1, test2_s2);
	printf("memcmp strcat 2 : %d\n", memcmp(s1, temoin_s1, 10));

	//test 3
	char	*test3_s1 = malloc(sizeof(char) * 2);
	char	*temoin3_s1 = malloc(sizeof(char) * 2);
	test3_s1[0] = 'a';
	test3_s1[1] = '\0';
	temoin3_s1[0] = 'a';
	temoin3_s1[1] = '\0';
	char	*test3_s2 = "test";
	strcat(temoin3_s1, test3_s2);
	ft_strcat(test3_s1, test3_s2);
	printf("memcmp strcat 3 : %d\n", memcmp(test3_s1, temoin3_s1, 2));

	//test 4
	s1[0] = 'a';
	s1[1] = 'b';
	s1[2] = 'c';
	temoin_s1[0] = 'a';
	temoin_s1[1] = 'b';
	temoin_s1[2] = 'c';
	char	*test4_s2 = "defgh";
	strcat(temoin_s1, test4_s2);
	ft_strcat(s1, test4_s2);
	printf("memcmp strcat 4 : %d\n", memcmp(s1, temoin_s1, 10));

	putchar('\n');
}

void		test_isalpha(void)
{
	printf("======= Test isalpha =======\n");
	printf("test isalpha avec '8', renvoit 0 : %d\n", ft_isalpha('8'));
	printf("test isalpha avec 'a', renvoit 1 : %d\n", ft_isalpha('a'));
	printf("test isalpha avec 'k', renvoit 1 : %d\n", ft_isalpha('k'));
	printf("test isalpha avec 'z', renvoit 1 : %d\n", ft_isalpha('z'));
	putchar('\n');
}

void		test_isdigit(void)
{
	printf("======= Test isdigit =======\n");
	printf("test isdigit avec 'a', renvoit 0 : %d\n", ft_isdigit('a'));
	printf("test isdigit avec '0', renvoit 1 : %d\n", ft_isdigit('0'));
	printf("test isdigit avec '9', renvoit 1 : %d\n", ft_isdigit('9'));
	printf("test isdigit avec '5', renvoit 1 : %d\n", ft_isdigit('5'));
	putchar('\n');
}

void		test_isalnum(void)
{
	printf("======= Test isalnum =======\n");
	printf("test isalnum avec ']', renvoit 0 : %d\n", ft_isalnum(']'));
	printf("test isalnum avec 'u', renvoit 1 : %d\n", ft_isalnum('u'));
	printf("test isalnum avec '6', renvoit 1 : %d\n", ft_isalnum('6'));
	putchar('\n');
}

void		test_isascii(void)
{
	printf("======= Test isascii =======\n");
	//characteres entre 0 et 0177
	printf("test isascii avec 032(sub), renvoit 1 : %d\n", ft_isascii(032));
	printf("test isascii avec 000(nul), renvoit 1 : %d\n", ft_isascii(000));
	printf("test isascii avec 043(#), renvoit 1 : %d\n", ft_isascii(043));
	printf("test isascii avec 112(J), renvoit 1 : %d\n", ft_isascii(0112));
	printf("test isascii avec 172(z), renvoit 1 : %d\n", ft_isascii(0172));
	printf("test isascii avec 135(]), renvoit 1 : %d\n", ft_isascii(0135));
	printf("test isascii avec 173({), renvoit 1 : %d\n", ft_isascii(0173));
	printf("test isascii avec 177(del), renvoit 1 : %d\n", ft_isascii(0177));
	putchar('\n');
}

void		test_isprint(void)
{
	printf("======= Test isprint =======\n");
	printf("test isprint avec 040(sp), renvoit 1 : %d\n", ft_isprint(040));
	printf("test isprint avec 046(&), renvoit 1 : %d\n", ft_isprint(046));
	printf("test isprint avec 077(!), renvoit 1 : %d\n", ft_isprint(050));
	printf("test isprint avec 111(I), renvoit 1 : %d\n", ft_isprint(0111));
	printf("test isprint avec 163(s), renvoit 1 : %d\n", ft_isprint(0163));
	printf("test isprint avec 137(_), renvoit 1 : %d\n", ft_isprint(0137));
	printf("test isprint avec 000(nul), renvoit 0 : %d\n", ft_isprint(000));
	printf("test isprint avec 012(nl), renvoit 0 : %d\n", ft_isprint(012));
	printf("test isprint avec 177(del), renvoit 0 : %d\n", ft_isprint(0177));
	putchar('\n');
}

void		test_toupper(void)
{
	printf("======= Test toupper =======\n");
	printf("test toupper avec ('a') : %c\n", ft_toupper('a'));
	printf("test toupper avec ('m') : %c\n", ft_toupper('m'));
	printf("test toupper avec ('z') : %c\n", ft_toupper('z'));
	printf("test toupper avec ('C') : %c\n", ft_toupper('C'));
	printf("test toupper avec ('A') : %c\n", ft_toupper('A'));
	printf("test toupper avec ('Z') : %c\n", ft_toupper('Z'));
	printf("test toupper avec (']') : %c\n", ft_toupper(']'));
	printf("test toupper avec ('&') : %c\n", ft_toupper('&'));
	printf("test toupper avec ('2') : %c\n", ft_toupper('2'));
	printf("\n");
}

void		test_puts(void)
{

	printf("======= Test puts =======\n");
	ft_puts("caca");
	ft_puts("");
	ft_puts("xdgofjhohiu08w407ofdhkgjnf][pl';.\\");
	ft_puts("sfoshjd ;fghfkgjhnfgkjnfjfbdkfh\n");
	putchar('\n');
}

void		test_strlen(void)
{
	printf("======= Test strlen ========\n");
	printf("strlen de 'hello' : %zu\n", strlen("hello"));
	printf("ft_strlen de 'hello' : %zu\n", ft_strlen("hello"));
	printf("strlen chaine vide : %zu\n", strlen(""));
	printf("ft_strlen chaine vide : %zu\n", ft_strlen(""));
	putchar('\n');
}

void		test_memset(void)
{
	printf("======== Test memset ========\n");
	char	*memset1 = malloc(sizeof(char) * 3);
	memset1[0] = 'a';
	memset1[1] = 'b';
	memset1[2] = '\0';

	//test 1
	printf("test avec le vrai memset : ");
	printf("%s\n", memset(memset1, 'a', 5));
	printf("ft_memset : ");
	printf("%s\n", ft_memset(memset1, 'a', 5));
	free(memset1);

	//test 2
	printf("chaine vide avec le vrai memset :");
	printf("%s\n", memset(memset1, 'a', 5));
	printf("ft_memset chaine vide :");
	printf("%s\n", ft_memset(memset1, 'a', 5));

	//test 3
	printf("chaine vide pas assez de place vrai memset :");
	printf("%s\n", memset(memset1, 'a', 18));
	printf("chaine vide pas assez de place ft_memset :");
	printf("%s\n", ft_memset(memset1, 'a', 18));
	putchar('\n');
}

void		test_memcpy(void)
{
	printf("======== Test memcpy ========\n");

	char	*src = strdup("aaaaaaaaa");
	char	*dst = malloc(sizeof(char) * 10);
	char	*temoin_dst = malloc(sizeof(char) * 10);
	memcpy(dst, src, 9);
	memcpy(temoin_dst, src, 9);

	int toto;
	printf("test memcpy : ");
	for (toto = 0; toto < 10 ; toto++){
		memcpy(temoin_dst, src, toto);
		ft_memcpy(dst, src, toto);
		assert(strcmp(dst, temoin_dst) == 0);
	}
	printf("OK\n");
	putchar('\n');
}

void		test_strdup(void)
{
	printf("======= Test strdup =======\n");

	char	*s1 = malloc(sizeof(char) * 5);
	char	*s1ref = malloc(sizeof(char) * 5);
	char	*s2;
	char	*s2ref;
	//Test 1
	//	chaine normale
	s1 = "abcde";
	s1ref = "abcde";
	s2ref = strdup(s1ref);
	s2ref[2] = 'Z';
	printf("Resultat strdup test 1 : %s\n", s2ref);
	s2 = ft_strdup(s1);
	s2[2] = 'Z';
	printf("Resultat ft_strdup test 1 : %s\n", s2);
	printf("comparaison strcmp : %d\n", memcmp(s2ref, s2, ft_strlen(s2) + 1));
	putchar('\n');

	//Test 2
	//	chaine wtf
	s1 = ";8*_~";
	s1ref = ";8*_~";
	strdup(s1ref);
	printf("Resultat strdup test 2 : %s\n", strdup(s1ref));
	strdup(s1);
	printf("Resultat ft_strdup test 2 : %s\n", ft_strdup(s1));
	printf("comparaison strcmp : %d\n", strcmp(s1ref, s1));
	putchar('\n');

	//Test 3
	//	chaine vide
	s1 = "";
	s1ref = "";
	strdup(s1ref);
	printf("Resultat strdup chaine vide : %s\n", strdup(s1ref));
	strdup(s1);
	printf("Resultat ft_strdup chaine vide : %s\n", ft_strdup(s1));
	printf("comparaison strcmp : %d\n", strcmp(s1ref, s1));
	putchar('\n');
}

void		test_cat(void)
{
	printf("======= Test cat =======\n");
	int		fd;
	//int		i;

	fd = open("main.c", O_RDONLY);
	ft_cat(fd);
	//i = ft_cat(0);    0 soit 1. i = ft_cat
	//printf("Ft cat return: %d\n", i);
}

void		test_islower(void)
{
	printf("======= Test islower =====\n");

	printf("%d\n", ft_islower('D'));
	printf("%d\n", ft_islower('w'));
	printf("%d\n", ft_islower('f'));
	printf("%d\n", ft_islower('A'));
	printf("%d\n", ft_islower('a'));
	printf("%d\n", ft_islower('Z'));
	printf("%d\n", ft_islower('z'));
	printf("resut is 0110101\n");	
}

void		test_isupper(void)
{
	printf("======= Test isupper =====\n");

	printf("%d\n", ft_isupper('D'));
	printf("%d\n", ft_isupper('w'));
	printf("%d\n", ft_isupper('f'));
	printf("%d\n", ft_isupper('A'));
	printf("%d\n", ft_isupper('a'));
	printf("%d\n", ft_isupper('Z'));
	printf("%d\n", ft_isupper('z'));
	printf("result is 1001010\n");
}

void		test_strchr(void)
{
	printf("======= Test strchr ====\n");

	char *tmp = "toto";
	char *tmp1 = "toto";

	if (ft_strchr(tmp, 'o') == strchr(tmp1, 'o'))
		printf("ok\n");
	else	
		printf("fail");
}

void		test_isspace(void)
{
	printf("======= Test isspace =====\n");

	char c;

	c = '\v';
	if (ft_isspace(c))
		printf("first test k\n");
	c = '\n';
	ft_isspace(c);
	printf("test complete\n");

}

void		test_isallower(void)
{
	printf("====== Test isallower ======\n");

	char *tmp = "gehuhHUg\n";
	char *tmp1 = "ijeojihe\n";

	printf("%d\n", ft_isallower(tmp));
	printf("%d\n", ft_isallower(tmp1));

	printf("result is 0 1\n");
}

int			main(void)
{
	test_bzero();
	test_strcat();
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_puts();
	test_strlen();
	test_memset();
	test_memcpy();
	test_strdup();
	test_cat();
	test_islower();
	test_isupper();
	test_strchr();
	test_isspace();
	test_isallower();

	return (0);
}
