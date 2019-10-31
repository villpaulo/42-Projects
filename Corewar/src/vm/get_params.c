/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:06:04 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:07:08 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <stdlib.h>

static int			ft_return(int opcode, int (*tab)[4])
{
	int		ret;
	int		i;

	i = 0;
	ret = 2;
	while (i < 3)
	{
		if ((*tab)[i] & T_REG)
			ret += 1;
		else if ((*tab)[i] & T_IND || ((*tab)[i] & T_DIR && opcode > 8
					&& opcode < 16 && opcode != 13))
			ret += 2;
		else if (((*tab)[i] & T_DIR && opcode > 0 && opcode < 9))
			ret += 4;
		i++;
	}
	return (ret);
}

static uint8_t		get_arg_type(uint8_t val)
{
	if (val & 1)
	{
		if (val & 2)
			return (T_IND);
		else
			return (T_REG);
	}
	else if (val & 2)
		return (T_DIR);
	else
		return (0);
}

int					get_params(int (*tab)[4], char ocp, int opcode)
{
	(*tab)[3] = get_arg_type(ocp);
	(*tab)[2] = get_arg_type(ocp >> 2);
	(*tab)[1] = get_arg_type(ocp >> 4);
	(*tab)[0] = get_arg_type(ocp >> 6);
	return (ft_return(opcode, tab));
}
