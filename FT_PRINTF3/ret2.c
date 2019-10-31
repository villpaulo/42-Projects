/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:30:21 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/30 18:34:25 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ret_modulo2(int *tab, char *str, int i)
{
	if (tab[5] > 0)
	{
		i = 0;
		while (tab[5]-- != 1)
			str[i++] = ' ';
		str[i++] = '%';
		str[i] = '\0';
	}
	else if (tab[2] > 0 && tab[1] == 0)
	{
		str = fillz2(str, tab[2]);
		str[tab[2] - 1] = '%';
		str[tab[2]] = '\0';
	}
	else
	{
		str[0] = '%';
		str[1] = '\0';
	}
	return (str);
}

char	*ret_d2(int *tab, char *str, int j, int z)
{
	int ne;

	ne = 0;
	if (tab[1] > 0)
		ne = 1;
	z = tab[6];
	if (str[0] == '+' || str[0] == '-')
		z++;
	if (tab[2] > tab[6] || tab[5] > tab[6])
	{
		j = tab[2] + tab[5];
		if (str[0] == '+' || str[0] == '-')
			j++;
	}
	str = checkfill(str, j, ne, z);
	return (str);
}

char	*ret_p(char *str, int *tab)
{
	tab = ft_zero(tab, 13);
	return (str);
}

char	*ret_s2(char *str, int *tab)
{
	tab = ft_zero(tab, 13);
	return (str);
}

char	*ret_c(char c, int *tab)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (tab[5] + 2));
	if (tab[5] > 0 && tab[i = 1] > 0)
	{
		str[0] = c;
		while (tab[5]-- != 1)
			str[i++] = ' ';
		str[i] = '\0';
	}
	else if (tab[5] > 0)
	{
		i = 0;
		while (tab[5]-- != 1)
			str[i++] = ' ';
		str[i++] = c;
		str[i] = '\0';
	}
	else
	{
		str[0] = c;
		str[1] = '\0';
	}
	return (str);
}
