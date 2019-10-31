/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:30:36 by pvillene          #+#    #+#             */
/*   Updated: 2018/03/08 16:45:26 by pv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ret_modulo(int *tab)
{
	char	*str;
	int		i; i = 0;
	str = (char *)malloc(sizeof(char) * (tab[5] + tab[2] + 2));
	if (tab[5] > 0 && tab[i = 1] > 0)
	{
		str[0] = '%';
		while (tab[5]-- != 1)
			str[i++] = ' ';
		str[i] = '\0';
	}
	str = ret_modulo2(tab, str, i);
	return (str);
}

char		*ret_s(char *n, int *tab)
{
	int		i;
	char	*str;
	int		j;

	if (tab[5] > ft_strlen(n))
		j = tab[5] - ft_strlen(n);
	else
		j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(n) + j + 1));
	i = 0;
	if (tab[5] > 0 && tab[1] > 0)
	{
		i = -1;
		while (n[++i])
			str[i] = n[i];
		if (j != 0)
			str = fill(str, i, j);
	}
	else if (tab[5] > 0)
	{
		if (j != 0)
			str = fill(str, i, j);
		str = ft_strjoin(str, n);
	}
	return (str);
}

char		*ret_x(char *str, int *tab, int ne)
{
	int		j;
	int		z;

	z = 0;
	j = 0;
	if (tab[6] > ft_strlen(str))
	{
		z = tab[6];
		if (str[0] == '+' || str[0] == '-')
			z++;
		if (tab[2] > tab[6] || tab[5] > tab[6])
		{
			j = tab[2] + tab[5];
			if (str[0] == '+' || str[0] == '-')
				j++;
		}
	}
	else if ((tab[5] > ft_strlen(str)) && (tab[6] <= ft_strlen(str)))
		j = tab[2] + tab[5];
	else if ((tab[2] > ft_strlen(str)) && (tab[6] <= ft_strlen(str)))
		z = tab[2] + tab[5];
	if (j > 0 || z > 0)
		str = checkfill(str, j, ne, z);
	return (str);
}

char		*ret_d(long n, int *tab, int b)
{
	char	*str;
	int		ne;
	int		j;
	int		z;

	z = 0;
	j = 0;
	ne = 0;
	if (!(str = ft_putnbr(n, 10, b)))
		return (NULL);
	if (tab[1] > 0)
		ne = 1;
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

char		*ret_x2(char *str, int *tab)
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
	{
		j = tab[2] + tab[5];
	}
	else if (tab[2] > ft_strlen(str))
		z = tab[2] + tab[5];
	if (j > 0 || z > 0)
		str = checkfill(str, j, ne, z);
	return (str);
}
