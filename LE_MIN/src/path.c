/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 13:59:32 by pvillene          #+#    #+#             */
/*   Updated: 2016/11/05 19:18:57 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_room		*copyroom(t_room *src)
{
	t_room *dest;

	if (src->es != 1)
		src->es = 33;
	dest = (t_room *)malloc(sizeof(t_room));
	dest->place = src->place;
	dest->es = 0;
	dest->coord[0] = 0;
	dest->coord[1] = 0;
	dest->i = 0;
	dest->links = NULL;
	return (dest);
}

t_link		*makepath(t_link *link)
{
	int		c;
	t_link	*paths;
	t_link	*tmp;
	void	*s2;
	t_room	*path;

	c = 0;
	link = findendroom(link);
	paths = (t_link *)malloc(sizeof(t_link));
	path = NULL;
	s2 = paths;
	paths->lk = onepath(link);
	if (paths->lk != NULL)
		return (paths);
	while (42)
	{
		tmp = link;
		paths->lk = newpath(tmp, c);
		if (paths->lk == NULL)
			return (s2);
		paths->next = (t_link *)malloc(sizeof(t_link));
		paths = paths->next;
	}
}

t_room		*newpath(t_link *tmp, int c)
{
	t_room		*nway;
	t_room		*tmp2;

	nway = NULL;
	while (42)
	{
		if (!(tmp = searchpath(tmp)))
			return (NULL);
		tmp2 = copyroom(tmp->lk);
		tmp2->links = nway;
		nway = tmp2;
		c++;
		if (((t_room *)tmp->lk)->es == 1)
		{
			nway->i = c;
			return (nway);
		}
		tmp = ((t_room *)tmp->lk)->links;
	}
	return (nway);
}

t_link		*searchpath(t_link *paths)
{
	int		j;
	t_link	*tmp;
	void	*s;

	tmp = paths;
	j = 100000;
	while (tmp)
	{
		if (((t_room *)tmp->lk)->i < j && ((t_room *)tmp->lk)->es != 33)
		{
			j = ((t_room *)tmp->lk)->i;
			s = tmp;
		}
		tmp = tmp->next;
	}
	if (j == 100000)
		return (NULL);
	return (s);
}
