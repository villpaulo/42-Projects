/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <pvillene@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:59:04 by pvillene          #+#    #+#             */
/*   Updated: 2017/02/11 17:53:52 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		parse(t_asm *env)
{
	t_reader	reader;
	int			ret;

	ret = 1;
	if (!init_reader(&reader, env->filename))
		ret = 0;
	else if (!parse_header(env, &reader))
		ret = 0;
	else if (!parse_commands(env, &reader))
	{
		free_env(env);
		return (0);
	}
	else if (!add_null_terminator(env))
	{
		free_env(env);
		return (0);
	}
	del_reader(&reader);
	return (ret);
}
