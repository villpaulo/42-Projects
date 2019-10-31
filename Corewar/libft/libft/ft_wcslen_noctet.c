/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen_noctet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 22:53:33 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:58:06 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <wchar.h>
#include <string.h>

size_t	ft_wcslen_noctet(wchar_t *s, size_t max)
{
	size_t len;

	len = 0;
	while (*s && len <= max)
	{
		if (*s < 0x80 && (len + 1 <= max))
			len++;
		else if (*s < 0x800 && (len + 2 <= max))
			len += 2;
		else if (*s < 0x10000 && (len + 3 <= max))
			len += 3;
		else if (*s < 0x200000 && (len + 4 <= max))
			len += 4;
		s++;
	}
	return (len);
}
