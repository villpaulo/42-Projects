/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 02:58:19 by pvillene          #+#    #+#             */
/*   Updated: 2017/02/10 19:27:20 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			findocp(char *name, t_op2 *op)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (!(ft_strcmp(op[i].name, name)))
			break ;
		i++;
	}
	if (op[i].octal_encode == 0)
		return (0);
	return (1);
}

char		*findargs(t_lst *labels, t_arg args, int *i, char *s1)
{
	int		t;

	t = *i;
	if (!(checkargs(args, labels)))
		return (NULL);
	if (args.type == 1)
		s1[*i] = (char)args.already_done;
	else if (args.type == 10 || args.type == 2)
		s1 = filldir(args, s1, labels, i);
	else if (args.type == 11 || args.type == 3)
		s1 = filldir(args, s1, labels, i);
	*i = t + args.size;
	return (s1);
}

char		*filldir(t_arg args, char *s1, t_lst *labels, int *i)
{
	int		lol;
	int		c;

	lol = 0;
	c = 0;
	lol = findlabels(args, labels, lol);
	if (lol == 0)
		lol = (int)args.already_done;
	s1 = memrevcpy(s1, (char *)&lol, args.size, i);
	return (s1);
}

char		retreg(int already_done)
{
	char	ret;

	if (already_done > 16 || already_done < 1)
	{
		ft_putstr("bad reg number, must be between 1 and 16\n");
		exit(0);
	}
	ret = (char)already_done;
	return (ret);
}

int			findlabels(t_arg args, t_lst *labels, int lol)
{
	t_lst	*tmp;
	t_label	*instr;
	int		n;

	tmp = labels;
	while (tmp)
	{
		if (!(ft_strcmp(((t_label *)tmp->data)->name, args.value + 2)))
		{
			instr = (t_label*)tmp->data;
			break ;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (0);
	n = singleown(0, 1);
	lol = ((t_cmd *)instr->location->data)->size_idx - n;
	return (lol);
}
