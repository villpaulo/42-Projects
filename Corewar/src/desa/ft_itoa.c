/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:49:51 by pibenoit          #+#    #+#             */
/*   Updated: 2016/11/29 17:26:44 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "desa.h"
#include <stdlib.h>

static char		length(int n)
{
	char	i;

	i = 2;
	if (n < 0)
	{
		i = i + 1;
		n = (-1) * n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_intmin(char *str)
{
	*str = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	char	len;

	len = length(n);
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	else if (n == -2147483648)
		return (ft_intmin(str));
	if (n < 0)
	{
		n = (-1) * n;
		*str = '-';
	}
	else if (n == 0)
		*str = '0';
	len -= 2;
	*(str + len + 1) = '\0';
	while (len >= 0 && n > 0)
	{
		*(str + len) = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}
