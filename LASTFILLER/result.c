/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:18:41 by pvillene          #+#    #+#             */
/*   Updated: 2016/09/08 14:22:09 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/filler.h"

t_coor		*result(t_coor *z, char p)
{
	z->x = 0;
	while ((z->ret[1] + 1) <= z->i[1])
	{
		if (solution(z, z->ret[0], z->ret[1], p) == 1)
			return (z);
		else if (!(repairresult3(z, p, z->ret[0])))
			break ;
	}
	if (z->s == 0 && (z->ret[0] - 1) >= 0 && repairresult1(z, p, z->ret[0]))
		z->ret[0]--;
	else if (z->ret[0] <= z->i[0] && repairresult2(z, p, z->ret[0]))
		z->ret[0]++;
	else
		return (NULL);
	z = result(z, p);
	return (z);
}

int			solution(t_coor *z, int i, int j, char p)
{
	t_res	*res;

	res = (t_res *)malloc(sizeof(t_res) * 1);
	res = initres(res, i, j);
	if (z->tab[i][j] != p)
		return (0);
	while (z->pi[res->c = 0][res->solv])
	{
		while (z->pi[res->c] != NULL)
		{
			res = initres2(res, i, j);
			z->recup[0] = res->c;
			z->recup[1] = res->solv;
			if (solution2(res, z, p))
				return (1);
			res->c = res->savec;
			if ((i - (res->c + 1)) < 0 || (res->c + 1) >= z->p[0])
				break ;
			res->c++;
		}
		res->solv++;
	}
	return (0);
}

int			solution2(t_res *r, t_coor *z, char p)
{
	int rep;
	int v;

	rep = 0;
	r->savec = r->c;
	while (z->pi[r->c] != NULL && z->tab[r->k2[0]] != NULL)
	{
		if (!repair(r->solv, r, z, &v))
			return (0);
		while (z->pi[r->c][++v] && z->tab[r->k2[0]][++r->k2[1]])
		{
			if (z->pi[r->c][v] == '*' && z->tab[r->k2[0]][r->k2[1]] == p)
				rep++;
			if (z->pi[r->c][v] == '*' && z->tab[r->k2[0]][r->k2[1]] == z->inv)
				return (0);
		}
		if ((r->k2[1] + 1) > z->i[1] || rep > 1)
			return (0);
		r->c++;
		r->k2[0]++;
	}
	if (r->savec > 0)
		return (solution3(r, z, rep, p));
	return ((rep != 1) ? 0 : 1);
}

int			solution3(t_res *res, t_coor *z, int rep, char p)
{
	int i;
	int e;

	e = res->savec - 1;
	res->k2[0] = z->ret[0] - 1;
	while (e >= 0 && res->k2[0] >= 0)
	{
		if (!(repair(res->solv, res, z, &i)))
			return (0);
		while (z->pi[e][++i] && rep <= 1 && z->tab[res->k2[0]][++res->k2[1]])
		{
			if (z->pi[e][i] == '*' && z->tab[res->k2[0]][res->k2[1]] == p)
				rep++;
			if (z->pi[e][i] == '*' && z->tab[res->k2[0]][res->k2[1]] == z->inv)
				return (0);
		}
		if ((res->k2[1] + 1) > z->i[1] || rep > 1)
			return (0);
		e--;
		res->k2[0]--;
	}
	if (e > -1)
		return (0);
	return ((rep != 1) ? 0 : 1);
}

int			repair(int b, t_res *res, t_coor *z, int *i)
{
	*i = -1;
	res->k2[1] = z->ret[1];
	res->k2[1] -= b;
	res->k2[1]--;
	if (res->k2[1] < -1)
		return (0);
	else
		return (1);
}
