/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:06:42 by pibenoit          #+#    #+#             */
/*   Updated: 2016/12/19 12:22:03 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_lenght(char const *s)
{
	unsigned int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;
	unsigned int	len;

	len = ft_lenght(s1) + ft_lenght(s2) + 1;
	str = (char*)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j) != '\0')
	{
		*(str + i) = *(s2 + j);
		i++;
		j++;
	}
	*(str + i) = '\0';
	return (str);
}
