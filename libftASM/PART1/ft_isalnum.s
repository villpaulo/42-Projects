; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/13 12:13:56 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/13 12:13:56 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_isalnum
	externe _ft_isdigit
	externe _ft_isalpha


_ft_isalnum:
	call _ft_isalpha
	cmp rax 1
	je true
	call _ft_isdigit
	cmp rax 1
	je true
	jmp false

true:
	mov rax 1
	ret
false:
	mov rax 0
	ret
	


