/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 21:41:25 by pvillene          #+#    #+#             */
/*   Updated: 2016/12/06 19:34:16 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		n;

	i = 0;
	neg = 1;
	n = 0;
	while (((str[i] > 8) && (str[i] < 14)) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	if ((str[i] == '+') && (neg != -1))
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		n = 10 * n;
		n = n + (str[i] - 48);
		if (n > INT_MAX)
			return (0);
		i++;
	}
	return (neg * n);
}
