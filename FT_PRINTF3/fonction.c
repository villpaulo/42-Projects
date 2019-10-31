/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:25:55 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/28 17:32:58 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itoa(int nbr)
{
	int		neg;
	char	*str;
	int		count;

	neg = 0;
	count = count_len(nbr);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (nbr < 0)
		neg = 1;
	str[count + 1] = '\0';
	while (count-- != 0)
	{
		if (nbr < 0)
			str[count] = (((nbr % 10) * -1) + '0');
		else
			str[count] = ((nbr % 10) + '0');
		nbr = nbr / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		*ft_zero(int *tab, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int		ft_atoi(char *str)
{
	int i;
	int neg;
	int n;

	i = 0;
	neg = 1;
	n = 0;
	while (((str[i] > 8) && (str[i] < 14)) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	if ((str[i] == '+') && (neg != -1))
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		n = 10 * n;
		n = n + (str[i] - 48);
		i++;
	}
	return (neg * n);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = n;
	while (ft_isdigit(str[n]))
	{
		n++;
		i++;
	}
	tmp = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (ft_isdigit(str[j]))
	{
		tmp[i] = str[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}
