/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstrx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 18:03:03 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:47:28 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <wchar.h>

void	ft_putwstrx(wchar_t *str)
{
	while (*str)
	{
		if (*str < 0x80)
			ft_putcharx(*str);
		else if (*str < 0x800)
		{
			ft_putcharx(0xC0 | (*str >> 6));
			ft_putcharx(0x80 | (*str & 0x3F));
		}
		else if (*str < 0x10000)
		{
			ft_putcharx(0xE0 | (*str >> 12));
			ft_putcharx(0x80 | ((*str >> 6) & 0x3F));
			ft_putcharx(0x80 | (*str & 0x3F));
		}
		else if (*str < 0x200000)
		{
			ft_putcharx(0xF0 | (*str >> 18));
			ft_putcharx(0x80 | ((*str >> 12) & 0x3F));
			ft_putcharx(0x80 | ((*str >> 6) & 0x3F));
			ft_putcharx(0x80 | (*str & 0x3F));
		}
		str++;
	}
}
