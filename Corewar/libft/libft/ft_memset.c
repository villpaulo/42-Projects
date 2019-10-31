/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:16:57 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:41:30 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned int	i;
	char			*s2;

	a = ((char)c);
	s2 = (char*)s;
	i = 0;
	while (i < n)
	{
		s2[i] = a;
		i++;
	}
	return (s);
}
