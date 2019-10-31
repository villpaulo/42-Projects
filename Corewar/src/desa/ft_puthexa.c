/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 05:14:21 by pibenoit          #+#    #+#             */
/*   Updated: 2017/02/10 05:14:23 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "desa.h"

void			ft_hexa(unsigned char *nb)
{
	if (*nb < 10)
		*nb += 48;
	else
		*nb += 87;
}

char			*ft_translate(char *str, int ret)
{
	int				i;
	int				j;
	unsigned char	nb1;
	unsigned char	nb2;
	char			*s2;

	if (!(s2 = (char*)malloc((ret * 3) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ret)
	{
		nb1 = (unsigned char)str[i] / 16;
		nb2 = (unsigned char)str[i] % 16;
		ft_hexa(&nb1);
		ft_hexa(&nb2);
		s2[j] = nb1;
		s2[j + 1] = nb2;
		j += 2;
		i++;
	}
	s2[j] = '\0';
	free(str);
	return (s2);
}

void			ft_copy(char *str, int i)
{
	int	j;

	j = ft_strlen(str);
	str[j + 1] = '\0';
	while (j > i)
	{
		str[j] = str[j - 1];
		j--;
	}
	str[i] = '\n';
}

unsigned int	ft_give_hexa(char a, char b)
{
	int	c;

	c = 0;
	if (a > 47 && a < 58)
		c = a - 48;
	else if (a > 96 && a < 123)
		c = a - 87;
	c = c * 16;
	if (b > 47 && b < 58)
		c = c + (b - 48);
	else if (b > 96 && b < 123)
		c = c + (b - 87);
	return (c);
}

int				ft_analyse(char *str, int i, unsigned int c, unsigned int d)
{
	c = ft_give_hexa(str[i], str[i + 1]);
	d = ft_give_hexa(str[i + 2], str[i + 3]);
	if (c == 1 || (c == 3 && d == 112) || (((c > 3 && c < 9) || c == 10\
	|| c == 11 || c == 14) && d == 84) || (d == 209 && (c == 2 || c == 13)))
		return (10);
	else if (c == 9 || c == 12 || c == 15 || c == 16)
		return (6);
	else if (c == 3 && d == 80)
		return (8);
	else if (((c == 10 || c == 11 || c == 14) && d == 100) || (c == 11\
			&& d == 88) || ((c == 10 || c == 14) && d == 148) || (c > 5\
			&& c < 9 && (d == 116 || d == 212)) || (c == 11 && d == 116))
		return (12);
	else if (((c == 2 || c == 13) && d == 144) || (c > 5 && c < 9 && d == 244)\
			|| ((c == 10 || c == 14) && (d == 164 || d == 228))\
			|| (c == 11 && (d == 104 || d == 120)))
		return (14);
	else if (c > 5 && c < 9 && (d == 100 || d == 148))
		return (16);
	else if (c > 5 && c < 9 && (d == 180 || d == 228))
		return (18);
	else if (c > 5 && c < 9 && d == 164)
		return (22);
	return (-1);
}
