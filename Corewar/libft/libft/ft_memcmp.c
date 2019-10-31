/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:22:54 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:39:44 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const unsigned char	*s1c;
	const unsigned char	*s2c;

	i = 0;
	s1c = (const unsigned char*)s1;
	s2c = (const unsigned char*)s2;
	while (s1c[i] == s2c[i] && i < n)
		i++;
	if (n == 0)
		return (0);
	if (i == n)
		i--;
	return ((int)(s1c[i] - s2c[i]));
}
