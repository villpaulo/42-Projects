; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/15 17:19:13 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/15 17:19:13 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;
section	.data
			buffer times 255 db 0
			bsize equ $ - buffer

section	.text
global	_ft_cat

_ft_cat:
push rdi
mov r9, rdi
jmp boucle

boucle:

mov rax, 0x2000003
mov rdi, r9
lea rsi, [rel buffer]
mov rdx, bsize
syscall
cmp rax, 1
jne fin
mov rax, 0x2000004
mov rdi, 1
lea rsi, [rel buffer]
mov rdx, bsize
syscall
cmp rax, -1
je fin
jmp boucle

fin:
pop 	rdi
mov 	rax, 0
ret
