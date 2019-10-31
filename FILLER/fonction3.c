/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:00:59 by pvillene          #+#    #+#             */
/*   Updated: 2016/09/08 14:22:11 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/filler.h"

int			repairresult1(t_coor *elem, int p, int modif)
{
	int		i;
	int		o;

	i = 0;
	o = modif - 1;
	elem->ret[1] = elem->ret2;
	elem->x = 0;
	while (i < (elem->i[1] - 1))
	{
		if ((elem->ret2 - i) >= 0)
		{
			elem->ret[1] = elem->ret2 - i;
			if (elem->tab[o][elem->ret[1]] == p)
				return (1);
		}
		if ((elem->ret2 + i) <= (elem->i[1] - 1))
		{
			elem->ret[1] = elem->ret2 + i;
			if (elem->tab[o][elem->ret[1]] == p)
				return (1);
		}
		i++;
	}
	elem->s = 1;
	return (0);
}

int			repairresult2(t_coor *elem, int p, int modif)
{
	int		i;
	int		o;

	i = 0;
	elem->s = 1;
	o = modif + 1;
	elem->ret[1] = elem->ret2;
	elem->x = 0;
	while (i < (elem->i[1] - 1))
	{
		if ((elem->ret2 - i) >= 0)
		{
			elem->ret[1] = elem->ret2 - i;
			if (elem->tab[o][elem->ret[1]] == p)
				return (1);
		}
		if ((elem->ret2 + i) <= (elem->i[1] - 1))
		{
			elem->ret[1] = elem->ret2 + i;
			if (elem->tab[o][elem->ret[1]] == p)
				return (1);
		}
		i++;
	}
	return (0);
}

int			repairresult3(t_coor *elem, int p, int modif)
{
	elem->ret[1] = elem->x;
	while (elem->x <= (elem->i[1] - 1))
	{
		if (elem->tab[modif][elem->ret[1]] == p)
		{
			elem->x++;
			return (1);
		}
		elem->x++;
		elem->ret[1] = elem->x;
	}
	return (0);
}
