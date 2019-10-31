/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:39:19 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:57:40 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <wchar.h>
#include <string.h>

size_t	ft_wcslen(const wchar_t *s)
{
	register const wchar_t *str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}
