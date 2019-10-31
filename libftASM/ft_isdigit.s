; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/13 12:01:31 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/13 12:01:31 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_isdigit

_ft_isdigit:
	cmp rdi, 0
	je false
	cmp rdi, 48
	jl false
	cmp rdi, 57
	jg false
	jmp true

false:
	mov rax, 0
	ret
true:
	mov rax, 1
	ret
