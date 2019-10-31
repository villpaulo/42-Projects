/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstrx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:11:50 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:44:50 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	ft_putnstrx(const char *s, size_t len)
{
	int i;

	i = 0;
	while (i < (int)len && s[i])
	{
		ft_putcharx(s[i]);
		i++;
	}
}
