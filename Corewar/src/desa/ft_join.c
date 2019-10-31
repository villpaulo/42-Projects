/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:44:16 by pibenoit          #+#    #+#             */
/*   Updated: 2016/11/29 19:23:11 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "desa.h"
#include <stdlib.h>

static unsigned int	ft_calcul_len(char **tab, unsigned int nb_word)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	len2;

	i = 0;
	len2 = 0;
	while (i < nb_word)
	{
		len = 0;
		while (tab[i][len])
			len++;
		len2 += len;
		i++;
	}
	len2 += nb_word;
	return (len2);
}

static unsigned int	ft_calcul_nb(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char				*ft_join(char **tab)
{
	char			*str;
	unsigned int	i;
	unsigned int	len;
	unsigned int	len2;
	unsigned int	nb_word;

	nb_word = ft_calcul_nb(tab);
	len2 = ft_calcul_len(tab, nb_word);
	str = (char*)malloc(sizeof(char) * (len2 + 1));
	str[len2] = '\0';
	i = -1;
	len2 = 0;
	while (++i < nb_word && (len = -1))
	{
		while (tab[i][++len])
		{
			str[len2] = tab[i][len];
			len2++;
		}
		str[len2] = '\n';
		len2++;
		free(tab[i]);
	}
	free(tab);
	return (str);
}
