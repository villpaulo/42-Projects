/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:17:54 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:17:55 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

int		ft_zjump(t_env *env, t_process *current_p)
{
	int	jump;

	if (current_p->carry)
	{
		jump = get_ind(env->map, current_p->pc + 1);
		return ((MEM_SIZE + jump) % MEM_SIZE);
	}
	return (3);
}
