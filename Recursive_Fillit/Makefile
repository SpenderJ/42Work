##
## Makefile for emacs in /home/jules/fillit
## 
## Made by Jules Spender
## Login   <louis.chegaray@epitech.eu@epitech.net>
## 
## Started on  Tue Nov 14 02:53:37 2017 Jules Spender
## Last update Tue Nov 14 03:00:10 2017 Jules Spender
##

NAME	= 	fillit

RM		=	rm -f

SRC		=	src/main.c		\
			src/reader.c		\
			src/tetrimino.c		\
			src/map.c		\
			src/solver.c		\
			src/test.c

OBJ			= $(SRC:.c=.o)

INCLUDE		= /includes/fillit.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

%.o: %.c
			gcc $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) ./libft/libft.a

clean:
	make clean -C libft/
	$(RM) $(OBJ)

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
