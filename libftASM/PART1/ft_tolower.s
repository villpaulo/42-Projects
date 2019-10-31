; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/13 12:39:25 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/13 12:39:25 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_tolower

_ft_tolower:
	cmp rdi, 0
	je false
	cmp rdi, 65
	jl false
	cmp rdi, 90
	jle true
	jmp false

false:
	mov rax, rdi
	ret

true:
	mov rax, rdi
	add rax, 32
	ret

