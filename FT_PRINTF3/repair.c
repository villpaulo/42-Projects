/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repair.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:47:39 by pvillene          #+#    #+#             */
/*   Updated: 2016/08/10 13:23:10 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*checkfill(char *str, int j, int n, int z)
{
	char	*new;

	if (j > 0)
	{
		new = (char *)malloc(sizeof(char) * j + 1);
		j = (z > 0) ? j - z : j - ft_strlen(str);
		if (n == 1)
		{
			if (z > ft_strlen(str) && (str[0] == '+' || str[0] == '-'))
				j--;
			new = copy(str, new, 0, z);
			new = fill(new, ft_strlen(new), j);
		}
		else
		{
			new = fill(new, 0, j);
			new = copy(str, new, j, z);
		}
	}
	if (z > 0 && j == 0)
	{
		new = (char *)malloc(sizeof(char) * z + 1);
		new = copy(str, new, 0, z);
	}
	return (new);
}

char	*copy(char *str, char *new, int i, int z)
{
	int		j;

	j = 0;
	if (z > 0)
	{
		if (str[0] == '-' || str[0] == '+')
		{
			if (i == 0)
			{
				new[i] = str[0];
				i++;
			}
			else
				new[i - 1] = str[0];
			j++;
		}
		new = fillz(new, i, z - ft_strlen(str));
		i = i + z - ft_strlen(str);
	}
	while (str[j])
		new[i++] = str[j++];
	new[i] = '\0';
	return (new);
}

char	*copystring(char *str, char *new, int i, int j)
{
	while (str[j])
	{
		new[i] = str[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*copystringl(char *str, char *new, int i, int l)
{
	while (str[i] && i != l)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*fill(char *str, int i, int j)
{
	while (j-- != 0)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}
