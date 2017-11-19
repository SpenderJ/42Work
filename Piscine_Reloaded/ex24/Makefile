CC	= gcc

RM	= rm -f

NAME	= libft.a

OBJS	= $(SRCS:.c=.o)

SRCS	= 	srcs/ft_putchar.c		\
			srcs/ft_putstr.c		\
			srcs/ft_strcmp.c		\
			srcs/ft_strlen.c		\
			srcs/ft_swap.c		

all:	$(NAME)

CFLAGS	=	-I ./includes/ -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
