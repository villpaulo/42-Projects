/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 03:02:10 by pvillene          #+#    #+#             */
/*   Updated: 2017/02/08 03:13:42 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_isdigitc(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char		*memrevcpy(char *dest, char *source, size_t n, int *i)
{
	while (n-- != 0)
	{
		dest[*i] = source[n];
		(*i)++;
	}
	return (dest);
}

int			checkargs(t_arg args, t_lst *labels)
{
	t_label	*label;
	int		c;

	c = 1;
	if (args.type == 1)
		if (args.already_done <= 0 || args.already_done > 16)
			return (0);
	if (ft_isdigitc(args.value[2]))
		c++;
	if ((args.type == 2 || args.type == 10) &&
		(!(ft_isdigitc(args.value[c]))))
	{
		while (labels)
		{
			label = labels->data;
			if (!ft_strcmp(label->name, args.value + 2))
				break ;
			labels = labels->next;
		}
		if (labels == NULL)
			return (0);
	}
	return (1);
}

int			ocpright(char c)
{
	char	bit;
	int		i;

	bit = 0;
	i = 7;
	while (i >= 6)
	{
		bit = (c & (1 << i)) >> i;
		if (bit != 0)
			return (1);
		i--;
	}
	return (0);
}

int			changeargtype(int i)
{
	if (i == 10)
		i = 2;
	if (i == 4)
		i = 3;
	return (i);
}
