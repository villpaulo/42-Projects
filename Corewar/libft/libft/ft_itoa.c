/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:51:35 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:12:07 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <string.h>

static char		ft_len(int nb)
{
	char i;

	i = 2;
	if (nb == -2147483648)
		return (12);
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

static char		*ft_intmin(char *str)
{
	str[0] = '-';
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
	int		len;

	len = ft_len(n);
	str = (char*)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		str = ft_intmin(str);
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
