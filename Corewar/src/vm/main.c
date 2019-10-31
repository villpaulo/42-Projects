/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:49:06 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/02 19:39:38 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_init.h"
#include "play_game.h"
#include <unistd.h>

int			main(int ac, char **av)
{
	t_env	alpha;
	t_champ *champ;

	ft_init(&alpha, ac, av);
	if ((alpha.map)[0] == 0 || alpha.champ == NULL || alpha.process == NULL)
		return (0);
	if (alpha.flags.v == 0)
	{
		champ = alpha.champ;
		ft_play_game(&alpha);
		while (champ)
		{
			if (champ->player == alpha.winner)
				ft_printf("le joueur %d(%s) a gagne\n", champ->player,
						champ->name);
			champ = champ->next;
		}
	}
	else
		ft_play_game_gui(&alpha);
	ft_free(&alpha);
	return (0);
}
