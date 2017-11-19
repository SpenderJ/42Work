# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 09:31:51 by juspende          #+#    #+#              #
#    Updated: 2017/07/18 01:38:42 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		ft_display_file

SRCS	=		srcs/ft_putstr.c	\
				srcs/ft_putchar.c	\
				srcs/ft_putsterr.c	\
				srcs/main.c

OBJS	=		$(SRCS:.c=.o)

CC		=		CC

CFLAGS	=		-I ./includes/ -Wall -Wextra -Werror

RM		=		rm -f

CLEAN	=		clean

all		:
				@make $(NAME)

$(NAME)	:		$(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean	:
				$(RM) $(OBJS)

fclean	:		clean
				$(RM) $(NAME)

re		:		fclean all
