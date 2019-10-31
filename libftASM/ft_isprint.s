; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/13 12:34:11 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/13 12:34:11 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_isprint
_ft_isprint:
	cmp rdi, 32
	jl false
	cmp rdi, 126
	jg false
	mov rax, 1
	ret
false:
	mov rax, 0
	ret
