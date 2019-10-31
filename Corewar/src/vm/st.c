/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:17:32 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:17:35 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "ft_init.h"

/*
** OCP values :
**	- 80 : REG, REG
**	- 112 : REG, INDIR
*/

/*
** copy reg[pc + 1] data in reg[pc + 2] or in map at pos
** pc + map[pc + 2] % IDX_MOD
*/
/*
** static unsigned int	swap_int(unsigned int a)
** {
** 	return ((a << 24) |
** 			((a << 8) & 0x00ff0000) |
** 			((a >> 8) & 0x0000ff00) |
** 			((unsigned int)(a >> 24)));
** }
*/

void			ft_st_2(t_env *env, t_process *current_p, int src_reg)
{
	int				index;
	unsigned int	val;

	index = (get_ind(env->map, current_p->pc + 3)) % IDX_MOD;
	val = get_reg(current_p->reg, src_reg);
	env->map[(MEM_SIZE + current_p->pc + index) % MEM_SIZE] =
		(unsigned char)((val >> 24) & 255);
	env->map[(MEM_SIZE + current_p->pc + index + 1) % MEM_SIZE] =
		(unsigned char)((val >> 16) & 255);
	env->map[(MEM_SIZE + current_p->pc + index + 2) % MEM_SIZE] =
		(unsigned char)((val >> 8) & 255);
	env->map[(MEM_SIZE + current_p->pc + index + 3) % MEM_SIZE] =
		(unsigned char)(val & 255);
	env->map2[(MEM_SIZE + current_p->pc + index) % MEM_SIZE] =
		env->map2[(MEM_SIZE + current_p->pc) % MEM_SIZE];
	env->map2[(MEM_SIZE + current_p->pc + index + 1) % MEM_SIZE] =
		env->map2[(MEM_SIZE + current_p->pc) % MEM_SIZE];
	env->map2[(MEM_SIZE + current_p->pc + index + 2) % MEM_SIZE] =
		env->map2[(MEM_SIZE + current_p->pc) % MEM_SIZE];
	env->map2[(MEM_SIZE + current_p->pc + index + 3) % MEM_SIZE] =
		env->map2[(MEM_SIZE + current_p->pc) % MEM_SIZE];
}

int				ft_st(t_env *env, t_process *current_p)
{
	int			src_reg;
	int			dest_reg;
	int			args[4];
	int			ret;

	ret = get_params(&args, env->map[(current_p->pc + 1) % MEM_SIZE],
			current_p->instruction);
	src_reg = env->map[(MEM_SIZE + current_p->pc + 2) % MEM_SIZE];
	if (args[0] & g_op_tab[2].type_args[0] && args[1] & g_op_tab[2].type_args[1]
			&& src_reg > 0 && src_reg < 17)
	{
		dest_reg = env->map[(MEM_SIZE + current_p->pc + 3) % MEM_SIZE];
		if (args[1] & T_REG && dest_reg > 0 && dest_reg < 17)
		{
			current_p->reg[dest_reg - 1] = current_p->reg[src_reg - 1];
			return (ret);
		}
		else if (args[1] & T_IND)
			ft_st_2(env, current_p, src_reg);
	}
	return (ret);
}
