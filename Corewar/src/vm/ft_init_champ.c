/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:43:56 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/02 21:27:09 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_init.h"
#include <unistd.h>
#include <fcntl.h>

static unsigned int	swap_int(unsigned int a)
{
	return ((a << 24) |
			((a << 8) & 0x00ff0000) |
			((a >> 8) & 0x0000ff00) |
			((unsigned int)(a >> 24)));
}

static void			ft_check_header(t_header *header)
{
	if (COREWAR_EXEC_MAGIC != swap_int(header->magic))
	{
		write(1, "ERROR: BAD MAGIC\n", 17);
		exit(0);
	}
	if (CHAMP_MAX_SIZE < swap_int(header->prog_size))
	{
		write(1, "ERROR: BAD LENGHT CHAMP\n", 17);
		exit(0);
	}
}

static t_champ		*add_champ(t_env *a, t_champ *lst, char *name, int player)
{
	t_champ		*elm;
	t_header	header;
	int			fd;

	if ((fd = open(name, O_RDONLY)) < 1)
		ft_error(a);
	if ((read(fd, &header, sizeof(t_header))) == -1)
		ft_error(a);
	ft_check_header(&header);
	if (!(elm = (t_champ*)malloc(sizeof(t_champ))))
		ft_error(a);
	elm->prog_size = swap_int(header.prog_size);
	elm->fd = fd;
	elm->player = a->flags.j[player];
	ft_strcpy(elm->name, header.prog_name);
	ft_strcpy(elm->comment, header.comment);
	elm->nb_lives_done = 0;
	elm->next = NULL;
	if (!lst)
		return (elm);
	elm->next = lst;
	return (elm);
}

static void			ft_give_me_i_and_j(t_env *a, int ac, char **av, int t[3])
{
	unsigned int	i;
	int				j;
	unsigned int	nb_cor;

	i = 0;
	nb_cor = 0;
	while (i < a->nb_joueurs && a->flags.j[i] != t[0] + 1)
		i++;
	j = 1;
	while (j < ac && nb_cor < i)
	{
		if (ft_strlcmp(av[j], ".cor"))
			nb_cor++;
		j++;
	}
	while (j < ac && !ft_strlcmp(av[j], ".cor"))
		j++;
	t[1] = i;
	t[2] = j;
}

void				ft_init_champs(t_env *a, int ac, char **av)
{
	t_champ			*lst;
	int				t[3];

	lst = NULL;
	t[0] = 0;
	while ((unsigned int)t[0] < a->nb_joueurs)
	{
		ft_give_me_i_and_j(a, ac, av, t);
		if (ft_strlcmp(av[t[2]], ".cor"))
			lst = add_champ(a, lst, av[t[2]], t[1]);
		t[0]++;
	}
	a->champ = lst;
}
