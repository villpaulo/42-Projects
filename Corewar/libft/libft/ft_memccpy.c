/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:47:02 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:39:18 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	*dst2;
	unsigned char	*src2;

	i = 0;
	a = (unsigned char)c;
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	while (i < n && src2[i] != a)
	{
		dst2[i] = src2[i];
		i++;
	}
	if (src2[i] == a)
	{
		dst2[i] = src2[i];
		return (dst2 + i + 1);
	}
	if ((src2[i] != a && i == n) || (n == 0))
		return (0);
	return (dst2);
}
