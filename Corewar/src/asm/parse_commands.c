/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <pvillene@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:59:06 by pvillene          #+#    #+#             */
/*   Updated: 2017/02/10 20:55:53 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int		detect_label(t_asm *env, t_reader *reader)
{
	int		i;
	char	*line;

	i = 0;
	line = reader->line;
	while (line[i] && !ft_isspace(line[i]) && line[i] != LABEL_CHAR)
		i++;
	if (line[i] == LABEL_CHAR)
	{
		if (!create_label(env, reader, i))
			return (0);
		reader->line += (i + 1);
		skip_whitespace(reader);
	}
	return (1);
}

static void		get_name(t_reader *reader, t_cmd *cmd)
{
	size_t		i;
	char		*line;

	line = reader->line;
	i = 0;
	while (!ft_isspace(line[i]))
		i++;
	cmd->name = malloc(sizeof(char) * (i + 1));
	ft_strncpy(cmd->name, line, i);
	cmd->name[i] = '\0';
	reader->line += i;
	skip_whitespace(reader);
}

static int		get_op_from_name(char *name, int line, t_op2 ops[17])
{
	int		i;

	i = -1;
	while (++i < 16)
		if (!ft_strcmp(name, ops[i].name))
			return (i);
	ERROR(UNKNOWN_COMMAND(line, name));
	return (-1);
}

static void		add_cmd(t_asm *env, t_cmd *cmd)
{
	t_lst		*lst;

	lst = ft_lstnew(cmd, sizeof(t_cmd));
	ft_lstaddback(&env->cmd, lst);
	update_labels(env->labels, lst);
}

int				parse_commands(t_asm *env, t_reader *reader)
{
	t_cmd		*cmd;
	int			op;
	size_t		index;

	index = 0;
	while (42)
	{
		clean_read(reader);
		if (reader->state <= 0)
			return (!reader->state);
		if (!detect_label(env, reader))
			return (0);
		if (!reader->line[0] || is_comment(reader->line[0]))
			continue ;
		cmd = malloc(sizeof(t_cmd));
		get_name(reader, cmd);
		op = get_op_from_name(cmd->name, reader->index, env->op);
		if (op == -1 || !verify_op(reader, cmd, env->op[op]))
			return (0);
		cmd->op_idx = op;
		cmd->code = env->op[op].code;
		cmd->size_idx = index;
		index += cmd->size;
		add_cmd(env, cmd);
	}
}
