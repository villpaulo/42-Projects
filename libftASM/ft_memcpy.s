; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/15 19:51:09 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/15 19:51:09 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_memcpy

_ft_memcpy:
	push rdi
	mov rcx, rdx
	cld
	rep movsb
	pop rax
	ret
