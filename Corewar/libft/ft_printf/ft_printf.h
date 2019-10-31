/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:48:45 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/19 18:49:00 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./../libft/libft.h"
# include <stdarg.h>

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
