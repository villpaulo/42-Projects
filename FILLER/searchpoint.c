/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:34:38 by pvillene          #+#    #+#             */
/*   Updated: 2016/09/08 13:37:18 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/filler.h"

t_coor		*searchpoint(t_coor *z, char p)
{
	z = findposp(z, p);
	z = findposinv(z, z->inv);
	return (z);
}

t_coor		*findposp(t_coor *z, char p)
{
	while ((z->ret[0] + 1) <= z->i[0])
	{
		z->ret[1] = 0;
		while ((z->ret[1] + 1) <= z->i[1])
		{
			if (z->tab[z->ret[0]][z->ret[1]] == p)
			{
				return (z);
			}
			z->ret[1]++;
		}
		z->ret[0]++;
	}
	return (z);
}

t_coor		*findposinv(t_coor *z, char inv)
{
	int		i;

	while (z->x + 1 <= z->i[0])
	{
		i = 0;
		while (i + 1 <= z->i[1])
		{
			if (z->tab[z->x][i] == inv)
			{
				if (z->tab[z->x][i] == inv)
				{
					z = find(z->x, i, z);
					return (z);
				}
			}
			i++;
		}
		z->x++;
	}
	return (z);
}

t_coor		*find(int x, int y, t_coor *z)
{
	int		new;

	z->s = calcul(z->ret[0], z->ret[1], x, y);
	if ((new = calcul(z->ret[0] + 1, z->ret[1], x, y)) < z->s && new > 0)
		z->ret[0]++;
	else if ((new = calcul(z->ret[0] - 1, z->ret[1], x, y)) < z->s && new > 0)
		z->ret[0]--;
	else if ((new = calcul(z->ret[0], z->ret[1] + 1, x, y)) < z->s && new > 0)
		z->ret[1]++;
	else if ((new = calcul(z->ret[0], z->ret[1] - 1, x, y)) < z->s && new > 0)
		z->ret[1]--;
	else if ((new = calcul(z->ret[0], z->ret[1], x + 1, y)) < z->s && new > 0)
		x++;
	else if ((new = calcul(z->ret[0], z->ret[1], x - 1, y)) < z->s && new > 0)
		x--;
	else if ((new = calcul(z->ret[0], z->ret[1], x, y + 1)) < z->s && new > 0)
		y++;
	else if ((new = calcul(z->ret[0], z->ret[1], x, y - 1)) < z->s && new > 0)
		y--;
	else
		return (z);
	find(x, y, z);
	return (z);
}

int			calcul(int x, int y, int x2, int y2)
{
	int		res;
	t_coor	*z;

	z = singleton(NULL, 1);
	if (x == z->i[0] || y == z->i[1] || x2 == z->i[0] || y2 == z->i[1])
		return (0);
	if (x < 0 || y < 0 || x2 < 0 || y2 < 0)
		return (0);
	if (z->tab[x][y] != z->player)
		return (0);
	if (z->tab[x2][y2] != z->inv)
		return (0);
	res = ((x2 - x) * (x2 - x)) + ((y2 - y) * (y2 - y));
	if (res < 0)
		res = res * -1;
	return (res);
}
