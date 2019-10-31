/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:16:36 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/11 15:16:38 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_lst **alst, void (*del)(void *, size_t))
{
	if (*alst != NULL)
	{
		if (del)
			(*del)((*alst)->data, (*alst)->size);
		free(*alst);
	}
	*alst = NULL;
}
