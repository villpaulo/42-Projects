/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:14:19 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:14:21 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_H
# define FT_INIT_H

# include "corewar.h"

void			ft_init(t_env *a, int ac, char **av);

/*
** ft_init_print.c
*/

void			print_help(void);

/*
** ft_init_checkarg_2.c
*/

void			ft_check_args_2(t_env *a, int ac, char **av);

/*
** ft_init_strklcmp.c
*/

int				ft_strkcmp(const char *s1, const char *s2);
int				ft_strlcmp(const char *s1, const char *s2);

/*
** ft_init_champ.c
*/

void			ft_init_champs(t_env	*a, int ac, char **av);

/*
** ft_init_map.c
*/

void			ft_init_map(t_env *a);

/*
** ft_init_process.c
*/

void			ft_init_process(t_env *a);

/*
** ft_init_flags.c
*/

void			ft_init_flags(t_flags *flags);
void			ft_asign_flags(t_env *a, char *s);

#endif
