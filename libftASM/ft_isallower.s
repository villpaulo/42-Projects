; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isallower.s                                     :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/15 15:36:40 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/15 15:36:40 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_isallower
	extern _ft_islower

_ft_isallower:
	cmp rdi, 0
	je empty
	jmp boucle

boucle:
	call _ft_islower
	cmp rax, 0
	je false
	inc rdi
	cmp rdi, 0
	je true
	jmp boucle


false:
	mov rax, 0
	ret

true:
	mov rax, 1
	ret
	
empty:
	mov rax, rdi
	ret
