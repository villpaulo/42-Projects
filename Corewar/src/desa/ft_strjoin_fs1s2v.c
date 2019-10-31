/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:06:42 by pibenoit          #+#    #+#             */
/*   Updated: 2016/11/30 00:25:28 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "desa.h"
#include <stdlib.h>

static char	ft_len(char const *s)
{
	unsigned int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char		*ft_strjoin_fs1s2v(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!(str = (char*)malloc(ft_len(s1) + ft_len(s2) + 3)))
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = ',';
	str[i + 1] = ' ';
	i += 2;
	while (s2[j])
	{
		*(str + i) = *(s2 + j);
		i++;
		j++;
	}
	*(str + i) = '\0';
	free(s1);
	free(s2);
	return (str);
}
