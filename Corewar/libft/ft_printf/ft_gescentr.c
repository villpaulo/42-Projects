/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gescentr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:32:43 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 13:37:06 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

int		ft_gescentr2(char *s, int t[15], int w[2], va_list ap)
{
	int j;
	int tmp;

	j = w[1];
	tmp = w[0];
	while (j < tmp && s[j] == 0)
		j++;
	if (s[j] > 48 && s[j] < 58)
	{
		ft_wildcard(s, t, w, &(*ap));
		return ((ft_atoi(s + j)));
	}
	else
		return (-1);
}

int		ft_gescentr(char *s, int t[15], int v[3], va_list ap)
{
	int w[2];

	w[1] = v[1];
	w[0] = w[1];
	t[12] = 1;
	t[4] = 1;
	while (w[1] >= v[0])
	{
		if (s[w[1]] == ',')
		{
			w[1]++;
			if (s[w[1]] == '*')
				return (ft_wildprec(&(*ap)));
			return (ft_gescentr2(s, t, w, &(*ap)));
		}
		w[1]--;
	}
	return (0);
}
