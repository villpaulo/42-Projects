/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 21:05:22 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/02 21:07:35 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	print_vitess(t_gui *gui)
{
	int i;

	i = 1;
	werase(gui->vitess);
	wborder(gui->vitess, '|', '|', '-', '-', '+', '+', '+', '+');
	wattron(gui->vitess, COLOR_PAIR(10));
	mvwprintw(gui->vitess, 1, 1, "-                  VITE");
	mvwprintw(gui->vitess, 1, 24, "SSE                   +");
	wattroff(gui->vitess, COLOR_PAIR(10));
	while (i <= (23000 - gui->speed) / 500)
	{
		wattron(gui->vitess, COLOR_PAIR(9));
		mvwprintw(gui->vitess, 2, i, " ");
		wattroff(gui->vitess, COLOR_PAIR(9));
		i++;
	}
	mvwprintw(gui->vitess, 3, 7, "PRESS '-'/'+' TO CHANGE THE SPEED");
	wrefresh(gui->vitess);
}

void	ins_aff_gui(t_gui *gui, int val, char a)
{
	wattron(gui->info, COLOR_PAIR(10));
	mvwprintw(gui->info, 35, 1, "                INSTRUCT");
	mvwprintw(gui->info, 35, 25, "ION AFF               ");
	wattroff(gui->info, COLOR_PAIR(10));
	if (a != 0)
		mvwprintw(gui->info, 36, 5, "VAL : ->%d<-", val);
}

void	print_mod(t_gui *gui)
{
	mvwprintw(gui->info, 15, 2, "CYCLE_DELTA: %d", CYCLE_DELTA);
	mvwprintw(gui->info, 16, 2, "NBR_LIVE: %d", NBR_LIVE);
	wattron(gui->info, COLOR_PAIR(10));
	mvwprintw(gui->info, 25, 1, "                 MOD AFF");
	mvwprintw(gui->info, 25, 25, "ICHAGE:               ");
	wattroff(gui->info, COLOR_PAIR(10));
	mvwprintw(gui->info, 27, 2, "- '1' : CLASSICAL MOD");
	mvwprintw(gui->info, 28, 5, "MAP WITH CHAMP IN HEXA");
	mvwprintw(gui->info, 29, 2, "- '2' : SIMPLE MOD");
	mvwprintw(gui->info, 30, 5, "MAP WITH COLOR");
	ins_aff_gui(gui, 0, 0);
	wattron(gui->info, COLOR_PAIR(10));
	mvwprintw(gui->info, 55, 1, "                  COREWA");
	mvwprintw(gui->info, 55, 25, "R BY                  ");
	wattroff(gui->info, COLOR_PAIR(10));
	mvwprintw(gui->info, 56, 5, "PBENOIT (VM & GUI)");
	mvwprintw(gui->info, 57, 5, "PIBENOIT (VM & DESA)");
	mvwprintw(gui->info, 58, 5, "PVILLENE (ASM)");
	mvwprintw(gui->info, 59, 5, "CARODRIG (CHAMP & VM)");
}

void	print_stat(t_env *env, t_gui *gui)
{
	unsigned int	i;
	t_champ			*champ;
	t_process		*proc;

	i = 0;
	proc = env->process;
	wattron(gui->info, COLOR_PAIR(10));
	mvwprintw(gui->info, 1, 1, "                  INFORM");
	mvwprintw(gui->info, 1, 25, "ATIONS                ");
	wattroff(gui->info, COLOR_PAIR(10));
	mvwprintw(gui->info, 3, 2, "Nombre de joueur: %d", env->nb_joueurs);
	champ = env->champ;
	while (i < env->nb_joueurs)
	{
		mvwprintw(gui->info, i + 4, 15, "- Joueur %d: ", champ->player);
		wattron(gui->info, COLOR_PAIR(env->nb_joueurs - i));
		mvwprintw(gui->info, i + 4, 27, "%s", champ->name);
		wattroff(gui->info, COLOR_PAIR(env->nb_joueurs - i));
		i++;
		champ = champ->next;
	}
	mvwprintw(gui->info, 12, 2, "Nombre de process: %d", env->nb_process);
	mvwprintw(gui->info, 13, 2, "Nombre de cycles: %d", env->nb_cycle);
	mvwprintw(gui->info, 14, 2, "CYCLE_TO_DIE: %d", env->cycles_to_die);
	print_mod(gui);
}
