/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:30:02 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/11 18:53:57 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>
# define BUFF_SIZE 10

typedef struct		s_lst
{
	void			*data;
	size_t			size;
	struct s_lst	*next;
}					t_lst;

/*
**	libft de base
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_lstaddback(t_lst **alst, t_lst *new);
t_lst				*ft_lstpushback(t_lst **alst, void *data, size_t csize);
t_lst				*ft_lstnew(void *content, size_t content_size);
void				ft_lstdelone(t_lst **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_lst **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_lst **alst, t_lst *new);
void				ft_lstiter(t_lst *lst, void (*f)(t_lst *elem));
t_lst				*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *elem));
char				*ft_itoa_base(int nb, char base);
void				ft_putnbr_base(int n, char base);
int					ft_iscntrl(int c);
int					ft_islower(int c);
int					ft_ispunct(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);

/*
**	get_next_line.c
*/

int					get_next_line(int const fd, char **line);
char				*ft_read(int cpt, int const fd, char **str, int tab[3]);
char				*ft_strjoingnl(char **s1, char *s2, int *cpt, int tab[4]);
void				ft_cpy(char **str, int tab[3], char **line);

/*
**	Pour le Printf
*/

char				*ft_strpbrk(const char *s1, const char *s2);
char				*ft_strsub_f(char *s, unsigned int start, size_t len);
char				**ft_strsplit_save(char **s, char c);
char				*ft_lltoa(long long n);
char				*ft_lltoa_base(unsigned long long nb, char base);
char				*ft_lltoa_base_min(unsigned long long nb, char base);
void				ft_putnstr(const char *s, size_t len);
void				ft_putnwstr(const wchar_t *s, size_t len);
void				ft_putwchar(wchar_t c);
void				ft_putwstr(const wchar_t *s);
void				ft_putxchar(char c, int i);
size_t				ft_wcslen(const wchar_t *s);
size_t				ft_wchart_octet(wchar_t s);
size_t				ft_wcslen_octet(wchar_t *s);
size_t				ft_wcslen_noctet(wchar_t *s, size_t max);
void				ft_putcharx(char c);
void				ft_putwstrx(wchar_t *str);
void				ft_putstrx(char *s);
void				ft_putnstrx(const char *s, size_t len);
void				ft_putnwstrx(const wchar_t *s, size_t len);
void				ft_putwcharx(wchar_t c);
void				ft_putxcharx(char c, int i);
int					ft_putstrz(char *s, int i, int len);

/*
**	Les fonctions du ./ft_printf
*/
int					ft_printf(const char *str, ...);
void				ft_flag(char *str, int t[15], int len, va_list ap);

void				ft_convcc(char c, int t[15], va_list ap);
void				ft_convoub(char c, int t[15], va_list ap);
void				ft_convoub_maj(char c, int t[15], va_list ap);
void				ft_convpd(char c, int t[15], va_list ap);
void				ft_convxx(char c, int t[15], va_list ap);
void				ft_convid(int t[15], va_list ap);
void				ft_convss(char c, int t[15], va_list ap);

int					ft_geslenmod(char *str, int i, int j);
unsigned long long	ft_convuns(int tab[15], va_list ap);
int					ft_lennb(int t[15], char c, int len);
int					ft_lens(int t[15], int len);

void				ft_printzerox(int t[15], char *s, char c);
void				ft_printzeroandspace(int t[15], int v, int len);
void				ft_printsigne(int t[15], char *s);
void				ft_print(char c, int t[15], va_list ap);
void				ft_printcolor(char *s, int t[15]);

int					ft_wildprec(va_list ap);
int					ft_wildlenmin(int t[15], va_list ap);
void				ft_wildcard(char *s, int t[15], int v[3], va_list ap);

int					ft_gescentr(char *s, int t[15], int v[3], va_list ap);

#endif
