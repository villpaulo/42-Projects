/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:00:50 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:05:08 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <stdarg.h>

void	ft_centrx(int t[15], int len)
{
	t[7] = 0;
	if (t[4] == 2)
		ft_printzeroandspace(t, t[10], len);
}

void	ft_printxx2(int t[15], char *str, int len, int tmp)
{
	t[7] = 0;
	if (t[11] > 0)
	{
		t[7] = 1;
		ft_printzeroandspace(t, t[11], len);
		t[7] = 0;
	}
	ft_putstrx(str);
	ft_printzeroandspace(t, t[10], tmp);
}

void	ft_printxx(int t[15], char *str, char c, int len)
{
	int tmp;

	if (t[5] == 1)
		t[5] = 2;
	tmp = len + t[5];
	if (t[11] > len + t[5])
		tmp = t[11];
	if (t[6] == 0)
	{
		if (t[7] == 0 && t[10] != 0)
			ft_printzeroandspace(t, t[10], tmp);
		ft_printzerox(t, str, c);
		if (t[7] == 1 && t[10] != 0)
			ft_printzeroandspace(t, t[10], tmp);
		t[7] = 1;
		ft_printzeroandspace(t, t[11], len);
		ft_putstrx(str);
	}
	else
	{
		ft_printzerox(t, str, c);
		ft_printxx2(t, str, len, tmp);
	}
}

void	ft_convxx(char c, int t[15], va_list ap)
{
	char				*str;
	unsigned long long	i;
	int					len;

	i = ft_convuns(t, &(*ap));
	if (c == 'X')
		str = ft_lltoa_base(i, 16);
	else
		str = ft_lltoa_base_min(i, 16);
	if (i == 0)
	{
		if (t[11] == -1)
		{
			free(str);
			str = ft_strdup("\0");
		}
		t[5] = 0;
	}
	if (t[11] != 0)
		t[7] = 0;
	len = ft_strlen(str);
	if (t[11] < len)
		t[11] = 0;
	ft_printxx(t, str, c, len);
}
