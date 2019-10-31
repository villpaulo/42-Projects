/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:37:37 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/01 16:16:50 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_init.h"

void		print_help(void)
{
	write(1, "You Need Help :\n", 17);
	write(1, "Usage: ./corewar [-dump nbr_cycles] [-alv] ", 41);
	write(1, "[[-n number] <champ1.cor>] ...\n", 31);
	write(1, "Explications :\n", 15);
	write(1, "-a : to see all aff\n", 20);
	write(1, "-l : to see when champ are alive\n", 33);
	write(1, "-u : to see all aff without \"aff :\"\n", 47);
	write(1, "-v : to see our corewar Graphic User Interface\n", 47);
	write(1, "-dump : to limit the count of round and print memory\n", 53);
	write(1, "-n : to asign priority to next champion\n", 40);
	exit(0);
}
