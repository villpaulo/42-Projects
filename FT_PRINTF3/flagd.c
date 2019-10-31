/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:39:45 by pvillene          #+#    #+#             */
/*   Updated: 2016/08/10 13:22:35 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*filldx22(char *ret, char *str, int *tab)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '0' && tab[5] == 0)
	{
		if (str[i + 1] == '0')
			str[i + 1] = 'X';
	}
	else if (str[i] == '0' && tab[5] > 0)
	{
		ret[0] = '0';
		ret[1] = 'X';
		ret = copystring(str, ret, 2, 0);
		return (ret);
	}
	return (str);
}

char	*filldx(char *str, int *tab, unsigned long n)
{
	char	*ret;
	int		c;

	c = 0;
	while (n >= 1)
	{
		n = n / 10;
		c++;
	}
	c = c + 2;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 3));
	if (tab[5] > 0 && tab[5] < tab[2])
		tab[2] = tab[5];
	if (c <= tab[2] && tab[5] <= tab[2])
		return (filldx2(ret, str, tab));
	if (c <= tab[5] && tab[5] >= tab[2])
		return (filldx3(str));
	ret[0] = '0';
	ret[1] = 'x';
	if (c - tab[2] == 1)
		ret = copystring(str, ret, 2, 1);
	else
		ret = copystring(str, ret, 2, 0);
	return (ret);
}

char	*filldxp(char *str, int *tab)
{
	char	*ret;
	int		i;
	int		c;

	c = 2;
	i = 0;
	if (tab[5] > ft_strlen(str) + 3)
		ret = (char *)malloc(sizeof(char) * (tab[5] + 1));
	else
		ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 3));
	if (tab[5] > ft_strlen(str) + 3 && tab[1] == 0)
	{
		c = tab[5] - ft_strlen(str) + 2;
		ret = fillp(ret, 0, c);
	}
	ret = copystring(str, ret, c, 0);
	if (c == 1)
		c++;
	ret[c - 2] = '0';
	ret[c - 1] = 'x';
	if (tab[5] > ft_strlen(str) + 3 && tab[1] > 0)
		ret = fillp(ret, ft_strlen(str), tab[5] - ft_strlen(str));
	return (ret);
}

char	*filldxx(char *str, int *tab, unsigned long n)
{
	char	*ret;
	int		c;

	c = 0;
	while (n >= 1)
	{
		n = n / 10;
		c++;
	}
	c = c + 2;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 3));
	if (tab[5] > 0 && tab[5] < tab[2])
		tab[2] = tab[5];
	if (c <= tab[2] && tab[5] <= tab[2])
		return (filldx22(ret, str, tab));
	if (c <= tab[5] && tab[5] >= tab[2])
		return (filldx33(str));
	ret[0] = '0';
	ret[1] = 'X';
	if (c - tab[2] == 1)
		ret = copystring(str, ret, 2, 1);
	else
		ret = copystring(str, ret, 2, 0);
	return (ret);
}

char	*fillrepair2(char *str)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 3));
	ret[0] = '0';
	ret[1] = 'x';
	ret = copystring(str, ret, 2, 0);
	return (ret);
}
