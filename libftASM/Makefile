# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvillene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 14:41:43 by pvillene          #+#    #+#              #
#    Updated: 2015/05/25 17:35:14 by pvillene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

NASM = /nfs/zfs-student-3/users/2014/pvillene/.brew/Cellar/nasm/2.11.06/bin/nasm

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FLAGS = -f macho64

SOURCES = ft_isalnum.s\
		  ft_isalpha.s\
		  ft_isdigit.s\
		  ft_isascii.s\
		  ft_isprint.s\
		  ft_toupper.s\
		  ft_tolower.s\
		  ft_puts.s\
		  ft_strlen.s\
		  ft_bzero.s\
		  ft_strcat.s\
		  ft_memset.s\
		  ft_memcpy.s\
		  ft_strdup.s\
		  ft_cat.s\
		  ft_isallower.s\
		  ft_islower.s\
		  ft_isupper.s\
		  ft_strchr.s\
		  ft_isspace.s\

OBJS = $(SOURCES:.s=.o)

.PHONY: all clean fclean re
.SILENT: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
%.o: %.s
	$(NASM) $(FLAGS) $<

test : $(NAME) main.c
	$(CC) $(CFLAGS) main.c -L . -lfts


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
