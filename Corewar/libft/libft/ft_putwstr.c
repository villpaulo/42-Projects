/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:42:55 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:47:18 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <wchar.h>

void	ft_putwstr(const wchar_t *s)
{
	while (*s)
	{
		ft_putwchar((wchar_t)*s);
		s++;
	}
}
