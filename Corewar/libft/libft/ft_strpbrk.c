/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 13:59:22 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:54:25 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	s3 = (char*)s1;
	while (s1[i] != '\0' && s1[i] != s2[j])
	{
		while (s1[i] != s2[j] && s2[j] != '\0')
			j++;
		if (s2[j] == '\0')
		{
			j = 0;
			i++;
		}
	}
	if (s1[i] == s2[j])
		return ((s3 + i));
	else
		return (NULL);
}
