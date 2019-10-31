/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 18:17:32 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/10 01:18:34 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

char		*ft_strjoin_free(char *s1, char *s2)
{
	unsigned int		t[4];
	char				*s3;

	ft_memset(t, 0, 16);
	t[2] = ft_strlen(s1);
	t[3] = ft_strlen(s2);
	s3 = (char*)malloc(sizeof(char) * (t[2] + t[3] + 1));
	if (s3 == NULL)
		return (NULL);
	while (t[0] <= t[2] && s1[t[0]] != '\0')
	{
		s3[t[0]] = s1[t[0]];
		t[0]++;
	}
	while (t[1] <= t[3] && s2[t[1]] != '\0')
	{
		s3[t[0]] = s2[t[1]];
		t[0]++;
		t[1]++;
	}
	s3[t[0]] = '\0';
	free(s1);
	free(s2);
	return (s3);
}
