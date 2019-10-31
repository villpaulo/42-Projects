/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:15:53 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/01 16:15:55 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <unistd.h>

void	ft_puthexa_to_so(char nb, int i)
{
	unsigned char	tab[4];

	tab[0] = (unsigned char)nb / 16;
	tab[1] = (unsigned char)nb % 16;
	if (i % 32 == 31)
		tab[2] = '\n';
	else
		tab[2] = ' ';
	tab[3] = '\0';
	if (tab[0] < 10)
		tab[0] += 48;
	else
		tab[0] += 87;
	if (tab[1] < 10)
		tab[1] += 48;
	else
		tab[1] += 87;
	write(1, tab, 3);
}

void	ft_dump(t_env *env)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_puthexa_to_so(env->map[i], i);
		i++;
	}
	ft_free(env);
	exit(0);
}
