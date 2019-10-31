# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvillene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/28 05:31:53 by pvillene          #+#    #+#              #
#    Updated: 2016/10/27 13:44:46 by pvillene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCF = src/
SRC = 	main.c\
	  	parse.c\
	  	parsetunnel2.c\
	  	util.c\
		algo.c\
		path.c \
		solution.c \
		util2.c \

OBJ = $(SRC:.c:.o)

SRCS = $(addprefix $(SRCF), $(SRC))

INCS = -I inc/ -I libft/

FLAGS = -Wall -Werror -Wextra

LIB = -L libft -lft

all : $(NAME)

$(NAME):
	@/bin/echo "-----Compilating sources-----"
	@make -C ./libft
	@/bin/echo "---Done---"
	@/bin/echo "-----Creating executable-----"
	@gcc $(FLAGS) $(SRCS) -o $(NAME) $(INCS) $(LIB)
	@/bin/echo "---Done---"

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft

fclean:
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
