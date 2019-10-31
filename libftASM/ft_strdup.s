; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/15 13:44:04 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/15 13:44:04 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strdup
	extern _ft_memcpy
	extern _ft_strlen
	extern _malloc

_ft_strdup:
	mov rbx, rdi
	call _ft_strlen
	mov rdi, rax
	inc rdi
	push rdi
	call _malloc
	cmp rax, 0
	je fin
	mov rdi, rax
	mov rsi, rbx
	pop rdx
	call _ft_memcpy
	
fin:
	ret
