/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctionprint2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 22:58:32 by pvillene          #+#    #+#             */
/*   Updated: 2016/04/06 18:12:37 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*printdrep(int *tab, int b)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 3);
	if (b == 1)
	{
		str[0] = '+';
		str[1] = '0';
		str[2] = '\0';
	}
	else if (tab[4] > 0)
	{
		str[0] = ' ';
		str[1] = '0';
		str[2] = '\0';
	}
	else
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

char	*printdrep2(int *tab, int b, char *str, long long int n)
{
	if (tab[6] > 0 && n == 0 && tab[2] == 0)
		str = replacez(str);
	if (tab[5] > tab[6] && tab[6] > (ft_strlen(ft_putnbr(n, 10, 0))) && b == 1)
		str = flagpos(str, tab);
	if (tab[5] <= tab[6] && tab[4] > 0 && tab[0] == 0 && n > 0)
		str = flag4d(str);
	return (str);
}

char	*print_xrep(char *str, int ne, unsigned long n, int *tab)
{
	if (tab[1] > 0)
		ne = 1;
	if (n != 0)
		str = ft_putnbrx(n, 16, str);
	else if (n == 0 && tab[6] == 0)
		str = retz(str);
	else if (n == 0 && tab[6] > 0)
		str = retspace(str);
	str = ret_x(str, tab, ne);
	return (str);
}

void	print_xrep2(int *tab)
{
	tab[2] = 0;
	tab[6] = 0;
}

char	*print_xxrep(char *str, unsigned long n, int *tab)
{
	if (n != 0)
		str = ft_putnbrx2(n, 16);
	else if (n == 0 && tab[6] == 0)
		str = retz(str);
	else if (n == 0 && tab[6] > 0)
		str = retspace(str);
	return (str);
}
