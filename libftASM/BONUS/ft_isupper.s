; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/15 16:04:07 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/15 16:04:07 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
		global _ft_isupper

_ft_isupper:
	cmp rdi, 0
	je empty
	cmp rdi, 65
	jl false
	cmp rdi, 90
	jle true
	jmp false

false:
	cmp rax, 0
	ret

true:
	cmp rax, 1
	ret

empty:
	mov rax, rdi
	ret
