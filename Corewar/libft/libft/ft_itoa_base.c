/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:46:04 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:12:23 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <string.h>

static char		ft_len(int nb, char base)
{
	char i;

	i = 2;
	while (nb >= base)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int nb, char base)
{
	char	*str;
	int		len;

	len = ft_len(nb, base);
	str = (char*)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	if (base == 10)
	{
		str = ft_itoa(nb);
		return (str);
	}
	str[len - 1] = '\0';
	len = len - 2;
	while (len >= 0 && nb > 0)
	{
		str[len] = (nb % base);
		if (str[len] <= 9)
			str[len] = str[len] + 48;
		else if (str[len] < 16)
			str[len] = str[len] + 55;
		nb = nb / base;
		len--;
	}
	return (str);
}
