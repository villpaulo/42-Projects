/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:06:42 by pibenoit          #+#    #+#             */
/*   Updated: 2016/12/19 12:22:17 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "desa.h"
#include <stdlib.h>

static int	ft_lenght(char const *s)
{
	unsigned int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char		*ft_strjoin_fs1s2(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	str = (char*)malloc(sizeof(char) * (ft_lenght(s1) + ft_lenght(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j) != '\0')
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
