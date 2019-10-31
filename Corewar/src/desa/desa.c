/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 05:14:02 by pibenoit          #+#    #+#             */
/*   Updated: 2017/02/10 05:14:04 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include "op.h"
#include "desa.h"

void			ft_check_flags(t_flags *flags, char **av, int *i)
{
	int	j;

	j = 1;
	if (av[1][0] == '-')
	{
		while (av[1][j])
		{
			if (av[1][j] == 'f')
				flags->file = 1;
			else if (av[1][j] == 's')
				flags->txt = 1;
			else if (av[1][j] == 'i')
				flags->intro = 1;
			else if (av[1][j] == 'a')
				flags->align = 1;
			else if (av[1][j] == 't')
				flags->trad = 1;
			else
				ft_help();
			*i = 2;
			j++;
		}
	}
}

unsigned int	ft_prog_size(unsigned int prog_size)
{
	unsigned int	a;

	a = prog_size / 16777216;
	a += ((prog_size % 16777216) / 65536) * 256;
	a += ((prog_size % 65536) / 256) * 65536;
	a += (prog_size % 256) * 16777216;
	return (a);
}

int				ft_read(char *filename, char **str, t_flags *f)
{
	int fd;
	int	ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read(fd, &(f->header), sizeof(t_header));
	if (ret == -1)
		return (0);
	f->header.prog_size = ft_prog_size(f->header.prog_size);
	(*str) = (char*)malloc(f->header.prog_size + 1);
	ret = read(fd, *str, f->header.prog_size);
	if (ret == -1)
		return (0);
	(*str)[ret] = '\0';
	close(fd);
	return (ret);
}

void			ft_init(t_flags *f)
{
	f->file = 0;
	f->hexa = 1;
	f->txt = 0;
	f->intro = 0;
	f->align = 0;
	f->trad = 0;
	f->header.magic = 0;
	f->header.prog_size = 0;
	f->header.prog_name[0] = 0;
	f->header.comment[0] = 0;
}

int				main(int ac, char **av)
{
	t_flags		flags;
	int			i;
	int			ret;
	char		*str;

	if (ac == 1)
	{
		ft_help();
		return (0);
	}
	ft_init(&flags);
	i = 1;
	ft_check_flags(&flags, av, &i);
	ret = 0;
	str = NULL;
	if (i == ac)
		ft_help();
	while (i < ac)
	{
		ret = ft_read(av[i], &str, &flags);
		ft_write(ret, av[i], str, &flags);
		i++;
	}
	return (0);
}
