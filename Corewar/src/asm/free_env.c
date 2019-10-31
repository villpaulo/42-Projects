/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 03:16:08 by pvillene          #+#    #+#             */
/*   Updated: 2017/02/08 03:16:12 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void		del_label(void *ptr, size_t size)
{
	t_label		*label;

	label = ptr;
	(void)size;
	free(label->name);
	free(label);
}

static void		del_cmd(void *ptr, size_t size)
{
	t_cmd	*cmd;
	int		i;

	(void)size;
	cmd = ptr;
	i = -1;
	while (++i < cmd->nargs)
		free(cmd->args[i].value);
	free(cmd->args);
	free(cmd->name);
}

void			free_env(t_asm *env)
{
	ft_lstdel(&env->labels, del_label);
	ft_lstdel(&env->cmd, del_cmd);
}
