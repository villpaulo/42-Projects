/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 15:54:18 by pvillene          #+#    #+#             */
/*   Updated: 2015/01/20 21:29:37 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	void			*tmp;
	size_t			i;
	unsigned char	*p;

	i = 0;
	tmp = malloc(size);
	if (tmp == NULL)
		return (NULL);
	p = tmp;
	while (i++ < size)
		*p++ = 0;
	return (tmp);
}
