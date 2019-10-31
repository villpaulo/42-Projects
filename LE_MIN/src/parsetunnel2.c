/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsetunnel2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 13:56:54 by pvillene          #+#    #+#             */
/*   Updated: 2016/11/17 11:19:41 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int			push_rooms(t_room *r1, t_room *r2)
{
	t_link *links;
	t_link *tmp;

	if (r2 == NULL || r1 == NULL)
		return (0);
	links = (t_link *)malloc(sizeof(t_link));
	links->next = NULL;
	links->lk = r1;
	if (r2->links == NULL)
	{
		r2->links = links;
		return (1);
	}
	tmp = r2->links;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = links;
	return (1);
}

t_room		*add_room(t_link *links, char *str)
{
	t_link *tmp;

	tmp = links;
	while (tmp)
	{
		if (!(ft_strcmp(((t_room *)tmp->lk)->place, str)))
			return (((t_room *)tmp->lk));
		tmp = tmp->next;
	}
	return (NULL);
}

int			parsetunnel(t_link *link, char *str)
{
	int i;

	i = 0;
	while (str[i] != '-' && str[i])
		i++;
	if (str[i] == '\0')
		return (0);
	str[i] = '\0';
	i++;
	if (!(push_rooms(add_room(link, str), add_room(link, str + i))))
		return (0);
	if (!(push_rooms(add_room(link, str + i), add_room(link, str))))
		return (0);
	return (1);
}
