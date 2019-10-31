/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:37:56 by pbenoit           #+#    #+#             */
/*   Updated: 2017/01/27 09:40:19 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>

static t_process	*add_process(t_env *a, t_process *lst, unsigned int nb)
{
	t_process		*elm;
	unsigned int	i;

	if ((elm = (t_process*)malloc(sizeof(t_process))) == NULL)
		ft_error(a);
	elm->carry = 0;
	elm->num = a->num;
	(a->num)++;
	elm->cycles_left = 0;
	elm->player = nb;
	elm->pc = (MEM_SIZE / a->nb_joueurs) * (nb - 1);
	elm->alive = 0;
	elm->instruction = 0;
	elm->reg[0] = -nb;
	i = 1;
	while (i < REG_NUMBER)
	{
		elm->reg[i] = 0;
		i++;
	}
	elm->next = NULL;
	if (!lst)
		return (elm);
	elm->next = lst;
	return (elm);
}

void				ft_init_process(t_env *a)
{
	t_process		*lst;
	unsigned int	nb_player;

	lst = NULL;
	nb_player = 1;
	while (nb_player <= a->nb_joueurs)
	{
		lst = add_process(a, lst, nb_player);
		nb_player++;
	}
	a->process = lst;
}
