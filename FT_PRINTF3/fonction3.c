/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:25:37 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/28 17:46:19 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
			i++;
	}
	return (i);
}

int		count_len(int nbr)
{
	int count;

	count = 1;
	while (nbr > 9 || nbr < -9)
	{
		count++;
		nbr = nbr / 10;
	}
	if (nbr < 0)
		count++;
	return (count);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *str, char *str2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (str2 == NULL)
		return (str);
	if (str == NULL)
		return (str2);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(str2) + 1));
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	while (str2[j])
	{
		ret[i] = str2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strcopy(char *s1, char *s2)
{
	int i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
