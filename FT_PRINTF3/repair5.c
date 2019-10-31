/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repair5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:11:59 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/28 18:19:57 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*retz(char *str)
{
	str = (char *)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*retuz(char *str, int *tab)
{
	str = (char *)malloc(sizeof(char) * 3);
	if (tab[5] == 0 && tab[6] == 0 && tab[2] == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
		str[0] = '\0';
	return (str);
}
