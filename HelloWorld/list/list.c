#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "list.h"

int			ft_strlen(char *s)
{
	return (*s ? ft_strlen(++s) + 1 : 0);
}

t_list		*push_list(t_list *list, t_list *new)
{
	t_list *tmp;

	if (list == NULL)
		return (new);
	tmp = list;
	while (tmp)
	{
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	tmp->next = new;
	return (list);
}

t_list		*add_new_element(char *str)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));

	new->data = str;
	new->data_size = ft_strlen(str);
	new->next = NULL;
	return (new);
}

void	insert_list(t_list **list, int x, t_list *new)
{
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	t_list *current_list;

	current_list = *list;
	x -= 1;
	while (x-- > 0)
	current_list = current_list->next;
	new->next = current_list->next;
	current_list->next = new;
}

void	print_list(t_list *list)
{
	if (list != NULL)
	{
		while (list)
		{
			printf("%s ", list->data);
			printf("   taille = %d  \n", list->data_size);
			list = list->next;
		}
	}
}

void	free_list(t_list *list)
{
	t_list *tmp;

	while (list)
	{
		//printf("UNTOUR\n");
		if (list->next == NULL)
			break;
		tmp = list->next;;
		free(list);
		list = tmp;
	}
}

int		main(int ac, char **av)
{
	int i;
	t_list *list;

	list = NULL;
	i = 1;
	if (ac == 1)
		return (0);
	while (av[i + 1])
	{
		list = push_list(list, add_new_element(av[i]));
		i++;
	}
	insert_list(&list, (i/2), add_new_element(av[i]));
	print_list(list);
	free_list(list);
	return (0);
}

