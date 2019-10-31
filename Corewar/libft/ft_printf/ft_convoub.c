/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convoub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 20:02:24 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:05:43 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>

unsigned long long	ft_convuns(int t[15], va_list ap)
{
	unsigned long long i;

	i = 0;
	if (t[14] == 0)
		i = (unsigned int)va_arg(ap, unsigned int);
	else if (t[14] == 1)
		i = (unsigned char)va_arg(ap, int);
	else if (t[14] == 2)
		i = (unsigned short)va_arg(ap, int);
	else if (t[14] == 3)
		i = (unsigned long)va_arg(ap, unsigned long);
	else if (t[14] == 4)
		i = va_arg(ap, unsigned long long);
	else if (t[14] == 5)
		i = (uintmax_t)va_arg(ap, uintmax_t);
	else if (t[14] == 6)
		i = (size_t)va_arg(ap, size_t);
	return (i);
}

void				ft_printoub2(int t[15], char *str, char c, int len)
{
	int tmp;

	tmp = len + t[5];
	if (t[11] > len + t[5])
		tmp = t[11];
	if (t[11] != 0)
	{
		t[7] = 1;
		ft_printzeroandspace(t, t[11], len);
	}
	t[7] = 0;
	ft_printzerox(t, str, c);
	ft_putstrx(str);
	ft_printzeroandspace(t, t[10], (tmp));
}

void				ft_printoub(int t[15], char *str, char c, int len)
{
	int	tmp;

	tmp = len + t[5];
	if (t[11] > len + t[5])
		tmp = t[11];
	if (t[6] == 0)
	{
		ft_printzeroandspace(t, t[10], (tmp));
		t[7] = 1;
		ft_printzerox(t, str, c);
		ft_printzeroandspace(t, t[11], len + t[5]);
		ft_putstrx(str);
		t[7] = 0;
		if (t[4] == 2)
			ft_printzeroandspace(t, t[10], (tmp));
	}
	else
		ft_printoub2(t, str, c, len);
}

void				ft_convoub(char c, int t[15], va_list ap)
{
	char				*str;
	unsigned long long	i;
	int					len;

	i = ft_convuns(t, &(*ap));
	if (c == 'u')
		str = ft_lltoa_base(i, 10);
	else if (c == 'o')
		str = ft_lltoa_base(i, 8);
	else
		str = ft_lltoa_base(i, 2);
	if (i == 0 && t[11] == -1 && t[5] == 0)
	{
		free(str);
		str = ft_strdup("\0");
	}
	if (t[11] != 0)
		t[7] = 0;
	len = ft_strlen(str);
	if (t[11] < len)
		t[11] = 0;
	ft_printoub(t, str, c, len);
}

void				ft_convoub_maj(char c, int t[15], va_list ap)
{
	t[14] = 4;
	if (c == 'U')
		ft_convoub('u', t, &(*ap));
	else if (c == 'O')
		ft_convoub('o', t, &(*ap));
	else
		ft_convoub('b', t, &(*ap));
}
