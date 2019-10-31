; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_islower.s                                     :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: pvillene <marvin@42.fr>                    +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/05/15 14:20:26 by pvillene          #+#    #+#              #
;    Updated: 2015/05/15 14:20:26 by pvillene         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

section .text
	global ft_islower

_ft_toupper:
	cpm rdi, 97
	jl false
	cmp rdi, 122
	jle true
	jmp false

false:
	mov, rax 0
	ret
true:
	mov, rax 1
	ret

