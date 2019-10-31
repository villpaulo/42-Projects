/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:20:31 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:49:57 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	s2 = malloc(sizeof(char) * (i + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
