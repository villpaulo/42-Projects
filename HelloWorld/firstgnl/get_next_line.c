/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 23:45:40 by pvillene          #+#    #+#             */
/*   Updated: 2016/09/07 22:04:10 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		join(char **line, char *buf, int ret)
{
	char *tmp;

	tmp = *line; //je ne sais pqs pourauoi// peut etre que comme je modifie line, je supprime son ancienne valeur a l'aide d'un pointeur sur caracteres
	buf[ret] = '\0';
	(*line) = ft_strjoin(*line, buf);
	free(tmp);
}

static void		sub(char **line, char **buffer)
{
	char *tmp;

	tmp = *line;
	*line = ft_strsub(*line, 0, *buffer - *line); //(char *s, int start, size_t), a partir de la line ne sera plus constitue que des
	*buffer = *buffer + 1;
	*buffer = ft_strdup(*buffer);
	free(tmp); // meme chose que pour la fonction en haut
}

int		get_next_line(int fd, char **line)
{
	static char *buffer;
	char *buf;
	int ret;

	buf = (char *)malloc(sizeof(BUFF_SIZE + 1));
	if (fd != -1 && *line != NULL)
	{
		if (buffer != NULL)
		{
			*line = ft_strdup(buffer);
			free(buffer);
		}
		*line = ft_strdup(*line);
		while (((buffer = ft_strchr(*line, '\n')) == NULL) 
				&& (ret = read(fd, buf, BUFF_SIZE)) > 0)// verifier pour ligne vide si c un /n des le premier caractere .. et contourner le bp
			join(line, buf, ret);
		if (ret == 0 || buffer == NULL)
			return (0);
		ret = (ret == -1) ? -1 : 1; // (question) ? sioui -1 : sinon 1
		sub(line, &buffer);
		free(buf);
		return (ret);
	}
	else
		return (-1);
}
