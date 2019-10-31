/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:52:23 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:39:00 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void			*tab;
	unsigned int	i;

	i = 0;
	tab = malloc(sizeof(char) * size);
	if (tab == NULL)
		return (NULL);
	while (i < size)
	{
		*((char*)tab + i) = 0;
		i++;
	}
	return (tab);
}
