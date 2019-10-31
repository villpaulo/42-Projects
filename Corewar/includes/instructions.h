/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:14:31 by pbenoit           #+#    #+#             */
/*   Updated: 2017/02/09 00:14:38 by pbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "corewar.h"

# define PARAM_ERROR 0

int			ft_live(t_env *env, t_process *process);
int			ft_ld(t_env *env, t_process *process);
int			ft_st(t_env *env, t_process *process);
int			ft_add(t_env *env, t_process *process);
int			ft_sub(t_env *env, t_process *process);
int			ft_and(t_env *env, t_process *process);
int			ft_or(t_env *env, t_process *process);
int			ft_xor(t_env *env, t_process *process);
int			ft_zjump(t_env *env, t_process *process);
int			ft_ldi(t_env *env, t_process *process);
int			ft_sti(t_env *env, t_process *process);
int			ft_fork(t_env *env, t_process *process);
int			ft_lld(t_env *env, t_process *process);
int			ft_lldi(t_env *env, t_process *process);
int			ft_lfork(t_env *env, t_process *process);
int			ft_aff(t_env *env, t_process *process);

t_process	*init_fork(t_process *process, int dist, unsigned int *num);

int			get_params(int (*tab)[4], uint8_t ocp, int opcode);

int			get_reg(const int *reg, uint8_t index);
int			get_dir(const char *map, int pc);
int			get_ind(const char *map, int pc);
int16_t		get_ind_st(const char *map, int index);
int			get_ind_index(const char *map, int pc);

#endif
