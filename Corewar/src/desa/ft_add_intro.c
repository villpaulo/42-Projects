/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_intro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 05:13:27 by pibenoit          #+#    #+#             */
/*   Updated: 2017/02/10 05:13:29 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "desa.h"
#include "op.h"
#include <stdlib.h>

char	*ft_add_intro(t_flags *flags)
{
	char	*s1;
	char	*s2;

	s1 = ft_strjoin(".name\t\"", flags->header.prog_name);
	s1 = ft_strjoin_fs1(s1, "\"\n");
	s2 = ft_strjoin(".comment\t\"", flags->header.comment);
	s2 = ft_strjoin_fs1(s2, "\"\n\n");
	return (ft_strjoin_fs1s2(s1, s2));
}
