/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:17:46 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:19:31 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

/*
** OCP values :
**	- 84 : REG, REG, REG
*/

/*
** sub() function sub the two firsts parameters reg1 and reg2 and store
** the result in res3
*/

int				ft_sub(t_env *env, t_process *current_p)
{
	int			args[4];
	int			ret;

	ret = get_params(&args, env->map[(current_p->pc + 1) % MEM_SIZE],
			current_p->instruction);
	current_p->carry = 0;
	if (args[0] == T_REG && args[1] == T_REG && args[2] == T_REG)
	{
		current_p->reg[env->map[(current_p->pc + 4) % MEM_SIZE] - 1] =
			current_p->reg[env->map[(current_p->pc + 2) % MEM_SIZE] - 1]
			- current_p->reg[env->map[(current_p->pc + 3) % MEM_SIZE] - 1];
		if (current_p->reg[env->map[(current_p->pc + 4) % MEM_SIZE] - 1] == 0)
			current_p->carry = 1;
		return (ret);
	}
	return (ret);
}
