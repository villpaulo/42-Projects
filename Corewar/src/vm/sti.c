/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:17:38 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:17:39 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

/*
** OCP values :
**	- 84 : REG, REG, REG
**	- 88 : REG, REG, DIR
**	- 100 : REG, DIR, REG
**	- 104 : REG, DIR, DIR
**	- 116 : REG, IND, REG
**	- 120 : REG, IND, DIR
*/

/*
** check_sti_param return size of instruction with arguments
*/

static int		check_sti_params(const char *map, int pc, int args[4])
{
	int		next;
	int		i;

	next = 2;
	i = 0;
	while (i < 3)
	{
		if (args[i] & g_op_tab[10].type_args[i])
		{
			if (args[i] & T_REG && map[(MEM_SIZE + pc + next) % MEM_SIZE] > 0
					&& map[(MEM_SIZE + pc + next) % MEM_SIZE] < 17)
				next += 1;
			else if (args[i] & T_DIR || args[i] & T_IND)
				next += 2;
			else
				return (PARAM_ERROR);
		}
		else
			return (PARAM_ERROR);
		i++;
	}
	return (next);
}

/*
** get_index calculate the addr (param1 + param2) and return it
*/

static int32_t	get_index(const char *map, t_process *p, int args[4])
{
	int		ret;
	int		jump;
	int		i;

	ret = 0;
	jump = 3;
	i = 1;
	while (i < 3)
	{
		if (args[i] & T_DIR || args[i] & T_IND)
		{
			ret += get_ind(map, p->pc + jump);
			jump += 2;
		}
		else if (args[i] & T_REG)
		{
			ret += get_reg(p->reg, map[(MEM_SIZE + p->pc + jump) % MEM_SIZE]);
			jump += 1;
		}
		i++;
	}
	return (ret);
}

static void		ft_sti_2(t_env *env, t_process *current_p, int val, int index)
{
	env->map[(MEM_SIZE + current_p->pc + index) % MEM_SIZE] =
		(val >> 24) & 255;
	env->map[(MEM_SIZE + current_p->pc + index + 1) % MEM_SIZE] =
		(val >> 16) & 255;
	env->map[(MEM_SIZE + current_p->pc + index + 2) % MEM_SIZE] =
		(val >> 8) & 255;
	env->map[(MEM_SIZE + current_p->pc + index + 3) % MEM_SIZE] =
		val & 255;
	env->map2[(MEM_SIZE + current_p->pc + index) % MEM_SIZE] =
		env->map2[(MEM_SIZE + current_p->pc) % MEM_SIZE];
	env->map2[(MEM_SIZE + current_p->pc + index + 1) % MEM_SIZE] =
		env->map2[(MEM_SIZE + current_p->pc) % MEM_SIZE];
	env->map2[(MEM_SIZE + current_p->pc + index + 2) % MEM_SIZE] =
		env->map2[(MEM_SIZE + current_p->pc) % MEM_SIZE];
	env->map2[(MEM_SIZE + current_p->pc + index + 3) % MEM_SIZE] =
		env->map2[(MEM_SIZE + current_p->pc) % MEM_SIZE];
}

int				ft_sti(t_env *env, t_process *current_p)
{
	int			src_reg;
	int			index;
	int			args[4];
	int			val;
	int			ret;

	ret = get_params(&args, env->map[(current_p->pc + 1) % MEM_SIZE],
			current_p->instruction);
	if (check_sti_params(env->map, current_p->pc, args) != PARAM_ERROR)
	{
		src_reg = env->map[(MEM_SIZE + current_p->pc + 2) % MEM_SIZE];
		index = get_index(env->map, current_p, args) % IDX_MOD;
		val = current_p->reg[src_reg - 1];
		ft_sti_2(env, current_p, val, index);
		return (ret);
	}
	return (ret);
}
