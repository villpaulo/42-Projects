/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 17:52:28 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/11 15:20:25 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "./../libft.h"

int		get_next_line(int const fd, char **line)
{
	static char	*str[256];
	int			tab[4];

	if (fd < 0 || fd > 256 || line == NULL || BUFF_SIZE == 0)
		return (-1);
	tab[0] = 1;
	if (str[fd] == NULL)
	{
		str[fd] = (char*)malloc(sizeof(char));
		if (str[fd] == NULL)
			return (-1);
		str[fd][0] = '\0';
	}
	str[fd] = ft_read(0, fd, (str + fd), tab);
	if (tab[0] == 1)
		ft_cpy(str + fd, tab, line);
	else if (!(tab[0]))
	{
		free(str[fd]);
		str[fd] = NULL;
	}
	return (tab[0]);
}

char	*ft_read(int cpt, int const fd, char **str, int tab[4])
{
	char *buf;

	while ((*str)[cpt] != '\0' && (*str)[cpt] != '\n')
		(cpt)++;
	if ((*str)[cpt] == '\0')
	{
		if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (NULL);
		(cpt) = BUFF_SIZE;
		while ((cpt) == BUFF_SIZE && *str != NULL)
		{
			if (((cpt) = read(fd, buf, BUFF_SIZE)) != -1)
			{
				buf[(cpt)] = '\0';
				if (!(*str = ft_strjoingnl(str, buf, &cpt, tab)))
					tab[0] = -1;
				if ((cpt) == 0 && (*str)[0] == '\0')
					tab[0]--;
			}
			else
				tab[0] = -1;
		}
		free(buf);
	}
	return ((*str));
}

char	*ft_strjoingnl(char **s1, char *s2, int *cpt, int tab[4])
{
	char			*s3;

	tab[1] = 0;
	tab[2] = 0;
	tab[3] = ft_strlen(*s1) + ft_strlen(s2) + 1;
	s3 = (char*)malloc(sizeof(char) * tab[3]);
	if (s3 == NULL)
		return (NULL);
	while ((*s1)[tab[1]] != '\0')
	{
		s3[tab[1]] = (*s1)[tab[1]];
		tab[1]++;
	}
	while (s2[tab[2]] != '\0')
	{
		s3[tab[1]] = s2[tab[2]];
		if (s2[tab[2]] == '\n')
			*cpt = -2;
		tab[1]++;
		tab[2]++;
	}
	s3[tab[1]] = '\0';
	free(*s1);
	return (s3);
}

void	ft_cpy(char **str, int tab[4], char **line)
{
	char	*strtmp;

	tab[1] = 0;
	tab[2] = ft_strlen(*str);
	while ((*str)[tab[1]] != '\0' && (*str)[tab[1]] != '\n')
		tab[1]++;
	*line = (char*)malloc(sizeof(char) * (tab[1] + 1));
	if (*line == NULL)
	{
		tab[0] = -1;
		return ;
	}
	tab[1] = 0;
	while ((*str)[tab[1]] != '\0' && (*str)[tab[1]] != '\n')
	{
		(*line)[tab[1]] = (*str)[tab[1]];
		tab[1]++;
	}
	(*line)[tab[1]] = '\0';
	strtmp = ft_strsub(*str, tab[1] + 1, tab[2] - tab[1]);
	free(*str);
	*str = strtmp;
}
