# **************************************************************************** #
#                                                                              # :::      ::::::::    # Makefile                                           :+:      :+:    :+:    # +:+ +:+         +:+      # By: pvillene <marvin@42.fr>                    +#+  +:+       +#+         # +#+#+#+#+#+   +#+            # Created: 2014/11/28 05:31:53 by pvillene          #+#    #+#              # Updated: 2016/04/06 17:14:56 by pvillene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Werror -Wall -Wextra -Oz

SRCS =	parse.c \
		fonction.c \
		fonctionprint.c \
		repair.c \
		repair2.c \
		conver.c \
		fonction2.c \
		ret.c \
		flagd.c \
		repair3.c \
		parse2.c \
		norme.c \
		parse3.c \
		conver2.c \
		fonction3.c \
		fonction4.c \
		flagd2.c \
		repair4.c \
		repair5.c \
		fonctionprint2.c \
		fonctionprint3.c \
		fonctionprint4.c \
		fonctionprint5.c \
		fonctionprint6.c \
		ret2.c \
		ret3.c \

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS): $(SRCS) printf.h
	@$(CC) $(CFLAGS) -c $(SRCS)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)


clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
