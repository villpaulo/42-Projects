/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:19:40 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:52:15 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <string.h>

size_t		ft_strlen(const char *s)
{
	register const char *str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}
