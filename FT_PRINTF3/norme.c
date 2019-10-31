/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:13:58 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/28 17:14:42 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

extern t_element	g_element[];

int		norme1(char *p, int i)
{
	int e;

	e = 0;
	while (p[i] != g_element[e].c && g_element[e].c)
		e++;
	if (p[i] == g_element[e].c)
		return (0);
	return (1);
}

int		norme2(int j, char *p, int i)
{
	int		curs;
	char	*tmp;

	curs = 0;
	if (j == 2 || j == 6 || j == 5)
	{
		tmp = ft_strndup(p, i);
		curs = ft_strlen(tmp);
		if (curs == 0 && j == 2)
			curs--;
		if (curs >= 1)
			curs--;
		free(tmp);
	}
	return (curs);
}

int		norme3(int k)
{
	k++;
	return (k);
}
