/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:42:21 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 13:37:54 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdarg.h>

int		ft_printother(char c, int t[15])
{
	if (t[6] == 1)
		t[7] = 0;
	if (t[10] == 0 || t[10] == 1)
	{
		ft_putcharx(c);
		return (1);
	}
	else
	{
		if (t[6] == 0)
		{
			ft_printzeroandspace(t, t[10], 1);
			ft_putcharx(c);
		}
		else
		{
			ft_putcharx(c);
			ft_printzeroandspace(t, t[10], 1);
		}
		return (t[10]);
	}
}

void	ft_printconv(char c, int t[15], va_list ap)
{
	if (c == 's' || c == 'S')
		ft_convss(c, t, &(*ap));
	if (c == 'i' || c == 'd')
		ft_convid(t, &(*ap));
	if (c == 'p' || c == 'D')
		ft_convpd(c, t, &(*ap));
	if (c == 'o' || c == 'u' || c == 'b')
		ft_convoub(c, t, &(*ap));
	if (c == 'O' || c == 'U' || c == 'B')
		ft_convoub_maj(c, t, &(*ap));
	if (c == 'x' || c == 'X')
		ft_convxx(c, t, &(*ap));
	if (c == 'c' || c == 'C')
		ft_convcc(c, t, &(*ap));
	if (c == 'n')
		t[3] = va_arg(ap, int);
}

void	ft_print(char c, int t[15], va_list ap)
{
	if (c == 's' || c == 'S' || c == 'd' || c == 'p' || c == 'i' || c == 'o'
			|| c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
			|| c == 'c' || c == 'C' || c == 'D' || c == 'b' || c == 'B'
			|| c == 'n')
		ft_printconv(c, t, &(*ap));
	else
		ft_printother(c, t);
}
