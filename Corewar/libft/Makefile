# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbenoit <pbenoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/24 11:28:26 by pbenoit           #+#    #+#              #
#    Updated: 2017/02/10 21:17:17 by pibenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3 -g

LIBDIR = ./libft
PFDIR = ./ft_printf

#LIBHEADER = $(LIBDIR)libft.h
#SRCHEADER = $(PFDIR)ft_printf.h

LIBOBJ = ft_memchr.o ft_putnbr_fd.o ft_striter.o ft_strnew.o ft_atoi.o\
		 ft_memcmp.o ft_putstr.o ft_striteri.o ft_strnstr.o ft_bzero.o\
		 ft_memcpy.o ft_putstr_fd.o ft_strjoin.o ft_strrchr.o ft_isalnum.o\
		 ft_memdel.o ft_strcat.o ft_strlcat.o ft_strsplit.o ft_isalpha.o\
		 ft_memmove.o ft_strchr.o ft_strlen.o ft_strstr.o ft_isascii.o\
		 ft_memset.o ft_strclr.o ft_strmap.o ft_strsub.o ft_isdigit.o\
		 ft_putchar.o ft_strcmp.o ft_strmapi.o ft_strtrim.o ft_isprint.o\
		 ft_putchar_fd.o ft_strcpy.o ft_strncat.o ft_tolower.o ft_itoa.o\
		 ft_putendl.o ft_strdel.o ft_strncmp.o ft_toupper.o ft_memalloc.o\
		 ft_putendl_fd.o ft_strdup.o ft_strncpy.o ft_memccpy.o ft_putnbr.o\
		 ft_strequ.o ft_strnequ.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o\
		 ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_itoa_base.o ft_putnbr_base.o\
		 ft_iscntrl.o ft_islower.o ft_ispunct.o ft_isspace.o ft_isupper.o\
		 ft_strpbrk.o ft_strsub_f.o ft_strsplit_save.o ft_lltoa.o\
		 ft_lltoa_base.o ft_lltoa_base_min.o ft_putnstr.o ft_putnwstr.o\
		 ft_putwchar.o ft_putwstr.o ft_putxchar.o ft_wcslen.o ft_wcslen_octet.o\
		 ft_wchart_octet.o ft_wcslen_noctet.o ft_putcharx.o ft_putstrz.o\
		 ft_putwstrx.o ft_strjoin_free.o ft_putstrx.o ft_putnwstrx.o\
		 ft_putwcharx.o ft_putnstrx.o ft_putxcharx.o get_next_line.o\
		 ft_lstpushback.o ft_lstaddback.o

PFOBJ = ft_convcc.o ft_convoub.o ft_convpd.o ft_convxx.o ft_geslenmod.o\
		 ft_printf.o ft_convid.o ft_convss.o ft_flag.o ft_print.o\
		 ft_printelse.o ft_wildcard.o ft_printcolor.o ft_gescentr.o

PFLIB = $(LIBOBJ) $(PFOBJ)

all: $(NAME)

$(NAME): $(PFLIB)
	@echo "ALL IS COMPILED"
	@ar rc $(NAME) $(PFLIB)
	@ranlib $(NAME)
	@echo "made" $(NAME)

$(LIBOBJ): %.o: $(addprefix $(LIBDIR)/, %.c)
	@$(CC) -c $(FLAGS) -I $(LIBDIR) $< -o $@

$(PFOBJ): %.o: $(addprefix $(PFDIR)/, %.c)
	@$(CC) -c $(FLAGS) -I $(LIBDIR) -I $(PFDIR) $< -o $@

clean:
	@-/bin/rm -f $(PFLIB)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
