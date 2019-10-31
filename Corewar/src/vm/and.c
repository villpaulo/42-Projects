/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:39:20 by carodrig          #+#    #+#             */
/*   Updated: 2017/02/09 00:05:50 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

/*
**	OCP values :
**	- 84 : REG, REG, REG
**	- 100 : REG, DIR, REG
**	- 116 : REG, IND, REG
**	- 148 : DIR, REG, REG
**	- 164 : DIR, DIR, REG
**	- 180 : DIR, IND, REG
**	- 212 : IND, REG, REG
**	- 228 : IND, DIR, REG
**	- 244 : IND, IND, REG
*/

/*
**	check_and_param return size of instruction with arguments
**
**	La fonction and() applique un ET bit-a-bit sur les deux premiers parametres
**	et stocke le resultat dans le troisieme
*/

static void		check_and_params_2(const char *map, t_process *p,
		int t[4], int args[4])
{
	if (args[t[3]] & T_IND)
	{
		t[t[3]] = get_dir(map, p->pc + (get_ind(map, p->pc + t[2]) % IDX_MOD));
		t[2] += 2;
	}
	else if (args[t[3]] & T_DIR)
	{
		t[t[3]] = get_dir(map, p->pc + t[2]);
		t[2] += 4;
	}
}

static int		check_and_params(const char *map, t_process *p,
		int args[4], int t[4])
{
	t[2] = 2;
	t[3] = 0;
	if ((args[2] & T_REG) == 0)
		return (PARAM_ERROR);
	while (t[3] < 2)
	{
		if (args[t[3]] & g_op_tab[5].type_args[t[3]])
		{
			if (args[t[3]] & T_REG && map[(p->pc + t[2]) % MEM_SIZE] > 0
					&& map[(p->pc + t[2]) % MEM_SIZE] <= 16)
			{
				t[t[3]] = p->reg[(int)(map[(p->pc + t[2]) % MEM_SIZE]) - 1];
				t[2] += 1;
			}
			else if (args[t[3]] & T_IND || args[t[3]] & T_DIR)
				check_and_params_2(map, p, t, args);
			else
				return (PARAM_ERROR);
		}
		else
			return (PARAM_ERROR);
		t[3]++;
	}
	return (t[2] + 1);
}

int				ft_and(t_env *env, t_process *cur_p)
{
	int			args[4];
	int			ret;
	int			t[4];

	*t = 0;
	cur_p->carry = 0;
	ret = get_params(&args, env->map[(cur_p->pc + 1) % MEM_SIZE],
			cur_p->instruction);
	if (check_and_params(env->map, cur_p, args, t) != PARAM_ERROR)
	{
		if ((t[0] & t[1]) == 0)
			cur_p->carry = 1;
		cur_p->reg[env->map[(cur_p->pc + ret) % MEM_SIZE] - 1] = t[0] & t[1];
	}
	return (ret);
}
