/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 13:04:06 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:44:04 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <unistd.h>

void	ft_putnbr_base(int n, char base)
{
	int	i;
	int j;

	i = 48;
	j = 55;
	if (n >= base)
	{
		ft_putnbr_base(n / base, base);
		ft_putnbr_base(n % base, base);
	}
	else if (n > 0 && n < base)
	{
		if (n <= 9)
		{
			i = i + n;
			write(1, &i, 1);
		}
		else if (n < 16 && n > 9)
		{
			j = j + n;
			write(1, &j, 1);
		}
	}
}
