/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:40:00 by pvillene          #+#    #+#             */
/*   Updated: 2016/08/10 13:22:33 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*filldx3(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	str[i - 2] = '0';
	str[i - 1] = 'x';
	return (str);
}

char	*filldx33(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	str[i - 2] = '0';
	str[i - 1] = 'X';
	return (str);
}

char	*filldx2(char *ret, char *str, int *tab)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '0' && tab[5] == 0)
	{
		if (str[i + 1] == '0')
			str[i + 1] = 'x';
	}
	else if (str[i] == '0' && tab[5] > 0)
	{
		ret[0] = '0';
		ret[1] = 'x';
		ret = copystring(str, ret, 2, 0);
		return (ret);
	}
	return (str);
}
