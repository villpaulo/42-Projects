; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/13 10:37:54 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/13 10:37:54 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_isalpha

_ft_isalpha:
	cmp rdi, 65
	jge comp1
	jmp false

comp1:
	cmp rdi, 90
	jle true
	jmp comp2

comp2:
	cmp rdi, 97
	jge comp3
	jmp false
	
comp3:
	cmp rdi, 122
	jle true
	jmp false

true:
	mov rax, 1
	ret

false:
	mov rax, 0
	ret
	
	

