# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvillene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/28 05:31:53 by pvillene          #+#    #+#              #
#    Updated: 2017/07/08 23:12:50 by pvillene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = binex3

SRC = 	./ex3.c\
	./main.c\
	./quicksort.c\

OBJ = $(SRC:.c:.o)

FLAGS = -Wall -Wextra -Werror -std=c99 -g -pedantic -fno-stack-protector -ftest-coverage -fprofile-arcs

all : $(NAME)

$(NAME):
	@/bin/echo "-----Compilating sources-----"
	@/bin/echo "---Done---"
	@/bin/echo "-----Creating executable-----"
	@gcc $(FLAGS) -o $(NAME) $(SRC)
	@/bin/echo "---Done---"
	@/bin/rm -f ex3.gcda ex3.gcno main.gcda main.gcno quicksort.gcno quicksort.gcda
	@/bin/rm -rf binex2.dSYM
clean:
	@/bin/rm -f $(OBJ)

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
