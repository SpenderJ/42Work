# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 14:09:02 by juspende          #+#    #+#              #
#    Updated: 2017/12/07 16:51:38 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	filler

RM		=	rm -f

SRC		=	srcs/filler.c			\
			srcs/get_next_line.c	\
			srcs/fill_info_struct.c	\
			srcs/play_1.c			\
			srcs/get_piece.c		\
			srcs/attack.c			\
			srcs/get_map.c			\
			srcs/play_2.c			\

OBJ			= $(SRC:.c=.o)

INCLUDE		= /includes/filler.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -O3

%.o: %.c
			@gcc $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) ./libft/libft.a
	@echo  "$(NAME): exe \033[32m[✔]\033[0m"

clean:
	@make clean -C libft
	@$(RM) $(OBJ)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"

fclean: clean
	@make fclean -C libft/
	@$(RM) $(NAME)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"

re: fclean all

.PHONY: all clean fclean re
