/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convpd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:55:11 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:05:33 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>

void	ft_printp2(int t[15], char *str, int len, int tmp)
{
	ft_printzerox(t, str, 'p');
	if (t[11] > 0)
	{
		t[7] = 1;
		ft_printzeroandspace(t, t[11], len);
	}
	t[7] = 0;
	ft_putstrx(str);
	ft_printzeroandspace(t, t[10], tmp);
}

void	ft_printp(int t[15], char *str, int len)
{
	int tmp;

	t[5] = 2;
	tmp = len + t[5];
	if (t[11] > len + t[5])
		tmp = t[11];
	if (t[6] == 0)
	{
		if (t[7] == 0)
			ft_printzeroandspace(t, t[10], tmp);
		ft_printzerox(t, str, 'p');
		if (t[7] == 1)
			ft_printzeroandspace(t, t[10], tmp);
		t[7] = 1;
		ft_printzeroandspace(t, t[11], len);
		ft_putstrx(str);
		t[7] = 0;
		if (t[4] == 2)
			ft_printzeroandspace(t, t[10], (tmp));
	}
	else
		ft_printp2(t, str, len, tmp);
}

void	ft_convpd(char c, int t[15], va_list ap)
{
	char			*str;
	unsigned long	i;

	if (c == 'D')
	{
		t[14] = 4;
		ft_convid(t, &(*ap));
	}
	else
	{
		i = (unsigned long)va_arg(ap, unsigned long);
		str = ft_lltoa_base_min(i, 16);
		if (i == 0)
		{
			free(str);
			if (t[11] == -1)
				str = ft_strdup("\0");
			else
				str = ft_strdup("0");
		}
		if (t[11] != 0)
			t[7] = 0;
		ft_printp(t, str, ft_strlen(str));
	}
}
