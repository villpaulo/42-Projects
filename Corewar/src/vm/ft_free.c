/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:36:06 by pbenoit           #+#    #+#             */
/*   Updated: 2017/01/27 09:36:55 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champ			*ft_free_champ(t_champ *champ)
{
	t_champ		*champ1;
	t_champ		*champ2;

	champ1 = champ;
	while (champ1 != NULL)
	{
		champ2 = champ1->next;
		free(champ1);
		champ1 = champ2;
	}
	return (NULL);
}

t_process		*ft_free_process(t_process *proc)
{
	t_process	*proc1;
	t_process	*proc2;

	proc1 = proc;
	while (proc1 != NULL)
	{
		proc2 = proc1->next;
		free(proc1);
		proc1 = proc2;
	}
	return (NULL);
}

void			ft_free(t_env *env)
{
	if (env->process)
		env->process = ft_free_process(env->process);
	if (env->champ)
		env->champ = ft_free_champ(env->champ);
}

void			ft_error(t_env *env)
{
	write(1, "UNE ERREUR EST SURVENUE.\n", 25);
	ft_free(env);
	exit(0);
}
