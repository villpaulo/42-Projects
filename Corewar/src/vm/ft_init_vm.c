/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:44:41 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/07 20:29:36 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_init.h"

static int		ft_count_player(int ac, char **av)
{
	int		i;
	int		nb;

	nb = 0;
	i = 1;
	while (i < ac)
	{
		if (ft_strlcmp(av[i], ".cor"))
			nb++;
		i++;
	}
	if (nb == 0 || nb > 4)
		print_help();
	return (nb);
}

static int		ft_check_nb(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int		cnt_lps(char *s)
{
	int		i;
	int		j;
	int		ret;

	ret = 0;
	i = CYCLE_TO_DIE;
	j = CYCLE_DELTA;
	while (i >= 0)
	{
		ret += i;
		i -= j;
	}
	if (ft_atoi(s) > ret)
		return (0);
	return (1);
}

static void		ft_check_args_1(int ac, char **av, int nb)
{
	int		i;
	int		detect;

	if (ac == 1)
		print_help();
	i = 1;
	detect = 0;
	while (i < ac)
	{
		if (ft_strlcmp(av[i], ".cor"))
			detect = 1;
		if (detect == 1 && !ft_strlcmp(av[i], ".cor")
				&& !ft_strkcmp(av[i], "-n"))
			print_help();
		else if (ft_strkcmp(av[i], "-dump") && (ft_atoi(av[i + 1]) < 0
					|| !cnt_lps(av[i + 1]) || !ft_check_nb(av[i + 1])))
			print_help();
		else if (ft_strkcmp(av[i], "-n") && (ft_atoi(av[i + 1]) < 0
					|| ft_atoi(av[i + 1]) > nb || av[i + 1][1] != '\0'
					|| !ft_strlcmp(av[i + 2], ".cor")))
			print_help();
		if (ft_strkcmp(av[i], "-dump") || (ft_strkcmp(av[i], "-n")))
			i++;
		i++;
	}
}

void			ft_init(t_env *a, int ac, char **av)
{
	a->nb_joueurs = ft_count_player(ac, av);
	a->cycles_to_die = CYCLE_TO_DIE;
	a->winner = a->nb_joueurs;
	a->nb_process = a->nb_joueurs;
	a->num = 1;
	a->process = NULL;
	a->champ = NULL;
	ft_check_args_1(ac, av, a->nb_joueurs);
	ft_check_args_2(a, ac, av);
	if (a->flags.v && a->flags.dump)
		print_help();
	ft_init_champs(a, ac, av);
	ft_init_map(a);
	ft_init_process(a);
	a->nb_lives = 0;
	a->nb_cycle = 1;
	a->check = 1;
}
