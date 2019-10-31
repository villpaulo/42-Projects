/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 05:14:32 by pibenoit          #+#    #+#             */
/*   Updated: 2017/02/10 05:14:34 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "desa.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "op.h"

char			*ft_give_param(char *str, int index, int nb, int code)
{
	if (code == 1)
		return (ft_give_reg(str, index));
	else if (code == 2)
		return (ft_give_dir(str, index, nb));
	else if (code == 3)
		return (ft_give_ind(str, index));
	return (NULL);
}

char			*ft_change(char *str)
{
	char			*s2;
	unsigned int	nb;
	unsigned int	ocp;

	s2 = (char*)malloc(50);
	s2[0] = 0;
	nb = ft_give_hexa(str[0], str[1]);
	s2 = ft_strcat(s2, ft_give_instruct(nb));
	ocp = 0;
	if (nb == 16)
		return (ft_strcatf(s2, ft_give_reg(str, 4)));
	if (nb == 1 || nb == 9 || nb == 12 || nb == 15)
		return (ft_strcatf(s2, ft_give_dir(str, 2, nb)));
	ocp = ft_give_hexa(str[2], str[3]);
	if (nb == 2 || nb == 3 || nb == 13)
		return (ft_strcatf(s2, ft_give_str_dparam(str, 2, nb, ocp)));
	else
		return (ft_strcatf(s2, ft_give_str_tparam(str, 2, nb, ocp)));
}

void			ft_add_translate(char ***tab, t_flags *flags)
{
	int		i;
	char	*str;

	i = 0;
	while ((*tab)[i])
	{
		str = ft_change((*tab)[i]);
		if (flags->trad)
			(*tab)[i] = ft_strjoin_fs1s2(ft_strjoin_fs1((*tab)[i],
				"   --->   "), str);
		else
		{
			free((*tab)[i]);
			(*tab)[i] = str;
		}
		i++;
	}
}

int				ft_open(char *filename)
{
	int	i;
	int	fd;

	i = 0;
	while (filename && filename[i] != '.')
		i++;
	i++;
	filename[i] = 't';
	filename[i + 1] = 'x';
	filename[i + 2] = 't';
	fd = open(filename, O_CREAT | O_WRONLY, 0755);
	if (fd == -1)
		return (-1);
	return (fd);
}

void			ft_write(int ret, char *filename, char *str, t_flags *flags)
{
	int		i;
	int		fd;
	char	**tab;

	i = 0;
	tab = NULL;
	fd = 1;
	if (flags->file)
		fd = ft_open(filename);
	if (fd == -1)
		return ;
	str = ft_translate(str, ret);
	if (flags->align || flags->txt || flags->trad)
		ft_put_endl(str);
	if (flags->txt || flags->trad)
	{
		tab = ft_strsplit(str, '\n');
		ft_add_translate(&tab, flags);
		str = ft_strjoin_fs1s2(ft_add_intro(flags), ft_join(tab));
	}
	write(fd, str, ft_strlen(str));
	close(fd);
	free(str);
	str = NULL;
}
