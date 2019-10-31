/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 05:13:37 by pibenoit          #+#    #+#             */
/*   Updated: 2017/02/10 05:13:38 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "desa.h"

void			ft_help(void)
{
	write(1, "###   Usage:   ###\n", 19);
	write(1, "Mode standard: afficher le bytecode en hexa\n", 44);
	write(1,
		"Flags:\n\t-f:\tpour mettre le resultat dans un fichier .txt\n", 58);
	write(1,
		"\t-s:\tpour sortir un fichier assemblable(par l'asm de zaz)\n", 58);
	write(1, "\t-i:\tpour afficher l'intro\n", 28);
	write(1, "\t-a:\tpour mettre une instruction en hexa par ligne\n", 52);
	write(1,
		"\t-t:\tpour afficher le bytecode en hexa et sa traduction\n", 56);
	exit(0);
}

void			ft_put_endl(char *str)
{
	int		i;
	int		octet;

	i = 0;
	octet = 20;
	while (str[i])
	{
		if (i == 0 || str[i - 1] == '\n')
			octet = ft_analyse(str, i, 0, 0);
		else if (octet == 0)
		{
			ft_copy(str, i);
			octet = 20;
		}
		if (octet < 0)
		{
			free(str);
			exit(0);
		}
		octet--;
		i++;
	}
	str[i] = '\n';
	str[i + 1] = '\0';
}

char			*ft_give_instruct(int i)
{
	static char	tab[16][6] = {"live ", "ld ", "st ", "add ", "sub ", "and ",\
		"or ", "xor ", "zjmp ", "ldi ", "sti ", "fork ", "lld ", "lldi ",\
			"lfork ", "aff "};

	return (tab[i - 1]);
}
