/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:34:07 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:05:00 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

int		ft_geslenmin(char *s, int t[15], int v[3], va_list ap)
{
	int i;
	int j;

	i = v[0];
	j = v[1];
	t[12] = 1;
	while (j >= i)
	{
		if (s[j] == '*' && s[j - 1] != '.' && s[j - 1] != ',')
			return (ft_wildlenmin(t, &(*ap)));
		if (s[j] > 48 && s[j] < 58)
		{
			while (s[j] > 48 && s[j] < 58)
				j--;
			if (s[j] != '.')
			{
				ft_wildcard(s, t, v, &(*ap));
				return (ft_atoi(s + j + 1));
			}
		}
		j--;
	}
	return (0);
}

int		ft_gesprec2(char *s, int t[15], int w[2], va_list ap)
{
	int j;
	int tmp;

	j = w[1];
	tmp = w[0];
	while (j < tmp && s[j] == 0)
		j++;
	if (s[j] > 48 && s[j] < 58)
	{
		ft_wildcard(s, t, w, &(*ap));
		return (ft_atoi(s + j));
	}
	else
		return (-1);
}

int		ft_gesprecision(char *s, int t[15], int v[3], va_list ap)
{
	int w[2];

	w[1] = v[1];
	w[0] = w[1];
	t[13] = 1;
	while (w[1] >= v[0])
	{
		if (s[w[1]] == '.')
		{
			w[1]++;
			if (s[w[1]] == '*')
				return (ft_wildprec(&(*ap)));
			return (ft_gesprec2(s, t, w, &(*ap)));
		}
		w[1]--;
	}
	return (0);
}

void	ft_gesflag(char *s, int t[15], int v[3], va_list ap)
{
	if (s[v[0]] == '#')
		t[5] = 1;
	if (s[v[0]] == '-')
		t[6] = 1;
	if (s[v[0]] == '0' && (s[v[0] - 1] > 57 || s[v[0] - 1] < 48)
			&& s[v[0] - 1] != '.' && s[v[0]] != ',')
		t[7] = 1;
	if (s[v[0]] == '+')
		t[8] = 1;
	if (s[v[0]] == ' ')
		t[9] = 1;
	if (((s[v[0]] > 48 && s[v[0]] < 58)
				|| (s[v[0]] == '*' && (s[v[0] - 1] != '.'
				|| s[v[0] - 1] != ','))) && t[12] == 0)
		t[10] = ft_geslenmin(s, t, v, &(*ap));
	if (s[v[0]] == '.' && t[13] == 0)
		t[11] = ft_gesprecision(s, t, v, &(*ap));
	if (s[v[0]] == ',' && t[12] == 0)
		t[10] = ft_gescentr(s, t, v, &(*ap));
}

void	ft_flag(char *str, int t[15], int len, va_list ap)
{
	int v[3];

	ft_memset(t + 4, 0, 52);
	ft_memset(v, 0, 12);
	v[1] = len;
	while (v[0] < v[1])
	{
		if (str[v[0]] == '#' || str[v[0]] == '-' || str[v[0]] == '0'
				|| str[v[0]] == '+' || str[v[0]] == ' ' || str[v[0]] == '.'
				|| (str[v[0]] > 48 && str[v[0]] < 58) || str[v[0]] == '*'
				|| str[v[0]] == ',')
			ft_gesflag(str, t, v, &(*ap));
		if ((str[v[0]] == 'h' || str[v[0]] == 'l' || str[v[0]] == 'j'
					|| str[v[0]] == 'z')
				&& v[2] == 0)
		{
			v[2]++;
			t[14] = ft_geslenmod(str, v[0], v[1]);
		}
		v[0]++;
	}
}
