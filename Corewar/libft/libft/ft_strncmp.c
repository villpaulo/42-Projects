/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:08:09 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:53:12 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	i = 0;
	s1c = (unsigned char*)s1;
	s2c = (unsigned char*)s2;
	while ((s1c[i] == s2c[i]) && (i < n) && s1c[i] != '\0')
		i++;
	if (i == n)
		i--;
	if (n == 0)
		return (0);
	return (s1c[i] - s2c[i]);
}
