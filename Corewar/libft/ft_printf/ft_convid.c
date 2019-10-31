/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 04:24:26 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:05:53 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>

int			ft_gesneg(int t[15], char *s, int len)
{
	int tmp;

	tmp = len;
	if (t[11] >= len)
	{
		if (s[0] == '-')
		{
			t[11]++;
			tmp = t[11];
		}
		else
			tmp = t[11];
	}
	if (s[0] != '-' && (t[8] == 1 || t[9] == 1))
		tmp++;
	return (tmp);
}

void		ft_printid2(int t[15], char *str, int len, int tmp)
{
	ft_printsigne(t, str);
	if (t[11] > 0)
	{
		t[7] = 1;
		ft_printzeroandspace(t, t[11], len);
	}
	t[7] = 0;
	if (str[0] == '-')
	{
		ft_putstrx(ft_strsub(str, 1, ft_strlen(str + 1)));
		free(str);
	}
	else
		ft_putstrx(str);
	ft_printzeroandspace(t, t[10], tmp);
}

void		ft_printid(int t[15], char *str, int len)
{
	int tmp;

	tmp = ft_gesneg(t, str, len);
	if (t[6] == 0)
	{
		if (t[7] == 0)
			ft_printzeroandspace(t, t[10], tmp);
		ft_printsigne(t, str);
		if (t[7] != 0)
			ft_printzeroandspace(t, t[10], tmp);
		t[7] = 1;
		ft_printzeroandspace(t, t[11], len);
		if (str[0] == '-')
		{
			ft_putstrx(ft_strsub(str, 1, ft_strlen(str + 1)));
			free(str);
		}
		else
			ft_putstrx(str);
	}
	else
		ft_printid2(t, str, len, tmp);
}

long long	ft_convsigned(int t[15], va_list ap)
{
	if (t[14] == 0)
		return ((int)va_arg(ap, int));
	else if (t[14] == 1)
		return ((char)va_arg(ap, int));
	else if (t[14] == 2)
		return ((short)va_arg(ap, int));
	else if (t[14] == 3)
		return ((long)va_arg(ap, long));
	else if (t[14] == 4)
		return (va_arg(ap, long long));
	else if (t[14] == 5)
		return ((intmax_t)va_arg(ap, intmax_t));
	else if (t[14] == 6)
		return ((size_t)va_arg(ap, size_t));
	return (0);
}

void		ft_convid(int t[15], va_list ap)
{
	char		*str;
	long long	i;
	int			len;

	i = ft_convsigned(t, &(*ap));
	str = ft_lltoa(i);
	if (i == 0 && t[11] == -1)
	{
		free(str);
		str = ft_strdup("\0");
		t[5] = 0;
	}
	if (t[11] != 0)
		t[7] = 0;
	if (t[8] == 1)
		t[9] = 0;
	len = ft_strlen(str);
	ft_printid(t, str, len);
	len = ft_gesneg(t, str, len);
	t[7] = 0;
	if (t[4] == 2)
		ft_printzeroandspace(t, t[10], len);
}
