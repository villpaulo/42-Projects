/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:17:09 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:17:11 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAY_GAME_H
# define PLAY_GAME_H

# include "corewar.h"
# include "gui.h"

void			check_alive_process(t_env *env, t_process *prev,
		t_process *alst);
void			exec_process(t_env *env, t_process *current_p);
unsigned int	set_cycles(int instruction);

void			ft_play_game(t_env *env);
unsigned int	ft_play_game_2(t_env *env, unsigned int i);
void			ft_play_game_gui(t_env *env);

#endif
