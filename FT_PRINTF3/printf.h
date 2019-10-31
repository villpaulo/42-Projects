/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:32:59 by pvillene          #+#    #+#             */
/*   Updated: 2016/11/24 08:59:37 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define IMIN -2147483648
# define IMAX 2147483647

typedef struct	s_element
{
	char		c;
	char		*(*f)(va_list ap, int *tab);
}				t_element;

typedef struct	s_ret
{
	char		*buffer;
	long long	size;
}				t_ret;

char			*print_len(char *str, int i);
int				ft_strlen(char *str);
int				count_len(int nbr);
char			*ft_strdup(char *str);
char			*ft_itoa(int nbr);
int				ft_isdigit(int c);
int				*ft_zero(int *tab, int size);
int				ft_atoi(char *str);

char			*ft_strcopy(char *s1, char *s2);
char			*ft_strndup(char *str, int n);
char			*ft_strjoin(char *s1, char *s2);
char			*checkelement(int *tab, char *p, int i, va_list ap);
int				count(char *p, int i);
int				checkmodif(char *p, int j, char *p2, int i);
int				*applymodif(int i, char *p, int *tab, char *p2);
t_ret			*ft_vsprintf(char *p, va_list ap);
t_ret			*ft_vsprintf2(char *p, va_list ap, int *tab, t_ret *elem);
char			*repairvsprint(char *str, char *p, int k, int i);
int				ft_sprintf(char *buffer, char *p, ...);
int				ft_printf(char *p, ...);

void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*niquetam(char *str);
char			*ft_putnbr(long long n, int base, int b);
char			*ft_putnbrx(unsigned long n, unsigned long base, char *str);
char			*ft_putnbrx2(unsigned long n, int base);
char			*print_c(va_list ap, int *tab);
char			*print_c2(va_list ap, int *tab);
char			*print_s(va_list ap, int *tab);
char			*print_s2(va_list ap, int *tab);
char			*print_d(va_list ap, int *tab);
char			*print_p(va_list ap, int *tab);
char			*print_d2(va_list ap, int *tab);
char			*print_i(va_list ap, int *tab);
char			*print_o(va_list ap, int *tab);
char			*print_o2(va_list ap, int *tab);
char			*print_u(va_list ap, int *tab);
char			*print_u2(va_list ap, int *tab);
char			*print_x(va_list ap, int *tab);
char			*print_x2(va_list ap, int *tab);
char			*print_s3(wchar_t n);
char			*print_modulo(int *tab);
char			*ret_c(char c, int *tab);
char			*ret_s(char *n, int *tab);
char			*ret_s2(char *str, int *tab);
char			*ret_d(long n, int *tab, int b);
char			*ret_p(char *str, int *tab);
char			*ret_i(int n, int *tab, int b);
char			*ret_o(char *str, int *tab);
char			*ret_o2(char *str, int *tab);
char			*ret_u(int n, int *tab, int b);
char			*ret_x(char *str, int *tab, int ne);
char			*ret_x2(char *str, int *tab);
char			*ret_modulo(int *tab);

unsigned long	conver_x(int *tab, unsigned long n, va_list ap);
unsigned long	conver_x2(int *tab, unsigned long n, va_list ap);
int				*conver_c(int *tab);
long			conver_d(int *tab, long n, va_list ap);
unsigned long	conver_u(int *tab, unsigned long n, va_list ap);
unsigned long	conver_o(int *tab, unsigned long n, va_list ap);
long			conver_d2(int *tab, long n, va_list ap);

char			*fill(char *n, int i, int j);
char			*fillz(char *n, int i, int j);
char			*fillz2(char *str, int c);
char			*copy(char *str, char *ret, int i, int z);
char			*copystring(char *str, char *ret, int i, int z);
char			*checkfill(char *str, int j, int n, int z);
char			*filldxx(char *str, int *tab, unsigned long n);
char			*filldx2(char *ret, char *str, int *tab);
char			*filldx3(char *str);
char			*filldx(char *str, int *tab, unsigned long n);
char			*filldxp(char *str, int *tab);
char			*filldx2(char *ret, char *str, int *tab);
char			*filldx22(char *ret, char *str, int *tab);
char			*filldx33(char *str);
char			*filldo(char *str);
int				jump(char *p, int k, int i);
int				jump2(char *p, int i);
char			*add_char1(wchar_t n);
char			*add_char2(wchar_t n);
char			*add_char3(wchar_t n);
char			*add_char4(wchar_t n);
int				checkmodulo(char *p, int i);
char			*retz(char *str);
char			*flag6s(char *n, int *tab);
char			*flagpos(char *str, int *tab);
char			*flag4d(char *str);
char			*retspace(char *str);
int				ft_strlen2(int n);
char			*replacez(char *str);
int				searchc(char	*p, int i);
char			*retcz(char *str, int *tab);
int				searchsempty(char *str);
char			*replace(char *str);
char			*fillp(char *str, int i, int j);
char			*retuz(char *str, int *tab);
char			*ft_strnew(size_t size);
int				ft_strlen3(unsigned long n, int i);
char			*fillrepair2(char *str);
int				*repairdeg(int *tab, char *modifier, char *p, int i);
int				norme1(char *p, int i);
int				norme2(int j, char *p, int i);
int				norme3(int k);
char			*copystringl(char *str, char *toto, int i, int l);
char			*printdrep(int *tab, int b);
char			*printdrep2(int *tab, int b, char *str, long long int n);
char			*print_xrep(char *str, int ne, unsigned long n, int *tab);
void			print_xrep2(int *tab);
char			*print_xxrep(char *str, unsigned long n, int *tab);
char			*print_orep(char *str, int *tab, unsigned long n);
char			*ft_putnbr2(int i, int base, int b, int *tab);
char			*ret_modulo2(int *tab, char *str, int i);
char			*ret_d2(int *tab, char *str, int j, int z);

#endif
