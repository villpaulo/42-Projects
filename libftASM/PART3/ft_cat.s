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

%define SYSTEMECALL(nb) 0x200000 | nb
%define OPEN  5
%define WRITE 4
%define READ  3
%define EXIT  1

section .bsq
	data:


section .text
	global _ft_cat
	extern _ft_strlen

_ft_cat:
	
