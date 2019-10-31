/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:17:01 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:17:05 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play_game.h"
#include "instructions.h"
#include "ft_init.h"

unsigned int	set_cycles(int instruction)
{
	if (instruction == 16)
		return (2);
	else if (instruction == 2 || instruction == 3)
		return (5);
	else if (instruction == 6 || instruction == 7 || instruction == 8)
		return (6);
	else if (instruction == 1 || instruction == 4 || instruction == 5
			|| instruction == 13)
		return (10);
	else if (instruction == 9)
		return (20);
	else if (instruction == 10 || instruction == 11)
		return (25);
	else if (instruction == 14)
		return (50);
	else if (instruction == 12)
		return (800);
	else
		return (1000);
}

void			exec_process_2(t_env *env, t_process *current_p)
{
	static int	(*operator_table[16])(t_env *env, t_process *process) =
	{ft_live, ft_ld, ft_st, ft_add, ft_sub, ft_and, ft_or, ft_xor, ft_zjump,
		ft_ldi, ft_sti, ft_fork, ft_lld, ft_lldi, ft_lfork, ft_aff};
	int			nb;

	(current_p->cycles_left)--;
	if (current_p->instruction != 0 && current_p->cycles_left == 0)
	{
		nb = (*operator_table[current_p->instruction - 1])(env, current_p);
		current_p->pc = (MEM_SIZE + current_p->pc + nb) % MEM_SIZE;
		current_p->instruction = 0;
	}
}

void			exec_process(t_env *env, t_process *current_p)
{
	if (current_p->cycles_left == 0 && current_p->instruction == 0)
	{
		if (env->map[current_p->pc % MEM_SIZE] > 0
				&& env->map[current_p->pc % MEM_SIZE] < 17)
		{
			current_p->instruction = env->map[current_p->pc % MEM_SIZE];
			current_p->cycles_left = set_cycles(current_p->instruction);
			(current_p->cycles_left)--;
			return ;
		}
		else if (env->map[(MEM_SIZE + current_p->pc) % MEM_SIZE] < 1 ||
				env->map[(MEM_SIZE + current_p->pc) % MEM_SIZE] > 16)
		{
			current_p->pc = (MEM_SIZE + current_p->pc + 1) % MEM_SIZE;
			return ;
		}
	}
	else if (current_p->instruction != 0 && current_p->cycles_left > 0)
		exec_process_2(env, current_p);
}

void			check_alive_process(t_env *env, t_process *prev,
		t_process *alst)
{
	while (alst)
	{
		if (alst->alive == 0 && alst == env->process)
		{
			env->process = alst->next;
			(env->nb_process)--;
			free(alst);
			alst = env->process;
		}
		else if (alst->alive == 0 && alst != env->process)
		{
			prev = env->process;
			while (prev && prev->next != alst)
				prev = prev->next;
			prev->next = alst->next;
			(env->nb_process)--;
			free(alst);
			alst = prev->next;
		}
		else if (alst->alive)
		{
			alst->alive = 0;
			alst = alst->next;
		}
	}
}

void			ft_play_game(t_env *env)
{
	t_process		*current_p;
	unsigned int	i;

	i = 0;
	while (env->process && env->nb_cycle <= env->cycles_to_die)
	{
		current_p = env->process;
		while (current_p)
		{
			exec_process(env, current_p);
			current_p = current_p->next;
		}
		env->nb_cycle++;
		if (env->flags.dump == 1 && env->flags.nb_dump == env->nb_cycle)
			ft_dump(env);
		if (env->nb_cycle == env->cycles_to_die)
			i = ft_play_game_2(env, i);
	}
}
