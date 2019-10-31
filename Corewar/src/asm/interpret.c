/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 02:53:23 by pvillene          #+#    #+#             */
/*   Updated: 2017/02/11 17:53:35 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			interpret(t_asm *env)
{
	char	*s1;
	int		road;
	int		fd;
	t_lst	*lst;

	lst = env->cmd;
	s1 = strbytec(NULL, env);
	ft_memcpy(s1, &env->header, sizeof(t_header));
	road = 0;
	while (lst)
	{
		fillstr(s1 + (((t_cmd *)lst->data)->size_idx + 2192),
			lst->data, env->op, env->labels);
		if (lst->next)
			lst = lst->next;
		if (lst != NULL && lst->next == NULL)
			break ;
	}
	if (!((t_cmd *)lst->data))
		return (0);
	road = ((t_cmd*)lst->data)->size_idx + ((t_cmd *)lst->data)->size + 2192;
	fd = newfile(env->filename);
	write(fd, s1, road);
	close(fd);
	return (1);
}

char		*strbytec(char *s1, t_asm *env)
{
	int		i;
	int		j;
	int		c;

	c = -1;
	i = ((t_header)env->header).prog_size;
	j = 0;
	while (++c < 4)
	{
		j = j * 0x100 + (i & 0xff);
		i = i >> 8;
	}
	s1 = (char *)malloc((sizeof(char) * (j + 1)) + sizeof(t_header));
	ft_bzero((void *)s1, j);
	return (s1);
}

void		fillstr(char *s1, t_cmd *data, t_op2 *op, t_lst *labels)
{
	int		ocp;
	int		i;
	int		j;

	j = 0;
	i = 1;
	s1[0] = (char)data->code;
	if ((ocp = (findocp(data->name, op)) != 0))
		i++;
	singleown(data->size_idx, 0);
	while ((size_t)i < data->size)
	{
		if (ocp != 0)
		{
			data->args[j].type = changeargtype(data->args[j].type);
			s1[1] = (s1[1] << 2) + data->args[j].type;
			if (j == (data->nargs - 1))
				while (!(ocpright(s1[1])))
					s1[1] <<= 2;
		}
		s1 = findargs(labels, data->args[j], &i, s1);
		if (s1 == NULL)
			exit(0);
		j++;
	}
}

int			newfile(char *filename)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(filename) + 3));
	ft_strcpy(str, filename);
	if (!ft_strlcmp(str, ".s"))
	{
		ft_putstr("not .s file\n");
		exit(0);
	}
	while (str[i])
		i++;
	i -= 2;
	ft_strcpy(str + i, ".cor");
	fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	free(str);
	if (fd == -1)
		exit(0);
	return (fd);
}

int			singleown(int i, int b)
{
	static int r;

	if (b == 0)
		r = i;
	return (r);
}
