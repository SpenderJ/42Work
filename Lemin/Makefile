# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 17:29:07 by juspende          #+#    #+#              #
#    Updated: 2017/12/26 13:36:53 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS  =  -Wall -Wextra -Iinclude

CC	= gcc

RM	= rm -f

NAME	= lem_in

SRCS	=	src/main.c \
		src/getnextline.c \
		src/rank.c \
		src/parsing.c \
		src/parcour.c \
		src/tell_me.c \
		src/list_op.c \
		src/list_op2.c \
		src/tool.c \
		src/tool2.c \
		src/my_str_to_wordtab.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	@make -C printf/
	$(CC) $(OBJS) -o $(NAME) ./printf/libftprintf.a

clean :
	@make clean -C printf/
	$(RM) $(OBJS)

fclean : clean
	@make fclean -C printf/
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
