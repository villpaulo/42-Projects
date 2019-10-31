/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_strklcmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:43:16 by pbenoit           #+#    #+#             */
/*   Updated: 2017/01/27 09:43:21 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_strkcmp(const char *s1, const char *s2)
{
	register const char		*s3;
	register const char		*s4;

	s3 = s1;
	s4 = s2;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (*s3 && *s4)
	{
		if (*s3 != *s4)
		{
			return (0);
		}
		s3++;
		s4++;
	}
	if (*s3 != *s4)
		return (0);
	return (1);
}

int		ft_strlcmp(char *str, const char *comp)
{
	int		i;
	int		j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(comp) - 1;
	if (i < j)
		return (0);
	while (i && j)
	{
		if (str[i] != comp[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}
