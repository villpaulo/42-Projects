/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 05:14:11 by pibenoit          #+#    #+#             */
/*   Updated: 2017/02/10 05:14:13 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "desa.h"
#include <string.h>
#include <stdlib.h>

char			*ft_give_reg(char *str, int index)
{
	char			s1[4];
	unsigned int	i;

	s1[0] = 'r';
	i = ft_give_hexa(str[index], str[index + 1]);
	if (i > 10)
	{
		s1[1] = '1';
		s1[2] = i + 38;
		s1[3] = '\0';
	}
	else
	{
		s1[1] = i + 48;
		s1[2] = '\0';
	}
	return (ft_strdup(s1));
}

char			*ft_give_dir(char *s, int i, int nb)
{
	char	*s1;
	int		a;
	short	b;

	a = 0;
	b = 0;
	s1 = (char*)malloc(2);
	s1[0] = DIRECT_CHAR;
	s1[1] = '\0';
	if (nb == 1 || nb == 2 || nb == 6 || nb == 7 || nb == 8 || nb == 13)
		a = (((((ft_give_hexa(s[i], s[i + 1]) << 8)
			+ ft_give_hexa(s[i + 2], s[i + 3])) << 8)
			+ ft_give_hexa(s[i + 4], s[i + 5])) << 8)
			+ ft_give_hexa(s[i + 6], s[i + 7]);
	else if (nb >= 9 && nb <= 15 && nb != 13)
	{
		b = (((char)ft_give_hexa(s[i], s[i + 1]) << 8)
			+ ft_give_hexa(s[i + 2], s[i + 3]));
		a = b;
	}
	s1 = ft_strjoin_fs1s2(s1, ft_itoa(a));
	return (s1);
}

char			*ft_give_ind(char *str, int i)
{
	int		a;

	a = (short)(ft_give_hexa(str[i], str[i + 1]) * 256)
		+ ft_give_hexa(str[i + 2], str[i + 3]);
	return (ft_itoa(a));
}

char			*ft_give_str_dparam(char *str, int i, int nb, int ocp)
{
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	i = 2;
	if (ocp / 64 > 1)
	{
		if (nb != 10 && nb != 11 && nb != 12 && ocp / 64 == 2)
			i = 8;
		else
			i = 4;
	}
	s1 = ft_give_param(str, 4, nb, (ocp / 64));
	s2 = ft_give_param(str, 4 + i, nb, (ocp / 16) % 4);
	return (ft_strjoin_fs1s2v(s1, s2));
}

char			*ft_give_str_tparam(char *str, int i, int nb, int ocp)
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		j;

	j = 2;
	i = 2;
	if (ocp / 64 > 1)
	{
		i = i << 1;
		if (nb >= 6 && nb <= 8 && ocp / 64 == 2)
			i = i << 1;
	}
	if (((ocp / 16) % 4) > 1)
	{
		j = j << 1;
		if (nb >= 6 && nb <= 8 && ((ocp / 16) % 4) == 2)
			j = j << 1;
	}
	s1 = ft_give_param(str, 4, nb, (ocp / 64));
	s2 = ft_give_param(str, 4 + i, nb, (ocp / 16) % 4);
	s3 = ft_give_param(str, 4 + i + j, nb, (ocp / 4) % 4);
	return (ft_strjoin_fs1s2v(ft_strjoin_fs1s2v(s1, s2), s3));
}
