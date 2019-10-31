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

section	.data
msg:
db "(null)"

section	.text
global	_ft_puts
extern	_ft_strlen

_ft_puts:
	cmp	rdi, 0
	je	_null

	; write rdi
	push	rdi
	call	_ft_strlen
	mov	rdx, rax
	pop	rsi
	mov	rdi, 1
	mov	rax, 0x2000004
	syscall
	jc error
	jmp	_newl

_null:
; write "(null)"
	lea	rsi, [rel msg]
	mov	rdx, 6
	mov	rdi, 1
	mov	rax, 0x2000004
	syscall
	jc error

_newl:
; write new-line character
	; rsp est egal au dernier push
	push	0xa
	mov	rsi, rsp
	mov	rdx, 1
	mov	rdi, 1
	mov	rax, 0x2000004
	syscall
	jc error
	pop	rax
	ret

error:
	mov rax, -1
	leave
	ret

