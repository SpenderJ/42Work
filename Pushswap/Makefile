# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 14:09:02 by juspende          #+#    #+#              #
#    Updated: 2017/12/26 14:39:02 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

NAME2	= checker

RM		=	rm -f

SRC2	=	check/srcs/checker.c

SRC		=	pushswap/srcs/push_swap.c

OBJ			= $(SRC:.c=.o)

OBJ2		= $(SRC2:.c=.o)

INCLUDE		= /includes/push_swap.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -O3

%.o: %.c
			@gcc $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C printf/
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) ./libft/libft.a ./printf/libftprintf.a
	@echo "$(NAME): exe \033[32m[✔]\033[0m"

$(NAME2): $(OBJ2)
	@$(CC) $(CFLAGS) $(SRC2) -o $(NAME2) ./libft/libft.a ./printf/libftprintf.a
	@echo "$(NAME2): exe \033[32m[✔]\033[0m"

clean:
	@make clean -C libft/
	@make clean -C printf/
	@$(RM) $(OBJ)
	@$(RM) $(OBJ2)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"
	@echo "$(NAME2): $@ \033[32m[✔]\033[0m"

fclean: clean
	@make fclean -C libft/
	@make fclean -C printf/
	@$(RM) $(NAME)
	@$(RM) $(NAME2)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"
	@echo "$(NAME2): $@ \033[32m[✔]\033[0m"

re: fclean all

.PHONY: all clean fclean re
