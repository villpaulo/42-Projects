/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:16:24 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/11 15:16:25 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

void	ft_lstdel(t_lst **alst, void (*del)(void *, size_t))
{
	t_lst	*pnt;

	while (*alst != NULL)
	{
		pnt = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = pnt;
	}
}
