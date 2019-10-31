/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:07:00 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:44:34 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <unistd.h>
#include <string.h>

void	ft_putnstr(const char *s, size_t len)
{
	write(1, s, (ft_strlen(s) - ft_strlen(s + len)));
}
