/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_print_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 21:02:28 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/02 21:57:41 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	gui_winner(t_env *env)
{
	t_champ *champ;

	champ = env->champ;
	while (champ)
	{
		if (champ->player == env->winner)
		{
			wattron(env->gui.game, COLOR_PAIR(11));
			mvwprintw(env->gui.game, 32, 95, "LE GAGNANT EST : %s(%d)",
					champ->name, champ->player);
			mvwprintw(env->gui.game, 33, 95, "Cri de victoire : %s",
					champ->comment);
			mvwprintw(env->gui.game, 34, 95, "PRESS ANY KEY TO QUIT");
			wattroff(env->gui.game, COLOR_PAIR(11));
			wrefresh(env->gui.game);
			nodelay(stdscr, FALSE);
			getch();
		}
		champ = champ->next;
	}
}

void	print_on_map_2(t_gui *gui, char d, int t[2])
{
	if (t[1] == 4)
		t[1] = 0;
	else
		t[1] = 4;
	if (d > 0)
		wattron(gui->game, COLOR_PAIR(d + t[1]));
	else
		wattron(gui->game, COLOR_PAIR(0));
	if (t[1] == 4)
		mvwprintw(gui->game, t[0] / 64 + 1, (t[0] % 64) * 3 + 1, "   ");
	else
		mvwprintw(gui->game, t[0] / 64 + 1, (t[0] % 64) * 3 + 1, "\\o/");
	if (d > 0)
		wattroff(gui->game, COLOR_PAIR(d + t[1]));
	else
		wattroff(gui->game, COLOR_PAIR(0));
}

void	print_on_map(t_gui *gui, char c, char d, int t[2])
{
	unsigned char	val[3];

	val[0] = (unsigned char)c / 16;
	val[1] = (unsigned char)c % 16;
	if (val[0] < 10)
		val[0] += 48;
	else
		val[0] += 87;
	if (val[1] < 10)
		val[1] += 48;
	else
		val[1] += 87;
	val[2] = 0;
	if (d > 0)
		wattron(gui->game, COLOR_PAIR(d + t[1]));
	else
		wattron(gui->game, COLOR_PAIR(0));
	mvwprintw(gui->game, t[0] / 64 + 1, (t[0] % 64) * 3 + 1, "%s", val);
	if (d > 0)
		wattroff(gui->game, COLOR_PAIR(d + t[1]));
	else
		wattroff(gui->game, COLOR_PAIR(0));
	mvwprintw(gui->game, t[0] / 64 + 1, (t[0] % 64) * 3 + 3, " ");
}

void	print_map(t_env *env, t_gui *gui)
{
	int			t[2];
	t_process	*proc;

	t[0] = 0;
	while (t[0] < 4096)
	{
		proc = env->process;
		t[1] = 0;
		while (proc)
		{
			if (t[0] == proc->pc)
			{
				t[1] = 4;
				break ;
			}
			proc = proc->next;
		}
		if (gui->mod == 1)
			print_on_map(gui, env->map[t[0]], env->map2[t[0]], t);
		else if (gui->mod == 2)
			print_on_map_2(gui, env->map2[t[0]], t);
		t[0]++;
	}
	wrefresh(gui->game);
}
