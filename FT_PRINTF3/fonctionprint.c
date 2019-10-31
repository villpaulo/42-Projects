/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctionprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:42:54 by pvillene          #+#    #+#             */
/*   Updated: 2016/04/06 18:12:34 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*print_c(va_list ap, int *tab)
{
	int		n;
	char	*ret;
	char	c;
	char	*str;

	str = NULL;
	if ((n = va_arg(ap, int)) == 0)
	{
		str = retcz(str, tab);
		return (niquetam(str));
	}
	c = (char)n;
	if ((tab = conver_c(tab)) == NULL)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	ret = ret_c(n, tab);
	return (ret);
}

char	*print_s(va_list ap, int *tab)
{
	char	*n;

	if ((n = va_arg(ap, char *)) == 0)
		return (0);
	if ((void *)n < (void *)0x100000000)
		return (0);
	n = ft_strdup(n);
	if (tab[6] > 0 && tab[6] < ft_strlen(n))
		n = flag6s(n, tab);
	if (tab[5] == 0 && tab[6] > ft_strlen(n))
		return (n = ft_strdup(n));
	if (tab[5] > 0)
		n = ret_s(n, tab);
	return (n);
}

char	*print_d(va_list ap, int *tab)
{
	long long int	n;
	int				b;
	char			*str;

	n = 0;
	b = 0;
	n = conver_d(tab, n, ap);
	if (tab[0] > 0)
		b = 1;
	if (n == 0 && tab[5] == 0 && tab[2] == 0 && tab[6] == 0)
		return (printdrep(tab, b));
	if (tab[6] == 1 && tab[5] == 0 && tab[2] == 0)
	{
		tab[5] = ft_strlen2(n);
		tab[6] = 0;
	}
	if (tab[5] > 0 && tab[2] > 0)
	{
		tab[2] = tab[5];
		tab[5] = 0;
		b = 1;
	}
	str = ret_d(n, tab, b);
	str = printdrep2(tab, b, str, n);
	return (str);
}

char	*print_d2(va_list ap, int *tab)
{
	long long int	n;
	char			*str;
	int				b;

	n = 0;
	b = 0;
	if (tab[0] > 0)
		b = 1;
	n = conver_d2(tab, n, ap);
	if (n == 0 && tab[5] == 0 && tab[2] == 0 && tab[6] == 0)
		return (printdrep(tab, b));
	if (tab[6] == 1 && tab[5] == 0 && tab[2] == 0)
	{
		tab[5] = ft_strlen2(n);
		tab[6] = 0;
	}
	if (tab[5] > 0 && tab[2] > 0)
	{
		tab[2] = tab[5];
		tab[5] = 0;
		b = 1;
	}
	str = ret_d(n, tab, b);
	str = printdrep2(tab, b, str, n);
	return (str);
}

char	*print_i(va_list ap, int *tab)
{
	long long	n;
	char		*str;
	int			b;

	n = 0;
	b = 0;
	if (tab[0] > 0)
		b = 1;
	n = conver_d(tab, n, ap);
	if (n == 0 && tab[5] == 0 && tab[2] == 0 && tab[6] == 0)
		return (printdrep(tab, b));
	if (tab[6] == 1 && tab[5] == 0 && tab[2] == 0)
	{
		tab[5] = ft_strlen2(n);
		tab[6] = 0;
	}
	if (tab[5] > 0 && tab[2] > 0)
	{
		tab[2] = tab[5];
		tab[5] = 0;
		b = 1;
	}
	str = ret_d(n, tab, b);
	str = printdrep2(tab, b, str, n);
	return (str);
}
