; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/13 15:40:47 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/13 15:40:47 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
global _ft_strlen

_ft_strlen:
	xor	rcx, rcx
	not	rcx
	xor	al, al
	cld
	repne	scasb
	not	rcx
	dec	rcx
	mov	rax, rcx
	ret
