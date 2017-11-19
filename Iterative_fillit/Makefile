# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 13:06:32 by juspende          #+#    #+#              #
#    Updated: 2017/11/16 12:54:18 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

RM	= rm -f

NAME	= fillit

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

INCLUDE	= /includes/fillit.h

%.o: %.c
		gcc $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

SRCS	= srcs/edit_tab.c		\
		  srcs/empty.c			\
		  srcs/get_file.c		\
		  srcs/lst_functions.c	\
		  srcs/resolve.c		\
		  srcs/verification.c	\
		  srcs/succes.c			\
		  srcs/previous.c		\
		  srcs/ft_generator.c

all:	$(NAME)

$(NAME): $(OBJS)
	@make re -C libft/
	@make clean -C libft/
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) ./libft/libft.a
	@make fclean -C libft/
	@echo "done"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
