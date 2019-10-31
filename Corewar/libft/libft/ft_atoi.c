/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:51:59 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:07:05 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

static unsigned int	ft_pow(unsigned int nb)
{
	if (nb == 0)
		return (1);
	else if (nb == 1)
		return (10);
	else
		return (ft_pow(nb - 1) * 10);
}

static unsigned int	ft_strlength(const char *nb)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (*(nb + i) != '\0' && *(nb + i) > 47 && *(nb + i) < 58)
		i++;
	return (i);
}

static int			ft_addnumber(const char *nptr, int i, unsigned int len)
{
	int				j;
	unsigned int	cpt;

	j = 0;
	cpt = 0;
	while (cpt < len)
	{
		j = j + (nptr[i + len - cpt - 1] - 48) * ft_pow(cpt);
		cpt++;
	}
	return (j);
}

int					ft_atoi(const char *nptr)
{
	int				i;
	int				j;
	unsigned int	len;
	int				neg;

	i = 0;
	j = 0;
	neg = 0;
	while (*(nptr + i) == '\f' || *(nptr + i) == '\n' || *(nptr + i) == '\r'
			|| *(nptr + i) == '\t' || *(nptr + i) == ' ' || *(nptr + i) == '\v')
		i++;
	if (*(nptr + i) == '-')
	{
		neg = 1;
		i++;
	}
	else if (*(nptr + i) == '+')
		i++;
	len = ft_strlength(nptr + i);
	j = ft_addnumber(nptr, i, len);
	if (neg == 1)
		j = (-1) * j;
	return (j);
}
