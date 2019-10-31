/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 04:19:00 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/29 18:26:55 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			len(int n)
{
	int		res;

	res = 1;
	while (n < -9 || n > 9)
	{
		res++;
		n = n / 10;
	}
	if (n >= 0)
		return (res);
	else
		return (res + 1);
}

char				*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		neg;

	if (n < 0)
		neg = 1;
	else
		neg = 0;
	i = len(n);
	res = (char *)ft_memalloc(sizeof(char) * i + 1);
	while (i-- != 0)
	{
		if (n < 0)
			res[i] = (((n % 10) * -1) + '0');
		else
			res[i] = ((n % 10) + '0');
		n = n / 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
