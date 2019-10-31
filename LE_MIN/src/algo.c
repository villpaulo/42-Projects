/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:05:52 by pvillene          #+#    #+#             */
/*   Updated: 2016/11/01 14:07:54 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_link		*findstarter(t_link *link)
{
	while (link)
	{
		if (((t_room *)link->lk)->es == 1)
			return (((t_room *)link->lk)->links);
		link = link->next;
	}
	return (NULL);
}

int			findtheend(t_link *link)
{
	t_link *tmp;

	tmp = link;
	while (tmp)
	{
		if (((t_room *)tmp->lk)->es == 2)
		{
			if (((t_room *)tmp->lk)->i == 0)
				return (0);
			else
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_link		*resolv(t_link *link)
{
	t_link	*tmp;
	int		j;

	tmp = link;
	j = possibility(link);
	tmp = findstarter(tmp);
	if (tmp == NULL)
		return (NULL);
	while (tmp)
	{
		search(tmp, 0);
		tmp = tmp->next;
	}
	if (!findtheend(link))
		return (NULL);
	return (link);
}

void		search(t_link *link, int i)
{
	t_link *tmp;

	tmp = link;
	i++;
	if (((t_room *)tmp->lk)->i == 0 || ((t_room *)tmp->lk)->i > i)
		if (((t_room *)tmp->lk)->es != 1)
			((t_room *)tmp->lk)->i = i;
	if (((t_room *)tmp->lk)->es != 2 && ((t_room *)tmp->lk)->es != 1)
		((t_room *)tmp->lk)->es = 0;
	else
		return ;
	tmp = ((t_room *)tmp->lk)->links;
	while (tmp)
	{
		if (((t_room *)tmp->lk)->i == 0 || ((t_room *)tmp->lk)->i > (i + 1))
			search(tmp, i);
		tmp = tmp->next;
	}
}
