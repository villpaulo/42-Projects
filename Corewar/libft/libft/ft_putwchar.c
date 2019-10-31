/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:28:17 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:46:56 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <wchar.h>

void	ft_putwchar(wchar_t c)
{
	if (c < 0x80)
		ft_putchar(c);
	else if (c < 0x800)
	{
		ft_putchar(0xC0 | (c >> 6));
		ft_putchar(0x80 | (c & 0x3F));
	}
	else if (c < 0x10000)
	{
		ft_putchar(0xE0 | (c >> 12));
		ft_putchar(0x80 | ((c >> 6) & 0x3F));
		ft_putchar(0x80 | (c & 0x3F));
	}
	else if (c < 0x200000)
	{
		ft_putchar(0xF0 | (c >> 18));
		ft_putchar(0x80 | ((c >> 12) & 0x3F));
		ft_putchar(0x80 | ((c >> 6) & 0x3F));
		ft_putchar(0x80 | (c & 0x3F));
	}
}
