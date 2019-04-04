# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 14:09:02 by juspende          #+#    #+#              #
#    Updated: 2019/04/03 18:37:08 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	ft_ssl

RM		=	rm -f

SRC		=	srcs/ft_ssl.c 			\
			srcs/get_next_line.c	\

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
	@echo "\n\n\033[36m[ft_ssl Project:]\033[0m\n\n"
	@echo "\n\033[33m[Compiling Files]\033[0m\n"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) ./libft/libft.a ./free_all/libfree.a
	@echo "$(NAME): exe \033[32m[✔]\033[0m"

clean:
	@echo "\n\033[33m[Cleaning Workspace]\033[0m\n"
	@make clean -C libft/
	@make clean -C free_all/
	@$(RM) $(OBJ)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"

fclean: clean
	@echo "\n\033[33m[Removing Executables]\033[0m\n"
	@make fclean -C libft/
	@make fclean -C free_all/
	@$(RM) $(NAME) srcs/*.d
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re ft_ssl
