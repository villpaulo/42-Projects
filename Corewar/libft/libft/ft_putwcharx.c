/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwcharx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:51:26 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:47:05 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>
#include <wchar.h>

void	ft_putwcharx(wchar_t c)
{
	if (c < 0x80)
		ft_putcharx(c);
	else if (c < 0x800)
	{
		ft_putcharx(0xC0 | (c >> 6));
		ft_putcharx(0x80 | (c & 0x3F));
	}
	else if (c < 0x10000)
	{
		ft_putcharx(0xE0 | (c >> 12));
		ft_putcharx(0x80 | ((c >> 6) & 0x3F));
		ft_putcharx(0x80 | (c & 0x3F));
	}
	else if (c < 0x200000)
	{
		ft_putcharx(0xF0 | (c >> 18));
		ft_putcharx(0x80 | ((c >> 12) & 0x3F));
		ft_putcharx(0x80 | ((c >> 6) & 0x3F));
		ft_putcharx(0x80 | (c & 0x3F));
	}
}
