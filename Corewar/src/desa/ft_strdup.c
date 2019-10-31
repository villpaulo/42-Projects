/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:42:16 by pibenoit          #+#    #+#             */
/*   Updated: 2016/11/29 13:26:12 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "desa.h"
#include <stdlib.h>

char	*ft_strdup(char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	s2 = (char*)malloc(sizeof(char) * i + 1);
	if (s2 != NULL)
		while (i >= 0)
		{
			*(s2 + i) = *(s1 + i);
			i--;
		}
	else
		return (NULL);
	return (s2);
}
