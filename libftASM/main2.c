/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeldame <tbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:51:11 by tbeldame          #+#    #+#             */
/*   Updated: 2015/05/27 14:37:48 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include "libftasm.h"
#include <ctype.h>
#include <fcntl.h>

int		main(void)
{
	char	*name = getenv("LOGNAME");
	char	*test1;
	char	*test2;
	char	*test3;
	int		a;
	int		i;

	/*		TEST BZERO		*/
	printf("Press return to continue");  
	getchar();
	usleep(100000);
	printf("\033[1m\033[32mTesting ft_bzero\033[39m\n");
	test1 = strdup("Bonjour");
	printf("\033[94mOriginal String :\033[39m\n");
	for (i = 0; i <= 7; i++)
		printf("[%c] ", test1[i]);
	printf("\n\033[94mbzero :\033[39m\n");
	bzero(test1, 7);
	for (i = 0; i <= 7; i++)
		printf("[%c] ", test1[i]);
	free(test1);
	test1 = strdup("Bonjour");
	printf("\n\033[94mft_bzero :\033[39m\n");
	ft_bzero(test1, 7);
	for (i = 0; i <= 7; i++)
		printf("[%c] ", test1[i]);
	free(test1);


	/*		TEST STRCAT		*/
	printf("\n\n\nPress return to continue");  
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_strcat\033[39m\n");
	test1 = malloc(sizeof(char) * 20);
	test3 = malloc(sizeof(char) * 20);
	test1 = strcpy(test1, "Bonjour");
	test2 = "Salut";
	test3 = strcpy(test3, "Bonjour");

	printf("\033[94mOriginal String :\033[39m\n");
	printf("%s", test1);
	
	printf("\n\033[94mstrcat \"Salut\" :\033[39m\n");
	strcat(test1, test2);
	printf("%s", test1);
	
	printf("\n\033[94mft_strcat \"Salut\" :\033[39m\n");
	strcat(test3, test2);
	printf("%s", test3);
	
	free(test1);
	free(test3);


	/*		TEST ISALPHA		*/
	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_isalpha\033[39m\n");
	for (a = 0; (int)a <128; a++)
		printf("Char : %c  |  \033[94misalpha : \033[39m%d  |  \033[94mft_isalpha : \033[39m%d\n", a, isalpha(a), ft_isalpha(a));


	/*		TEST ISDIGIT		*/
	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_isdigit\033[39m\n");
	for (a = 0; (int)a <128; a++)
		printf("Char : %c  |  \033[94misdigit : \033[39m%d  |  \033[94mft_isdigit : \033[39m%d\n", a, isdigit(a), ft_isdigit(a));

	/*		TEST ISALNUM		*/
	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_isalnum\033[39m\n");
	for (a = 0; (int)a <128; a++)
		printf("Char : %c  |  \033[94misalnum : \033[39m%d  |  \033[94mft_isalnum : \033[39m%d\n", a, isalnum(a), ft_isalnum(a));

	/*		TEST ISASCII		*/
	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_isascii\033[39m\n");
	for (a = -1; (int)a <129; a++)
		printf("Char : %c  |  \033[94misascii : \033[39m%d  |  \033[94mft_isascii : \033[39m%d\n", a, isascii(a), ft_isascii(a));

	/*		TEST ISPRINT		*/
	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_isprint\033[39m\n");
	for (a = 0; (int)a <128; a++)
		printf("Char : %c  |  \033[94misprint : \033[39m%d  |  \033[94mft_isprint : \033[39m%d\n", a, isprint(a), ft_isprint(a));

	/*		TEST TOUPPER		*/
	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_toupper\033[39m\n");
	printf("Char : A  |  \033[94mtoupper : \033[39m%c  |  \033[94mft_toupper : \033[39m%c\n", toupper('A'), ft_toupper('A'));
	printf("Char : b  |  \033[94mtoupper : \033[39m%c  |  \033[94mft_toupper : \033[39m%c\n", toupper('b'), ft_toupper('b'));
	printf("Char : 5  |  \033[94mtoupper : \033[39m%c  |  \033[94mft_toupper : \033[39m%c\n", toupper('5'), ft_toupper('5'));
	printf("Char : .  |  \033[94mtoupper : \033[39m%c  |  \033[94mft_toupper : \033[39m%c\n", toupper('.'), ft_toupper('.'));

	/*		TEST TOLOWER		*/
	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_tolower\033[39m\n");
	printf("Char : C  |  \033[94mtolower : \033[39m%c  |  \033[94mft_tolower : \033[39m%c\n", tolower('C'), ft_tolower('C'));
	printf("Char : x  |  \033[94mtolower : \033[39m%c  |  \033[94mft_tolower : \033[39m%c\n", tolower('x'), ft_tolower('x'));
	printf("Char : 9  |  \033[94mtolower : \033[39m%c  |  \033[94mft_tolower : \033[39m%c\n", tolower('9'), ft_tolower('9'));
	printf("Char : #  |  \033[94mtolower : \033[39m%c  |  \033[94mft_tolower : \033[39m%c\n", tolower('#'), ft_tolower('#'));

	/*		TEST PUTS		*/
	int		ret;
	int		stdout_cpy;

	test1 = "Bonjour";
	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_puts\033[39m\n");
	printf("\033[32mString : %s\033[39m\n", test1);
	printf("\033[94m   puts : \033[39m");
	ret = puts(test1);
	printf("\033[94m   ret : \033[39m%d\n", ret);
	printf("\033[94m   ft_puts : \033[39m");
	fflush(stdout);
	ret = ft_puts(test1);
	printf("\033[94m   ret : \033[39m%d\n", ret);
	test1 = NULL;
	printf("\033[32mString : %s\033[39m\n", test1);
	printf("\033[94m   puts : \033[39m");
	ret = puts(test1);
	printf("\033[94m   ret : \033[39m%d\n", ret);
	printf("\033[94m   ft_puts : \033[39m");
	fflush(stdout);
	ret = ft_puts(test1);
	printf("\033[94m   ret : \033[39m%d\n", ret);
	printf("\033[32mError test (closed stdout)\033[39m\n");
	printf("\033[94m   puts ret: \033[39m");
	fflush(stdout);
	stdout_cpy = dup(1);
	close(1);
	ret = puts("lol");
	dup2(stdout_cpy, 1);
	printf("%d\n", ret);
	printf("\033[94m   ft_puts ret: \033[39m");
	stdout_cpy = dup(1);
	close(1);
	ret = ft_puts("lol");
	dup2(stdout_cpy, 1);
	printf("%d", ret);
	free(test1);

	/*		TEST STRLEN		*/
	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_strlen\033[39m\n");
	test1 = "Bonjour";
	printf("\033[32mString : \033[39m%s\033[39m\n", test1);
	printf("\033[94m    strlen : \033[39m%lu\n \033[94m   ft_strlen : \033[39m%lu\n", strlen(test1), ft_strlen(test1));
	test1 = ".";
	printf("\033[32mString : \033[39m%s\033[39m\n", test1);
	printf("\033[94m    strlen : \033[39m%lu\n \033[94m   ft_strlen : \033[39m%lu", strlen(test1), ft_strlen(test1));

	/*		TEST MEMSET		*/
	printf("\n\n\nPress return to continue");  
	getchar();
	usleep(100000);
	a = 'u';
	printf("\033[1m\033[32mTesting ft_memset\033[39m\n");
	test1 = strdup("Bonjour");
	printf("\033[94mOriginal String :\033[39m\n");
	for (i = 0; i <= 7; i++)
		printf("[%c] ", test1[i]);
	printf("\n\033[94mmemset (val = %c | size = 8) :\033[39m\n", a);
	memset(test1, a, 8);
	for (i = 0; i <= 7; i++)
		printf("[%c] ", test1[i]);
	free(test1);
	test1 = strdup("Bonjour");
	printf("\n\033[94mft_memset (val = %c | size = 8) :\033[39m\n", a);
	ft_memset(test1, a, 8);
	for (i = 0; i <= 7; i++)
		printf("[%c] ", test1[i]);


	/*		TEST MEMCPY		*/
	printf("\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_memcpy\033[39m\n");
	test3 = "Salut !";
	test1 = malloc(20);
	test2 = malloc(20);
	printf("\033[94mOriginal String :\033[39m\n");
	printf("%s", test3);
	printf("\n\033[94mmemcpy (8) :\033[39m\n");
	test1 = memcpy(test1, test3, 8);
	printf("%s", test1);
	printf("\n\033[94mft_memcpy (8) :\033[39m\n");
	test2 = ft_memcpy(test2, test3, 8);
	printf("%s", test2);


	/*		TEST STRDUP		*/
	printf("\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_strdup\033[39m\n");
	test3 = "Bonjour.";
	printf("\033[94mOriginal String :\033[39m\n");
	printf("%s", test3);
	printf("\n\033[94mstrdup :\033[39m\n");
	test1 = strdup(test3);
	printf("%s", test1);
	printf("\n\033[94mft_strdup :\033[39m\n");
	test2 = ft_strdup(test3);
	printf("%s", test2);


	/*		TEST CAT		*/
	FILE *f;
	test1 = "Bonjour, je suis un fchier";
	printf("\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_cat\033[39m\n");
	f = fopen("file", "w");
	fputs(test1, f);
	printf("\033[94mString in file : \033[39m\n%s\n", test1);
	printf("\033[94mft_cat :\033[39m\n");
	fclose(f);
	int fd = open("file", O_RDONLY);
	ft_cat(fd);

	/*						*/
	/*		BONUS PART		*/
	/*						*/

	printf("\n\n\n\e[91m||\e[93m||\e[92m||\e[96m||\e[94m||\e[95m||\e[34m");
	printf("\n\033[96m BONUS PART\033[34m");
	printf("\n\e[91m||\e[93m||\e[92m||\e[96m||\e[94m||\e[95m||\e[34m");

	/*		TEST ISSPACE		*/
/*	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_isspace\033[39m\n");
	for (a = 0; (int)a <128; a++)
		printf("Char : %c  |  \033[94misspace : \033[39m%d  |  \033[94mft_isspace : \033[39m%d\n", a, isspace(a), ft_isspace(a));

*/
	/*		TEST ISUPPER		*/
	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_isupper\033[39m\n");
	for (a = 0; (int)a <128; a++)
		printf("Char : %c  |  \033[94misupper : \033[39m%d  |  \033[94mft_isupper : \033[39m%d\n", a, isupper(a), ft_isupper(a));


	/*		TEST ISLOWER		*/
	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_islower\033[39m\n");
	for (a = 0; (int)a <128; a++)
		printf("Char : %c  |  \033[94mislower : \033[39m%d  |  \033[94mft_islower : \033[39m%d\n", a, islower(a), ft_islower(a));


	/*		TEST MEMCMP		*/
/*	printf("\n\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_memcmp\033[39m\n");
	test1 = strdup("Bonjour, ca va ?");
	test1 = strdup("Bonjour correcteur ?");
	printf("\033[94mOriginal Strings :\033[39m\n");
	printf("%s\n", test1);
	printf("%s\n", test2);
	printf("\033[94mmemcmp (7) :\033[39m ");
	printf("%d\n", memcmp(test1, test2, 7));
	printf("\033[94mmemcmp (10) :\033[39m ");
	printf("%d\n", memcmp(test1, test2, 10));
	printf("\033[94mft_memcmp (7) : \033[39m ");
	printf("%d\n", ft_memcmp(test1, test2, 7));
	printf("\033[94mft_memcmp (10) : \033[39m ");
	printf("%d\n", ft_memcmp(test1, test2, 10));
	
*/
	/*		TEST STRCPY		*/
/*	printf("\n\nPress return to continue");
	getchar();
	usleep(100000);
	printf("\033[32mTesting ft_strcpy\033[39m\n");
	test3 = "Bonjour !";
	test1 = malloc(20);
	test2 = malloc(20);
	printf("\033[94mOriginal String :\033[39m\n");
	printf("%s", test3);
	printf("\n\033[94mstrcpy :\033[39m\n");
	strcpy(test1, test3);
	printf("%s", test1);
	printf("\n\033[94mftstrcpy :\033[39m\n");
	ft_strcpy(test2, test3);
	printf("%s", test1);
*/

	printf("\n\nCreated by %s\n", name);
}
