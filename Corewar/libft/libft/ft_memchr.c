/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:09:02 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:39:28 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	*s2;

	a = (unsigned char)c;
	s2 = (unsigned char *)s;
	i = 0;
	while (i < n && s2[i] != a)
		i++;
	if (i == n)
		return (NULL);
	else
		return ((void*)(s + i));
}
