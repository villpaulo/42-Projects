/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 23:40:28 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/29 21:17:04 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;
	void	*c;

	c = (void *)ft_memalloc(content_size);
	if (content == NULL)
	{
		c = NULL;
		content_size = 0;
	}
	else
		c = ft_memcpy(c, content, content_size);
	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp->content = c;
	tmp->content_size = content_size;
	tmp->next = NULL;
	return (tmp);
}
