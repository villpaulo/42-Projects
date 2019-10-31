/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:16:21 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:16:22 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "libft.h"

/*
** live() function take player id on first argument and players list on second
** argument
** function returns true if player is alive or false if he's dead
*/

void	ft_aff_live(t_champ *champ)
{
	char	s;

	s = champ->player + 48;
	write(1, "un processus dit que le joueur ", 31);
	write(1, &s, 1);
	write(1, "(", 1);
	write(1, champ->name, ft_strlen(champ->name));
	write(1, ") est en vie\n", 13);
}

int		ft_live(t_env *env, t_process *current_p)
{
	t_champ			*tmp;
	unsigned int	id;

	tmp = env->champ;
	env->nb_lives++;
	id = get_dir((char *)env->map, current_p->pc + 1);
	current_p->alive = 1;
	while (tmp)
	{
		if (tmp->player == -id)
		{
			(tmp->nb_lives_done)++;
			env->winner = -id;
			if (env->flags.l == 1)
				ft_aff_live(tmp);
			break ;
		}
		tmp = tmp->next;
	}
	return (5);
}
