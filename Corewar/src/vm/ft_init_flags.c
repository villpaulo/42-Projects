/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:05:10 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 17:23:27 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_init.h"

void	ft_init_flags(t_flags *flags)
{
	flags->dump = 0;
	flags->nb_dump = -1;
	flags->v = 0;
	flags->u = 0;
	flags->l = 0;
	flags->a = 0;
	flags->j[0] = 0;
	flags->j[1] = 0;
	flags->j[2] = 0;
	flags->j[3] = 0;
}

void	ft_asign_flags(t_env *a, char *s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (s[i] == 'a')
			a->flags.a = 1;
		else if (s[i] == 'l')
			a->flags.l = 1;
		else if (s[i] == 'u')
			a->flags.u = 1;
		else if (s[i] == 'v')
			a->flags.v = 1;
		else
			print_help();
		i++;
	}
}
