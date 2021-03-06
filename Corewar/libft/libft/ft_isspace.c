/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:39:34 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 17:00:39 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

int		ft_isspace(int c)
{
	if (c == 32 || c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r')
		return (1);
	else
		return (0);
}
