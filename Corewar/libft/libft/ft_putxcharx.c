/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxcharx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:46:19 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:47:54 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

void	ft_putxcharx(char c, int i)
{
	char str[i + 1];

	ft_memset(str, c, i);
	str[i] = '\0';
	ft_putstrx(ft_strdup(str));
}
