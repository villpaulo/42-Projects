/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:25:43 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:54:09 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

static char	ft_similar(const char *s1, const char *s2, unsigned int tab[3])
{
	int				isav;

	isav = 0;
	if (s1[tab[0]] == s2[tab[1]])
	{
		isav = tab[0];
		while (s1[tab[0]] == s2[tab[1]] && s1[tab[0]] != '\0'
				&& tab[0] < tab[2])
		{
			(tab[0])++;
			(tab[1])++;
		}
		tab[0] = isav + 1;
	}
	if (s2[tab[1]] != '\0' && tab[0] < tab[2])
	{
		tab[1] = 0;
		return (0);
	}
	return (1);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	tab[3];
	int				a;
	char			*s1c;

	s1c = (char*)s1;
	tab[0] = 0;
	tab[1] = 0;
	a = 0;
	tab[2] = n;
	while (s1[tab[0]] != '\0' && s2[tab[1]] != '\0' && a == 0
			&& tab[0] < tab[2])
	{
		if (s1[tab[0]] == s2[tab[1]])
			a = ft_similar(s1, s2, tab);
		else
			tab[0]++;
	}
	if (a == 1)
	{
		s1c = s1c + (tab[0] - 1);
		return (s1c);
	}
	if (*s2 == '\0')
		return (s1c);
	return (NULL);
}
