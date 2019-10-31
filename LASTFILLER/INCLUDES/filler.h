/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 18:16:08 by pvillene          #+#    #+#             */
/*   Updated: 2016/09/08 13:38:21 by pvillene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <fcntl.h>

typedef struct	s_coor
{
	int			s;
	int			i[2];
	char		**tab;
	int			x;
	int			p[5];
	int			ret[2];
	char		**pi;
	int			ret2;
	int			recup[2];
	char		player;
	char		inv;
}				t_coor;

typedef	struct	s_result
{
	int			solv;
	int			k2[2];
	int			savec;
	int			c;
	int			s;
}				t_res;

void			filler(char *str, char p, t_coor *z);
void			searchp(char *p, char *inv, char *str);
t_coor			*parse(t_coor *z, char *str);
void			modifmap(char **tab);
void			initz(t_coor *z);
t_coor			*iniplateau(t_coor *z, char *str);
t_coor			*parsemap(t_coor *z, char *str);
t_coor			*findc(t_coor *z, char *str, char c);
t_coor			*searchpoint(t_coor *z, char p);
t_coor			*findposinv(t_coor *z, char inv);
t_coor			*findposp(t_coor *z, char p);
void			error_exit(char *str);
void			freez(t_coor *z);
t_coor			*find(int x, int y, t_coor *z);
int				calcul(int x, int y, int x2, int y2);
t_coor			*parsepi(t_coor *z, char *str);
t_coor			*result(t_coor *z, char p);
t_coor			*modifline(int i, int j, t_coor *z);
int				solution(t_coor *z, int i, int j, char p);
int				solution2(t_res *res, t_coor *z, char p);
int				solution3(t_res *res, t_coor *z, int rep, char p);
int				repair(int b, t_res *res, t_coor *z, int *i);
t_res			*initres(t_res *z, int i, int j);
t_res			*initres2(t_res *z, int i, int j);
int				repairresult1(t_coor *z, int p, int modif);
int				repairresult2(t_coor *z, int p, int modif);
int				repairresult3(t_coor *z, int p, int modif);
void			print_result(t_coor *z);
void			*singleton(void *ptr, int key);
t_coor			*repairparsepi(t_coor *z);
char			*funread(char *str);
void			changepiece(t_coor *z);
int				changepiece2(t_coor *z);
char			**getlines(char **tab, int size, char *str, int sub);
char			**changepi(char **tab, t_coor *z);
int				findfirstlineofpi(char **tab);
int				checkmap(char **tab);

#endif
