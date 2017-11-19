# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 13:06:32 by juspende          #+#    #+#              #
#    Updated: 2017/11/18 17:47:20 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

RM	= rm -f

NAME	= libftprintf.a

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra

INCLUDE	= /include/ft_printf.h

%.o: %.c
		gcc $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

SRCS	=	srcs/ft_printf.c		\
			basic/ft_putint.c		\
			basic/ft_atoi.c			\
			basic/ft_putstr.c		\
			basic/ft_putchar.c		\
			basic/ft_putuint.c		\
			basic/ft_putlong.c		\
			basic/ft_putdouble.c	\
			basic/ft_itoa.c			\
			basic/ft_itoa_double.c	\
			basic/ft_strnew.c		\
			basic/ft_putshort.c		\
			basic/ft_putnbr_base.c	\
			basic/ft_print_bits.c	\
			letters/a.c				\
			letters/b.c				\
			letters/c.c				\
			letters/d.c				\
			letters/e.c				\
			letters/f.c				\
			letters/g.c				\
			letters/h.c				\
			letters/i.c				\
			letters/j.c				\
			letters/k.c				\
			letters/l.c				\
			letters/m.c				\
			letters/n.c				\
			letters/o.c				\
			letters/p.c				\
			letters/q.c				\
			letters/r.c				\
			letters/s.c				\
			letters/t.c				\
			letters/u.c				\
			letters/v.c				\
			letters/w.c				\
			letters/x.c				\
			letters/y.c				\
			letters/z.c

all:	$(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
