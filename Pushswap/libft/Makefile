# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 13:06:32 by juspende          #+#    #+#              #
#    Updated: 2018/01/08 18:35:05 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

RM	= rm -f

NAME	= libft.a

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

INCLUDE	= /include/libft.h

%.o: %.c
		@gcc $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

SRCS	=	ft_toupper.c ft_tolower.c ft_isalpha.c ft_memalloc.c ft_memdel.c int_len.c \
		ft_isdigit.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_strnew.c ft_strdel.c ft_intlimit.c \
		ft_isascii.c ft_isprint.c ft_atoi.c ft_strstr.c ft_strclr.c ft_striter.c ft_countspace.c \
		ft_strnstr.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_striteri.c ft_strmap.c ft_isnum.c \
		ft_strrchr.c ft_strchr.c ft_strcat.c ft_strncat.c ft_strmapi.c ft_strequ.c ft_putsterr.c \
		ft_strlcat.c ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strnequ.c ft_strsub.c \
		ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c ft_strjoin.c ft_strtrim.c ft_revint.c \
		ft_memcpy.c ft_memset.c ft_bzero.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_sqrt.c \
		ft_putstr.c ft_putnbr.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_is_negative.c \
		ft_putnbr_fd.c ft_putendl_fd.c ft_lstadd.c ft_lstdel.c ft_putnbr_base.c ft_range.c \
		ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_swap.c ft_strrev.c ft_print_words_tables.c\

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
