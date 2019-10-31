/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 21:37:43 by pvillene          #+#    #+#             */
/*   Updated: 2015/05/02 17:02:56 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		nb1;
	int		nb2;

	if (!*s2)
		return ((char *)s1);
	nb1 = 0;
	while (s1[nb1])
	{
		nb2 = 0;
		while (s2[nb2] && s1[nb1 + nb2] && s1[nb1 + nb2] == s2[nb2])
			nb2++;
		if (!s2[nb2])
			return ((char *)s1 + nb1);
		nb1++;
	}
	return (NULL);
}
