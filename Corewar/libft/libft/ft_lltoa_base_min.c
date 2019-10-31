/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 20:10:58 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:13:17 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <string.h>

static char		ft_len(unsigned long long nb, char base)
{
	char i;

	i = 2;
	while (nb >= (unsigned long long)base)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char			*ft_lltoa_base_min(unsigned long long nb, char base)
{
	char	*str;
	int		len;

	len = ft_len(nb, base);
	str = (char*)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	if (nb == 0)
	{
		free(str);
		return (ft_strdup("0"));
	}
	str[len - 1] = '\0';
	len = len - 2;
	while (len >= 0 && nb > 0)
	{
		str[len] = (nb % base);
		if (str[len] <= 9)
			str[len] = str[len] + 48;
		else if (str[len] < 16)
			str[len] = str[len] + 87;
		nb = nb / base;
		len--;
	}
	return (str);
}
