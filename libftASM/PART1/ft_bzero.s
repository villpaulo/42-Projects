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

bal	_ft_bzero

section	.text

_ft_bzero:
	test rdi, rdi
	jz end

loop:
	mov byte [rdi], 0
	inc rdi
	dec rsi
	cmp rsi 0
	je  end
	jmp loop

end:
	ret

