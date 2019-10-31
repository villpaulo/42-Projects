/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:17:43 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/11 15:17:46 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

t_lst	*ft_lstpushback(t_lst **alst, void *data, size_t csize)
{
	t_lst	*new_lst;

	if (alst != NULL)
	{
		new_lst = ft_lstnew(data, csize);
		if (new_lst == NULL)
			return (NULL);
		ft_lstaddback(alst, new_lst);
		return (new_lst);
	}
	return (NULL);
}
