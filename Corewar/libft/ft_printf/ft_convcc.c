/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convcc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 20:21:47 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:06:30 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdarg.h>
#include <wchar.h>

void	ft_printc(int t[15], char c)
{
	if (t[6] == 0)
	{
		ft_printzeroandspace(t, t[10], 1);
		ft_putcharx(c);
		t[7] = 0;
		if (t[4] == 2)
			ft_printzeroandspace(t, t[10], 1);
	}
	else
	{
		if (t[7] == 1)
			t[7] = 0;
		ft_putcharx(c);
		ft_printzeroandspace(t, t[10], 1);
	}
}

void	ft_printc_maj(int t[15], unsigned int c, int len)
{
	if (t[6] == 0 && t[10] != 0)
		ft_printzeroandspace(t, t[10], len);
	ft_putwcharx(c);
	t[7] = 0;
	if (t[4] == 2)
		ft_printzeroandspace(t, t[10], len);
	if (t[6] != 0 && t[10] != 0)
	{
		t[7] = 0;
		ft_printzeroandspace(t, t[10], len);
	}
}

void	ft_convcc(char c, int t[15], va_list ap)
{
	char	c1;
	wchar_t	c2;
	int		len;

	c1 = 0;
	c2 = 0;
	if (c == 'c' && t[14] != 3)
	{
		c1 = (char)va_arg(ap, int);
		if (c1 == (int)NULL)
			c1 = '\1';
		ft_printc(t, c1);
	}
	else
	{
		c2 = va_arg(ap, wchar_t);
		if (c2 == (wchar_t)NULL)
			c2 = '\1';
		len = ft_wchart_octet(c2);
		ft_printc_maj(t, c2, len);
	}
}
