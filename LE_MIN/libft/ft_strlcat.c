/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 21:34:58 by pvillene          #+#    #+#             */
/*   Updated: 2014/11/27 18:09:51 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	int			a;
	size_t		res;

	i = 0;
	a = 0;
	res = ft_strlen(dst) + ft_strlen(src);
	while (dst[i] != 0 && i < size)
		i = i + 1;
	if (size - i == 0)
		return (i + ft_strlen(src));
	while (i != (size - 1) && src[a] != 0)
	{
		dst[i] = src[a];
		i++;
		a++;
	}
	dst[i] = 0;
	return (res);
}
