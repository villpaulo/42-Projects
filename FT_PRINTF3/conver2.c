/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:15:51 by pvillene          #+#    #+#             */
/*   Updated: 2016/03/28 17:24:31 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long		conver_u(int *tab, unsigned long n, va_list ap)
{
	if (tab[7] == 0 && tab[8] == 0 && tab[9] > 0 && tab[10] == 0)
		return (n = va_arg(ap, unsigned long));
	if (tab[7] == 0 && tab[8] == 0 && tab[9] == 0 && tab[10] > 0)
		return (n = va_arg(ap, unsigned long));
	if (tab[7] == 0 && tab[8] == 0 && (tab[11] > 0 || tab[12] > 0))
		return (n = va_arg(ap, unsigned long));
	n = va_arg(ap, unsigned int);
	if (n == 0)
		return (0);
	return (n);
}

unsigned long		conver_o(int *tab, unsigned long n, va_list ap)
{
	if (tab[7] == 0 && tab[8] == 0 && tab[9] > 0 && tab[10] == 0)
		return (n = va_arg(ap, unsigned long));
	if (tab[7] == 0 && tab[8] == 0 && tab[9] == 0 && tab[10] > 0)
		return (n = va_arg(ap, unsigned long));
	if (tab[7] == 0 && tab[8] == 0 && (tab[11] > 0 || tab[12] > 0))
		return (n = va_arg(ap, unsigned long));
	n = va_arg(ap, long);
	if (n == 0)
		return (0);
	return (n);
}
