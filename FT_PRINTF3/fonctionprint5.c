/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctionprint5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:24:02 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/29 16:29:33 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*print_u(va_list ap, int *tab)
{
	unsigned long	n;
	char			*str;

	n = 0;
	str = NULL;
	n = conver_u(tab, n, ap);
	if (n == 0)
		return (retuz(str, tab));
	str = ft_putnbrx(n, 10, str);
	str = ret_o(str, tab);
	return (str);
}

char	*print_u2(va_list ap, int *tab)
{
	unsigned long	n;
	char			*str;

	n = 0;
	str = NULL;
	n = conver_u(tab, n, ap);
	if (n == 0)
		return (retuz(str, tab));
	str = ft_putnbrx(n, 10, str);
	str = ret_o(str, tab);
	return (str);
}

char	*print_c2(va_list ap, int *tab)
{
	wchar_t	n;
	char	*str;

	n = 0;
	str = NULL;
	if ((n = (wchar_t)va_arg(ap, wchar_t)) == 0)
	{
		str = retcz(str, tab);
		return (niquetam(str));
	}
	if (n <= 0x7F)
		str = (add_char1(n));
	else if (n <= 0x7FF)
		str = (add_char2(n));
	else if (n <= 0xFFFF)
		str = (add_char3(n));
	else if (n <= 0x10FFFF)
		str = (add_char4(n));
	else
		return (ft_strnew(1));
	if (tab[5] != 0)
		str = ret_s(str, tab);
	return (str);
}

char	*print_s2(va_list ap, int *tab)
{
	wchar_t	*n;
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	if ((n = (wchar_t *)va_arg(ap, wchar_t *)) == 0)
		return (NULL);
	if ((void *)n < (void *)0x100000000)
		return (NULL);
	while (n[i])
	{
		str = ft_strjoin(str, print_s3(n[i]));
		i++;
	}
	if (tab[5] > 0)
		str = ret_s(str, tab);
	return (str);
}

char	*print_s3(wchar_t n)
{
	char	*str;

	if (n <= 0x7F)
		str = (add_char1(n));
	else if (n <= 0x7FF)
		str = (add_char2(n));
	else if (n <= 0xFFFF)
		str = (add_char3(n));
	else if (n <= 0x10FFFF)
		str = (add_char4(n));
	else
		return (ft_strnew(1));
	return (str);
}
