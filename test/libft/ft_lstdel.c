/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 00:50:20 by pvillene          #+#    #+#             */
/*   Updated: 2015/01/22 16:54:36 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*cur_list;
	t_list		*next_list;

	cur_list = *alst;
	while (cur_list != NULL)
	{
		next_list = cur_list->next;
		ft_lstdelone(&cur_list, del);
		cur_list = next_list;
	}
	*alst = NULL;
}
