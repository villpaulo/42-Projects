/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:40:29 by pbenoit           #+#    #+#             */
/*   Updated: 2017/01/27 09:43:07 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_init.h"

static void		ft_bzero_map(t_env *a)
{
	int i;

	i = 0;
	while (i <= MEM_SIZE)
	{
		a->map[i] = 0;
		a->map2[i] = 0;
		i++;
	}
}

static void		ft_init_map_2(t_env *a, int nb, int size)
{
	int	j;

	j = MEM_SIZE / a->nb_joueurs * (nb - 1);
	while (size > 0)
	{
		a->map2[j] = (char)nb;
		j++;
		size--;
	}
}

void			ft_init_map(t_env *a)
{
	t_champ			*champ;
	char			*str;
	int				i;
	unsigned int	nb;

	ft_bzero_map(a);
	i = 0;
	nb = 1;
	while (nb <= a->nb_joueurs)
	{
		champ = a->champ;
		while (champ && champ->player != nb)
			champ = champ->next;
		if (!(str = (char*)malloc(sizeof(char) * CHAMP_MAX_SIZE + 1)))
			ft_error(a);
		i = read(champ->fd, str, CHAMP_MAX_SIZE);
		str[i] = '\0';
		ft_memcpy(a->map + (MEM_SIZE / a->nb_joueurs * (nb - 1)), str, i);
		ft_init_map_2(a, nb, i);
		nb++;
		free(str);
		str = NULL;
		close(champ->fd);
	}
}
