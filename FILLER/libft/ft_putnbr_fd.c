/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 06:57:05 by pvillene          #+#    #+#             */
/*   Updated: 2015/04/07 22:30:20 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int tab[100];
	int i;

	i = 0;
	if (!n)
		ft_putchar_fd('0', fd);
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	while (n > 0)
	{
		tab[i] = n % 10;
		n = n / 10;
		i++;
	}
	while (i--)
		ft_putchar_fd(tab[i] + 48, fd);
}
