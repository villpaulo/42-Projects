/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 20:59:14 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/02 21:36:58 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	print_pause(t_gui *gui)
{
	werase(gui->run);
	wborder(gui->run, '|', '|', '-', '-', '+', '+', '+', '+');
	if (gui->pause == 0)
	{
		mvwprintw(gui->run, 7, 8, "PRESS 'SPACE' TO RUN/STOP");
		mvwprintw(gui->run, 2, 4, " ____  _   _ _   _ _   _ ___ _   _  ____");
		mvwprintw(gui->run, 3, 4, "|  _ \\| | | | \\ | | \\ | |_ _|");
		mvwprintw(gui->run, 3, 33, " \\ | |/ ___|");
		mvwprintw(gui->run, 4, 4, "| |_) | | | |  \\| |  \\| || ||");
		mvwprintw(gui->run, 4, 33, "  \\| | |  _");
		mvwprintw(gui->run, 5, 4, "|  _ <| |_| | |\\  | |\\  || || |\\");
		mvwprintw(gui->run, 5, 36, "  | |_| |");
		mvwprintw(gui->run, 6, 4, "|_| \\_\\\\___/|_| \\_|_| ");
		mvwprintw(gui->run, 6, 26, "\\_|___|_| \\_|\\____|");
	}
	else
	{
		mvwprintw(gui->run, 7, 8, "PRESS 'SPACE' TO RUN/STOP");
		mvwprintw(gui->run, 2, 8, " ____   _   _   _ ____  _____");
		mvwprintw(gui->run, 3, 8, "|  _ \\ / \\ | | | / ___|| ____|");
		mvwprintw(gui->run, 4, 8, "| |_) / _ \\| | | \\___ \\|  _|");
		mvwprintw(gui->run, 5, 8, "|  __/ ___ \\ |_| |___) | |___");
		mvwprintw(gui->run, 6, 8, "|_| /_/   \\_\\___/|____/|_____|");
	}
	wrefresh(gui->run);
}

void	print_corewar2(t_gui *gui)
{
	mvwprintw(gui->title, 6, 136, "   `Mb.");
	mvwprintw(gui->title, 7, 55, "  `\"bmmmd'    `\"bmmd\"' .JMML.");
	mvwprintw(gui->title, 7, 84, " .JMM..JMMmmm");
	mvwprintw(gui->title, 7, 97, "mMMM      VF      VF .AMA.");
	mvwprintw(gui->title, 7, 123, "   .AMMA..JMML. .JMM.");
	mvwprintw(gui->title, 7, 159, "THE COREWAR GRAPHIC USER INTERFACE");
}

void	print_corewar(t_gui *gui)
{
	mvwprintw(gui->title, 1, 1, "PRESS 'ESC' TO QUIT");
	mvwprintw(gui->title, 1, 55, "  .g8\"\"\"bgd   .g8\"\"8q. `7MM\"\"\"Mq.");
	mvwprintw(gui->title, 1, 88, "  `7");
	mvwprintw(gui->title, 1, 92, "MM\"\"\"YMM `7MMF'     A     `7MF' db");
	mvwprintw(gui->title, 1, 126, "      `");
	mvwprintw(gui->title, 1, 133, "7MM\"\"\"Mq.");
	mvwprintw(gui->title, 2, 55, ".dP'     `M .dP'    `YM. MM   `MM.   MM");
	mvwprintw(gui->title, 2, 94, "    `7");
	mvwprintw(gui->title, 2, 100, "   `MA     ,MA     ,V  ;MM:       MM");
	mvwprintw(gui->title, 2, 136, "   `MM.");
	mvwprintw(gui->title, 3, 55, "dM'       ` dM'      `MM MM   ,M9    MM");
	mvwprintw(gui->title, 3, 94, "   d  ");
	mvwprintw(gui->title, 3, 100, "    VM:   ,VVM:   ,V  ,V^MM.      MM   ,M9");
	mvwprintw(gui->title, 4, 55, "MM          MM        MM MMmmdM9");
	mvwprintw(gui->title, 4, 87, "     MMmmMM  ");
	mvwprintw(gui->title, 4, 100, "     MM.  M' MM.  M' ,M  `MM      MMmmdM9");
	mvwprintw(gui->title, 5, 55, "MM.         MM.      ,MP MM  YM.     MM");
	mvwprintw(gui->title, 5, 94, "   Y  ");
	mvwprintw(gui->title, 5, 100, ",    `MM A'  `MM A'  AbmmmqMA     MM  YM.");
	mvwprintw(gui->title, 6, 55, "`Mb.     ,' `Mb.    ,dP' MM   `Mb.   MM");
	mvwprintw(gui->title, 6, 94, "     ,");
	mvwprintw(gui->title, 6, 100, "M     :MM;    :MM;  A'     VML    MM");
	print_corewar2(gui);
}

void	create_window(t_gui *gui)
{
	wborder(gui->title, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(gui->run, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(gui->game, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(gui->info, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(gui->vitess, '|', '|', '-', '-', '+', '+', '+', '+');
}

void	print_error_gui(t_env *env)
{
	mvprintw(0, 0, "PLEASE RESIZE THE WINDOWS, THANKS ;D");
	mvprintw(1, 0, "PRESS ANY KEY TO QUIT");
	refresh();
	getch();
	endwin();
	ft_error(env);
}
