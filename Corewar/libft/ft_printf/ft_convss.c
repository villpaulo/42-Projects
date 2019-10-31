/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 04:20:52 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 14:05:20 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <wchar.h>

void	ft_prints(int t[15], char *str, int len)
{
	int i;

	i = len;
	if (t[11] < len && t[11] > 0)
		i = t[11];
	if (t[6] == 0 && t[10] != 0)
		ft_printzeroandspace(t, t[10], i);
	if (len > t[11] && t[11] != 0)
		ft_putnstrx(str, t[11]);
	else
		ft_putstrx(ft_strdup(str));
	t[7] = 0;
	if (t[4] == 2)
		ft_printzeroandspace(t, t[10], len);
	if (t[6] == 1 && t[10] != 0)
		ft_printzeroandspace(t, t[10], i);
}

void	ft_printsmaj(int t[15], wchar_t *str, int len)
{
	int i;

	i = len;
	if (t[11] < len && t[11] > 0)
		i = t[11];
	if (t[6] == 0 && t[10] != 0)
		ft_printzeroandspace(t, t[10], i);
	if (len > t[11] && t[11] != 0)
		ft_putnwstrx(str, t[11]);
	else
		ft_putwstrx(str);
	t[7] = 0;
	if (t[4] == 2)
		ft_printzeroandspace(t, t[10], len);
	if (t[6] == 1)
		ft_printzeroandspace(t, t[10], i);
}

void	ft_convsmaj(int t[15], va_list ap)
{
	wchar_t	*str;
	char	*s;
	int		len;

	str = va_arg(ap, wchar_t*);
	if (t[11] == -1)
	{
		s = "\0";
		len = 0;
		ft_prints(t, s, len);
	}
	else if (str == NULL)
	{
		s = "(null)";
		len = ft_strlen(s);
		ft_prints(t, s, len);
	}
	else
	{
		len = ft_wcslen_octet(str);
		if (t[11] < len)
			t[11] = ft_wcslen_noctet(str, t[11]);
		ft_printsmaj(t, str, len);
	}
}

void	ft_convss(char c, int t[15], va_list ap)
{
	char	*str;
	int		len;

	str = NULL;
	len = 0;
	if (c == 's')
	{
		if (t[14] == 3)
			ft_convss('S', t, ap);
		else
		{
			str = va_arg(ap, char*);
			if (str == NULL)
				str = "(null)";
			if (t[11] == -1)
				str = "";
			len = ft_strlen(str);
			ft_prints(t, str, len);
		}
	}
	else
		ft_convsmaj(t, &(*ap));
}
