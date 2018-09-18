# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 14:09:02 by juspende          #+#    #+#              #
#    Updated: 2018/04/24 13:53:37 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls 

RM		=	rm -f

SRC		=	src/ft_ls.c

OBJ		= $(SRC:.c=.o)

DEPS		= $(OBJ:.o=.d)

INCLUDE		= /includes

CC		= gcc

CFLAGS		= -Wall -Wextra

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE) -MM -MT $@ -MF $(patsubst %.o,%.d,$@) $<
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

all: ls $(NAME) $(NAME2)

ls:
	@echo "\n\n\033[36m[Ft_Ls Project:]\033[0m\n\n"

$(NAME): $(OBJ)
	@echo "\n\033[33m[Compiling Files]\033[0m\n"
	@make -C libft/
	@make -C printf/
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) ./libft/libft.a ./printf/libftprintf.a
	@echo "$(NAME): exe \033[32m[✔]\033[0m"

clean:
	@echo "\n\033[33m[Cleaning Workspace]\033[0m\n"
	@make clean -C libft/
	@make clean -C printf/
	@$(RM) $(OBJ)
	@$(RM) $(DEPS)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"

fclean: clean
	@echo "\n\033[33m[Removing Executables]\033[0m\n"
	@make fclean -C libft/
	@make fclean -C printf/
	@$(RM) $(NAME)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"

re: ls fclean all

-include $(DEPS)

.PHONY: all clean fclean re ls
