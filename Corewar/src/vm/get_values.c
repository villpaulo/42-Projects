/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:15:44 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:15:45 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <stdlib.h>
#include <stdio.h>

int			get_reg(const int *reg_tab, uint8_t index)
{
	return (reg_tab[index - 1]);
}

int			get_dir(const char *map, int pc)
{
	char			a;
	unsigned char	b;
	unsigned char	c;
	unsigned char	d;
	int				e;

	a = map[pc % MEM_SIZE];
	b = (unsigned char)map[(pc + 1) % MEM_SIZE];
	c = (unsigned char)map[(pc + 2) % MEM_SIZE];
	d = (unsigned char)map[(pc + 3) % MEM_SIZE];
	e = a * 16777216;
	e += b * 65536;
	e += c * 256;
	e += d;
	return (e);
}

int			get_ind(const char *map, int index)
{
	char			a;
	unsigned char	b;
	int				c;

	a = map[index % MEM_SIZE];
	b = (unsigned char)map[(index + 1) % MEM_SIZE];
	c = a * 256;
	c += b;
	return (c);
}
