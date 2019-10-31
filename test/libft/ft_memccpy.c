/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 21:25:08 by pvillene          #+#    #+#             */
/*   Updated: 2014/11/27 08:28:59 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;

	dest2 = dest;
	src2 = src;
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		if (src2[i] == c)
		{
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
