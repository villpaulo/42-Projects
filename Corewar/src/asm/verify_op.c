/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <pvillene@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:59:14 by pvillene          #+#    #+#             */
/*   Updated: 2017/02/10 20:59:38 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static char		*obtain_arg(t_reader *reader)
{
	int		i;
	char	*line;
	char	*arg;

	i = 0;
	line = reader->line;
	while (line[i] && line[i] != SEPARATOR_CHAR &&
		!ft_isspace(line[i]) && !is_comment(line[i]))
		i++;
	if (!i)
		return (NULL);
	arg = malloc(sizeof(char) * (i + 1));
	ft_strncpy(arg, line, i);
	arg[i] = '\0';
	reader->line += i;
	skip_whitespace(reader);
	reader->line++;
	skip_whitespace(reader);
	return (arg);
}

static int		get_value(char *str, int *res)
{
	int		i;
	int		neg;
	int		final;

	i = -1;
	final = 0;
	neg = 0;
	if (str[0] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		final = final * 10 + (str[i] - '0');
	}
	*res = final * (neg ? -1 : 1);
	return (1);
}

static int		get_type_info(t_arg *arg, int dir_size, int line)
{
	char	c;

	c = arg->value[0];
	if (c == DIRECT_CHAR)
	{
		arg->type = arg->value[1] == LABEL_CHAR ? T_DIR + T_LAB : T_DIR;
		arg->size = dir_size ? DIR_BIT : DIR_BIT * 2;
	}
	else if (c == REGISTER_CHAR)
	{
		arg->type = T_REG;
		arg->size = REG_BIT;
	}
	else if (ft_isdigit(c) || c == '-' || c == LABEL_CHAR)
	{
		arg->type = T_IND + (c == LABEL_CHAR ? T_LAB : 0);
		arg->size = IND_BIT;
	}
	else
	{
		(void)line;
		ERROR(BAD_ARG(line, arg->value));
		return (0);
	}
	return (1);
}

static int		identify_type(t_arg *arg, int dir_size, int line)
{
	int		value;
	int		dec;

	if (!get_type_info(arg, dir_size, line))
		return (0);
	if (!(arg->type & T_LAB))
	{
		dec = arg->type != T_IND;
		if (!get_value(arg->value + dec, &value))
			ERROR(TRUNCATE_ARG(line, arg->value + dec, value));
		if (arg->type == T_REG && (value < 1 && value >= REG_NUMBER))
		{
			ERROR(BAD_REG(line, arg->value, value));
			return (0);
		}
		arg->already_done = value;
	}
	return (arg->size);
}

int				verify_op(t_reader *reader, t_cmd *cmd, t_op2 op)
{
	int		i;
	char	*arg;
	int		size;

	i = 0;
	cmd->nargs = op.args;
	cmd->args = malloc(sizeof(t_arg) * op.args);
	cmd->size = 0;
	while (i < op.args)
	{
		arg = obtain_arg(reader);
		if (!arg)
		{
			ERROR(NO_ARG(reader->index, cmd->name, i));
			return (0);
		}
		cmd->args[i].value = arg;
		if (!(size = identify_type(&cmd->args[i], op.dir_size, reader->index)))
			return (0);
		cmd->size += size;
		i++;
	}
	cmd->size += (1 + op.octal_encode);
	return (verify_args(cmd, op, reader->index));
}
