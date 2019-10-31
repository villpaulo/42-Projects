/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:53:06 by pvillene          #+#    #+#             */
/*   Updated: 2016/11/24 08:59:36 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

extern t_element	g_element[];

int		checkmodif(char *modifier, int j, char *p, int i)
{
	while (modifier[j] && modifier[j] != p[i])
	{
		if (ft_isdigit(p[i]) && p[i] != '0')
		{
			j = 5;
			return (j);
		}
		j++;
	}
	if (modifier[j] == '\0')
		return (-1);
	return (j);
}

int		checkmodulo(char *p, int i)
{
	int j;

	while (p[i] && p[i] != '%')
	{
		j = 0;
		while (g_element[j].c && p[i] != g_element[j].c)
			j++;
		if (p[i] == g_element[j].c)
			return (0);
		i++;
	}
	if (p[i] == '%')
		return (1);
	return (0);
}

char	*print_len(char *str, int i)
{
	int		j;
	char	*ret;

	j = i;
	while (str[i] != '\0' && str[i] != '%')
	{
		i++;
	}
	if (j != 0)
		i++;
	if (j != 0 && j == (i - 1))
		return (NULL);
	if (i == 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (i - j + 1));
	i = 0;
	while (str[j] && str[j] != '%')
	{
		ret[i] = str[j];
		j++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int		*applymodif(int i, char *p, int *tab, char *modifier)
{
	int j;
	int k;

	k = 0;
	while (p[i] != '%')
		i++;
	i++;
	while (p[i] && p[i] != '%')
	{
		if (norme1(p, i) == 0)
			break ;
		j = 0;
		j = checkmodif(modifier, j, p, i);
		if ((j == 9 && p[i + 1] == 'l') || (j == 7 && p[i + 1] == 'h'))
			j++;
		if (j == 2 || j == 6 || j == 10 || j == 8)
			i++;
		if (j == 2 || j == 6 || j == 5)
			tab[j] = ft_atoi(ft_strndup(p, i));
		if (j != -1 && tab[j] == 0)
			tab[j] = norme3(k);
		i = norme2(j, p, i) + i + 1;
	}
	return (tab);
}

char	*checkelement(int *tab, char *p, int i, va_list ap)
{
	int		j;
	char	*str;

	while (p[i] && p[i] != '%')
	{
		j = 0;
		while (g_element[j].c && p[i] != g_element[j].c)
			j++;
		if (p[i] == g_element[j].c)
		{
			str = g_element[j].f(ap, tab);
			if (str == NULL && g_element[j].c == 's')
				str = "(null)";
			return (str);
		}
		i++;
	}
	return (NULL);
}
