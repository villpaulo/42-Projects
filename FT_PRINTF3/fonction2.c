/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:25:43 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/28 17:34:52 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*niquetam(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	if (str != NULL)
	{
		ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
		while (str[i])
		{
			ret[i] = str[i];
			i++;
		}
	}
	else
		ret = (char *)malloc(sizeof(char) * 2);
	ret[i] = '\1';
	i++;
	ret[i] = '\0';
	return (ret);
}

int		searchsempty(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' && str[i])
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

char	*replace(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\1')
			str[i] = '\0';
		i++;
	}
	return (str);
}

int		ft_strlen3(unsigned long n, int i)
{
	int c;

	c = 0;
	while (n >= 1)
	{
		n = n / 10;
		c++;
	}
	if (c < i)
		return (1);
	return (0);
}
