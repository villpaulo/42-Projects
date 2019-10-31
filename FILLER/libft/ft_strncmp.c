/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 21:40:22 by pvillene          #+#    #+#             */
/*   Updated: 2014/11/28 07:23:43 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s1_value;
	size_t	s2_value;

	i = 0;
	while (s1[i] == s2[i] && i < n && s1[i] != 0 && s2[i] != 0)
	{
		i++;
	}
	if (i == n)
	{
		s1_value = s1[i - 1];
		s2_value = s2[i - 1];
	}
	else
	{
		s1_value = s1[i];
		s2_value = s2[i];
	}
	return ((unsigned char)s1_value - (unsigned char)s2_value);
}
