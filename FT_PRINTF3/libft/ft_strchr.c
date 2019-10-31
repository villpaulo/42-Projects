/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 21:35:50 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/30 11:42:13 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)s;
	while (s[i] != 0 && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (ret + i);
	else
		return (NULL);
}
