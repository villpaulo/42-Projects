/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 17:48:21 by pvillene          #+#    #+#             */
/*   Updated: 2016/09/29 00:34:32 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/filler.h"

int			changepiece2(t_coor *z)
{
	int		i;
	int		j;
	int		c1;

	i = 0;
	c1 = 0;
	while (z->pi[i] != NULL)
	{
		j = 0;
		while (z->pi[i][j])
		{
			if (z->pi[i][j] == '*')
			{
				if (z->p[2] == 0 && c1 == 0)
					z->p[2] = i;
				c1++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (c1);
}

void		changepiece(t_coor *z)
{
	int		i;
	int		j;
	int		c1;

	c1 = 0;
	j = 0;
	while (z->pi[i = 0][j])
	{
		i = 0;
		while (z->pi[i] != NULL && z->pi[i][j] != '*')
			i++;
		if (z->pi[i] == NULL)
			i = 0;
		if (z->pi[i] == NULL && z->pi[i][j] != '*' && c1 != 0)
			break ;
		if (z->pi[i][j] == '*')
		{
			if (z->p[3] == 0 && c1 == 0)
				z->p[3] = j;
			c1++;
		}
		j++;
	}
	z->p[0] = changepiece2(z);
	z->p[1] = c1;
}

char		**changepi(char **tab, t_coor *z)
{
	char	**new;
	int		i;

	new = (char **)malloc(sizeof(char *) * (z->p[0] + 1));
	i = 0;
	z->p[4] = z->p[2];
	while (i < z->p[0])
	{
		new[i] = ft_strsub(tab[z->p[2]], z->p[3], z->p[1]);
		i++;
		z->p[2]++;
	}
	new[i] = NULL;
	i = 0;
	while (z->pi[i] != NULL)
	{
		free(z->pi[i]);
		i++;
	}
	free(z->pi);
	z->pi = NULL;
	return (new);
}

t_coor		*repairparsepi(t_coor *z)
{
	int i;
	int j;
	int c1;
	int c0;

	i = 0;
	c1 = 0;
	c0 = 0;
	j = 0;
	while (i + 1 <= z->p[0])
	{
		if (j > c1)
			c1 = j;
		j = 0;
		while (j + 1 <= z->p[1])
		{
			if (j > 0 && z->pi[i][j - 1] == 3 && z->pi[i][j] == 0)
				break ;
			j++;
		}
		i++;
	}
	z->p[1] = c1 + 1;
	return (z);
}

char		*funread(char *str)
{
	char	buff[2];

	str = (char *)malloc(sizeof(char) * 1);
	while (read(1, buff, 1) > 0)
	{
		buff[1] = '\0';
		if (buff[0] == '\n')
			break ;
		str = ft_strjoin(str, buff);
	}
	return (str);
}
