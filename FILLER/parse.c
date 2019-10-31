/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 13:27:44 by pvillene          #+#    #+#             */
/*   Updated: 2016/09/08 13:39:02 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/filler.h"

void		initz(t_coor *z)
{
	z->x = 0;
	z->i[0] = 0;
	z->i[1] = 0;
	z->tab = NULL;
	z->p[0] = 0;
	z->p[1] = 0;
	z->p[2] = 0;
	z->p[3] = 0;
	z->p[4] = 0;
	z->ret[0] = 0;
	z->ret[1] = 0;
	z->ret2 = 0;
	z->pi = NULL;
	z->recup[0] = 0;
	z->recup[1] = 0;
}

t_coor		*iniplateau(t_coor *z, char *str)
{
	int		i;

	i = 0;
	while ((!(ft_isdigit(str[i]))) && str[i])
		i++;
	z->i[0] = ft_atoi(str + i);
	while (ft_isdigit(str[i]) && str[i])
		i++;
	i++;
	z->i[1] = ft_atoi(str + i);
	free(str);
	return (z);
}

t_coor		*parse(t_coor *z, char *str)
{
	int i;

	i = 0;
	initz(z);
	get_next_line(0, &str);
	z = iniplateau(z, str);
	get_next_line(0, &str);
	free(str);
	z->tab = getlines(z->tab, z->i[0], str, 4);
	modifmap(z->tab);
	get_next_line(0, &str);
	while (!(ft_isdigit(str[i])) && str[i])
		i++;
	z->p[0] = ft_atoi(str + i);
	i++;
	z->p[1] = ft_atoi(str + i);
	z->pi = getlines(z->pi, z->p[0], str, 0);
	return (z);
}

char		**getlines(char **tab, int size, char *str, int sub)
{
	int		i;

	tab = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (size != 0)
	{
		get_next_line(0, &str);
		tab[i] = ft_strsub(str, sub, ft_strlen(str));
		free(str);
		i++;
		size--;
	}
	tab[i] = NULL;
	return (tab);
}

void		modifmap(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == 'x')
				tab[i][j] = 'X';
			if (tab[i][j] == 'o')
				tab[i][j] = 'O';
			j++;
		}
		i++;
	}
}
