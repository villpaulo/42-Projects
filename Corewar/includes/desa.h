/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desa.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:48:21 by pibenoit          #+#    #+#             */
/*   Updated: 2017/02/11 18:48:23 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESA_H
# define DESA_H
# include "op.h"

typedef struct	s_flags
{
	char		file;
	char		hexa;
	char		txt;
	char		intro;
	char		align;
	char		trad;
	t_header	header;
}				t_flags;

/*
**	desa.c
*/

void			ft_init(t_flags *f);
void			ft_check_flags(t_flags *flags, char **av, int *i);
int				ft_read(char *filename, char **str, t_flags *f);

/*
**	ft_add_intro.c
*/

char			*ft_add_intro(t_flags *flags);

/*
**	ft_puthexa.c
*/

void			ft_hexa(unsigned char *nb);
char			*ft_translate(char *str, int ret);
void			ft_copy(char *str, int i);
unsigned int	ft_give_hexa(char a, char b);
int				ft_analyse(char *str, int i, unsigned int c, unsigned int d);

/*
**	ft_autre.c
*/

void			ft_put_endl(char *str);
char			*ft_give_instruct(int i);
void			ft_help(void);

/*
**	ft_libft.c a supprimer
*/

int				ft_strlen(char *str);

/*
**	ft_param.c
*/

char			*ft_give_reg(char *s, int i);
char			*ft_give_dir(char *s, int i, int nb);
char			*ft_give_ind(char *str, int i);
char			*ft_give_str_dparam(char *str, int i, int nb, int ocp);
char			*ft_give_str_tparam(char *str, int i, int nb, int ocp);

/*
**	ft_write.c
*/

char			*ft_give_param(char *str, int index, int nb, int code);
char			*ft_change(char *str);
void			ft_add_translate(char ***tab, t_flags *flags);
int				ft_open(char *filename);
void			ft_write(int ret, char *filename, char *str, t_flags *flags);

/*
**	libft
*/

char			*ft_itoa(int nb);
char			*ft_strdup(char *s1);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoin_fs1(char *s1, const char *s2);
char			*ft_strjoin_fs1s2(char *s1, char *s2);
char			*ft_strjoin_fs1s2v(char *s1, char *s2);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcatf(char *s1, char *s2);
char			**ft_strsplit(char *str, char c);
char			*ft_join(char **tab);

#endif
