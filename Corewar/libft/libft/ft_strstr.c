/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:30:10 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:55:26 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

static char	ft_similar(const char *s1, const char *s2, int *i, int *j)
{
	int		isav;

	isav = 0;
	if (s1[*i] == s2[*j])
	{
		isav = *i;
		while (s1[*i] == s2[*j] && s1[*i] != '\0')
		{
			(*i)++;
			(*j)++;
		}
		*i = isav + 1;
	}
	if (s2[*j] != '\0')
	{
		*j = 0;
		return (0);
	}
	return (1);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		a;
	char	*s1c;

	s1c = (char*)s1;
	i = 0;
	j = 0;
	a = 0;
	while (s1[i] != '\0' && s2[j] != '\0' && a == 0)
	{
		if (s1[i] == s2[j])
			a = ft_similar(s1, s2, &i, &j);
		else
			i++;
	}
	if (a == 1)
	{
		s1c = s1c + i - 1;
		return (s1c);
	}
	if (*s2 == '\0')
		return (s1c);
	return (NULL);
}
