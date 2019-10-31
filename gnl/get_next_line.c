/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 23:45:40 by pvillene          #+#    #+#             */
/*   Updated: 2017/01/04 11:02:36 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

static void		join(char **buffer, char *buf, int ret)
{
	char *tmp;

	tmp = *buffer;
	buf[ret] = '\0';
	*buffer = ft_strjoin(*buffer, buf);
	free(tmp);
}

static void		sub(char **line, char **buffer)
{
	int len;
	char *ptr;

	len = (ft_strchr(*buffer, '\n') - *buffer);
	*line = ft_strsub(*buffer, 0, len);
	ptr = *buffer;
	*buffer = ft_strdup(ft_strchr(*buffer, '\n') + 1);
	ft_strdel(&ptr);
	printf("fin de la fonction ou en suis dans le buffer= %s\n", *buffer);
}

int		get_next_line(int fd, char **line)
{
	static char *buffer;
	char *buf;
	int ret;

	buf = ft_strnew(BUFF_SIZE + 1);
	if (fd != -1 && *line != NULL)
	{
		if (buffer == NULL)
			buffer = ft_strnew(1);
		while ((!(ft_strchr(buffer, '\n'))) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
			join(&buffer, buf, ret);
		sub(line, &buffer);
		if (ret == 0 || buffer == NULL)
		{
			free(buffer);
			buffer = NULL;
			return (0);
		}
		ret = (ret == -1) ? -1 : 1; // (question) ? sioui -1 : sinon 1
		free(buf);
		return (ret);
	}
	else
		return (-1);
}
