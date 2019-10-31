/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_checkarg_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:44:16 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/02 18:19:10 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_init.h"

static void		ft_check_tab(t_env *a)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 4)
		{
			if (a->flags.j[i] == a->flags.j[j] && a->flags.j[i] != 0)
				print_help();
			j++;
		}
		i++;
	}
}

static void		ft_asign_player(t_env *a)
{
	int		i;
	int		nb;

	ft_check_tab(a);
	nb = a->nb_joueurs;
	while (nb > 0)
	{
		i = 0;
		while (i < 4 && a->flags.j[i] != nb)
			i++;
		if (i == 4)
		{
			i = a->nb_joueurs - 1;
			while (i > -1 && a->flags.j[i] != 0)
				i--;
			a->flags.j[i] = nb;
		}
		nb--;
	}
}

static int		ft_give_me_my_dump(t_env *a, int i, int nb)
{
	if (a->flags.dump == 1)
		print_help();
	a->flags.dump = 1;
	a->flags.nb_dump = nb;
	return (i + 1);
}

void			ft_check_args_2(t_env *a, int ac, char **av)
{
	int		nb_champ;
	int		i;

	nb_champ = 0;
	i = 1;
	ft_init_flags(&(a->flags));
	while (i < ac)
	{
		if (ft_strkcmp(av[i], "-dump"))
			i = ft_give_me_my_dump(a, i, ft_atoi(av[i + 1]));
		else if (ft_strkcmp(av[i], "-n"))
		{
			a->flags.j[nb_champ] = ft_atoi(av[i + 1]);
			i++;
		}
		else if (ft_strlcmp(av[i], ".cor"))
			nb_champ++;
		else if (av[i][0] == '-')
			ft_asign_flags(a, av[i]);
		else
			print_help();
		i++;
	}
	ft_asign_player(a);
}
