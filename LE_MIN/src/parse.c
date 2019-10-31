/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 13:52:20 by pvillene          #+#    #+#             */
/*   Updated: 2016/11/01 13:56:15 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_link		*parse(char *str, t_link *link, t_elem *elem)
{
	if (!ft_strcmp(str, "##start"))
		elem->b = 1;
	else if (!ft_strcmp(str, "##end"))
		elem->b = 2;
	if (str[0] == '#')
		return (link);
	link = push_list(link, parse_room(str, elem));
	if (elem->b > 0)
		elem->b = 33;
	return (link);
}

t_link		*push_list(t_link *link, t_link *new)
{
	t_link *tmp;

	if (link == NULL)
	{
		link = (t_link *)malloc(sizeof(t_link) * 1);
		link = new;
		return (link);
	}
	else if (new == NULL)
		return (link);
	tmp = link;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (link);
}

t_link		*parse_room(char *str, t_elem *elem)
{
	int		i;
	t_link	*new;
	t_room	*room;

	i = 0;
	new = (t_link *)malloc(sizeof(t_link));
	room = (t_room *)malloc(sizeof(t_room));
	room->es = elem->b;
	while (str[i] && str[i] != ' ')
		i++;
	room->place = ft_strsub(str, 0, i);
	i++;
	if (ft_isdigit(str[i]))
		room->coord[0] = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	i++;
	if (ft_isdigit(str[i]))
		room->coord[1] = ft_atoi(str + i);
	room->links = NULL;
	room->i = 0;
	room->ants = NULL;
	new->lk = room;
	new->next = NULL;
	return (new);
}

int			checktunnel(char *str, t_link *link)
{
	t_link	*tmp;
	int		c;
	int		i;

	i = 0;
	c = 0;
	tmp = link;
	while (tmp)
	{
		if (hidenp(((t_room *)tmp->lk)->place, str))
			c++;
		tmp = tmp->next;
	}
	while (str[i])
	{
		if (str[i] == '-' && c == 2)
			return (1);
		i++;
	}
	return (0);
}
