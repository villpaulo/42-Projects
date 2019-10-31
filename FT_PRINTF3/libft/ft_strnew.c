/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:11:51 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/23 20:41:52 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnew(size_t size)
{
	char		*new;
	int			i;

	i = (int)size;
	if (!(new = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i > 0)
	{
		new[i--] = '\0';
	}
	return (new);
}
