/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <pvillene@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:59:08 by pvillene          #+#    #+#             */
/*   Updated: 2016/12/13 17:40:43 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static unsigned int		create_magic(void)
{
	unsigned int	magic;
	unsigned int	res;
	int				i;

	magic = COREWAR_EXEC_MAGIC;
	res = 0;
	i = -1;
	while (++i < 4)
	{
		res = res * 0x100 + (magic & 0xff);
		magic = magic >> 8;
	}
	return (res);
}

static int				check_bad_case(t_reader *reader)
{
	char	*line;

	if (reader->state < 0)
		return (0);
	else if (reader->state == 0)
	{
		ERROR(BAD_SECTION_ERROR);
		return (0);
	}
	line = reader->line;
	if (*line && !is_comment(*line) && *line != SECTION_CHAR)
	{
		ERROR(BAD_SECTION_ERROR);
		return (0);
	}
	return (1);
}

static int				check_section(char *dst, t_reader *src, char *id,
		int *filled)
{
	size_t		len;
	char		*line;

	len = ft_strlen(id);
	line = src->line;
	if (!ft_strncmp(line, id, len))
	{
		if (*filled)
		{
			ERROR(TOO_MUCH_SECTION_ERROR);
			return (0);
		}
		*filled = 1;
		src->line += len;
		skip_whitespace(src);
		return (copy_section(dst, src));
	}
	return (1);
}

int						parse_header(t_asm *env, t_reader *reader)
{
	int		filled_name;
	int		filled_comment;

	env->header.magic = create_magic();
	filled_name = 0;
	filled_comment = 0;
	while (42)
	{
		if (filled_name && filled_comment)
			return (1);
		clean_read(reader);
		if (!check_bad_case(reader))
			break ;
		else if (!filled_name && !filled_comment &&
				!check_section(env->header.prog_name,
					reader, NAME_CMD_STRING, &filled_name))
			break ;
		else if (filled_name && !filled_comment &&
				!check_section(env->header.comment,
					reader, COMMENT_CMD_STRING, &filled_comment))
			break ;
	}
	return (0);
}
