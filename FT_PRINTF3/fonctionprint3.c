/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctionprint3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:21:40 by pvillene          #+#    #+#             */
/*   Updated: 2016/04/06 18:12:39 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*print_orep(char *str, int *tab, unsigned long n)
{
	if (tab[2] > 0 && tab[6] > 0)
		tab[5] = tab[2];
	if (n == 0 && tab[5] == 0 && tab[6] == 0 && tab[2] == 0)
		return (retz(str));
	else if (n == 0 && tab[6] == 0 && tab[5] > 0)
		str = retz(str);
	else if (n == 0 && tab[6] > 0)
	{
		if (tab[3] > 0)
			str = retz(str);
		else
			str = retspace(str);
		tab[2] = 0;
		tab[6] = 0;
	}
	tab[3] = 0;
	str = ret_o(str, tab);
	return (str);
}

char	*ft_putnbr2(int i, int base, int b, int *tab)
{
	char	*str;
	int		j;

	j = 0;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (b == 2)
		j++;
	if (b == 1)
	{
		j++;
		str[0] = '+';
	}
	if (j == 1 && b == 2)
		str[0] = '-';
	while (i--)
	{
		if (base > 10 && tab[i] > 9)
			str[j] = ((tab[i] + 87));
		else
			str[j] = (tab[i] + 48);
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_putnbr(long long n, int base, int b)
{
	int		tab[100];
	int		i;

	i = 0;
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0 && (n *= -1))
		b = 2;
	while (n > 0)
	{
		tab[i] = n % base;
		n = n / base;
		i++;
	}
	return (ft_putnbr2(i, base, b, tab));
}

char	*ft_putnbrx(unsigned long n, unsigned long base, char *str)
{
	int		tab[100];
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (n > 0)
	{
		tab[i] = n % base;
		n = n / base;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + j + 100000));
	while (i--)
	{
		if (base > 10 && tab[i] > 9)
			str[j] = (tab[i] + 87);
		else
			str[j] = (tab[i] + 48);
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_putnbrx2(unsigned long n, int base)
{
	int		tab[100];
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	while (n > 0)
	{
		tab[i] = n % base;
		n = n / base;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	while (i--)
	{
		if (base > 10 && tab[i] > 9)
			str[j] = ((tab[i] + 55));
		else
			str[j] = (tab[i] + 48);
		j++;
	}
	str[j] = '\0';
	return (str);
}
