/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 21:36:51 by pvillene          #+#    #+#             */
/*   Updated: 2014/11/22 21:36:55 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = (char *)s;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			j = i;
		i++;
	}
	if (s[i] == (char)c)
		return (ret + i);
	if (s[j] == (char)c)
		return (ret + j);
	else
		return (NULL);
}
