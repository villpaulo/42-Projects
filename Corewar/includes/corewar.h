/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:14:09 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 17:21:46 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"
# include <ncurses.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct			s_champ
{
	unsigned int		player;
	int					fd;
	int					nb_lives_done;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	unsigned int		prog_size;
	struct s_champ		*next;
}						t_champ;

typedef struct			s_process
{
	int					instruction;
	unsigned int		num;
	char				carry;
	unsigned int		cycles_left;
	unsigned int		player;
	int					pc;
	bool				alive;
	int					reg[REG_NUMBER];
	struct s_process	*next;
}						t_process;

typedef struct			s_gui
{
	WINDOW				*title;
	WINDOW				*run;
	WINDOW				*game;
	WINDOW				*info;
	WINDOW				*vitess;
	int					touche;
	char				pause;
	int					speed;
	char				mod;
}						t_gui;

typedef struct			s_flags
{
	char				dump;
	unsigned int		nb_dump;
	char				v;
	char				l;
	char				a;
	char				u;
	int					j[4];
}						t_flags;

typedef struct			s_env
{
	char				map[MEM_SIZE + 1];
	char				map2[MEM_SIZE + 1];
	unsigned int		num;
	unsigned int		cycles_to_die;
	unsigned int		nb_joueurs;
	unsigned int		nb_lives;
	unsigned int		winner;
	unsigned int		nb_cycle;
	unsigned int		nb_process;
	int					check;
	t_champ				*champ;
	t_process			*process;
	t_flags				flags;
	t_gui				gui;
}						t_env;

/*
**	ft_play_game
*/

/*
**	ft_free
*/

void					ft_free(t_env *env);
void					ft_error(t_env *env);
void					ft_dump(t_env *env);

#endif
