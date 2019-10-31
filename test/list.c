#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_list
{
	char *str;
	int length;
	struct s_list *next;
}		t_list;

int		ft_strlen(char *s)
{
	return (*s ? ft_strlen(++s) + 1 : 0);
}

t_list		*push_list(t_list *list, t_list *new)
{
	if (new == NULL)
		return NULL;
	if (list == NULL)
	{
		list = new;
		return (list);
	}

	t_list *tmp;

	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}

t_list		*create_list(char *str)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	new->str = str;
	new->length = ft_strlen(str);
	new->next = NULL;
	return (new);

}

void		display_list(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		printf("string =%s\n", tmp->str);
		printf("string =%d\n", tmp->length);
		tmp = tmp->next;
	}
}


void		free_list(t_list *list)
{
	t_list *tmp;

	tmp = NULL;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}


int		main(int ac, char **av)
{
	t_list *list;
	list = NULL;
	int i;

	i = 1;
	while (i < ac)
	{
		list = push_list(list, create_list(av[i]));
		i++;
	}
	display_list(list);
	free_list(list);
	return (0);
}
