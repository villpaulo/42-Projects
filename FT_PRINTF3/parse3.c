/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:30:09 by pvillene          #+#    #+#             */
/*   Updated: 2016/04/06 17:11:01 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

extern t_element	g_element[];

int		searchc(char *p, int i)
{
	int j;

	while (p[i] && p[i] != '%')
	{
		j = 0;
		while (g_element[j].c && p[i] != g_element[j].c)
			j++;
		if (g_element[j].c == 'c')
			break ;
		i++;
	}
	if (p[i] == g_element[j].c && g_element[j].c == 'c')
		return (1);
	return (0);
}

int		jump2(char *p, int i)
{
	while (p[i] != '%')
		i++;
	i++;
	return (i);
}

int		*repairdeg(int *tab, char *modifier, char *p, int i)
{
	tab = ft_zero(tab, 13);
	tab = applymodif(i, p, tab, modifier);
	return (tab);
}

int		jump(char *p, int k, int i)
{
	int j;

	while (k != 0)
	{
		j = 0;
		while (p[i] != '%' && p[i])
			i++;
		if (p[i] != '\0')
			i++;
		while (p[i] != g_element[j].c && p[i] != '%')
		{
			j++;
			if (j == 14)
			{
				j = 0;
				i++;
			}
		}
		if (p[i] == '%')
			k--;
		if (p[i] != '\0')
			i++;
		k--;
	}
	return (i);
}

int		count(char *p, int i)
{
	while (p[i] && p[i] != '%')
		i++;
	if (p[i] == '%')
		i++;
	if (p[i] == '\0')
		return (0);
	return (1);
}
