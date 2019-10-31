/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 08:32:08 by pvillene          #+#    #+#             */
/*   Updated: 2014/11/28 07:04:12 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		passe;
	int		i;
	int		j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && n > 0)
	{
		j = 0;
		if (n < ft_strlen(s2))
			return (NULL);
		passe = i;
		while (s1[passe] == s2[j] && s2[j] && s1[passe])
		{
			j++;
			passe++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		n--;
		i++;
	}
	return (NULL);
}
