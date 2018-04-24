# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 14:09:02 by juspende          #+#    #+#              #
#    Updated: 2018/04/24 13:03:44 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= vm

NAME2	= asm

RM		=	rm -f

SRC2	=	SRCS_ASM/check_code.c \
			SRCS_ASM/check_filedots.c \
			SRCS_ASM/check_head.c \
			SRCS_ASM/check_ins.c \
			SRCS_ASM/check_ins2.c \
			SRCS_ASM/errors.c \
			SRCS_ASM/ft_label.c \
			SRCS_ASM/ft_label2.c \
			SRCS_ASM/ft_opdir.c \
			SRCS_ASM/ins.c \
			SRCS_ASM/ins2.c \
			SRCS_ASM/ins3.c \
			SRCS_ASM/ins4.c \
			SRCS_ASM/ins5.c \
			SRCS_ASM/ins6.c \
			SRCS_ASM/ins7.c \
			SRCS_ASM/ins8.c \
			SRCS_ASM/main.c \
			SRCS_ASM/utils.c \
			SRCS_ASM/write.c

SRC		=	SRCS_VM/arena.c \
			SRCS_VM/inner_parser.c \
			SRCS_VM/main.c \
			SRCS_VM/outer_parser.c \
			SRCS_VM/player_builder.c \
			SRCS_VM/player_builder_set_number.c \
			SRCS_VM/utils.c \
			SRCS_VM/utils2.c

OBJ			= $(SRC:.c=.o)

OBJ2		= $(SRC2:.c=.o)

DEPS		= $(OBJ:.o=.d)

DEPS2		= $(OBJ2:.o=.d)

INCLUDE		= /includes/

CC			= gcc

CFLAGS		= -Wall -Wextra

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE) -MM -MT $@ -MF $(patsubst %.o,%.d,$@) $<
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

all: corewar $(NAME) $(NAME2)

corewar:
	@echo "\n\n\033[36m[Corewar Project:]\033[0m\n\n"

$(NAME): $(OBJ)
	@echo "\n\033[33m[Compiling Files]\033[0m\n"
	@make -C libft/
	@make -C printf/
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) ./libft/libft.a ./printf/libftprintf.a
	@echo "$(NAME): exe \033[32m[✔]\033[0m"

$(NAME2): $(OBJ2)
	@$(CC) $(CFLAGS) $(SRC2) -o $(NAME2) ./libft/libft.a ./printf/libftprintf.a
	@echo "$(NAME2): exe \033[32m[✔]\033[0m"
	@echo "\n\n\033[31m[Compilation Ended Succesfully]\033[0m\n"

clean:
	@echo "\n\033[33m[Cleaning Workspace]\033[0m\n"
	@make clean -C libft/
	@make clean -C printf/
	@$(RM) $(OBJ)
	@$(RM) $(OBJ2)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"
	@echo "$(NAME2): $@ \033[32m[✔]\033[0m"

fclean: clean
	@echo "\n\033[33m[Removing Executables]\033[0m\n"
	@make fclean -C libft/
	@make fclean -C printf/
	@$(RM) $(NAME)
	@$(RM) $(NAME2)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"
	@echo "$(NAME2): $@ \033[32m[✔]\033[0m"

re: corewar fclean all

-include $(DEPS)
-include $(DEPS2)

.PHONY: all clean fclean re corewar
