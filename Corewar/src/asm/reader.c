/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <pvillene@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:59:10 by pvillene          #+#    #+#             */
/*   Updated: 2017/02/10 20:59:07 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		init_reader(t_reader *reader, char *filename)
{
	ft_bzero(reader, sizeof(t_reader));
	reader->origin = NULL;
	reader->filename = filename;
	reader->fd = open(filename, O_RDONLY);
	if (reader->fd == -1)
	{
		ERROR(OPEN_ERROR(filename));
		return (0);
	}
	return (1);
}

void	skip_whitespace(t_reader *reader)
{
	int		i;
	char	*line;

	if (reader->state <= 0)
		return ;
	i = 0;
	line = reader->line;
	while (ft_isspace(line[i]))
		i++;
	reader->line = line + i;
}

int		simple_read(t_reader *reader)
{
	int		ret;

	free(reader->origin);
	reader->origin = NULL;
	ret = get_next_line(reader->fd, &reader->origin);
	if (ret < 0)
	{
		del_reader(reader);
		ERROR(READ_ERROR(reader->filename));
		return (-1);
	}
	reader->state = ret;
	reader->line = reader->origin;
	reader->index++;
	return (ret);
}

int		clean_read(t_reader *reader)
{
	int		ret;

	ret = simple_read(reader);
	skip_whitespace(reader);
	return (ret);
}

void	del_reader(t_reader *reader)
{
	free(reader->origin);
	close(reader->fd);
}
