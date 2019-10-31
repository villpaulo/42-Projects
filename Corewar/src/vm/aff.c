/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:15:35 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:15:36 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "gui.h"

/*
** OCP values :
**	- 64 : REG
*/

/*
** write reg[param1] % 256 in stdout
*/

int		ft_aff(t_env *env, t_process *current_p)
{
	char		reg_id;
	char		a;

	reg_id = env->map[(current_p->pc + 2) % MEM_SIZE];
	if (reg_id > 0 && reg_id < 17 && env->flags.v == 0 &&
		(env->flags.a == 1 || env->flags.u == 1))
	{
		a = current_p->reg[reg_id - 1] % 256;
		if (env->flags.u == 0)
			write(1, "Aff :", 5);
		write(1, &a, 1);
		if (env->flags.u == 0)
			write(1, "\n", 1);
	}
	else if (reg_id > 0 && reg_id < 17)
	{
		a = current_p->reg[reg_id - 1] % 256;
		ins_aff_gui(&env->gui, a, 1);
	}
	return (3);
}
