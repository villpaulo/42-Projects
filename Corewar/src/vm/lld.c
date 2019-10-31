/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:16:35 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:16:38 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

/*
** OCP values :
**	- 144 : DIR, REG
**	- 208 : INDIR, REG
*/

/*
** copy pc + 1 in reg[index]
*/

void		ft_lld_2(t_env *env, t_process *current_p, int t[3])
{
	t[0] = env->map[(current_p->pc + 4) % MEM_SIZE];
	if (t[0] < 1 || t[0] > 16)
		return ;
	t[1] = get_ind((char *)env->map, current_p->pc + 2);
	t[2] = get_dir((char *)env->map, current_p->pc + t[1]);
	current_p->reg[t[0] - 1] = t[2];
	if (t[2] == 0)
		current_p->carry = 1;
}

int			ft_lld(t_env *env, t_process *current_p)
{
	int			t[3];
	int			ret;
	int			args[4];

	ret = get_params(&args, env->map[(current_p->pc + 1) % MEM_SIZE],
			current_p->instruction);
	current_p->carry = 0;
	if (args[0] & g_op_tab[12].type_args[0]
			&& args[1] & g_op_tab[1].type_args[1])
	{
		if (args[0] & T_DIR && args[1] & T_REG)
		{
			t[0] = env->map[(current_p->pc + 6) % MEM_SIZE];
			if (t[0] < 1 || t[0] > 16)
				return (ret);
			t[2] = get_dir((char *)env->map, current_p->pc + 2);
			current_p->reg[t[0] - 1] = t[2];
			if (t[2] == 0)
				current_p->carry = 1;
			return (ret);
		}
		else if (args[0] & T_IND && args[1] & T_REG)
			ft_lld_2(env, current_p, t);
	}
	return (ret);
}
