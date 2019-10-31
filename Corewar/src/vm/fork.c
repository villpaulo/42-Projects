/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:05:03 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:05:29 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

t_process	*init_fork(t_process *current_p, int dist, unsigned int *num)
{
	t_process	*elm;
	int			i;

	i = -1;
	if ((elm = (t_process *)malloc(sizeof(t_process))) != NULL)
	{
		elm->cycles_left = 0;
		elm->num = *num;
		(*num)++;
		elm->carry = current_p->carry;
		elm->player = current_p->player;
		elm->pc = (MEM_SIZE + current_p->pc + dist) % MEM_SIZE;
		elm->alive = current_p->alive;
		elm->instruction = 0;
		while (++i < 16)
		{
			elm->reg[i] = current_p->reg[i];
		}
		elm->next = NULL;
	}
	return (elm);
}

/*
** create new process at list begin
*/

int			ft_fork(t_env *env, t_process *current_p)
{
	t_process		*elm;
	t_process		*tmp;
	int				dist;

	dist = get_ind(env->map, current_p->pc + 1);
	if ((elm = init_fork(current_p, dist % IDX_MOD, &(env->num))) == NULL)
		return (PARAM_ERROR);
	tmp = env->process;
	elm->next = tmp;
	env->process = elm;
	(env->nb_process)++;
	return (3);
}
