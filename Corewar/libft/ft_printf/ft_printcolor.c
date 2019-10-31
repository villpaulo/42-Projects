/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:50:31 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 13:38:14 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

int		ft_endofcolor(char *s, int t[15])
{
	int i;

	i = t[0];
	while (s[i] != '}' && s[i] != '\0')
		i++;
	return (i);
}

void	ft_gesbackground(char *s, int t[15])
{
	if (!(ft_strncmp((s + t[0]), "{/black/}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[40m"));
	else if (!(ft_strncmp((s + t[0]), "{/red/}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[41m"));
	else if (!(ft_strncmp((s + t[0]), "{/green/}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[42m"));
	else if (!(ft_strncmp((s + t[0]), "{/yellow/}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[43m"));
	else if (!(ft_strncmp((s + t[0]), "{/blue/}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[44m"));
	else if (!(ft_strncmp((s + t[0]), "{/magenta/}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[45m"));
	else if (!(ft_strncmp((s + t[0]), "{/cyan/}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[46m"));
	else if (!(ft_strncmp((s + t[0]), "{/white/}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[47m"));
	else if (!(ft_strncmp((s + t[0]), "{/end/}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[0m"));
}

void	ft_gescolor(char *s, int t[15])
{
	if (!(ft_strncmp((s + t[0]), "{/black}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[30m"));
	else if (!(ft_strncmp((s + t[0]), "{/red}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[31m"));
	else if (!(ft_strncmp((s + t[0]), "{/green}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[32m"));
	else if (!(ft_strncmp((s + t[0]), "{/yellow}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[33m"));
	else if (!(ft_strncmp((s + t[0]), "{/blue}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[34m"));
	else if (!(ft_strncmp((s + t[0]), "{/magenta}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[35m"));
	else if (!(ft_strncmp((s + t[0]), "{/cyan}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[36m"));
	else if (!(ft_strncmp((s + t[0]), "{/white}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[37m"));
	else if (!(ft_strncmp((s + t[0]), "{/end}", (t[1] - t[0]) + 1)))
		ft_putstrx(ft_strdup("\33[0m"));
}

void	ft_printcolor(char *s, int t[15])
{
	ft_putnstrx(ft_strdup(s + t[1]), (t[0] - t[1]));
	t[1] = ft_endofcolor(s, t);
	if (s[t[1]] != '\0')
	{
		if (s[t[1] - 1] == '/')
			ft_gesbackground(s, t);
		else
			ft_gescolor(s, t);
		t[0] = t[1];
		t[1]++;
	}
}
