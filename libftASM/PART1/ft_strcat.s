; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcatt.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pvillene <marvin@42.fr>                    +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/13 11:27:00 by pvillene          ;+;    ;+;              ;
;    Updated: 2015/05/13 11:27:00 by pvillene         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;


section .text
	global _ft_strcat

_ft_strcat:
	mov rax, rdi
	jmp while
while:
	cmp byte [rdi], 0
	je copy
	inc rdi
	jmp while

copy:
	cmp byte [rsi], 0
	je end
	movsb
	jmp copy
end:
	ret
	
	

