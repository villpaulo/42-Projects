/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:17:31 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/11 15:17:32 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>

t_lst		*ft_lstnew(void *data, size_t size)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (lst != NULL)
	{
		if (data != NULL)
			lst->size = size;
		else
			lst->size = 0;
		lst->data = data;
		lst->next = NULL;
	}
	return (lst);
}
