/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 18:03:17 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:42:38 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <wchar.h>
#include <stdlib.h>

void	ft_putcharx(char c)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 2);
	if (str == NULL)
		return ;
	str[0] = c;
	str[1] = '\0';
	ft_putstrz(str, 0, 0);
}
