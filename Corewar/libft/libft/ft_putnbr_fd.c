/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:53:19 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:44:19 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		i;

	i = 48;
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 0 && (n - 1) < n)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 0 && n < 10)
	{
		i = i + n;
		write(fd, &i, 1);
	}
	else
		write(fd, "-2147483648", 11);
}
