/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftasm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:53:31 by pvillene          #+#    #+#             */
/*   Updated: 2015/05/16 13:54:34 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTASM_H
# define LIBFTASM_H


int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *mem, int c, size_t n);
char			*ft_strchr(const char *src, int n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_cat(int fd);
int				ft_islower(int c);
int				ft_isupper(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);


#endif
