/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:40:31 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 13:38:52 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdarg.h>

int		ft_detectendconv(char *str, int t[15])
{
	int i;

	i = t[0] + 1;
	while ((str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == '.'
		|| str[i] == '+' || str[i] == ' ' || str[i] == 'h' || str[i] == '*'
		|| str[i] == 'l' || str[i] == 'j' || str[i] == 'z' || str[i] == ','
		|| (str[i] > 48 && str[i] < 58)) && str[i] != '\0')
		i++;
	return (i);
}

void	ft_param(char *str, int t[15], va_list ap)
{
	int i;

	i = 0;
	ft_putnstrx((str + t[1]), (t[0] - t[1]));
	t[1] = ft_detectendconv(str, t);
	if (str[t[1]] != '\0')
	{
		ft_flag((str + t[0]), t, (t[1] - t[0] + 1), &(*ap));
		ft_print(*(str + t[1]), t, &(*ap));
		t[0] = t[1];
		t[1]++;
	}
}

int		ft_analyse(char *str, va_list ap)
{
	int t[15];

	ft_memset(t, 0, 60);
	while (str[t[0]] != '\0')
	{
		if (str[t[0]] == '{' && str[t[0] + 1] == '/')
			ft_printcolor(str, t);
		else if (str[t[0]] == '%')
			ft_param(str, t, &(*ap));
		t[0]++;
	}
	ft_putstrz(ft_strdup(str + t[1]), 0, 0);
	return (t[3]);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		n;
	int		len;

	va_start(ap, str);
	n = ft_analyse((char*)str, &(*ap));
	len = ft_putstrz("", 1, n);
	va_end(ap);
	return (len);
}
