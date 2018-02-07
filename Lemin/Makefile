# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 17:29:07 by juspende          #+#    #+#              #
#    Updated: 2018/02/06 17:18:21 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in

RM		= rm -f

SRC		=	lem_in/srcs/main.c			\
			lem_in/srcs/input.c			\
			lem_in/srcs/line.c			\
			lem_in/srcs/move1.c			\
			lem_in/srcs/move2.c			\
			lem_in/srcs/neighbor.c		\
			lem_in/srcs/node.c			\
			lem_in/srcs/parsing.c		\
			lem_in/srcs/pathfinding.c	\
			lem_in/srcs/get_next_line/get_next_line.c

OBJ		= $(SRC:.c=.o)

INCLUDE	= /lem_in/includes

CC		= gcc

DEPS	= $(OBJ:.o=.d)

CFLAGS	= -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE) -MM -MT $@ -MF $(patsubst %.o,%.d,$@) $<
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

all: lem_in $(NAME)

lem_in:
	@echo "\n\n\033[36m[Lem-In Project:]\033[0m\n\n"

$(NAME): $(OBJ)
	@echo "\n\033[33m[Compiling Files]\033[0m\n"
	@make -C libft/
	@make -C printf/
	@make -C free_all/
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) ./libft/libft.a ./printf/libftprintf.a ./free_all/libfree.a
	@echo "$(NAME): exe \033[32m[✔]\033[0m"
	@echo "\n\n\033[31m[Compilation Ended Succesfully]\033[0m\n"

clean :
	@echo "\n\033[33m[Cleaning Workspace]\033[0m\n"
	@make clean -C libft/
	@make clean -C printf/
	@make clean -C free_all/
	@$(RM) $(OBJ)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"

fclean : clean
	@echo "\n\033[33m[Removing Executables]\033[0m\n"
	@make fclean -C libft/
	@make fclean -C printf/
	@make fclean -C free_all/
	@$(RM) $(NAME)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"

re : lem_in fclean all

-include $(DEPS)

.PHONY : all clean fclean re lem_in
