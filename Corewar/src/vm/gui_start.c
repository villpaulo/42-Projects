/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 21:08:04 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/02 22:01:58 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	gui_init_color(void)
{
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_RED);
	init_pair(6, COLOR_WHITE, COLOR_GREEN);
	init_pair(7, COLOR_WHITE, COLOR_YELLOW);
	init_pair(8, COLOR_WHITE, COLOR_CYAN);
	init_pair(9, COLOR_BLACK, COLOR_RED);
	init_pair(11, COLOR_BLUE, COLOR_WHITE);
}

void	init_gui(t_env *env)
{
	int lig;
	int col;

	initscr();
	getmaxyx(stdscr, lig, col);
	if (lig < 75 || col < 244)
		print_error_gui(env);
	env->gui.pause = 1;
	env->gui.speed = 11500;
	env->gui.mod = 1;
	env->gui.title = newwin(9, 194, 0, 0);
	env->gui.run = newwin(9, 48, 0, 195);
	env->gui.game = newwin(66, 194, 9, 0);
	env->gui.vitess = newwin(5, 48, 9, 195);
	env->gui.info = newwin(61, 48, 14, 195);
	noecho();
	gui_init_color();
	curs_set(FALSE);
}

void	touche(t_env *env, t_gui *gui)
{
	wrefresh(gui->info);
	if (gui->touche == 27 && gui->touche != 126)
	{
		endwin();
		ft_free(env);
		exit(0);
	}
	else if (gui->touche == 43 && gui->speed > 499)
		gui->speed -= 500;
	else if (gui->touche == 45 && gui->speed < 23001)
		gui->speed += 500;
	else if (gui->touche == 49 && gui->mod == 2)
		gui->mod = 1;
	else if (gui->touche == 50 && gui->mod == 1)
		gui->mod = 2;
}

void	la_pause(t_env *env, t_gui *gui)
{
	gui->pause = 1;
	create_window(gui);
	print_corewar(gui);
	print_pause(gui);
	print_map(env, gui);
	print_vitess(gui);
	print_stat(env, gui);
	wrefresh(gui->title);
	wrefresh(gui->info);
	while (1)
	{
		gui->touche = getch();
		wrefresh(gui->run);
		if (gui->touche == 32)
		{
			gui->pause = 0;
			return ;
		}
		else if (gui->touche != 32 && gui->touche != -1)
			touche(env, gui);
		print_vitess(gui);
		print_map(env, gui);
	}
}

void	true_gui(t_env *env)
{
	nodelay(stdscr, TRUE);
	create_window(&(env->gui));
	print_corewar(&(env->gui));
	print_pause(&(env->gui));
	print_map(env, &(env->gui));
	print_vitess(&(env->gui));
	print_stat(env, &(env->gui));
	wrefresh((env->gui.info));
	(env->gui.touche = getch());
	if (env->gui.touche == 32 || env->gui.pause == 1)
		la_pause(env, &(env->gui));
	else if (env->gui.touche != 32 && env->gui.touche != -1)
		touche(env, &(env->gui));
	usleep((env->gui.speed));
}
