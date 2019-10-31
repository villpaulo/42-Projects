/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:19:13 by pvillene          #+#    #+#             */
/*   Updated: 2016/09/05 16:19:17 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int tab[11];
	int i;

	i = 0;
	if (!n)
		ft_putchar('0');
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0 && (n *= -1))
		ft_putchar('-');
	while (n > 0)
	{
		tab[i] = n % 10;
		n = n / 10;
		i++;
	}
	while (i--)
		ft_putchar(tab[i] + 48);
}
