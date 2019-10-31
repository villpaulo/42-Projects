/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:11:47 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 17:00:56 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strsub_f(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*s2;

	i = 0;
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[len] = '\0';
	free(s);
	return (s2);
}
