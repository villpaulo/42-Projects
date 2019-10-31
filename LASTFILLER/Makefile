# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvillene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/28 05:31:53 by pvillene          #+#    #+#              #
#    Updated: 2016/09/08 13:39:51 by pvillene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = ./parse.c\
	  ./main.c\
	  ./result.c\
	  ./searchpoint.c\
	  ./fonction.c\
	  ./get_next_line.c\
	  ./fonction2.c \
	  ./fonction3.c \

OBJ = $(SRC:.c:.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):
	@/bin/echo "-----Compilating sources-----"
	@make -C ./libft
	@/bin/echo "---Done---"
	@/bin/echo "-----Creating executable-----"
	@gcc $(FLAGS) -I./INCLUDES/filler.h -L./libft -lft -o $(NAME) $(SRC)
	@/bin/echo "---Done---"

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft

fclean:
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
