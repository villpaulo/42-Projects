/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:20:53 by pvillene          #+#    #+#             */
/*   Updated: 2016/09/29 00:33:57 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/filler.h"

void		error_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

void		freez(t_coor *z)
{
	int		i;

	i = 0;
	while (z->tab[i] != NULL)
	{
		free(z->tab[i]);
		i++;
	}
	free(z->tab);
	z->tab = NULL;
	i = 0;
	while (z->pi[i] != NULL)
	{
		free(z->pi[i]);
		i++;
	}
	free(z->pi);
	z->pi = NULL;
}

int			**ft_intbzero(int **tab, int x, int y)
{
	while (x >= 0)
	{
		while (y >= 0)
		{
			tab[x][y] = 0;
			y--;
		}
		x--;
	}
	return (tab);
}

t_res		*initres(t_res *z, int i, int j)
{
	z->solv = 0;
	z->k2[0] = i;
	z->k2[1] = j;
	z->savec = 0;
	z->s = 0;
	z->c = 0;
	return (z);
}

t_res		*initres2(t_res *z, int i, int j)
{
	z->k2[0] = i;
	z->k2[1] = j;
	z->savec = 0;
	return (z);
}
