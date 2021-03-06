# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 14:09:02 by juspende          #+#    #+#              #
#    Updated: 2018/01/30 13:18:44 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

NAME2	= checker

RM		=	rm -f

SRC2	=	check/srcs/checker.c			\
			check/srcs/moves/swap.c			\
			check/srcs/moves/push.c			\
			check/srcs/moves/rotate.c		\
			check/srcs/moves/reverse.c		\
			check/srcs/get_next_line.c

SRC		=	pushswap/srcs/push_swap.c		\
			pushswap/srcs/algo.c			\
			pushswap/srcs/free.c			\
			pushswap/srcs/ds.c				\
			pushswap/srcs/moves/swap.c		\
			pushswap/srcs/moves/push.c		\
			pushswap/srcs/moves/rotate.c	\
			pushswap/srcs/buffer.c			\
			pushswap/srcs/moves/reverse.c

OBJ			= $(SRC:.c=.o)

OBJ2		= $(SRC2:.c=.o)

DEPS		= $(OBJ:.o=.d)

DEPS2		= $(OBJ2:.o=.d)

INCLUDE		= /includes

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE) -MM -MT $@ -MF $(patsubst %.o,%.d,$@) $<
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

all: pushswap $(NAME) $(NAME2)

pushswap:
	@echo "\n\n\033[36m[PushSwap Project:]\033[0m\n\n"

$(NAME): $(OBJ)
	@echo "\n\033[33m[Compiling Files]\033[0m\n"
	@make -C libft/
	@make -C printf/
	@make -C free_all/
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) ./libft/libft.a ./printf/libftprintf.a ./free_all/libfree.a
	@echo "$(NAME): exe \033[32m[✔]\033[0m"

$(NAME2): $(OBJ2)
	@$(CC) $(CFLAGS) $(SRC2) -o $(NAME2) ./libft/libft.a ./printf/libftprintf.a ./free_all/libfree.a
	@echo "$(NAME2): exe \033[32m[✔]\033[0m"
	@echo "\n\n\033[31m[Compilation Ended Succesfully]\033[0m\n"

clean:
	@echo "\n\033[33m[Cleaning Workspace]\033[0m\n"
	@make clean -C libft/
	@make clean -C printf/
	@make clean -C free_all/
	@$(RM) $(OBJ)
	@$(RM) $(OBJ2)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"
	@echo "$(NAME2): $@ \033[32m[✔]\033[0m"

fclean: clean
	@echo "\n\033[33m[Removing Executables]\033[0m\n"
	@make fclean -C libft/
	@make fclean -C printf/
	@make fclean -C free_all/
	@$(RM) $(NAME)
	@$(RM) $(NAME2)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"
	@echo "$(NAME2): $@ \033[32m[✔]\033[0m"

re: pushswap fclean all

-include $(DEPS)
-include $(DEPS2)

.PHONY: all clean fclean re pushswap
