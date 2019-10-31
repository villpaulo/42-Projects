/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:55:01 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:53:36 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int i;
	unsigned int k;

	i = 0;
	k = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n && k == 0)
	{
		if (s1[i] == s2[i])
			i++;
		else
			k++;
	}
	if (i == n || s1[i] == '\0')
		return (1);
	else
		return (0);
}
