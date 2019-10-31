/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:03:00 by pvillene          #+#    #+#             */
/*   Updated: 2016/12/06 19:25:39 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct		s_elem
{
	int ants;
	int b;
}					t_elem;

typedef struct		s_room
{
	int				es;
	char			*place;
	int				coord[2];
	void			*links;
	char			*ants;
	int				i;
}					t_room;

typedef struct		s_link
{
	void			*lk;
	struct s_link	*next;
}					t_link;

t_link				*parse(char *str, t_link *link, t_elem *elem);
t_link				*push_list(t_link *link, t_link *toto);
t_link				*parse_room(char *str, t_elem *elem);
void				print_link(t_link *link);
int					checktunnel(char *str, t_link *link);
int					parsetunnel(t_link *link, char *str);
int					push_rooms(t_room *r1, t_room *r2);
void				push_links(t_link *links, t_room *room);
void				print_inside_links(t_link *link);
int					findstr(char *str, char *hide);
t_link				*findstarter(t_link *link);
t_link				*resolv(t_link *link);
void				search(t_link *tmp, int i);
int					count_room(t_link *link);
void				print_ret(t_link *ret);
t_link				*shortway(t_link *link);
int					possibility(t_link *link);
void				print_path(t_link *path, t_elem *elem);
t_room				*copyroom(t_room *src);
t_link				*makepath(t_link *link);
t_room				*newpath(t_link *tmp, int c);
void				readpath(t_link *toto);
void				print_paths(t_link *paths, int ants, char *end, int nb);
char				*print(t_room *room, char *end);
void				checkpaths(t_room *room, char *end);
char				*findend(char *end, t_link *link);
int					useornot(t_link *paths, t_room *r2, int ants);
void				newant(t_room *room, char *end, int *nb, int *ants);
int					finish(t_link *paths);
void				moveants(t_room *room, char *t1, char *t2);
int					error(void);
int					findtheend(t_link *link);
t_link				*findendroom(t_link *link);
void				free_all(t_link *link, char *end);
t_link				*searchpath(t_link *paths);
t_room				*onepath(t_link *link);

#endif
