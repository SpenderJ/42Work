# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 14:09:02 by juspende          #+#    #+#              #
#    Updated: 2019/03/29 10:01:48 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	npuzzle

RM		=	rm -f

SRC		=	srcs/npuzzle.c \
			srcs/error_handler.c \
			srcs/npuzzle_parser.c \
			srcs/hamming.c \
			srcs/sfio.c

OBJ			= $(SRC:.c=.o)

DEPS		= $(OBJ:.o=.d)

INCLUDE		= /includes

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE) -MM -MT $@ -MF $(patsubst %.o,%.d,$@) $<
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "\n\n\033[36m[Npuzzle Project:]\033[0m\n\n"
	@echo "\n\033[33m[Compiling Files]\033[0m\n"
	@make -C libft/
	@make -C printf/
	@make -C free_all/
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) ./libft/libft.a ./printf/libftprintf.a ./free_all/libfree.a
	@echo "$(NAME): exe \033[32m[✔]\033[0m"

clean:
	@echo "\n\033[33m[Cleaning Workspace]\033[0m\n"
	@make clean -C libft/
	@make clean -C printf/
	@make clean -C free_all/
	@$(RM) $(OBJ)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"

fclean: clean
	@echo "\n\033[33m[Removing Executables]\033[0m\n"
	@make fclean -C libft/
	@make fclean -C printf/
	@make fclean -C free_all/
	@$(RM) $(NAME) srcs/*.d
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re npuzzle
