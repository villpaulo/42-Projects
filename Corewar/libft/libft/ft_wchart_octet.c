/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchart_octet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:58:04 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:57:18 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <wchar.h>
#include <string.h>

size_t	ft_wchart_octet(wchar_t s)
{
	size_t len;

	len = 0;
	if (s < 0x80)
		len++;
	else if (s < 0x800)
		len += 2;
	else if (s < 0x10000)
		len += 3;
	else if (s < 0x200000)
		len += 4;
	return (len);
}
