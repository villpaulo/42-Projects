; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strchr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/15 18:40:43 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/15 18:40:43 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .data
	null:
		.string db "(null)"
section .text
	global _ft_strchr

_ft_strchr:
	cmp rdi, 0
	je nomatch
	jmp boucle

boucle:
	cmp rdi, 0
	je nomatch
	mov rax, rsi
	cmp byte [rdi], al
	je fin
	inc rdi
	jmp boucle

nomatch:
	lea rax, [rel null.string]
	ret

fin:
	mov rax, rdi
	ret
