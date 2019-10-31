/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repair2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:56:30 by pvillene          #+#    #+#             */
/*   Updated: 2016/08/10 13:31:40 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*flag6s(char *n, int *tab)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(n) - tab[6] + 1));
	while (tab[6] != 0)
	{
		str[i] = n[i];
		i++;
		tab[6]--;
	}
	str[i] = '\0';
	return (str);
}

char		*add_char1(wchar_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = n;
	str[1] = '\0';
	return (str);
}

char		*add_char2(wchar_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 3);
	str[0] = ((n >> 6) + 0xC0);
	str[1] = ((n & 0x3F) + 0x80);
	str[2] = '\0';
	return (str);
}

char		*add_char3(wchar_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 4);
	str[0] = ((n >> 12) + 0xE0);
	str[1] = (((n >> 6) & 0x3F) + 0x80);
	str[2] = ((n & 0x3F) + 0x80);
	str[3] = '\0';
	return (str);
}

char		*add_char4(wchar_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 5);
	str[0] = ((n >> 18) + 0xF0);
	str[1] = (((n >> 12) & 0x3F) + 0x80);
	str[2] = (((n >> 6) & 0x3F) + 0x80);
	str[3] = ((n & 0x3F) + 0x80);
	str[4] = '\0';
	return (str);
}
