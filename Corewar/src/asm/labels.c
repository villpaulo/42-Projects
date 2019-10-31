/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <pvillene@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:58:59 by pvillene          #+#    #+#             */
/*   Updated: 2016/12/13 17:21:53 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int		is_good_label_character(char c)
{
	int		i;
	char	*characters;

	characters = LABEL_CHARS;
	i = 0;
	while (characters[i])
	{
		if (characters[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int				create_label(t_asm *env, t_reader *reader, int size)
{
	t_label		*label;
	char		*line;
	int			i;

	label = malloc(sizeof(t_label));
	label->location = NULL;
	label->name = malloc(sizeof(char) * (size + 2));
	i = -1;
	line = reader->line;
	while (++i < size)
	{
		if (!is_good_label_character(line[i]))
		{
			ERROR(BAD_LABEL(reader->index, line[i]));
			free(label->name);
			free(label);
			return (0);
		}
		label->name[i] = reader->line[i];
	}
	label->name[i] = '\0';
	ft_lstpushback(&env->labels, label, sizeof(t_label));
	return (1);
}

void			update_labels(t_lst *labels, t_lst *cmd)
{
	t_label		*label;

	if (!labels)
		return ;
	while (labels)
	{
		label = labels->data;
		if (!label->location)
			label->location = cmd;
		labels = labels->next;
	}
}
