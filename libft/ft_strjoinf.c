/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 08:31:55 by pvillene          #+#    #+#             */
/*   Updated: 2016/10/24 19:36:59 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char const *s1, char const *s2, char f)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	if (str)
	{
		ft_strcpy(str, (char *)s1);
		ft_strcat(str, (char *)s2);
	}
	if (f & 1)
		free((void*)s1);
	if (f & 2)
		free((void*)s2);
	return (str);
}
