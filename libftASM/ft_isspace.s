# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isspace.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvillene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/25 17:31:44 by pvillene          #+#    #+#              #
#    Updated: 2015/05/25 17:57:10 by pvillene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global	_ft_isspace

section	.text

_ft_isspace:
	cmp	rdi, 32
	je	_true
	cmp	rdi, 9
	jl	_false
	cmp	rdi, 13
	jg	_false
	jmp	_true

_false:
	mov	rax, 0
	ret

_true:
	mov	rax, 1
	ret
