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
 
 cmp rdi, 0
 je empty
 mov rcx, -1
 mov al, 0
 repnz scasb
 neg rcx
 sub rcx -2
 mov rax, rcx
 ret

empty:
mov rax, 0
ret
