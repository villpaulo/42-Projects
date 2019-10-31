/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repair3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:56:16 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/28 18:16:00 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*flagpos(char *str, int *tab)
{
	int		i;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 3));
	i = 0;
	while (str[i] && str[i] != '+')
		i++;
	if (i == 0 && tab[1] == 0)
	{
		ret[0] = '+';
		ret[1] = '0';
		ret = copystring(str, ret, 2, 1);
		return (ret);
	}
	else if (i == 0 && tab[1] > 0)
	{
		ret[0] = '+';
		ret[1] = '0';
		ret = copystring(str, ret, 2, 1);
		ret[ft_strlen(str)] = '\0';
		return (ret);
	}
	str[i] = '0';
	str[i - 1] = '+';
	return (str);
}

char	*flag4d(char *str)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	ret[0] = ' ';
	ret = copystring(str, ret, 1, 0);
	return (ret);
}

int		ft_strlen2(int n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*replacez(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			str[i] = ' ';
		i++;
	}
	return (str);
}

char	*retcz(char *str, int *tab)
{
	int		i;

	i = 0;
	if (tab[5] > 0)
	{
		str = (char *)malloc(sizeof(char) * (tab[5] + 1));
		while (tab[5] > 1)
		{
			str[i] = ' ';
			i++;
			tab[5]--;
		}
		str[i] = '\0';
	}
	return (str);
}
