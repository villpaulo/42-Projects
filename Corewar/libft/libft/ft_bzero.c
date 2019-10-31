/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:33:32 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:07:18 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*s2;

	i = 0;
	s2 = (char*)s;
	while (i < n)
	{
		s2[i] = '\0';
		i++;
	}
}
