/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 15:12:38 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:12:55 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <string.h>

static char		ft_len(long long nb)
{
	char	i;

	i = 2;
	if ((nb + 1) == -9223372036854775807)
		return (20);
	else if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_lltoa(long long n)
{
	char	*str;
	int		len;

	len = ft_len(n);
	str = (char*)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	if ((n + 1) == -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	else if (n == 0)
		*str = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len - 1] = '\0';
	len = len - 2;
	while (len >= 0 && n > 0)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}
