; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/13 12:39:25 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/13 12:39:25 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_toupper

_ft_toupper:
	cmp rdi, 0
	je false
	cmp rdi, 97
	jl false
	cmp rdi, 122
	jle true
	jmp false

false:
	mov rax, rdi
	ret

true:
	mov rax, rdi
	sub rax, 32
	ret
