/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:58:40 by pvillene          #+#    #+#             */
/*   Updated: 2016/11/05 20:01:34 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void		print_paths(t_link *paths, int ants, char *end, int nb)
{
	t_link	*tmp;
	t_room	*room;
	t_room	*r2;

	tmp = paths;
	((t_room *)paths->lk)->i = 0;
	room = NULL;
	r2 = NULL;
	while (42)
	{
		checkpaths((t_room *)tmp->lk, end);
		if (useornot(tmp, r2, ants))
			newant((t_room *)tmp->lk, end, &ants, &nb);
		r2 = (t_room *)tmp->lk;
		tmp = tmp->next;
		if (tmp == NULL || tmp->lk == NULL)
		{
			r2 = NULL;
			tmp = paths;
			ft_putchar('\n');
		}
		if (ants == 0 && finish(paths))
			break ;
	}
}

void		checkpaths(t_room *room, char *end)
{
	t_room	*tmp;
	char	*t1;
	char	*t2;
	char	*str;

	t1 = NULL;
	t2 = NULL;
	str = NULL;
	tmp = room;
	if (tmp->links != NULL)
		tmp = tmp->links;
	while (tmp)
	{
		str = ft_newjoin(print(tmp, end), str);
		tmp = tmp->links;
	}
	if (str != NULL)
		ft_putstr(str);
	free(str);
	tmp = room;
	tmp = tmp->links;
	moveants(tmp, t1, t2);
}

char		*print(t_room *room, char *end)
{
	char *str;

	str = NULL;
	if (room->ants != NULL)
	{
		if (room->links == NULL)
			str = ft_strjoin(room->ants, end);
		else
			str = ft_strjoin(room->ants, ((t_room *)room->links)->place);
		str = ft_strjoin(" ", str);
	}
	return (str);
}

void		moveants(t_room *room, char *t1, char *t2)
{
	while (room)
	{
		if (t1 == NULL && t2 == NULL)
		{
			t1 = room->ants;
			room->ants = NULL;
		}
		else if (t1 != NULL)
		{
			t2 = room->ants;
			room->ants = t1;
			t1 = NULL;
		}
		else if (t2 != NULL)
		{
			t1 = room->ants;
			room->ants = t2;
			t2 = NULL;
		}
		room = room->links;
	}
	free(t1);
	free(t2);
}

int			useornot(t_link *paths, t_room *r2, int ants)
{
	t_link	*tmp;
	t_room	*r1;
	int		c;

	tmp = paths;
	r1 = (t_room *)tmp->lk;
	if (r1->i == 0 && r1->links != NULL)
		r1 = r1->links;
	if (r1->i == 0)
	{
		if (r1->ants == 0 && ants > 0)
			return (1);
		return (0);
	}
	else
	{
		c = r1->i - r2->i;
		if (c <= ants && ((t_room *)r1->links)->ants == 0 && ants > 0)
			return (1);
		return (0);
	}
}
