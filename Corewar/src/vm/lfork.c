/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:16:09 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:16:11 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

/*
** create new process at list begin without IDX_MOD
*/

int			ft_lfork(t_env *env, t_process *current_p)
{
	t_process		*elm;
	t_process		*tmp;
	int				dist;

	dist = get_ind(env->map, current_p->pc + 1);
	if ((elm = init_fork(current_p, dist, &(env->num))) == NULL)
		return (PARAM_ERROR);
	tmp = env->process;
	elm->next = tmp;
	env->process = elm;
	(env->nb_process)++;
	return (3);
}
