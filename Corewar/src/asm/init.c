/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <pvillene@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:58:53 by pvillene          #+#    #+#             */
/*   Updated: 2017/02/10 20:47:26 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static size_t		find_point(char *str)
{
	size_t		i;

	i = ft_strlen(str);
	while (i && str[i] != '.')
		i--;
	return (i);
}

static int			verify_filename(char *filename)
{
	size_t		point;

	point = find_point(filename);
	if (!point || ft_strcmp(&filename[point], ".s"))
	{
		ERROR(BAD_ASM_ERROR(filename));
		return (0);
	}
	return (1);
}

int					init(t_asm *env, int ac, char **av)
{
	if (ac < 2)
	{
		ERROR(MISSING_ARGUMENT_ERROR);
		return (0);
	}
	ft_bzero(env, sizeof(t_asm));
	ft_memcpy(env->op, g_op_tab2, 17 * sizeof(t_op2));
	if (!verify_filename(av[ac - 1]))
		return (0);
	env->filename = av[ac - 1];
	return (1);
}
