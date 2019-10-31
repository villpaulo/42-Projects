; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcopy.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/15 16:38:24 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/15 16:38:24 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strcpy
	exter  _ft_strlen

_ft_strcopy:
	call _ft_strlen
	mov rcx rax
	inc rcx
	rep movsb
	mov rax rdi
	ret

	

