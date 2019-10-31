/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 19:01:01 by pibenoit          #+#    #+#             */
/*   Updated: 2017/02/11 19:01:03 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H

# define FUNCTIONS_H

int					init(t_asm *a, int b, char **c);

int					parse(t_asm *a);
int					parse_header(t_asm *a, t_reader *b);
int					parse_commands(t_asm *a, t_reader *b);
int					copy_section(char *a, t_reader *b);
int					verify_op(t_reader *a, t_cmd *b, t_op2 c);
int					add_null_terminator(t_asm *a);

int					create_label(t_asm *a, t_reader *b, int c);
void				update_labels(t_lst *a, t_lst *b);

int					init_reader(t_reader *a, char *b);
void				skip_whitespace(t_reader *a);
int					simple_read(t_reader *a);
int					clean_read(t_reader *a);
void				del_reader(t_reader *a);

void				free_env(t_asm *a);
int					is_comment(char a);
int					verify_args(t_cmd *a, t_op2 b, int c);

int					interpret(t_asm *env);
char				*strbytec(char *s1, t_asm *env);
void				fillstr(char *s1, t_cmd *data, t_op2 *op, t_lst *labels);
int					newfile(char *filename);
int					findocp(char *name, t_op2 *op);
char				*findargs(t_lst *labels, t_arg args, int *i, char *s1);
char				*filldir(t_arg args, char *s1, t_lst *labels, int *i);
char				retreg(int already_done);
int					findlabels(t_arg args, t_lst *labels, int lol);
char				*memrevcpy(char *dest, char *source, size_t n, int *i);
int					checkargs(t_arg args, t_lst *labels);
int					ocpright(char c);
int					singleown(int i, int b);
int					changeargtype(int i);
int					ft_strlcmp(char *str, const char *comp);

#endif
