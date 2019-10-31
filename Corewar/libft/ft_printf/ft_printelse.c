/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printelse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:58:23 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 13:38:30 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

void	ft_printzeroandspace(int t[15], int v, int len)
{
	if (t[7] == 1 && (v - len) > 0)
		ft_putxcharx('0', (v - len));
	else if ((v - len) > 0)
	{
		if (t[4] == 0)
			ft_putxcharx(' ', (v - len));
		else if (t[4] == 1)
		{
			ft_putxcharx(' ', ((v - len) / 2));
			t[4] = 2;
		}
		else if (t[4] == 2)
		{
			if ((len % 2) == 0)
				ft_putxcharx(' ', ((v - len) / 2));
			else
				ft_putxcharx(' ', (((v - len) / 2) + 1));
		}
	}
}

void	ft_printsigne(int t[15], char *s)
{
	if (t[8] == 1 && s[0] != '-')
		ft_putcharx('+');
	if (s[0] == '-')
		ft_putcharx('-');
	if (t[9] == 1 && s[0] != '-')
		ft_putcharx(' ');
}

void	ft_printzerox(int t[15], char *s, char c)
{
	if ((ft_strcmp(s, "0") == 0) && (c == 's' || c == 'o' || c == 'b'))
		t[5] = 0;
	if (t[5] > 0)
	{
		if (c == 'X')
			ft_putstrx(ft_strdup("0X"));
		else if (c == 'x' || c == 'p')
			ft_putstrx(ft_strdup("0x"));
		else if (c == 'o' || c == 'O')
			ft_putcharx('0');
		else if (c == 'b')
			ft_putstrx(ft_strdup("0b"));
	}
}
