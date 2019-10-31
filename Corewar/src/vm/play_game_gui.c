/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game_gui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:17:18 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:17:21 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play_game.h"
#include "ft_init.h"

unsigned int				ft_play_game_2(t_env *env, unsigned int i)
{
	check_alive_process(env, env->process, env->process);
	if (env->nb_lives >= NBR_LIVE || env->check == MAX_CHECKS)
	{
		i++;
		env->check = 1;
	}
	else
		(env->check)++;
	env->nb_lives = 0;
	if ((CYCLE_TO_DIE - (i * CYCLE_DELTA)) > 0)
		env->cycles_to_die += (CYCLE_TO_DIE - (i * CYCLE_DELTA));
	return (i);
}

void						ft_play_game_gui(t_env *env)
{
	t_process		*current_p;
	unsigned int	i;

	init_gui(env);
	i = 0;
	while (env->process && env->nb_cycle < env->cycles_to_die)
	{
		current_p = env->process;
		while (current_p)
		{
			exec_process(env, current_p);
			current_p = current_p->next;
		}
		if (env->nb_process < 500 ||
			(env->gui.speed == 0 && env->nb_cycle % 50 == 0))
			true_gui(env);
		env->nb_cycle++;
		if (env->nb_cycle == env->cycles_to_die)
			i = ft_play_game_2(env, i);
	}
	true_gui(env);
	gui_winner(env);
	endwin();
}
