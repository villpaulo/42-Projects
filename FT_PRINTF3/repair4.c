/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repair4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:10:18 by pvillene          #+#    #+#             */
/*   Updated: 2016/04/06 16:58:26 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*fillp(char *str, int i, int j)
{
	while (j-- != 0)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*fillz(char *str, int i, int j)
{
	while (j-- != 0)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*fillz2(char *str, int j)
{
	int		i;

	i = 0;
	while (j-- != 0)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*filldo(char *str)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	ret[0] = '0';
	ret = copystring(str, ret, 1, 0);
	return (ret);
}

char	*ft_strnew(size_t size)
{
	char	*new;
	int		i;

	i = (int)size;
	if (!(new = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i > 0)
	{
		new[i--] = '\0';
	}
	return (new);
}
