/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:59:08 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:52:02 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	isav;
	unsigned int	jsav;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	isav = i;
	while (src[j] != '\0')
		j++;
	jsav = j;
	if (i >= size)
		return (j + size);
	j = 0;
	while (src[j] != '\0' && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (isav + jsav);
}
