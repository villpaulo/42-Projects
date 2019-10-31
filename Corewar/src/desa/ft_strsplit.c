/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:58:21 by pibenoit          #+#    #+#             */
/*   Updated: 2016/11/29 21:44:55 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "desa.h"
#include <stdlib.h>

static unsigned int	ft_nb_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c && ((i != 0 && *(s + i - 1) == c) || i == 0))
			j++;
		i++;
	}
	return (j);
}

static unsigned int	ft_pos_word(char const *s, char c, unsigned int i)
{
	unsigned int	j;
	unsigned int	k;

	j = 0;
	k = 0;
	i++;
	while (k < i)
	{
		if (*(s + j) != c && ((j != 0 && *(s + j - 1) == c) || j == 0))
			k++;
		j++;
	}
	if (j > 0)
		j--;
	return (j);
}

static char			ft_malloc(char const *s, char **tab, unsigned int i, char c)
{
	unsigned int	length;

	length = 0;
	while (*(s + length) != c && *(s + length) != '\0')
		length++;
	*(tab + i) = (char*)malloc(sizeof(char) * (length + 1));
	if (*(tab + i) == NULL)
	{
		i--;
		while (i != 0)
		{
			free(*(tab + i));
			i--;
		}
		free(*tab);
		return (0);
	}
	return (1);
}

static void			ft_copie(char const *s, char *str, char c)
{
	unsigned int	i;

	i = 0;
	while (*(s + i) != c && *(s + i) != '\0')
	{
		*(str + i) = *(s + i);
		i++;
	}
	*(str + i) = '\0';
}

char				**ft_strsplit(char *s, char c)
{
	char			**tab;
	unsigned int	nb_word;
	unsigned int	i;
	unsigned int	pos;

	nb_word = ft_nb_word(s, c);
	tab = (char**)malloc(sizeof(char*) * (nb_word + 1));
	if (tab == NULL)
		return (NULL);
	tab[nb_word] = NULL;
	i = 0;
	while (i < nb_word)
	{
		pos = ft_pos_word(s, c, i);
		if (ft_malloc(s + pos, tab, i, c))
			ft_copie(s + pos, tab[i], c);
		else
		{
			free(tab);
			return (NULL);
		}
		i++;
	}
	return (tab);
}
