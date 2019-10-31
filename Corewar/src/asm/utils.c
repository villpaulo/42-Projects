/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <pvillene@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:59:12 by pvillene          #+#    #+#             */
/*   Updated: 2017/02/10 21:00:15 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				is_comment(char c)
{
	return (c == COMMENT_CHAR || c == OTHER_COMMENT);
}

int				verify_args(t_cmd *cmd, t_op2 op, int line)
{
	int		i;

	i = -1;
	while (++i < op.args)
	{
		if (!(op.params[i] & cmd->args[i].type))
		{
			ERROR(BAD_ARG(line, cmd->args[i].value));
			return (0);
		}
	}
	return (1);
}
