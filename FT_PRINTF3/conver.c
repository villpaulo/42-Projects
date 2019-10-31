/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:16:19 by pvillene          #+#    #+#             */
/*   Updated: 2016/08/10 13:22:05 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				*conver_c(int *tab)
{
	return (tab);
}

unsigned long	conver_x(int *tab, unsigned long n, va_list ap)
{
	if (tab[7] == 0 && tab[8] == 0 && tab[9] > 0 && tab[10] == 0)
		return (n = (unsigned long)va_arg(ap, unsigned long));
	if (tab[7] == 0 && tab[8] == 0 && tab[9] == 0 && tab[10] > 0)
		return (n = (unsigned long)va_arg(ap, unsigned long));
	if (tab[7] == 0 && tab[8] == 0 && (tab[11] > 0 || tab[12] > 0))
		return (n = va_arg(ap, unsigned long));
	n = va_arg(ap, unsigned int);
	if (n == 0)
		return (0);
	return (n);
}

unsigned long	conver_x2(int *tab, unsigned long n, va_list ap)
{
	if (tab[7] == 0 && tab[8] == 0 && tab[9] > 0 && tab[10] == 0)
		return (n = va_arg(ap, unsigned long));
	if (tab[7] == 0 && tab[8] == 0 && tab[9] == 0 && tab[10] > 0)
		return (n = va_arg(ap, unsigned long));
	if (tab[7] == 0 && tab[8] == 0 && tab[9] == 0 && tab[11] > 0)
		return (n = va_arg(ap, unsigned long));
	if (tab[7] == 0 && tab[8] == 0 && tab[9] == 0 && tab[12] > 0)
		return (n = va_arg(ap, unsigned long));
	n = va_arg(ap, unsigned int);
	if (n == 0)
		return (0);
	return (n);
}

long			conver_d(int *tab, long n, va_list ap)
{
	if (tab[7] == 0 && tab[8] == 0 && tab[9] > 0 && tab[10] == 0)
		return (n = va_arg(ap, long long));
	if (tab[7] == 0 && tab[8] == 0 && tab[9] == 0 && tab[10] > 0)
		return (n = va_arg(ap, long long));
	if (tab[7] == 0 && tab[8] == 0 && (tab[11] > 0 || tab[12] > 0))
		return (n = va_arg(ap, long long));
	n = va_arg(ap, int);
	if (n == 0)
		return (0);
	return (n);
}

long			conver_d2(int *tab, long n, va_list ap)
{
	if (tab[7] == 0 && tab[8] == 0 && tab[9] > 0 && tab[10] == 0)
		return (n = va_arg(ap, long long));
	if (tab[7] == 0 && tab[8] == 0 && tab[9] == 0 && tab[10] > 0)
		return (n = va_arg(ap, long long));
	if (tab[7] == 0 && tab[8] == 0 && (tab[11] > 0 || tab[12] > 0))
		return (n = va_arg(ap, long long));
	n = va_arg(ap, long);
	if (n == 0)
		return (0);
	return (n);
}
