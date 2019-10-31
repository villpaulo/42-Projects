/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:16:52 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:16:53 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

/*
** OCP values :
**	- 84 : REG, REG, REG
**	- 100 : REG, DIR, REG
**	- 148 : DIR, REG, REG
**	- 164 : DIR, DIR, REG
**	- 212 : IND, REG, REG
**	- 228 : IND, DIR, REG
*/

/*
** check_lldi_param return size of instruction with arguments
*/

static int		check_lldi_params(const char *map, int pc, int args[4])
{
	int		next;
	int		i;

	next = 1;
	i = 0;
	while (i < 2)
	{
		if (args[i] & g_op_tab[13].type_args[i])
		{
			if (args[i] & T_REG && map[(pc + next) % MEM_SIZE] > 0
					&& map[(pc + next) % MEM_SIZE] <= 16)
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
** get_index calculate the addr (param2 + param3) and return it
*/

static int32_t	get_index(const char *map, t_process *p, int args[4])
{
	int		ret;
	int		jump;
	int		i;

	ret = 1;
	jump = 2;
	i = 0;
	while (i < 2)
	{
		if (args[i] & T_DIR || args[i] & T_IND)
		{
			ret += get_ind(map, p->pc + jump);
			jump += 2;
		}
		else if (args[i] & T_REG)
		{
			ret += get_reg(p->reg, map[(p->pc + jump) % MEM_SIZE]);
			jump += 1;
		}
		i++;
	}
	return (ret);
}

int				ft_lldi(t_env *env, t_process *current_p)
{
	uint32_t	index;
	int			args[4];
	int			ret;
	int			res;

	ret = get_params(&args, env->map[(current_p->pc + 1) % MEM_SIZE],
			current_p->instruction);
	current_p->carry = 0;
	if (check_lldi_params(env->map, current_p->pc, args) != PARAM_ERROR)
	{
		index = get_index(env->map, current_p, args);
		res = get_dir(env->map, index);
		current_p->reg[(int)env->map[(current_p->pc + ret) % MEM_SIZE]] = res;
		if (res == 0)
			current_p->carry = 1;
		return (ret);
	}
	return (ret);
}
