/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 01:29:04 by pvillene          #+#    #+#             */
/*   Updated: 2014/11/27 08:05:56 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	k;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	k = 0;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k++;
	while ((i > k) && (s[i - 1] == ' ' || s[i - 1] == '\n'
				|| s[i - 1] == '\t'))
		i--;
	str = ft_strsub(s, k, (i - k));
	return (str);
}
