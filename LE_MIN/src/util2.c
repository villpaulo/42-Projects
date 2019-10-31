/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 13:38:49 by pvillene          #+#    #+#             */
/*   Updated: 2016/11/05 19:58:37 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_link		*findendroom(t_link *link)
{
	while (link)
	{
		if (((t_room *)link->lk)->es == 2)
		{
			((t_room *)link->lk)->es = 33;
			return (((t_room *)link->lk)->links);
		}
		link = link->next;
	}
	return (NULL);
}

t_room		*onepath(t_link *link)
{
	t_link *tmp;
	t_room *room;

	tmp = link;
	while (tmp)
	{
		if (((t_room *)tmp->lk)->es == 1)
		{
			room = (t_room *)tmp->lk;
			room->links = NULL;
			return (room);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int			finish(t_link *paths)
{
	t_link *tmp;
	t_room *room;

	tmp = paths;
	while (tmp)
	{
		room = (t_room *)tmp->lk;
		while (room)
		{
			if (room->ants != NULL)
				return (0);
			room = room->links;
		}
		tmp = tmp->next;
	}
	return (1);
}
