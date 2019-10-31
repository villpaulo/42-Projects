/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 01:07:17 by pvillene          #+#    #+#             */
/*   Updated: 2015/01/21 06:46:06 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*dest;

	dest = NULL;
	if (lst != NULL)
		dest = ft_lstnew(lst->content, lst->content_size);
	if (!dest)
		return (NULL);
	dest = f(dest);
	if (lst->next)
		dest->next = ft_lstmap(lst->next, f);
	return (dest);
}
