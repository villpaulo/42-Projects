/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:25:25 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:55:01 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <string.h>

static int				ft_nbword(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			j++;
	}
	return (j);
}

static unsigned int		ft_pos(char const *s, char c, int ctrword)
{
	unsigned int	i;
	int				w;
	unsigned int	isav;

	i = 0;
	w = 0;
	ctrword++;
	while (s[i] != '\0' && w < ctrword)
	{
		while (s[i] == c)
			i++;
		isav = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			w++;
	}
	return (isav);
}

static char				ft_mcw(char const *s, char c, char **s2, int ctrword)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	s2[ctrword] = (char*)malloc(sizeof(char) * (i + 1));
	if (s2[ctrword] == NULL)
	{
		while (ctrword > 0)
		{
			free(s2[ctrword - 1]);
			ctrword--;
		}
		return (0);
	}
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		s2[ctrword][i] = s[i];
		i++;
	}
	s2[ctrword][i] = '\0';
	return (1);
}

char					**ft_strsplit(char const *s, char c)
{
	int				nbword;
	unsigned int	ctrletter;
	int				ctrword;
	char			**s2;

	nbword = (ft_nbword(s, c));
	ctrword = 0;
	s2 = (char**)malloc(sizeof(char*) * nbword + 1);
	if (s2 == NULL)
		return (NULL);
	s2[nbword] = NULL;
	while (ctrword < nbword)
	{
		ctrletter = ft_pos(s, c, ctrword);
		if (ft_mcw(s + ctrletter, c, s2, ctrword))
			ctrword++;
		else
		{
			free(s2);
			return (NULL);
		}
	}
	return (s2);
}
