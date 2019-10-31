/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 19:41:33 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 13:39:15 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdarg.h>

int		ft_wildprec(va_list ap)
{
	int i;

	i = va_arg(ap, int);
	if (i > 0)
		return (i);
	if (i == 0)
		return (-1);
	return (0);
}

int		ft_wildlenmin(int t[15], va_list ap)
{
	int i;

	i = (va_arg(ap, int));
	if (i > 0)
		return (i);
	t[6] = 1;
	return (-i);
}

void	ft_wildcard(char *s, int t[15], int v[3], va_list ap)
{
	int tmp;
	int i;
	int j;

	i = v[0];
	j = v[1];
	tmp = 0;
	while (j >= i && t[12] == 1)
	{
		if (s[j] == '*' && s[j - 1] != '.')
		{
			t[12]++;
			tmp = (va_arg(ap, int));
		}
		j--;
	}
	while (j >= i && t[13] == 1)
	{
		if (s[j] == '*' && s[j - 1] == '.')
		{
			t[12]++;
			tmp = (va_arg(ap, int));
		}
		j--;
	}
}
