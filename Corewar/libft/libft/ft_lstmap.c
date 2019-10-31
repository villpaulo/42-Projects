/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:16:58 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/11 15:17:00 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

t_lst	*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *elem))
{
	t_lst	*newlst;
	t_lst	*newlst_first;
	t_lst	*newlst_prev;

	newlst_first = NULL;
	while (lst != NULL)
	{
		newlst = (t_lst *)ft_memalloc(sizeof(t_lst));
		if (newlst == NULL)
			return (NULL);
		if (newlst_first == NULL)
			newlst_first = newlst;
		ft_memcpy(newlst, (*f)(lst), sizeof(t_lst));
		newlst_prev->next = newlst;
		newlst_prev = newlst;
		lst = lst->next;
	}
	return (newlst_first);
}
