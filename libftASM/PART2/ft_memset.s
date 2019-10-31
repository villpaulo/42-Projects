; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/14 19:33:44 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/14 19:33:44 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
global _ft_memset

_ft_memset:
	push rdi
	mov rcx, rdx
	mov rax, rsi
	cld
	rep stosb
	pop rax
	ret
