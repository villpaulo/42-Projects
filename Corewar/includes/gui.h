/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 20:57:14 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/02 22:01:35 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "corewar.h"

/*
** gui_print_map.c
*/

void	gui_winner(t_env *env);
void	print_on_map_2(t_gui *gui, char d, int t[2]);
void	print_on_map(t_gui *gui, char c, char d, int t[2]);
void	print_map(t_env *env, t_gui *gui);

/*
** gui_stat.c
*/

void	print_vitess(t_gui *gui);
void	ins_aff_gui(t_gui *gui, int val, char a);
void	print_mod(t_gui *gui);
void	print_stat(t_env *env, t_gui *gui);

/*
** gui_top.c
*/

void	print_pause(t_gui *gui);
void	print_corewar(t_gui *gui);
void	create_window(t_gui *gui);
void	print_error_gui(t_env *env);

/*
** gui_start.c
*/

void	true_gui(t_env *env);
void	init_gui(t_env *env);

#endif
