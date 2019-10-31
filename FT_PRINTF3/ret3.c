/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:56:25 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/30 18:35:21 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ret_o(char *str, int *tab)
{
	int		ne;
	int		j;
	int		z;

	z = 0;
	j = 0;
	ne = 0;
	if (tab[1] > 0)
	{
		ne = 1;
		tab[2] = 0;
	}
	if (tab[6] > ft_strlen(str))
		return (ret_d2(tab, str, j, z));
	else if (tab[5] > ft_strlen(str))
		j = tab[2] + tab[5];
	else if (tab[2] > ft_strlen(str))
		z = tab[2] + tab[5];
	if (j > 0 || z > 0)
		str = checkfill(str, j, ne, z);
	return (str);
}

char		*ret_o2(char *str, int *tab)
{
	int		ne;
	int		j;
	int		z;

	z = 0;
	j = 0;
	ne = 0;
	if (tab[1] > 0)
	{
		ne = 1;
		tab[2] = 0;
	}
	if (tab[6] > ft_strlen(str))
		return (ret_d2(tab, str, j, z));
	else if (tab[5] > ft_strlen(str))
		j = tab[2] + tab[5];
	else if (tab[2] > ft_strlen(str))
		z = tab[2] + tab[5];
	if (j > 0 || z > 0)
		str = checkfill(str, j, ne, z);
	return (str);
}
