/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:42:32 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/11 16:42:56 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	s1 = dst;
	s2 = src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
