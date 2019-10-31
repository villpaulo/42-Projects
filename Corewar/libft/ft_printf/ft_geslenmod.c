/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geslenmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:02:18 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 13:37:31 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

int		ft_selectlenmod(int t[7])
{
	if (t[2] - t[1] == 0 && t[2] != 0)
		t[0] = 1;
	if (t[2] - t[1] > 0)
		t[0] = 2;
	if (t[3] - t[4] > 0)
		t[0] = 3;
	if (t[3] - t[4] == 0 && t[3] != 0)
		t[0] = 4;
	if (t[5] > 0)
		t[0] = 5;
	if (t[6] > 0)
		t[0] = 6;
	return (t[0]);
}

int		ft_geslenmod(char *str, int i, int j)
{
	int t[7];

	ft_memset(t, 0, 32);
	while (i < j)
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
			t[1] = t[1] + 2;
		if (str[i] == 'h')
			t[2]++;
		if (str[i] == 'l')
			t[3]++;
		if (str[i] == 'l' && str[i + 1] == 'l')
			t[4] = t[4] + 2;
		if (str[i] == 'j')
			t[5]++;
		if (str[i] == 'z')
			t[6]++;
		i++;
	}
	return (ft_selectlenmod(t));
}
