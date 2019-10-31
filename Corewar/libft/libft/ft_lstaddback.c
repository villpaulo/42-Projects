/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:16:04 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/11 15:16:06 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

void	ft_lstaddback(t_lst **alst, t_lst *new)
{
	t_lst	*view;

	if (alst != NULL && new != NULL)
	{
		view = *alst;
		if (view != NULL)
		{
			while (view->next != NULL)
				view = view->next;
			view->next = new;
		}
		else
			*alst = new;
	}
}
