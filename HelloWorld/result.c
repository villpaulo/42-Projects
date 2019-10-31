/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:18:41 by pvillene          #+#    #+#             */
/*   Updated: 2016/09/07 21:11:26 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
			if ((z->p[0] + i) > (z->i[0] - 1))
				res->c = (z->p[0] + i) - (z->i[0] - 1);
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

int			solution2(t_res *res, t_coor *z, char p)
{
	int rep;
	int v;

	rep = 0;
	res->savec = res->c;
	fprintf(stderr, "ici\n");
	while (z->pi[res->c] != NULL && z->tab[res->k2[v]] != NULL)
	{
		if (!repair(res->solv, res, z, &v))
			return (0);
		while (z->pi[res->c][++v] && z->tab[res->k2[0]][++res->k2[1]])
		{
			if (z->pi[res->c][v] == '*' && z->tab[res->k2[0]][res->k2[1]] == p)
				rep++;
			if (z->pi[res->c][v] == '*' && z->tab[res->k2[0]][res->k2[1]] == z->inv)
				return (0);
			if (z->pi[res->c][v] == '\0' || z->tab[res->k2[0]][res->k2[1]] == '\0')
					break ;
		}
		if ((res->k2[1] + 1) > z->i[1] || rep > 1)
			return (0);
		res->c++;
		res->k2[0]++;
	}
	if (res->savec > 0)
		return (solution3(res, z, rep, p));
	else if (rep != 1)
		return (0);
	return (1);
}

int			solution3(t_res *res, t_coor *z, int rep, char p)
{
	int i;
	int e;

	e = res->savec - 1;
	res->k2[0] = z->ret[0] - 1;
	while (e >= 0 && res->k2[i] >= 0)
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
	if (rep != 1)
		return (0);
	return (1);
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
