/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 23:53:28 by pvillene          #+#    #+#             */
/*   Updated: 2016/09/29 00:34:34 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/filler.h"

void		*singleton(void *ptr, int key)
{
	static void		*z;

	if (key == 0)
		z = ptr;
	return (z);
}

void		print_result(t_coor *z)
{
	while (z->recup[0] != 0)
	{
		z->recup[0]--;
		z->ret[0]--;
	}
	while (z->recup[1] != 0)
	{
		z->recup[1]--;
		z->ret[1]--;
	}
	z->ret[1] = z->ret[1] - z->p[3];
	z->ret[0] = z->ret[0] - z->p[4];
	z->s = 0;
	ft_putnbr(z->ret[0]);
	ft_putchar(' ');
	ft_putnbr(z->ret[1]);
	ft_putchar('\n');
}

void		searchp(char *p, char *inv, char *str)
{
	if (hidenp("p1", str) == 1)
	{
		*p = 'O';
		*inv = 'X';
	}
	else
	{
		*p = 'X';
		*inv = 'O';
	}
}

int			main(void)
{
	char	*str;
	t_coor	*z;

	str = NULL;
	z = NULL;
	if (!(z = (t_coor *)malloc(sizeof(t_coor))))
		return (0);
	z->player = 'n';
	singleton(z, 0);
	while (42)
	{
		if (z->player == 'n')
		{
			get_next_line(0, &str);
			searchp(&z->player, &z->inv, str);
		}
		if (str != NULL)
			filler(str, z->player, z);
	}
	return (0);
}

void		filler(char *str, char p, t_coor *z)
{
	z = parse(z, str);
	if (z == NULL)
	{
		ft_putstr("invalid map\n");
		exit(0);
	}
	changepiece(z);
	z->pi = changepi(z->pi, z);
	z = searchpoint(z, p);
	z->s = 0;
	z->ret2 = z->ret[1];
	z->x = 0;
	z = result(z, p);
	if (z == NULL)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
		exit(0);
	}
	freez(z);
	print_result(z);
}
