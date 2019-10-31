; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/14 13:42:59 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/14 13:42:59 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .data
	null:
		.string deb "(null)"
section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push rdi
	cmp rdi 0
	je	nul
	pop rsi
	call _ft_strlen
	mov rcx, rax
	mov rdi, 1
	mov rax, 0x2000004
	syscall
	jmp finish

nul:
	mov rdi 1
	lea rsi [rel null.string]
	mov rcx, 6;
	mov rax, 0x2000004
	syscall
	
finish:
	push 0xa
	mov rdi, 1
	mov rcx, 1
	pop rsi
	mov rax, 0x2000004
	syscall
	ret	
