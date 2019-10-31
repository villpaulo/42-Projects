/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 21:29:41 by pvillene          #+#    #+#             */
/*   Updated: 2015/05/09 17:02:32 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1cpy;
	int		i;

	i = 0;
	while (s1[i] != 0)
		i++;
	if ((s1cpy = (char*)malloc(sizeof(*s1) * (i + 1))))
	{
		i = 0;
		while (s1[i] != '\0')
		{
			s1cpy[i] = s1[i];
			i++;
		}
		s1cpy[i] = '\0';
		return (s1cpy);
	}
	else
		return (NULL);
}
