/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:30:44 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/28 17:37:45 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*flagzero(char *str, char n, int j)
{
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (j + 2));
	while (j-- != 0)
		str[i++] = '0';
	str[i] = n;
	str[i] = '\0';
	return (str);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char	*retspace(char *str)
{
	str = (char *)malloc(sizeof(char) * 1);
	str[0] = '\0';
	return (str);
}
