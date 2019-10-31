/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:15:51 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:15:52 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "ft_init.h"

/*
** OCP values :
**	- 144 : DIR, REG
**	- 208 : INDIR, REG
*/

/*
** copy pc + 1 in reg[index]
*/

void		ft_ld_2(t_env *env, t_process *current_p, int t[3])
{
	t[0] = env->map[(current_p->pc + 4) % MEM_SIZE];
	if (t[0] < 1 || t[0] > 16)
		return ;
	t[1] = (get_ind((char *)env->map, current_p->pc + 2)) % IDX_MOD;
	t[2] = get_dir((char *)env->map, current_p->pc + t[1]);
	if (t[2] == 0)
		current_p->carry = 1;
	current_p->reg[t[0] - 1] = t[2];
}

int			ft_ld(t_env *env, t_process *current_p)
{
	int			t[3];
	int			ret;
	int			args[4];

	ret = get_params(&args, env->map[(current_p->pc + 1) % MEM_SIZE],
			current_p->instruction);
	current_p->carry = 0;
	if (args[0] & g_op_tab[1].type_args[0]
			&& args[1] & g_op_tab[1].type_args[1])
	{
		if (args[0] & T_DIR && args[1] & T_REG)
		{
			t[0] = env->map[(MEM_SIZE + current_p->pc + 6) % MEM_SIZE];
			if (t[0] < 1 || t[0] > 16)
				return (ret);
			t[2] = get_dir((char *)env->map, current_p->pc + 2);
			if (t[2] == 0)
				current_p->carry = 1;
			current_p->reg[t[0] - 1] = t[2];
			return (ret);
		}
		else if (args[0] & T_IND && args[1] & T_REG)
			ft_ld_2(env, current_p, t);
	}
	return (ret);
}
