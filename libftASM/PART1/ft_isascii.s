; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/13 12:30:11 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/13 12:30:11 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_isascii

_ft_isascii:
	cmp rdi 0
	jl false
	cmp rdi 127
	jg false
	mov rax 1
	ret

false:
	mov rax 0
	ret
