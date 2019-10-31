/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_null_terminator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <pvillene@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:58:46 by pvillene          #+#    #+#             */
/*   Updated: 2017/02/11 17:53:40 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void		copy_null_command(t_op2 ops[17], t_cmd *cmd)
{
	int		i;

	i = -1;
	while (++i < 17)
		if (!ops[i].args)
			break ;
	cmd->code = ops[i].code;
	cmd->nargs = 0;
	cmd->op_idx = i;
	cmd->size = 0;
	cmd->name = NULL;
	cmd->args = NULL;
}

static t_lst	*get_last(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static int		interpret_size(t_header *header, size_t size)
{
	size_t		final;
	int			i;

	if (size > CHAMP_MAX_SIZE)
	{
		ERROR(CHP_SIZE(size));
		return (0);
	}
	final = 0;
	i = -1;
	while (++i < 4)
	{
		final = final * 0x100 + (size & 0xff);
		size = size >> 8;
	}
	header->prog_size = final;
	return (1);
}

int				add_null_terminator(t_asm *env)
{
	t_cmd		*cmd;
	t_cmd		*end;
	t_lst		*lst;

	cmd = malloc(sizeof(t_cmd));
	copy_null_command(env->op, cmd);
	lst = get_last(env->cmd);
	if (!lst)
	{
		ERROR(NO_OP);
		return (0);
	}
	end = lst->data;
	cmd->size_idx = end->size_idx + end->size;
	lst->next = ft_lstnew(cmd, sizeof(t_cmd));
	lst = lst->next;
	update_labels(env->labels, lst);
	if (!interpret_size(&env->header, cmd->size_idx))
		return (0);
	return (1);
}
