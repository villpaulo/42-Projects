#include "list.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

t_list	*add_new_element(char *str)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	new->str = str;
	new->next = NULL;
	return (new);
}

t_list	*push_list(t_list *list, t_list *new)
{
	t_list *tmp;

	if (list == NULL)
	{
		list = new;
		return (list);
	}
	tmp = list;
	while (tmp->next)
	{
		printf("1\n");
		tmp = tmp->next;
	}
	tmp->next = new;
	return (list);
}

void	print_list(t_list *list)// tester en se baladant directement sur list, tmp est normallement inutile (void)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		ft_putstr(tmp->str);
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		t_list *list;
		int i;

		i = 1;
		list = NULL;
		while (av[i])
		{
			list = push_list(list, add_new_element(av[i]));
			i++;
		}
		print_list(list);
		//free_list(list);
	}
	write(1, "\n", 1);
	return (0);
}
