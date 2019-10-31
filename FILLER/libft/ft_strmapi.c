/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:09:31 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/30 12:09:53 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t	i;
	char	*mem;

	i = 0;
	if (s != NULL || f != NULL)
	{
		mem = malloc(sizeof(char) * ft_strlen(s) + 1);
		while (s[i] != 0)
		{
			mem[i] = f(i, s[i]);
			i++;
		}
		mem[i] = '\0';
		return (mem);
	}
	return (NULL);
}
