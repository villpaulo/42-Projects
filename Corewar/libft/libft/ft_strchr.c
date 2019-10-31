/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:04:25 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:48:19 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s2;
	char	c2;

	i = 0;
	c2 = (char)c;
	while (s[i] != c2 && s[i] != '\0')
		i++;
	s2 = (char*)s + i;
	if (s[i] == c2)
		return (s2);
	return (NULL);
}
