/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_save.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:28:34 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:55:09 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <string.h>

static int		ft_nbline(char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

char			*ft_cpyandcut(char **s, char c)
{
	char	*s2;
	int		j;

	j = 0;
	if ((*s)[0] == c)
		j++;
	while ((*s)[j] != c && (*s)[j] != '\0')
		j++;
	s2 = ft_strsub(*s, 0, j);
	*s = ft_strsub(*s, j, ft_strlen(*s + j));
	return (s2);
}

char			**ft_strsplit_save(char **s, char c)
{
	int		nbline;
	char	**s2;
	int		i;

	i = 0;
	nbline = ft_nbline(*s, c);
	s2 = (char**)malloc(sizeof(char*) * nbline + 1);
	if (s2 == NULL)
		return (NULL);
	s2[nbline] = NULL;
	while (i < nbline)
	{
		*(s2 + i) = ft_cpyandcut(s, c);
		if (*(s2 + i) == NULL)
		{
			while (i > 0)
			{
				free(*(s2 + i - 1));
				i--;
			}
		}
		i++;
	}
	return (s2);
}
