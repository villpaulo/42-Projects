/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 17:01:29 by pvillene          #+#    #+#             */
/*   Updated: 2016/11/24 08:59:35 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

extern t_element	g_element[];

t_element g_element[] =
{
	{'c', print_c},
	{'s', print_s},
	{'d', print_d},
	{'x', print_x},
	{'X', print_x2},
	{'o', print_o},
	{'O', print_o2},
	{'u', print_u},
	{'U', print_u2},
	{'i', print_i},
	{'C', print_c2},
	{'S', print_s2},
	{'p', print_p},
	{'D', print_d2},
};

t_ret	*ft_vsprintf(char *p, va_list ap)
{
	int		i;
	int		*tab;
	char	*modifier;
	char	*new;
	t_ret	*elem;

	if (!(elem = malloc(sizeof(t_ret))))
		return (NULL);
	new = NULL;
	elem->buffer = NULL;
	elem->size = 0;
	tab = (int *)malloc(sizeof(int) * 13);
	modifier = "+-0# ?.hHlLzj";
	i = 0;
	if (ft_strlen(p) == 0)
		return (elem);
	return (ft_vsprintf2(p, ap, tab, elem));
}

t_ret	*ft_vsprintf2(char *p, va_list ap, int *tab, t_ret *elem)
{
	char	*modifier;
	int		i;
	int		k;
	char	*str;

	k = 0;
	i = 0;
	modifier = "+-0# ?.hHlLzj";
	while (1)
	{
		if ((elem->buffer = repairvsprint(elem->buffer, p, k, i)) || k != 0)
			i = jump(p, k, 0);
		if ((count(p, i)) == 0)
			return (elem);
		tab = repairdeg(tab, modifier, p, i);
		i = jump2(p, i);
		str = checkelement(tab, p, i, ap);
		if (checkmodulo(p, i) == 1)
			str = print_modulo(tab);
		if (checkmodulo(p, i) == 1)
			k++;
		if (str != NULL)
			elem->buffer = ft_strjoin(elem->buffer, str);
		k++;
	}
}

char	*repairvsprint(char *str, char *p, int k, int i)
{
	char *new;

	if (str == NULL && k == 0)
		str = print_len(p, i);
	else
	{
		i = jump(p, k, 0);
		if (i != 0)
		{
			new = print_len(p, i);
			str = ft_strjoin(str, new);
			if (ft_strlen(new) > 1)
				free(new);
		}
	}
	return (str);
}

int		ft_sprintf(char *b, char *p, ...)
{
	va_list	ap;
	t_ret	*elem;
	int		count;

	va_start(ap, p);
	elem = ft_vsprintf(p, ap);
	b = elem->buffer;
	if (elem->buffer == NULL)
		return (0);
	count = ft_strlen(elem->buffer);
	elem->buffer = replace(elem->buffer);
	write(1, b, count);
	va_end(ap);
	free(elem->buffer);
	return (count);
}

int		ft_printf(char *p, ...)
{
	va_list	ap;
	t_ret	*elem;
	int		count;

	va_start(ap, p);
	elem = ft_vsprintf(p, ap);
	if (elem->buffer == NULL)
		return (0);
	count = ft_strlen(elem->buffer);
	elem->buffer = replace(elem->buffer);
	write(1, elem->buffer, count);
	va_end(ap);
	free(elem->buffer);
	return (count);
}
