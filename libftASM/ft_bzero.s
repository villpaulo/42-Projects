; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzzero.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/13 11:44:58 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/13 11:44:58 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;


section	.text
global	_ft_bzero

_ft_bzero:
	xor	rcx, rcx

loop:
	cmp	rcx, rsi
	jge	end
	mov	byte [rdi], 0
	inc	rdi
	inc	rcx
	jmp	loop

	end:
ret
