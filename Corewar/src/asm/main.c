/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <pvillene@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:59:01 by pvillene          #+#    #+#             */
/*   Updated: 2016/12/20 19:01:59 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		main(int ac, char **av)
{
	t_asm		env;

	if (!init(&env, ac, av))
		return (0);
	if (!parse(&env))
		return (0);
	interpret(&env);
	free_env(&env);
	return (0);
}
