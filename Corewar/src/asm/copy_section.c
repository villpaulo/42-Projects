/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_section.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <pvillene@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:58:48 by pvillene          #+#    #+#             */
/*   Updated: 2016/12/06 11:58:49 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void		copy_text(char **dst, t_reader *reader, int *total_read)
{
	int		i;
	int		nb_read;
	char	*line;

	i = 0;
	line = *dst;
	nb_read = *total_read;
	while (reader->line[i] && reader->line[i] != '"' &&
		nb_read <= COMMENT_LENGTH)
	{
		line[i] = reader->line[i];
		i++;
		nb_read++;
	}
	(*dst) += i;
	*total_read = nb_read;
	reader->line += i;
}

static int		get_till_next_quote(char *dst, t_reader *reader)
{
	int		total_read;

	total_read = 0;
	while (42)
	{
		copy_text(&dst, reader, &total_read);
		if (*reader->line == '"')
			return (1);
		else if (total_read > COMMENT_LENGTH)
		{
			ERROR(SECTION_FORMAT_ERROR(reader->index));
			return (0);
		}
		else if (!*reader->line &&
			(!simple_read(reader) || reader->state == 0))
		{
			ERROR(BAD_SECTION_ERROR);
			return (0);
		}
		*dst = '\n';
		dst++;
	}
}

int				copy_section(char *dst, t_reader *reader)
{
	int		i;

	i = 0;
	while (reader->line[i] && reader->line[i] != '"')
		i++;
	if (!reader->line[i])
	{
		ERROR(SECTION_FORMAT_ERROR(reader->index));
		return (0);
	}
	reader->line += i + 1;
	return (get_till_next_quote(dst, reader));
}
