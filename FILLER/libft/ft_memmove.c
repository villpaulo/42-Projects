/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 21:26:18 by pvillene          #+#    #+#             */
/*   Updated: 2014/11/22 21:26:46 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*dstcpy;
	const char		*srccpy;

	i = 0;
	dstcpy = dst;
	srccpy = src;
	if (dstcpy > srccpy)
	{
		while (i < len)
		{
			dstcpy[len - 1] = srccpy[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			dstcpy[i] = srccpy[i];
			i++;
		}
	}
	return (dst);
}
