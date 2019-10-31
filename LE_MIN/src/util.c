/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:10:24 by pvillene          #+#    #+#             */
/*   Updated: 2016/11/17 11:39:29 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int			findstr(char *str, char *hide)
{
	int i;
	int j;
	int k;

	j = 0;
	while (str[j])
	{
		k = j;
		i = 0;
		if (str[j] == '-')
			return (0);
		while (str[k] == hide[i] && hide[i] && str[k])
		{
			i++;
			k++;
		}
		if (hide[i] == '\0')
			return (1);
		j++;
	}
	return (0);
}

char		*findend(char *end, t_link *link)
{
	t_link *tmp;

	tmp = link;
	while (tmp)
	{
		if (((t_room *)tmp->lk)->es == 2)
		{
			end = ((t_room *)tmp->lk)->place;
			return (end);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int			possibility(t_link *link)
{
	t_link	*tmp;
	int		c;
	int		j;

	tmp = link;
	c = 0;
	while (tmp)
	{
		tmp = tmp->next;
		c++;
	}
	j = c;
	while (j != 0)
	{
		j--;
		c += j;
	}
	return (c);
}

t_link		*shortway(t_link *link)
{
	t_link *tmp;

	tmp = link;
	while (tmp)
	{
		if (((t_room *)tmp->lk)->es == 2)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		newant(t_room *room, char *end, int *ants, int *nb)
{
	char *ret;

	ret = ft_strjoin("L", ft_strjoin(ft_itoa(*nb), "-"));
	*nb = *nb + 1;
	*ants = *ants - 1;
	if (room->links == NULL)
		ret = ft_strjoin(ret, end);
	else
	{
		room = room->links;
		room->ants = ret;
		ret = ft_strjoin(ret, room->place);
	}
	ft_putchar(' ');
	ft_putstr(ret);
	free(ret);
}
