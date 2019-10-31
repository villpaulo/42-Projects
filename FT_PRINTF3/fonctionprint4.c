/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctionprint4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:23:11 by pvillene          #+#    #+#             */
/*   Updated: 2016/04/06 18:12:41 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*print_p(va_list ap, int *tab)
{
	unsigned long	n;
	char			*str;
	int				ne;

	ne = 0;
	str = NULL;
	n = 0;
	if ((n = va_arg(ap, unsigned long long)) == 0)
	{
		str = (char *)malloc(sizeof(char) * 4);
		str[0] = '0';
		str[1] = 'x';
		str[2] = '0';
		str[3] = '\0';
		return (str);
	}
		str = ft_putnbrx(n, 16, str);
	str = filldx(str, tab, n);
	if (tab[1] > 0)
		ne = 1;
	str = ret_x(str, tab, ne);
	return (str);
}

char	*print_x(va_list ap, int *tab)
{
	unsigned long	n;
	char			*str;
	int				ne;

	ne = 0;
	str = NULL;
	n = 0;
	n = conver_x(tab, n, ap);
	if (n == 0)
		tab[3] = 0;
	if (n == 0 && tab[6] > 0 && tab[2] == 0 && tab[5] == 0)
		return (retspace(str));
	else if (n == 0 && tab[5] == 0 && tab[6] == 0 && tab[2] == 0)
		return (retz(str));
	str = print_xrep(str, ne, n, tab);
	if (n == 0 && tab[6] > 0)
		print_xrep2(tab);
	if (tab[6] > 0)
		tab[2] = tab[6];
	if (tab[6] > 0 && tab[5] == 0 && tab[3] > 0 && ft_strlen3(n, tab[6]) == 1)
		return (fillrepair2(str));
	if (tab[3] > 0)
		str = filldx(str, tab, n);
	return (str);
}

char	*print_x2(va_list ap, int *tab)
{
	unsigned long	n;
	char			*str;

	str = NULL;
	n = 0;
	n = conver_x2(tab, n, ap);
	if (n == 0)
		tab[3] = 0;
	if (n == 0 && tab[6] > 0 && tab[2] == 0 && tab[5] == 0)
		return (retspace(str));
	else if (n == 0 && tab[5] == 0 && tab[6] == 0 && tab[2] == 0)
		return (retz(str));
	str = print_xxrep(str, n, tab);
	if (n == 0 && tab[6] > 0)
		print_xrep2(tab);
	str = ret_x2(str, tab);
	if (tab[6] > 0)
		tab[2] = tab[6];
	if (tab[3] > 0)
		str = filldxx(str, tab, n);
	return (str);
}

char	*print_o2(va_list ap, int *tab)
{
	unsigned long	n;
	char			*str;

	str = NULL;
	n = 0;
	n = conver_o(tab, n, ap);
	if (n == 0)
		return (print_orep(str, tab, n));
	str = ft_putnbrx2(n, 8);
	if (tab[3] > 0)
		str = filldo(str);
	str = ret_o2(str, tab);
	return (str);
}

char	*print_o(va_list ap, int *tab)
{
	unsigned long	n;
	char			*str;

	str = NULL;
	n = 0;
	n = conver_o(tab, n, ap);
	if (n == 0)
		return (print_orep(str, tab, n));
	str = ft_putnbrx(n, 8, str);
	if (tab[3] > 0)
		str = filldo(str);
	str = ret_o(str, tab);
	return (str);
}
