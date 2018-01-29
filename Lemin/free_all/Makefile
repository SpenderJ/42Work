# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 13:06:32 by juspende          #+#    #+#              #
#    Updated: 2018/01/27 18:46:43 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

RM	= rm -f

NAME	= libfree.a

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -O3

INCLUDE	= /include/ft_freeall.h

%.o: %.c
		@gcc $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

SRCS	=	srcs/ft_freeall.c				\

all:	$(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo  "$(NAME): exe \033[32m[✔]\033[0m"

clean:
	@$(RM) $(OBJS)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "$(NAME): $@ \033[32m[✔]\033[0m"

re:	fclean all

.PHONY:	all clean fclean re
