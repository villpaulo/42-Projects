/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:45:51 by pvillene          #+#    #+#             */
/*   Updated: 2016/09/05 16:20:45 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		searchhide(char *hide, char *src)
{
	int i;

	i = 0;
	while (hide[i] == src[i] && hide[i] && src[i])
		i++;
	if (hide[i] == '\0')
		return (1);
	return (0);
}

int		hidenp(char *hide, char *src)
{
	int i;

	i = 0;
	if (!hide || !src)
		return (0);
	while (src[i])
	{
		if (hide[0] == src[i])
		{
			if (searchhide(hide, (src + i)) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}
