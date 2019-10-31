/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 19:01:10 by pibenoit          #+#    #+#             */
/*   Updated: 2017/02/11 19:01:12 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H

# define STRUCTS_H

# include <asm.h>

typedef struct		s_arg
{
	int				type;
	int				size;
	int				already_done;
	char			*value;
}					t_arg;

typedef struct		s_cmd
{
	int				code;
	int				nargs;
	size_t			size_idx;
	int				op_idx;
	char			ocp;
	size_t			size;
	char			*name;
	t_arg			*args;
}					t_cmd;

typedef struct		s_label
{
	char			*name;
	t_lst			*location;
}					t_label;

typedef struct		s_op2
{
	char			name[OP_NAME_LEN];
	int				args;
	t_arg_type		params[MAX_ARGS_NUMBER];
	int				code;
	int				cycles;
	char			description[OP_NAME_LEN];
	int				octal_encode;
	int				dir_size;
}					t_op2;

typedef struct		s_asm
{
	t_op2			op[17];
	t_lst			*cmd;
	t_lst			*labels;
	char			*filename;
	t_header		header;
}					t_asm;

typedef struct		s_reader
{
	int				fd;
	int				index;
	int				state;
	char			*line;
	char			*origin;
	char			*filename;
}					t_reader;

typedef struct		s_writer
{
	char			*data;
	char			*actual;
	size_t			written;
	size_t			total_size;
}					t_writer;

t_op2				g_op_tab2[17];

#endif
