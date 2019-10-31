/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstrx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:33:59 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:45:37 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>
#include <wchar.h>

void	ft_putnwstrx(const wchar_t *s, size_t len)
{
	int i;

	i = 0;
	while (*s && (((size_t)i + ft_wchart_octet(*s)) <= len))
	{
		i = i + ft_wchart_octet(*s);
		ft_putwcharx((wchar_t)(*s));
		s++;
	}
}
