/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 18:07:02 by pbenoit           #+#    #+#             */
/*   Updated: 2016/03/22 16:46:42 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_changeworld(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\1')
			s[i] = '\0';
		i++;
	}
}

int		ft_putstrz(char *s, int i, int len)
{
	static char	*str = NULL;

	if (str == NULL)
	{
		str = (char*)malloc(1);
		if (str == NULL)
			return (0);
		*str = 0;
	}
	if (i == 0)
		str = ft_strjoin_free(str, s);
	else if (len == 0)
	{
		len = ft_strlen(str);
		ft_changeworld(str);
		write(1, str, len);
	}
	else
		ft_putnstr(str, len);
	if (i == 1)
		ft_strdel(&str);
	return (len);
}
