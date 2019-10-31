/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ /*   Created: 2016/11/01 13:50:21 by pvillene          #+#    #+#             */
/*   Updated: 2016/12/06 19:56:10 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int			findcost(t_room *path)
{
	int i;

	i = 0;
	while (path)
	{
		i++;
		path = path->links;
	}
	return (i);
}

int			error(void)
{
	ft_putstr("ERROR\n");
	return (0);
}

t_elem		*takeants(char *str, t_elem *elem)
{
	int i;

	i = 0;
	elem->b = 33;
	elem->ants = 0;
	if (get_next_line(0, &str) > 0)
		if (!(ft_isdigit(str[i])))
			return (NULL);
	elem->ants = ft_atoi(str + i);
	if (elem->ants <= 0)
		return (NULL);
	return (elem);
}

void		init(t_link **link, char **str, char **end)
{
	*str = NULL;
	*link = NULL;
	*end = NULL;
}

int			main(void)
{
	char	*str;
	t_link	*link;
	t_elem	*elem;
	char	*end;

	init(&link, &str, &end);
	elem = (t_elem *)malloc(sizeof(t_elem) * 1);
	if (takeants(str, elem) == NULL)
		return (error());
	while (get_next_line(0, &str) > 0 && ft_strlen(str) != 0)
	{
		if (!checktunnel(str, link))
			link = parse(str, link, elem);
		else
		{
			if (!(parsetunnel(link, str)))
				break ;
		}
	}
	if (!(link = resolv(link)))
		return (error());
	end = findend(end, link);
	print_paths(makepath(link), elem->ants, end, 1);
	return (0);
}
