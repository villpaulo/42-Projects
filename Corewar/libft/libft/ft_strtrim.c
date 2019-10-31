/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:32:31 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:55:54 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*s2;

	if (*s == '\0')
		return ((char*)s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = i;
	while (s[j] != '\0')
		j++;
	j--;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && (j > i))
		j--;
	s2 = ft_strsub(s, i, (j - i + 1));
	return (s2);
}
